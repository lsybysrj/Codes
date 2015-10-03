#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if defined(__APPLE_CC__)
 #if defined(GLFW_INCLUDE_GLCOREARB)
  #warning "#include <OpenGL/gl3.h>"
  #if defined(GLFW_INCLUDE_GLEXT)
    #warning "#include <OpenGL/gl3ext.h>"
  #endif
 #elif !defined(GLFW_INCLUDE_NONE)
  #if !defined(GLFW_INCLUDE_GLEXT)
   #warning "#define GL_GLEXT_LEGACY"
  #endif
  #warning "#include <OpenGL/gl.h>"
 #endif
 #if defined(GLFW_INCLUDE_GLU)
  #warning "#include <OpenGL/glu.h>"
 #endif
#endif


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
      glTranslatef(0,0,-1.0f);
      break;
    case GLFW_KEY_W:
      glTranslatef(0,0,1.0f);
      break;
    default:
      break;

  }
  printf("press key:%c\n",key);
}

int main()
{

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
  const GLubyte* version=glGetString(GL_VERSION);
  const GLubyte* vendor=glGetString(GL_VENDOR);
  const GLubyte* ext=glGetString(GL_EXTENSIONS);
 // printf("version is %s , vendor is %s , extensions are %s\n",version,vendor,ext);
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
  glEnable(GL_POLYGON_STIPPLE);
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
  //  glCallList(nList);
    glCallList(nCircleList);
    glfwSwapBuffers(window);
    glfwPollEvents();
  } 
  return 0;
}
