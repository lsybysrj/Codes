#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>

GLuint pid=0;

void loadShaderFromFile(GLenum type,const char* filename)
{
  int errid=GL_NO_ERROR;
  std::ifstream ifs;
  ifs.open(filename,std::ifstream::in);
  int length=0;
  ifs.seekg(0,std::ifstream::end);
  length=ifs.tellg();
  ifs.seekg(0,std::ifstream::beg);
  char* f=new char[length];
  ifs.read(f,length);
  printf("%.*s\n",length,f);
  printf("file length: %d\n",length);
  GLuint sid=glCreateShader(type); 
  if((errid=glGetError())!=GL_NO_ERROR)
  {
    printf("glCreateShader faile,errid: %x\n",errid);
  }
  if(glIsShader(sid)!=GL_TRUE)
  {
    printf("sid: %d is not a shader\n",sid);
  }
  printf("sid is %d\n",sid);
  glShaderSource(sid,1,&f,&length);
  if((errid=glGetError())!=GL_NO_ERROR)
  {
    printf("glShaderSource failed,errod code: 0x%x\n",errid);
  }
  glCompileShader(sid);

  GLint compileStatus=GL_TRUE;
  glGetShaderiv(sid,GL_COMPILE_STATUS,&compileStatus);
  if(GL_TRUE!=compileStatus)
  {
    int loglength=0;
    glGetShaderiv(sid,GL_INFO_LOG_LENGTH,&loglength);
    char* logbuffer=new char[loglength];
    glGetShaderInfoLog(sid,loglength,&loglength,logbuffer);

    printf("shader compile log: %*s\n",loglength,logbuffer);
  }
   glAttachShader(pid,sid);
  delete f;
  ifs.close();
}


GLuint nList=0,nCircleList=0;
GLfloat globalf=1.0f;
void myrefresh(GLFWwindow* window)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

//  glRotated(globalf,1.0,0.0,0.0);
  glCallList(nList);
  glfwSwapBuffers(window);
}
void mykey(GLFWwindow* w,int key,int scancode,int action,int modifer)
{
  glMatrixMode(GL_MODELVIEW);
  switch(key)
  {
    case GLFW_KEY_A:
    case GLFW_JOYSTICK_1:
      glTranslatef(-100,0.0f,0.0f);
      break;
    case GLFW_KEY_D:
    case GLFW_JOYSTICK_3:
      glTranslatef(100,0.0f,0.0f);
      break;
    case GLFW_KEY_S:
      glTranslatef(0,0,-0.5f);
      break;
    case GLFW_KEY_W:
      glTranslatef(0,0,0.5f);
      break;
    default:
      break;

  }
  printf("press key:%c\n",key);
}

int main()
{

  GLuint codeid=GL_NO_ERROR;
  if(!glfwInit())
  {
    printf("cannot init glfw\n");
    return 0;
  }
  /*
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
 */ 

  GLFWwindow* window= glfwCreateWindow(1920,1080,"myglfw",0,0);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window,mykey);
  glfwShowWindow(window);
  /*
  const GLubyte* version=glGetString(GL_VERSION);
  const GLubyte* vendor=glGetString(GL_VENDOR);
  const GLubyte* ext=glGetString(GL_EXTENSIONS);
  printf("version is %s , vendor is %s , extensions are %s\n",version,vendor,ext);
  */

  pid=glCreateProgram();
  loadShaderFromFile(GL_VERTEX_SHADER,"./vertex.vs");
  loadShaderFromFile(GL_FRAGMENT_SHADER,"./frag.fs");
  glLinkProgram(pid);
  glUseProgram(pid);

    
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
  glHint(GL_LINE_SMOOTH,GL_NICEST);
  glHint(GL_POLYGON_SMOOTH,GL_NICEST);
  glDepthFunc(GL_ALWAYS);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  GLubyte* stipple[128];
  memset(stipple,183,40);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1920.0f,1920.0f,-1080.0f,1080.0f,1,200.0f);

  glColor3f(1.0f,0.0f,0.0f);

  nList=glGenLists(1);
  glNewList(nList,GL_COMPILE);
  //glEnable(GL_POLYGON_STIPPLE);
  glPolygonStipple((const GLubyte*)stipple);
  glBegin(GL_POLYGON);
  glVertex3i(-2500,2500,-100);
  glVertex3i(-2500,-2500,-100);
  glVertex3i(2500,-2500,-100);
  glVertex3i(2500,2500,-100);
  glEnd();
  glDisable(GL_POLYGON_STIPPLE);
  glEndList();
  nCircleList=glGenLists(1);
  glNewList(nCircleList,GL_COMPILE);
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<4000;i++)
  {
    glVertex3f(-2500*sin(i*3.14*2/40),-2500*cos(i*3.14*2/40),-100);
  }
  glEnd();
  glEndList();
  while(!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(nList);
//    glCallList(nCircleList);
    glfwSwapBuffers(window);
    glfwPollEvents();
  } 
  return 0;
}
