#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GLuint nList=0;
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

  GLFWwindow* window= glfwCreateWindow(400,400,"myglfw",0,0);
  glfwSetKeyCallback(window,mykey);
  glfwShowWindow(window);
  const GLubyte* version=glGetString(GL_VERSION);
  const GLubyte* vendor=glGetString(GL_VENDOR);
  const GLubyte* ext=glGetString(GL_EXTENSIONS);
 // printf("version is %s , vendor is %s , extensions are %s\n",version,vendor,ext);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
  glDepthFunc(GL_ALWAYS);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  GLubyte* stipple[128];
  memset(stipple,183,40);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1000.0f,1000.0f,-1000.0f,1000.0f,1,200.0f);


  nList=glGenLists(1);
  glNewList(nList,GL_COMPILE);
  glEnable(GL_POLYGON_STIPPLE);
  glPolygonStipple((const GLubyte*)stipple);
  glBegin(GL_POLYGON);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3i(-2500,2500,-100);
  glVertex3i(-2500,-2500,-100);
  glVertex3i(2500,-2500,-100);
  glVertex3i(2500,2500,-100);
  glEnd();
  glDisable(GL_POLYGON_STIPPLE);
  glEndList();
  while(!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(nList);
    glfwSwapBuffers(window);
    glfwPollEvents();
  } 
  return 0;
}
