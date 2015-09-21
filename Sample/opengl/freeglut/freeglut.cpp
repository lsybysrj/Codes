#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

GLuint nList=0;
GLfloat globalf=1.0f;
void myrefresh()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glCallList(nList);
  glutSwapBuffers();
}
void myjoyfun(unsigned int button,int x,int y ,int z)
{
  printf("joystick\n");
  glTranslatef(100*x/abs(x),0,0);
  glTranslatef(0,100*y/abs(y),0);
  glTranslated(0,0,100*z/abs(z));
}
void mykey(unsigned char key,int x,int y)
{
  glMatrixMode(GL_MODELVIEW);
  switch(key)
  {
    case 'A':
      glTranslatef(-100,0.0f,0.0f);
      break;
    case 'D':
      glTranslatef(100,0.0f,0.0f);
      break;
    case 'S':
      glTranslatef(0,-100.0f,0);
      break;
    case 'W':
      glTranslatef(0,100.0f,0);
      break;
    case 'Q':
      glTranslatef(0,0,-100.0f);
      break;
    case 'E':
      glTranslatef(0,0,100.0f);
      break;
    default:
      break;

  }
}

int main(int argc,char** argv)
{

  glutInit(&argc,argv);
  glutInitWindowSize(400,400);
  glutInitContextFlags(GLUT_DOUBLE|GLUT_RGBA);
  glutCreateWindow("opengl");
  glutDisplayFunc(myrefresh);
  glutKeyboardFunc(mykey);
  //glutJoystickFunc(myjoyfun,100);
  glutIdleFunc(myrefresh);

  /*  
  const GLubyte* version=glGetString(GL_VERSION);
  const GLubyte* vendor=glGetString(GL_VENDOR);
  const GLubyte* ext=glGetString(GL_EXTENSIONS);
  printf("version is %s , vendor is %s , extensions are %s\n",version,vendor,ext);
  */
  glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
  glDepthFunc(GL_ALWAYS);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  nList=glGenLists(1);
  glNewList(nList,GL_COMPILE);

  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10000,10000,-10000,10000,-1000,1000);
  glViewport(0,0,400,400);
  glBegin(GL_TRIANGLES);
  glColor3f(0.0,0.0,1.0f);
  glVertex3i(0,2500,-100);
  glEdgeFlag(GL_FALSE);
  glVertex3i(-2500,-2500,-100);
  glEdgeFlag(GL_TRUE);
  glVertex3i(2500,-2500,-100);
  glEdgeFlag(GL_FALSE);
  glVertex3i(2500,-2500,-100);
  glEdgeFlag(GL_TRUE);
  glVertex3i(-2500,-2500,-100);
  glVertex3i(0,-5000,-100);
  glEnd();
  

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1000.0f,1000.0f,-1000.0f,1000.0f,1,1000.0f);
  glViewport(400,0,400,400);
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3i(0,2500,-100);
  glVertex3i(-2500,-2500,-100);
  glVertex3i(2500,-2500,-100);
  glEnd();
  glEndList();
  glutMainLoop();
  return 0;
}
