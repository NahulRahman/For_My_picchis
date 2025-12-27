#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include <GL/freeglut.h>
#include<stdlib.h>
#include<math.h>

struct Color
{
    GLfloat r, g, b, a;
};

const Color RED = { 255.0f / 255.0, 0.0f / 255.0, 0.0f / 255.0, 1.0f };
const Color GREEN = { 0.0f / 255.0, 255.0f / 255.0, 0.0f / 255.0, 1.0f };
const Color BLUE = { 0.0f / 255.0, 0.0f / 255.0, 255.0f / 255.0, 1.0f };
const Color BG_COLOR = { 34.0f / 255.0, 34.0f / 255.0, 34.0f / 255.0, 1.0f };
const Color GREY = { 128.0f / 255.0, 128.0f / 255.0, 128.0f / 255.0, 1.0f };
const Color PURPLE = { 128.0f / 255.0, 0.0f / 255.0, 128.0f / 255.0, 1.0f };
const Color TEAL = { 0.0f / 255.0, 128.0f / 255.0, 128.0f / 255.0, 1.0f };
const Color YELLOW = { 255.0f / 255.0, 255.0f / 255.0, 0.0f / 255.0, 1.0f };

static GLfloat spin1 = 0.0, spin2 = 0.0;
static float tx = 0.0;
static float ty = 0.0;

float minScale=0.5, maxScale=20;
float bLeft=0, bRight=0, bTop=0, bBottom=0;

int Dimx=20;
int Dimy=20;
int Dimz=20;

constexpr float PI = 3.14159265358979f;
constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;
constexpr int refreshRate = 60;

int rotationAngle = 0.0f;
//int tx = 0, ty = 0, sideLen = 50;
int rx = -200, ry = 0;
float scaleFactor = 1.0f, scaleFactor2=1.0f;

bool paused = false;

void init()
{
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glClearColor(BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
    glOrtho(-Dimx, Dimx, -Dimy, Dimy, -Dimz, Dimz);
}

static void renderText(std::string text, float x, float y)
{
//	glColor3f(RED.r, RED.g, RED.b);
	glRasterPos2f(x, y);

	for (int i = 0; i < text.size(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}

static void timerFunc(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / value, timerFunc, value);

	if (!paused)
	{
		spin1 += 5.0f;
		if (spin1 > 360.0f)
		{
			spin1 -= 360.0f;
		}
	}
}

static void drawGrid(int h_half, int v_half)
{
    constexpr int blockSize = 1;
    glColor3f(GREY.r, GREY.g, GREY.b);
    glLineWidth(0.5f);

    glBegin(GL_LINES);

    for(int x = -h_half; x <= h_half; x += blockSize)
    {
        if(x==0)
            continue;
        glVertex2f(x, v_half);
        glVertex2f(x, -v_half);
    }

    for(int y = -v_half; y <= v_half; y += blockSize)
    {
        if(y==0)
            continue;
        glVertex2f(h_half, y);
        glVertex2f(-h_half, y);
    }

    glColor3f(RED.r, RED.g, RED.b);
    glVertex2f(0, v_half);
    glVertex2f(0, -v_half);
    glVertex2f(h_half, 0);
    glVertex2f(-h_half, 0);

    glEnd();
}


void rectangle(double width, double height, double spin=0, double padx=0, double pady=0, double padz=0, double scaleFactor=1)
{
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(padx, pady, padz);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glScaled(width/2, height/2, 1.0);
//    glScaled(width*scaleFactor/2, height*scaleFactor/2, 1.0);
//    glScaled(scaleFactor, scaleFactor, 1.0);
    glBegin(GL_QUADS);
        glVertex2d( 1.0,  1.0);
        glVertex2d(-1.0,  1.0);
        glVertex2d(-1.0, -1.0);
        glVertex2d( 1.0, -1.0);
    glEnd();

}

void triangle(double base, double height, double spin=0, double padx=0, double pady=0, double padz=0, double scaleFactor=1)
{
    glTranslatef(padx, pady, padz);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glScaled(base*scaleFactor/2, height*scaleFactor/2, 1.0);
//    glScaled(scaleFactor, scaleFactor, 1.0);
    glBegin(GL_TRIANGLES);
        //glColor3f(0.0f, 1.0f, 0.0f); /// Gradient colouring 1st side: Green
        glVertex2d(0.0, 1.0);

        //glColor3f(0.8f, 0.2f, 0.1f); /// Gradient colouring 2nd side
        glVertex2d(-1.0, 0.0);

        //glColor3f(0.4f, 0.5f, 0.9f); /// Gradient colouring 3rd side
        glVertex2d( 1.0, 0.0);
    glEnd();
}

void right_triangle(double base, double height, double spin=0, double padx=0, double pady=0, double padz=0, double scaleFactor=1, int flip=1)
{
    glTranslatef(padx, pady, padz);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glScaled(base/2, height/2, 1.0);
//    glScaled(base*scaleFactor/2, height*scaleFactor/2, 1.0);
//    glScaled(scaleFactor, scaleFactor, 1.0);
    glBegin(GL_TRIANGLES);
        //glColor3f(0.0f, 1.0f, 0.0f); /// Gradient colouring 1st side: Green
        glVertex2d(0.0, 1.0);

        //glColor3f(0.8f, 0.2f, 0.1f); /// Gradient colouring 2nd side
        glVertex2d(0.0, 0.0);

        //glColor3f(0.4f, 0.5f, 0.9f); /// Gradient colouring 3rd side
        glVertex2d( 1.0 * flip, 0.0);
    glEnd();
}

static void circle(float cx, float cy, float radius, double scaleFactor=1, bool fillCircle=false)
{
    if(fillCircle)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

	radius *= scaleFactor;

	for (int i = 1; i <= 100000; ++i)
	{
		float angle = 2 * PI * (i / 100000.0);
		float x = radius * cos(angle) + cx;
		float y = radius * sin(angle) + cy;

		glVertex2f(x, y);
	}

	glEnd();
}

static void spacebase(float cx, float cy, float radius, double scaleFactor=1, bool fillCircle=false)
{
    if(fillCircle)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

	radius *= scaleFactor;

	for (int i = 1; i <= 100000; ++i)
	{
		float angle = 2 * PI * (i / 100000.0);
		float x = radius * cos(angle) + cx;
		float y = 0.5*radius * sin(angle) + cy;

		glVertex2f(x, y);
	}

	glEnd();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /// Grid
    glPushMatrix();
    drawGrid(20, 20);
    glPopMatrix();

    /// Manush
        /// Head
    glPushMatrix();
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, 0, 0);
    circle(5,5,1,1,true);
    glPopMatrix();
        /// Body
    glPushMatrix();
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, -0, 0);
    rectangle(0.5,4,0,5,3,0,1);
    glPopMatrix();
        /// Left Hand
    glPushMatrix();
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, -0, 0);
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    rectangle(2,0.5,-135,4.5,3,0,1);
    glPopMatrix();
        /// Right Hand
    glPushMatrix();
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, -0, 0);
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    rectangle(2,0.5,-45,5.5,3,0,1);
    glPopMatrix();
         /// Left Leg
    glPushMatrix();
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, -0, 0);
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    rectangle(2,0.5,-135,4.5,3-2,0,1);
    glPopMatrix();
        /// Right Leg
    glPushMatrix();
    glTranslatef(5, 0, 0);
    glScaled(scaleFactor, scaleFactor, 1.0);
    glTranslatef(-5, -0, 0);
    glColor3f(YELLOW.r, YELLOW.g, YELLOW.b);
    rectangle(2,0.5,-45,5.5,3-2,0,1);
    glPopMatrix();

    /// Moon
    glPushMatrix();
    glColor3f(.999, .999, .999);
    circle(-13,13,3,1,true);
    glPopMatrix();



    ///Tent
    glPushMatrix();
    glColor3f(GREEN.r, GREEN.g, GREEN.b);
//    glTranslatef(6, 8, 0.0);
//    glRotatef(spin2, 0.0, 0.0, 1.0);

    triangle(8,16,0, 0, 0, 0,  1);

    glPopMatrix();

//    glPushMatrix();
//    glColor3f(0, 0, 1);
//    rectangle(0.02,8,0, 0, 0+4,0,1);
//
//    glPopMatrix();


    /// Space Ship
    double c1x=14,c1y=15;

    glPushMatrix();
    glColor3f(TEAL.r, TEAL.g, TEAL.b);
    glTranslatef(tx+c1x, ty+c1y-1+3, 0);
    glScaled(scaleFactor, scaleFactor*scaleFactor, 1.0);
    glTranslatef(-tx-c1x, -ty-c1y+1-3, 0);

    //glScaled(scaleFactor, scaleFactor, 1.0); /// Always change scale at the end of point rendering
    triangle(2,3,0,tx+c1x,ty+c1y-1.5,0,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.999, .999, .999);
//    glColor3f(0, 0, 1);
//    glTranslatef(c1x, c1y, 0);
//    glRotatef(spin1, 0.0, 0.0, 1.0);
//    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    spacebase(c1x,c1y,5,1,true);
    glPopMatrix();

    glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x+2,c1y+2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x,c1y+2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x-2,c1y+2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x-2,c1y,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x-2,c1y-2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x,c1y-2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x+2,c1y-2,1,1,true);
    glPopMatrix();

        glPushMatrix();
//    glColor3f(.999, .999, .999);
    glColor3f(0, 0, 1);
    glTranslatef(c1x, c1y, 0);
    glRotatef(spin1, 0.0, 0.0, 1.0);
    glTranslatef(-c1x, -c1y, 0);
    glTranslatef(tx, ty, 0);
    circle(c1x+2,c1y,1,1,true);
    glPopMatrix();


    glFlush();
}

void spinDisplay_Left(void)
{
    spin2 = spin2 + 0.5;
    if(spin2 > 360.0)
    spin2 = spin2 - 360;
    glutPostRedisplay(); /// Re-render the scene
}

void spinDisplay_Right(void)
{
    spin2 = spin2 - 0.5;
    if(spin2 < -360.0)
    spin2 = spin2 + 360.0;
    glutPostRedisplay(); /// Re-render the scene
}

void my_keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
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
        glutPostRedisplay(); /// Re-render the scene
        break;
    case ']':
        if(scaleFactor<maxScale) /// Setting Upper limit for scalefactor
            scaleFactor+=0.1;
        std::cout << scaleFactor << "\n";
        glutPostRedisplay();
        break;
    case '[':
        if(scaleFactor>minScale) /// Setting Lower limit for scalefactor
            scaleFactor-=0.1;
        std::cout << scaleFactor << "\n";
        glutPostRedisplay();
        break;
    case '9':
        if(scaleFactor2<maxScale) /// Setting Upper limit for scalefactor
            scaleFactor2+=1;
        glutPostRedisplay();
        break;
    case '0':
        if(scaleFactor2>minScale) /// Setting Lower limit for scalefactor
            scaleFactor2-=1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void spe_key(int key, int x, int y)
{
    bLeft= Dimx-1.5;
    bRight=18.5;
    bTop=17.5;
    bBottom=17.5;

    switch (key)
    {

    case GLUT_KEY_LEFT: /// Arrow Left
        if( tx-0.5 >= -bLeft)
            tx -= 0.5;
        std::cout << tx << "\n";
        glutPostRedisplay(); /// Re-render the scene
        break;

    case GLUT_KEY_RIGHT: /// Arrow Right
        tx += 0.5;
        glutPostRedisplay(); /// Re-render the scene
        break;

    case GLUT_KEY_DOWN: /// Arrow Down
        ty -= 0.5;
        glutPostRedisplay(); /// Re-render the scene
        break;

    case GLUT_KEY_UP: /// Arrow Up
        ty += 0.5;
        glutPostRedisplay(); /// Re-render the scene
        break;

    default:
        break;
    }
}

void my_mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) /// button pressed down
            glutIdleFunc(spinDisplay_Left);
        break;
    case GLUT_MIDDLE_BUTTON:
        glutIdleFunc(NULL); /// Stops the spin, or in other words Keep the window idle
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)/// button pressed down
            glutIdleFunc(spinDisplay_Right);
        break;
    default:
        break;
    }
}

static void mouseWheel(int wheelNum, int direction, int mouseX, int mouseY)
{
    switch (direction)
    {
    case 1: /// Scroll Up
//		rotationAngle += 5;
        spin1 += 45;
        break;
    case -1: /// Scroll Down
//		rotationAngle -= 5;
        spin1 -= 45;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700, 700); /// (WIDTH, HEIGHT)
    glutInitWindowPosition(400, 50);
    glutCreateWindow("202114093");

    init();

    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);
    glutMouseWheelFunc(mouseWheel);

    glutMainLoop();
    return 0;
}
