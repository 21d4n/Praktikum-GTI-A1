#include <GL/glut.h>
#include <stdlib.h>

static int shoulder=0, elbow=0;
static int finger[5]={0,0,0,0,0};

void drawPhalanx(float length,float thickness){
    glPushMatrix();
    glTranslatef(length*0.5f,0.0f,0.0f);
    glScalef(length,thickness,thickness);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawFinger(float yOffset,int angle){
    glPushMatrix();
    glTranslatef(0.6f,yOffset,0.0f);
    glRotatef(angle,0.0,-1.0,0.0);
    drawPhalanx(0.45f,0.12f);
    glTranslatef(0.45f,0.0f,0.0f);
    glRotatef(angle*0.7f,0.0,-1.0,0.0);
    drawPhalanx(0.32f,0.10f);
    glTranslatef(0.32f,0.0f,0.0f);
    glRotatef(angle*0.5f,0.0,-1.0,0.0);
    drawPhalanx(0.24f,0.09f);
    glPopMatrix();
}

void drawThumb(int angle){
    glPushMatrix();
    glTranslatef(0.45f,0.45f,0.0f);
    glRotatef(60.0f,0.0,0.0,1.0);
    glRotatef(angle,0.0,-1.0,0.0);
    drawPhalanx(0.38f,0.13f);
    glTranslatef(0.38f,0.0f,0.0f);
    glRotatef(angle*0.7f,0.0,-1.0,0.0);
    drawPhalanx(0.28f,0.11f);
    glPopMatrix();
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-1.0,0.0,0.0);
    glRotatef((GLfloat)shoulder,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);
    glPushMatrix();
    glScalef(2.0,0.4,1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)elbow,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);
    glPushMatrix();
    glScalef(2.0,0.4,1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.25f,0.0f,0.0f);
    glScalef(0.55f,0.85f,0.5f);
    glutWireCube(1.0);
    glPopMatrix();
    drawThumb(finger[0]);
    drawFinger(0.25f,finger[1]);
    drawFinger(0.05f,finger[2]);
    drawFinger(-0.15f,finger[3]);
    drawFinger(-0.35f,finger[4]);
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
}

void keyboard(unsigned char key,int x,int y){
    switch(key){
        // bahu
        case 's':
            shoulder=(shoulder+5)%360;
            break;
        case 'S':
            shoulder=(shoulder-5)%360;
            break;
        // siku
        case 'e':
            elbow=(elbow+5)%360;
            break;
        case 'E':
            elbow=(elbow-5)%360;
            break;
        // jempol
        case '1':
            if(finger[0]<90) finger[0]+=5;
            break;
        // telunjuk
        case '2':
            if(finger[1]<90) finger[1]+=5;
            break;
        // tengah
        case '3':
            if(finger[2]<90) finger[2]+=5;
            break;
        // manis
        case '4':
            if(finger[3]<90) finger[3]+=5;
            break;
        // kelingking
        case '5':
            if(finger[4]<90) finger[4]+=5;
            break;
        // reset jari
        case 'r':
            finger[0]=0;
            finger[1]=0;
            finger[2]=0;
            finger[3]=0;
            finger[4]=0;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("24060124130099 - Kode Lengan Modifikasi");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
