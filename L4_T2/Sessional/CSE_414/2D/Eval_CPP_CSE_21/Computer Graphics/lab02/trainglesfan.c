#include <GL/glut.h>  // GLUT header for OpenGL
#include <math.h>     // For sin() and cos()

#define PI 3.14159265358979323846  // Define the value of Pi

// Function to draw a rocket shape
void drawRocket() {
    glBegin(GL_TRIANGLE_STRIP);  // Begin drawing a triangle strip

    // Rocket body
    glColor3f(1.0, 0.0, 0.0);  // Red color for the rocket body
    glVertex2f(-0.2, -0.4);    // Bottom left vertex
    glVertex2f(0.2, -0.4);     // Bottom right vertex
    glVertex2f(0.0, 0.6);      // Top vertex (head of the rocket)

    // Rocket fins (left)
    glColor3f(0.0, 1.0, 0.0);  // Green color for the fins
    glVertex2f(-0.3, -0.4);    // Bottom left fin vertex
    glVertex2f(-0.4, -0.2);    // Top left fin vertex

    // Rocket fins (right)
    glVertex2f(0.3, -0.4);     // Bottom right fin vertex
    glVertex2f(0.4, -0.2);     // Top right fin vertex

    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    drawRocket();  // Call function to draw the rocket shape

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
    glutCreateWindow("Triangle Strip Rocket Shape");  // Create window with title

    init();               // Initialize OpenGL settings
    glutDisplayFunc(display);  // Set display callback function
    glutMainLoop();       // Enter the GLUT main loop

    return 0;
}
