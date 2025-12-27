#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

static GLfloat spin = 0.0;
static float tx = 0.0;
static float ty = 0.0;
static float sx = 0.0;
static float sy = 0.0;

static float ltx = 0.0;
static float lty = 0.0;
static float rtx = 0.0;
static float rty = 0.0;

static float utx = 0.0;
static float uty = 0.0;
static float dtx = 0.0;
static float dty = 0.0;


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-10, 10, -10, 10, -10, 10);
}

void lomba(float px, float py)
{
    glBegin(GL_QUADS);
      glVertex2d(0.5+px, 4.0+py);
      glVertex2d(-0.5+px, 4.0+py);
      glVertex2d(-0.5+px, -4.0+py);
      glVertex2d(0.5+px, -4.0+py);
    glEnd();
}

void choto(float px, float py)
{
    glBegin(GL_QUADS);
      glVertex2d(2.0+px, 0.5+py);
      glVertex2d(-2.0+px, 0.5+py);
      glVertex2d(-2.0+px, -0.5+py);
      glVertex2d(2.0+px, -0.5+py);
    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
     glScaled(0.5f, 0.5f, 1.0);
     glRotatef(spin, 0.0, 0.0, 1.0);

    ///1
    lomba(0,0);

   ///left 0
    glTranslatef(ltx, lty, 0.0);
    lomba(-19.5,0);
    choto(-18,4);
    choto(-18,-4);
    lomba(-16.5,0);

    /// right 0
    glTranslatef(rtx, rty, 0.0);
    lomba(19.5,0);
    choto(18,4);
    choto(18,-4);
    lomba(16.5,0);


    ///up 0
    glTranslatef(utx, uty, 0.0);
    lomba(1.5,16);
    choto(0,12);
    choto(0,20);
    lomba(-1.5,16);


    ///down 0
    glTranslatef(dtx, dty, 0.0);
    lomba(1.5,-16);
    choto(0,-12);
    choto(0,-20);
    lomba(-1.5,-16);



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

void trans(void)
{
    ltx -= 0.5;
    rtx += 0.5;
    uty += 0.5;
    dty -= 0.5;
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
        case '9':
            spin += 90.0;
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
		    if(tx>=10 || tx<=-10)
                break;
            else
            {
                tx -= 0.5;
                glutPostRedisplay();
                break;
            }


        case GLUT_KEY_RIGHT:
            if(tx>=10 || tx<=-10)
                break;
            else
            {
                tx += 0.5;
                glutPostRedisplay();
                break;
            }
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
            glutIdleFunc(trans);
            break;
      case GLUT_MIDDLE_BUTTON:
            glutIdleFunc(NULL);
            break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			//glutIdleFunc(spinDisplay_Right);
            break;
      default:
         break;
   }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
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
