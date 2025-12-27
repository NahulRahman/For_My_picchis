#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

#define WIDTH 500
#define HEIGHT 500
#define CELL_SIZE 20

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

/// Function declarations
void drawNine(int x, int y);
void drawThree(int x, int y);
void drawFood();
void drawSnake();
void generateFood();
void display();
void updateSnake();
void timer(int);
void keyboard(int key, int, int);

vector<Point> snake = {Point(5, 5), Point(4, 5)};
Point food(10, 10);
char foodShape = '9';
char direction = 'R';
bool gameOver = false;
int score = 0;

void drawNine(int x, int y) {
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(x + 0.2, y + 0.3);
    const char *digit = "9";
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, digit[0]);
}

void drawThree(int x, int y) {
    glColor3f(1.0, 0.5, 0.0);
    glRasterPos2f(x + 0.2, y + 0.3);
    const char *digit = "3";
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, digit[0]);
}

void drawFood() {
    glColor3f(1.0, 0.0, 0.0);
    if (foodShape == '9') {
        drawNine(food.x, food.y);
    } else {
        drawThree(food.x, food.y);
    }
}

void drawSnake() {
    for (size_t i = 0; i < snake.size(); ++i) {
        if (i % 2 == 0) {
            drawNine(snake[i].x, snake[i].y);
        } else {
            drawThree(snake[i].x, snake[i].y);
        }
    }
}

void drawScore() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(1, HEIGHT / CELL_SIZE - 2);
    string scoreText = "Score: " + to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawGameOverScreen() {
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(WIDTH / 2.0 / CELL_SIZE - 3, HEIGHT / 2.0 / CELL_SIZE);
    const char *msg = "Game Over";
    for (int i = 0; msg[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WIDTH / 2.0 / CELL_SIZE - 4, HEIGHT / 2.0 / CELL_SIZE - 2);
    string finalScore = "Final Score: " + to_string(score);
    for (char c : finalScore) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void generateFood() {
    food.x = rand() % (WIDTH / CELL_SIZE);
    food.y = rand() % (HEIGHT / CELL_SIZE);
    foodShape = (foodShape == '9') ? '3' : '9';
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver) {
        drawGameOverScreen();
    } else {
        drawFood();
        drawSnake();
        drawScore();
    }

    glutSwapBuffers();
}

void updateSnake() {
    if (gameOver) return;

    Point head = snake[0];
    switch (direction) {
        case 'U': head.y++; break;
        case 'D': head.y--; break;
        case 'L': head.x--; break;
        case 'R': head.x++; break;
    }

    /// Check boundaries
    if (head.x < 0 || head.y < 0 || head.x >= WIDTH / CELL_SIZE || head.y >= HEIGHT / CELL_SIZE) {
        gameOver = true;
        return;
    }

    /// Check self-collision
    for (const auto &segment : snake) {
        if (head.x == segment.x && head.y == segment.y) {
            gameOver = true;
            return;
        }
    }

    snake.insert(snake.begin(), head);

    /// Check if the snake eats the food
    if (head.x == food.x && head.y == food.y) {
        score += 1;
        generateFood();
    } else {
        snake.pop_back();
    }
}

void timer(int value) {
    updateSnake();
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void keyboard(int key, int, int) {
    switch (key) {
        case GLUT_KEY_UP: if (direction != 'D') direction = 'U'; break;
        case GLUT_KEY_DOWN: if (direction != 'U') direction = 'D'; break;
        case GLUT_KEY_LEFT: if (direction != 'R') direction = 'L'; break;
        case GLUT_KEY_RIGHT: if (direction != 'L') direction = 'R'; break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Snake Game-202114093");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH / CELL_SIZE, 0, HEIGHT / CELL_SIZE);
    srand(time(0));

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    timer(0);

    glutMainLoop();
    return 0;
}
