#include <GL/glut.h>  // GLUT header for OpenGL

// Initial color values
float r = 1.0f, g = 0.0f, b = 0.0f;  // Red color

// Position of the square
float x = 0.0f, y = 0.0f;

// Keyboard callback function
void keyboard(unsigned char key, int xPos, int yPos) {
    switch (key) {
        case 'r':  // Change color to red
            r = 1.0f; g = 0.0f; b = 0.0f;
            break;
        case 'g':  // Change color to green
            r = 0.0f; g = 1.0f; b = 0.0f;
            break;
        case 'b':  // Change color to blue
            r = 0.0f; g = 0.0f; b = 1.0f;
            break;
        case 27:   // Exit on ESC key
            exit(0);
            break;
    }
    glutPostRedisplay();  // Request to redraw the scene
}

// Mouse callback function
void mouse(int button, int state, int xPos, int yPos) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        x = (float)xPos / 250 - 1.0f;  // Map x position to [-1, 1]
        y = 1.0f - (float)yPos / 250; // Map y position to [-1, 1]
        glutPostRedisplay();  // Request to redraw the scene
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // Set the current color
    glColor3f(r, g, b);

    // Draw a square
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y + 0.1f);
    glVertex2f(x - 0.1f, y + 0.1f);
    glEnd();

    glFlush();  // Ensure all OpenGL commands are executed
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set 2D orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Single buffering, RGB color
    glutInitWindowSize(500, 500);                 // Set window size
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("Keyboard and Mouse Input Example using GLUT");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutKeyboardFunc(keyboard);  // Set keyboard callback function
    glutMouseFunc(mouse);       // Set mouse callback function
    glutMainLoop();       // Enter the GLUT main loop

    return 0;
}
