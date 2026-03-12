#include <GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);
    glVertex2f(-0.8,0.8);
    glVertex2f(-0.6,0.9);
    glVertex2f(-0.4,0.8);
    glEnd();

    // GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    glVertex2f(0.2,0.8);
    glVertex2f(0.4,0.9);
    glVertex2f(0.6,0.8);
    glVertex2f(0.4,0.7);
    glEnd();

    // GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,1);
    glVertex2f(-0.7,0.2);
    glVertex2f(-0.8,0.0);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.5,0.2);
    glVertex2f(-0.6,0.4);
    glEnd();

    // GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1,1,0);
    glVertex2f(-0.3,0.0);
    glVertex2f(-0.2,0.3);
    glVertex2f(-0.1,0.0);
    glVertex2f(0.0,0.3);
    glEnd();

    // GL_QUADS
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex2f(0.1,0.0);
    glVertex2f(0.3,0.0);
    glVertex2f(0.3,0.2);
    glVertex2f(0.1,0.2);
    glEnd();

    // GL_QUAD STRIP
    glBegin(GL_QUAD_STRIP);
    glColor3f(0,1,1);
    glVertex2f(0.5,0.0);
    glVertex2f(0.5,0.2);
    glVertex2f(0.7,0.0);
    glVertex2f(0.7,0.2);
    glVertex2f(0.9,0.0);
    glVertex2f(0.9,0.2);
    glEnd();

    // 5 KUBUS
    glColor3f(0.2,0.5,1);

    // bawah
    glRectf(-0.25,-0.7,-0.05,-0.5);
    glRectf(0.00,-0.7,0.20,-0.5);
    glRectf(0.25,-0.7,0.45,-0.5);

    // atas
    glRectf(-0.13,-0.48,0.07,-0.28);
    glRectf(0.13,-0.48,0.33,-0.28);

    glFlush();
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Pertemuan 1 Dehar Zaidan Dzaki Amirullah (24060124130099)");

    glutDisplayFunc(display);
    glClearColor(1,1,1,1);

    glutMainLoop();
}
