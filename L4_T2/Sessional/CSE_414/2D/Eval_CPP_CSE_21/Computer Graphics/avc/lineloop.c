#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

static GLfloat spin = 0.0; // angle for rotation
static float tx = 0.0;     // position along X-axis
static float ty = 0.0;     // position along Y-axis
static float dirX = 0.0;   // direction along X-axis
static float dirY = 0.0;   // direction along Y-axis

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // background color
    glOrtho(-10, 10, -10, 10, -10, 10);   // set the coordinate system
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glScaled(0.2f, 0.2f, 1);
    glTranslatef(tx, ty, 0.0); // position the object
    glRotatef(spin, 0.0, 0.0, 1.0); // rotation

    // Object Shape (A polygon)
      glBegin(GL_QUADS);
      // First Shape (Original)
glBegin(GL_POLYGON);
    glVertex2d(0, 0.5);
    glVertex2d(-3.0, 2);
    glVertex2d(-4.0, 2.0);
    glVertex2d(-0.5, 0);

    glVertex2d(3, 2);
    glVertex2d(2, 2);
    glVertex2d(-4.0, -2.0);
    glVertex2d(-3, -2);
glEnd();

// Second Shape (Shifted Right)
glBegin(GL_POLYGON);
    glVertex2d(7, 0.5);   // Shifted +5 units on x-axis
    glVertex2d(4.0, 2);
    glVertex2d(3.0, 2.0);
    glVertex2d(6.5, 0);

    glVertex2d(10, 2);
    glVertex2d(9, 2);
    glVertex2d(3.0, -2.0);
    glVertex2d(4, -2);
glEnd();
glBegin(GL_POLYGON);
    glVertex2d(14, 0.5);   // Shifted +5 units on x-axis
    glVertex2d(11.0, 2);
    glVertex2d(10.0, 2.0);
    glVertex2d(13.5, 0);

    glVertex2d(17, 2);
    glVertex2d(16, 2);
    glVertex2d(11.0, -2.0);
    glVertex2d(12, -2);
glEnd();


    glPopMatrix();
    glFlush();
}

void snakeMove(void)
{
    // Automatically update position based on direction
    tx += dirX * 0.05; // Speed: 0.05 per frame
    ty += dirY * 0.05;
    glutPostRedisplay();
}

void spe_key(int key, int x, int y)
{
    // Update direction based on arrow key press
    switch (key)
    {
    case GLUT_KEY_LEFT:
        dirX = -1.0; // Move left
        dirY = 0.0;
        break;

    case GLUT_KEY_RIGHT:
        dirX = 1.0; // Move right
        dirY = 0.0;
        break;

    case GLUT_KEY_UP:
        dirX = 0.0;
        dirY = 1.0; // Move up
        break;

    case GLUT_KEY_DOWN:
        dirX = 0.0;
        dirY = -1.0; // Move down
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
    glutCreateWindow("Snake Movement Example");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key); // Handle arrow keys
    glutIdleFunc(snakeMove);  // Continuously move the object
    glutMainLoop();
    return 0;
}
