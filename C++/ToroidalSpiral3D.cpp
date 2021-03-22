#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#define PI 3.1415926

int Width = 500;
int Height = 500;

float angle = 0;

void drawText(float xPos, float yPos, float zPos, const char* str) {
    glRasterPos3f(xPos, yPos, zPos);

    void* font = GLUT_BITMAP_9_BY_15;
    for (int i = 0; i < strlen(str); i++) {
        glutBitmapCharacter(font, str[i]);
    }
}

void drawAxis() {
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(2, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 2, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 2);
    glEnd();

    drawText(1.9, 0, 0, "X");
    drawText(0, 1.7, 0, "Y");
    drawText(0, 0, 1.9, "Z");
}

void drawToroidalSpiral(float a, float b, float c) {

    glBegin(GL_LINE_STRIP);
    for (double t = 0; t <= 70; t += 0.01)
        glVertex3f(
            (a * sin(c * t) + b) * cos(t), 
            (a * sin(c * t) + b) * sin(t),
            a * cos(c * t)
        );
    glEnd();

    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1, 1, 1, 0, 0, 0, 0.0, 1.0, 0.0);

    glRotatef(angle, 0, 1, 0);
    drawAxis();
    //    elip
    //    x(t) = R*cos(t)
    //    y(t) = R*sin(t)
    //    z(t) = bt

    drawToroidalSpiral(0.4, 1.2, 10);

    glFlush();
}
void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    float factor = 2;
    glMatrixMode(GL_PROJECTION); /* switch matrix mode */ glLoadIdentity();
    if (w <= h)
        glOrtho(-factor, factor, -factor * h / w, factor * h / w, -10, 10);
    else
        glOrtho(-factor * w / h, factor * w / h, -factor, factor, -10.0, 10.0);

}

void mySpecialFunc(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT)
        angle = angle + 5;
    else if (key == GLUT_KEY_RIGHT)
        angle = angle - 5;
    glutPostRedisplay();
}

void init()
{

    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    glColor3f(0.0, 0.0, 0.0); /* draw in red */

    glFrontFace(GL_CW);
    glEnable(GL_CULL_FACE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // bo dem doi
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(80, 80);

    glutCreateWindow("Toroidal Spiral");
    init();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutSpecialFunc(mySpecialFunc);

    glutMainLoop();
    return 0;
}