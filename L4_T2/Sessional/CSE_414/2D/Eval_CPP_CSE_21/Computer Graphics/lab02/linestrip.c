#include <GL/glut.h>  // Include the GLUT header

// Function to display the line strip
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    glColor3f(1.0, 0.0, 0.0);  // Set the line color (Red)
    glLineWidth(2.0);          // Set the line width (in pixels)

    glBegin(GL_LINE_STRIP);    // Begin drawing a line strip
        glVertex2f(-0.8, -0.5);  // Point 1
        glVertex2f(-0.4, 0.5);   // Point 2
        glVertex2f(0.0, -0.5);   // Point 3
        glVertex2f(0.4, 0.5);    // Point 4
        glVertex2f(0.8, -0.5);   // Point 5
    glEnd();

    glFlush();  // Force execution of OpenGL commands
}

// Initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set the background color (Black)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set the coordinate system for 2D
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Use single buffering and RGB color
    glutInitWindowSize(500, 500);                 // Set window size
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("Draw Line Strip using GLUT");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();       // Enter the GLUT event processing loop

    return 0;
}
