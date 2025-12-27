#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

static GLfloat spin = 0.0;
static float tx = 2.0;
static float ty = 2.0;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-5, 5, -5, 5, -5, 5);
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
     glScaled(0.5f, 0.5f, 1.0);
     glTranslatef(tx, ty, 0.0);
     glRotatef(spin, 0.0, 0.0, 1.0);


    glBegin(GL_QUADS);
      glVertex2d(3.0, 3.0);
      glVertex2d(-3.0, 3.0);
      glVertex2d(-3.0, -3.0);
      glVertex2d(3.0, -3.0);
    glEnd();
/*
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glTranslatef(tx,ty,0);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2d(0.0, 2.0);

        glColor3f(0.8f, 0.2f, 0.1f);
        glVertex2d(-2.0, 0.0);

        glColor3f(0.4f, 0.5f, 0.9f);
        glVertex2d(2.0, 0.0);
    glEnd();
*/


    glPopMatrix();

    glFlush();
}

void spinDisplay_Left(void)
{
    spin = spin + 0.5;
    glutPostRedisplay();
}

void spinDisplay_Right(void)
{
    spin = spin - 0.5;
    glutPostRedisplay();
}

void my_keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case 'l':
            spinDisplay_Left();
            break;
        case 'r':
            spinDisplay_Right();
            break;
        case 's':
            glutIdleFunc(NULL);
            break;
        case 'c':
            tx = 0;
		    ty = 0;
		    glutPostRedisplay();
		    break;
    default:
            break;
    }
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
		    tx -= 0.5;
		    glutPostRedisplay();
		    break;

        case GLUT_KEY_RIGHT:
		    tx += 0.5;
		    glutPostRedisplay();
		    break;

        case GLUT_KEY_DOWN:
		    ty -= 0.5;
		    glutPostRedisplay();
		    break;

        case GLUT_KEY_UP:
		    ty += 0.5;
		    glutPostRedisplay();
		    break;

	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_Left);
            break;
      case GLUT_MIDDLE_BUTTON:
            glutIdleFunc(NULL);
            break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_Right);
            break;
      default:
         break;
   }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CSE 21");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
