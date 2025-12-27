#include <GL/glut.h>  // GLUT header for OpenGL

// Display function to draw Quad Strip and Separate Quads
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // 1. Draw a Quad Strip
    glColor3f(1.0, 0.0, 0.0);  // Set color to Red
    glBegin(GL_QUAD_STRIP);    // Begin drawing a Quad Strip
        glVertex2f(-0.8, 0.2);  // Quad Strip Vertex 1
        glVertex2f(-0.8, -0.2); // Quad Strip Vertex 2
        glVertex2f(-0.5, 0.2);  // Quad Strip Vertex 3
        glVertex2f(-0.5, -0.2); // Quad Strip Vertex 4
        glVertex2f(-0.2, 0.4);  // Quad Strip Vertex 5
        glVertex2f(-0.2, -0.4); // Quad Strip Vertex 6
    glEnd();

    // 2. Draw Separate Quads
    glColor3f(0.0, 1.0, 0.0);  // Set color to Green
    glBegin(GL_QUADS);         // Begin drawing separate Quads

        // First Quad
        glVertex2f(0.2, -0.2);
        glVertex2f(0.4, -0.2);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.2, 0.2);

        // Second Quad
        glVertex2f(0.5, -0.4);
        glVertex2f(0.7, -0.4);
        glVertex2f(0.7, -0.1);
        glVertex2f(0.5, -0.1);
    glEnd();

    glFlush();  // Execute all OpenGL commands
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set 2D orthographic projection
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Use single buffering and RGB color mode
    glutInitWindowSize(500, 500);                 // Set window size
    glutInitWindowPosition(100, 100);             // Set window position
    glutCreateWindow("Quad Strip and Separate Quad Demo");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set the display callback function
    glutMainLoop();       // Enter the GLUT event processing loop

    return 0;
}
