#include <GL/glut.h>  // GLUT header for OpenGL
#include <math.h>     // For sin() and cos()

#define PI 3.14159265358979323846  // Define the value of Pi

// Function to draw a circle
void drawCircle(float centerX, float centerY, float radius, int numSegments) {
    glBegin(GL_LINE_LOOP);  // Draw a line loop to form a circle
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;  // Calculate angle for each point
        float x = radius * cos(angle) + centerX;    // X-coordinate
        float y = radius * sin(angle) + centerY;    // Y-coordinate
        glVertex2f(x, y);  // Plot the vertex
    }
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    glColor3f(0.0, 1.0, 0.0);  // Set circle color to green
    glLineWidth(2.0);          // Set line width for the circle

    // Draw circles with different radii and positions
    drawCircle(0.0, 0.0, 0.5, 100);   // Circle at the center with radius 0.5
    drawCircle(0.5, 0.5, 0.3, 50);    // Smaller circle at (0.5, 0.5)
    drawCircle(-0.5, -0.5, 0.2, 30);  // Another small circle at (-0.5, -0.5)

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
    glutCreateWindow("Circle Demo using GLUT");   // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutMainLoop();       // Enter the GLUT main loop

    return 0;
}
