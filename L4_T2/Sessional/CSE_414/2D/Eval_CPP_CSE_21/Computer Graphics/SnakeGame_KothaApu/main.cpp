#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>

// Global variables
const int windowWidth = 600, windowHeight = 600;
const int shapeSize = 20;
int currentShape = 7; // Starting with the second digit of the roll number
std::vector<std::pair<int, int>> snake = {{300, 300}, {280, 300}}; // Initial snake position
std::pair<int, int> food;
int directionX = shapeSize, directionY = 0; // Initial movement to the right

// Function to generate new food
void generateFood() {
    food.first = (rand() % (windowWidth / shapeSize)) * shapeSize;
    food.second = (rand() % (windowHeight / shapeSize)) * shapeSize;
}

// Function to check collision with the boundary or itself
bool checkCollision() {
    // Check boundary collision
    if (snake[0].first < 0 || snake[0].second < 0 ||
        snake[0].first >= windowWidth || snake[0].second >= windowHeight) {
        return true;
    }
    // Check self-collision
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[0] == snake[i]) {
            return true;
        }
    }
    return false;
}

// Function to draw a single shape (1 or 7)
void drawShape(int x, int y, int shape) {
    if (shape == 1) {
        // Draw digit '1'
        glBegin(GL_QUADS);
        glVertex2f(x + shapeSize / 3, y);
        glVertex2f(x + 2 * shapeSize / 3, y);
        glVertex2f(x + 2 * shapeSize / 3, y + shapeSize);
        glVertex2f(x + shapeSize / 3, y + shapeSize);
        glEnd();
    } else if (shape == 7) {
        // Draw digit '7'
        glBegin(GL_QUADS);
        glVertex2f(x, y + 3 * shapeSize / 4);
        glVertex2f(x + shapeSize, y + 3 * shapeSize / 4);
        glVertex2f(x + shapeSize, y + shapeSize);
        glVertex2f(x, y + shapeSize);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(x + 2 * shapeSize / 3, y);
        glVertex2f(x + shapeSize, y);
        glVertex2f(x + shapeSize, y + 3 * shapeSize / 4);
        glVertex2f(x + 2 * shapeSize / 3, y + 3 * shapeSize / 4);
        glEnd();
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the food
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawShape(food.first, food.second, currentShape);

    // Draw the snake
    glColor3f(0.0, 1.0, 0.0); // Green color
    for (size_t i = 0; i < snake.size(); i++) {
        drawShape(snake[i].first, snake[i].second, (i % 2 == 0) ? 1 : 7);
    }

    glutSwapBuffers();
}

// Timer function for animation
void timer(int) {
    // Move the snake
    for (size_t i = snake.size() - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0].first += directionX;
    snake[0].second += directionY;

    // Check collision with food
    if (snake[0] == food) {
        snake.push_back(snake.back()); // Add new segment to the tail
        currentShape = (currentShape == 1) ? 7 : 1; // Alternate shapes
        generateFood();
    }

    // Check collision with boundary or itself
    if (checkCollision()) {
        exit(0); // End the game
    }

    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

// Keyboard input for controlling the snake
void keyboard(int key, int, int) {
    switch (key) {
        case GLUT_KEY_UP:
            if (directionY == 0) {
                directionX = 0;
                directionY = shapeSize;
            }
            break;
        case GLUT_KEY_DOWN:
            if (directionY == 0) {
                directionX = 0;
                directionY = -shapeSize;
            }
            break;
        case GLUT_KEY_LEFT:
            if (directionX == 0) {
                directionX = -shapeSize;
                directionY = 0;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (directionX == 0) {
                directionX = shapeSize;
                directionY = 0;
            }
            break;
    }
}

// Main function
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    generateFood();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Snake Game");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
