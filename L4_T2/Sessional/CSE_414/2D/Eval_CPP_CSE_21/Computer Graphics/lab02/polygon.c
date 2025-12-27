#include <GL/glut.h>  // GLUT header for OpenGL

// Function to display the polygon
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    glColor3f(0.0, 0.5, 1.0);  // Set the polygon color (blueish)
    glLineWidth(2.0);          // Set the line width for borders (optional)

    // Draw a filled polygon
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);  // Vertex 1
        glVertex2f(0.5, -0.5);   // Vertex 2
        glVertex2f(0.7, 0.0);    // Vertex 3
        glVertex2f(0.5, 0.5);    // Vertex 4
        glVertex2f(-0.5, 0.5);   // Vertex 5
        glVertex2f(-0.7, 0.0);   // Vertex 6
    glEnd();

    glFlush();  // Force execution of OpenGL commands
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color (black)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set the 2D orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Single buffering and RGB color
    glutInitWindowSize(500, 500);                 // Set window size
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("Polygon Demo using GLUT");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutMainLoop();       // Enter the GLUT event processing loop

    return 0;
}
