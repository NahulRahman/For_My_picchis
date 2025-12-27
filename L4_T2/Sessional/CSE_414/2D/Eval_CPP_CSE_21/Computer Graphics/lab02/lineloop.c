#include <GL/glut.h>  // Include the GLUT header

// Function to display the line loop
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    glColor3f(0.0, 1.0, 0.0);  // Set the line color (Green)
    glLineWidth(2.0);          // Set the line width (in pixels)

    glBegin(GL_LINE_LOOP);     // Begin drawing a line loop
        glVertex2f(-0.5, -0.5);  // Point 1
        glVertex2f(0.5, -0.5);   // Point 2
        glVertex2f(0.5, 0.5);    // Point 3
        glVertex2f(-0.5, 0.5);   // Point 4
    glEnd();  // End of line loop

    glFlush();  // Force execution of OpenGL commands
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set the background color (Black)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set the 2D orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Single buffering and RGB color mode
    glutInitWindowSize(500, 500);                 // Set window size
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("Draw Line Loop using GLUT");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutMainLoop();       // Enter the GLUT event processing loop

    return 0;
}
