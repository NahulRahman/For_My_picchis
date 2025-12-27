#include <GL/glut.h>  // GLUT header for OpenGL
#include <math.h>     // For sin() and cos()

#define PI 3.14159265358979323846  // Define the value of Pi

// Function to draw a set of triangles
void drawTriangles() {
    glBegin(GL_TRIANGLES);

    // First Triangle
    glColor3f(1.0, 0.0, 0.0);  // Red color
    glVertex2f(-0.6, -0.6);     // First vertex
    glVertex2f(0.0, 0.6);       // Second vertex
    glVertex2f(0.6, -0.6);      // Third vertex

    // Second Triangle
    glColor3f(0.0, 1.0, 0.0);  // Green color
    glVertex2f(-0.3, -0.3);     // First vertex
    glVertex2f(0.3, -0.3);      // Second vertex
    glVertex2f(0.0, 0.3);       // Third vertex

    // Third Triangle
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glVertex2f(-0.7, 0.7);      // First vertex
    glVertex2f(-0.2, 0.7);      // Second vertex
    glVertex2f(-0.5, 1.0);      // Third vertex

    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    drawTriangles();  // Draw triangles

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
    glutCreateWindow("GL_TRIANGLES Example using GLUT");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutMainLoop();       // Enter the GLUT main loop

    return 0;
}
