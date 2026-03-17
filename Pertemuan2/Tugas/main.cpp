#include <GL/glut.h>
#include <math.h>

void drawCircle(float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.1416f / 180;
        glVertex2f(radius * cos(theta), radius * sin(theta));
    }
    glEnd();
}

void Roda() {
    glPushMatrix();

    glColor3f(0, 0, 0);
    drawCircle(0.1);

    glPopMatrix();
}

void Mobil() {
    glPushMatrix();

    glTranslatef(0.2f, -0.30f, 0.0f);
    glRotatef(20.0f, 0, 0, 1);

    // Body
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.15);
        glVertex2f(0.5, -0.15);
        glVertex2f(0.5, 0.1);
        glVertex2f(-0.5, 0.1);
    glEnd();

    // Atap
    glColor3f(0.8, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2, 0.1);
        glVertex2f(0.2, 0.1);
        glVertex2f(0.1, 0.25);
        glVertex2f(-0.1, 0.25);
    glEnd();

    // Roda kiri
    glPushMatrix();
        glTranslatef(-0.3, -0.18, 0);
        Roda();
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
        glTranslatef(0.3, -0.18, 0);
        Roda();
    glPopMatrix();

    glPopMatrix();
}

void Jalan() {
    glPushMatrix();

    glTranslatef(0.2f, -0.2f, 0.0f);
    glRotatef(20.0f, 0, 0, 1);
    
    glColor3f(0.6, 0.3, 0.1);

    glBegin(GL_POLYGON);
        glVertex2f(-5, -0.3);
        glVertex2f(5, -0.3);
        glVertex2f(5, -1.2);
        glVertex2f(-5, -1.2);
    glEnd();

    glPopMatrix();
}

void Matahari() {
    glPushMatrix();
    glTranslatef(0.7, 0.7, 0);

    glColor3f(1, 1, 0);
    drawCircle(0.15);

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Matahari();
    Jalan();
    Mobil();

    glFlush();
}

void init() {
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil pajero punyanya 24060124130099");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
