/*
    Brianna Brown Richardson
    CS300 - Computer Graphics
    Dr. Byrnes



 */

#ifdef __APPLE__
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static GLfloat angle = -150;   /* in degrees */
static GLfloat angle2 = 30;   /* in degrees */

static GLfloat baseAngle = 0;
static GLfloat armAngle = 0;
static GLfloat clawAngle = 0;
static GLfloat currentAngle = 0;

static int moving = 0, startx= 0, starty= 0;


//prototypes
void init(void);
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void EnableLighting( void );

void init(void)
{
   glClearColor(0.0, 0.0, 0.0,1.0);
	glClearDepth(1.0f);
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	 glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-200.0,200.0,-200.0, 200.0,-200.0, 200.0);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();


  /* Setup initial OpenGL rendering state. */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void wheels(){
    glColor3f(0.517647, 0.517647, 0.517647);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();

    //glTranslatef(0.0, 0.0, 20.0);
    glPushMatrix();
        glTranslatef(35.0, 0.0, -35.0);
        glPushMatrix();
        //glRotatef(60.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(quadratic,10.0f,10.0f,70.0f,32,32);
        glPopMatrix();

        glTranslatef(-70.0, 0.0, 0.0);
        glPushMatrix();
            //glRotatef(60.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(quadratic,10.0f,10.0f, 70.0f,32,32);
        glPopMatrix();
    glPopMatrix();


}

void base(){

  glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);

  glTranslatef(0.0, 20.0, 20.0);
  glPushMatrix();
    glPushMatrix();
    glTranslatef(-30.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -20.0);
    glPushMatrix();
    glTranslatef(-30.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -20.0);
    glPushMatrix();
    glTranslatef(-30.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glTranslatef(20.0, 0.0, 0.0);
    glutSolidCube(20.0);
    glPopMatrix();


  glPopMatrix();
  glPopMatrix();

}

void first_piece(){
    glColor3f(0.517647, 0.517647, 0.517647);
    glTranslatef(0.0, 45.0, 0.0);

    glutSolidCube(30.0);

}

void claw(){
    glTranslatef(0.0, 130.0, 0.0);
    glScalef(8.0, 8.0, 8.0);

    glColor3f(0.333333, 0.333333, 0.333333);
    glPushMatrix();
    glutSolidSphere(2.0, 20.0, 20.0);
    glPopMatrix();

    glColor3f(0.411765, 0.411765, 0.411765);
    glRotatef(0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    glRotatef(clawAngle, 1.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 3.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 1.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 1.0, 0.0);
    glutSolidCube(1.5);
   glRotatef(90, 0.0, 0.0, 1.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCube(1.5);
    glPopMatrix();

    glColor3f(0.411765, 0.411765, 0.411765);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef(clawAngle, 0.0, 0.0, 1.0);
    glutSolidCube(1.5);
    glTranslatef(-3.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(-1.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(-1.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, -1.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, -1.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, -1.0, 0.0);
    glutSolidCube(1.5);
    glPopMatrix();

    glColor3f(0.411765, 0.411765, 0.411765);
    glRotatef(180, 1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef(clawAngle, 0.0, 0.0, 1.0);
    glutSolidCube(1.5);
    glTranslatef(3.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(1.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(1.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 1.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 1.0, 0.0);
    glutSolidCube(1.5);
    glTranslatef(0.0, 0.0, 0.0);
    glutSolidCube(1.5);
    glPopMatrix();
}

void crane(){
    glTranslatef(0.0, 130.0, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glPushMatrix();
        //glTranslatef(0.0, 50.0, 0.0);
        glColor3f(0.517647, 0.517647, 0.517647);
        glTranslatef(0.0, 10.0, 0.0);
        // glutSolidSphere(10.0, 10.0, 20.0);
        glColor3f(0.333333, 0.333333, 0.333333);
        glutSolidCube(10.0);
        for (int i = 0; i < 12; i++){
            glTranslatef(0.0, 10.0, 0.0);
            glutSolidCube(10.0);
        }
        // glScalef(8.0, 8.0, 8.0);
        // claw();

    glPopMatrix();
}

void second_piece(){
    glColor3f(0.333333, 0.333333, 0.333333);
    glTranslatef(-9.7, 20.0, 0.0);
    glPushMatrix();

        glPushMatrix();
          glScalef(1.0, 14.0, 1.0);
          glTranslatef(0.0, 4.0, 0.0);
          glutSolidCube(10.0);
        glPopMatrix();


        glPushMatrix();
          glTranslatef(0.0, 120.0, 0.0);

          glColor3f(0.517647, 0.517647, 0.517647);
          glTranslatef(0.0, 10.0, 0.0);
          glutSolidSphere(10.0, 10.0, 20.0);


          // crane();
        glPopMatrix();
    glPopMatrix();
}



void crane_string(){
    glBegin(GL_POLYGON);

    glEnd();
}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;



    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    glPushAttrib(GL_CURRENT_BIT);
      glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
          glVertex3f(-100.0, 0, 0);
          glVertex3f(100.0, 0, 0);
        glColor3f(0.0, 1.0, 0.0);
          glVertex3f(0, -100.0, 0);
          glVertex3f(0, 100.0, 0);
        glColor3f(0.0, 0.0, 1.0);
          glVertex3f(0, 0, -100.0);
          glVertex3f(0, 0, 100.0);
      glEnd();
    glPopAttrib();

        wheels();
        glPushMatrix();
            base();
            glPushMatrix();

                glRotatef(baseAngle, 0.0, 1.0, 0.0);

                first_piece();

                glPushMatrix();
                    second_piece();

                    glPushMatrix();
                      glTranslatef(0.0, 130.0, 0.0);
                      glRotatef(armAngle, 0.0, 0.0, 1.0);
                      glTranslatef(0.0, -130.0, 0.0);
                      crane();

                      glPushMatrix();
                        claw();
                      glPopMatrix();
                    glPopMatrix();

                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();



    glFlush();
}

void reshape(int width, int height)
{
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_MODELVIEW);  // To operate on the Projection matrix
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   #pragma unused (x,y)
   switch (key) {

      case 'd':
      case 'D':
        if (clawAngle < 50) {
          clawAngle += 5;
        }
        break;
      case 'a':
      case 'A':
        if (clawAngle > -10) {
          clawAngle -= 5;
        }
        break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }

   glutPostRedisplay();
}

void mySpecialFunc (int key, int x, int y) {

  #pragma unused (x, y);

  if (glutGetModifiers() & GLUT_ACTIVE_SHIFT) {
    if (key == GLUT_KEY_RIGHT && armAngle < 120) {
      armAngle += 5;
    } else if (key == GLUT_KEY_LEFT && armAngle > -25) {
      armAngle -= 5;
    }
  } else {
    if (key == GLUT_KEY_RIGHT) {
      baseAngle += 5;
    } else if (key == GLUT_KEY_LEFT) {
      baseAngle -= 5;
    }
    if (key == GLUT_KEY_UP && armAngle < 120) {
      armAngle += 5;
    } else if (key == GLUT_KEY_DOWN && armAngle > -25) {
      armAngle -= 5;
    }
  }

  // switch (key) {
  //   case GLUT_KEY_RIGHT:
  //     if (currentAngle == 0) {
  //       baseAngle += 10;
  //     } else if ((currentAngle == 1) && (armAngle < 120)) {
  //       armAngle += 10;
  //     } else if ((currentAngle == 2) && (clawAngle < 50)) {
  //       clawAngle += 10;
  //     }
  //     break;
  //   case GLUT_KEY_LEFT:
  //     if (currentAngle == 0) {
  //       baseAngle -= 10;
  //     } else if ((currentAngle == 1) && (armAngle > -30)) {
  //       armAngle -= 10;
  //     } else if ((currentAngle == 2) && (clawAngle > -10)) {
  //       clawAngle -= 10;
  //     }
  //     break;
  //   default:
  //     break;
  // }

  glutPostRedisplay();

}

static void
mouse(int button, int state, int x, int y)
{
  /* Rotate the scene with the left mouse button. */
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}

/* ARGSUSED1 */
static void
motion(int x, int y)
{
  if (moving) {
    angle = (angle + (x - startx));
    angle2 = (angle2 + (y - starty));
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
 }

void Idle(){

    glutPostRedisplay();

}

void angleMenuFunc (int id) {
  currentAngle = id;
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (600, 600);
   //glutInitWindowPosition (50, 50);
   glutCreateWindow("Project 2");
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
  glutMotionFunc(motion);
    //glutIdleFunc(Idle);
   glutKeyboardFunc (keyboard);
   glutSpecialFunc(mySpecialFunc);

   int angleMenuId = glutCreateMenu(angleMenuFunc);
   glutAddMenuEntry("Base", 0);
   glutAddMenuEntry("Arm", 1);
   glutAddMenuEntry("Claw", 2);
   glutAttachMenu(GLUT_RIGHT_BUTTON);


   glutMainLoop();
   return 0;
}
