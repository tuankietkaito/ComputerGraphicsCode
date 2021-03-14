#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void display() {
	GLfloat vertices[3][2] = { {0.0,0.0},{25.0,50.0},{50.0,0.0} }; /* A triangle */
	int j, k;
	srand(time(NULL));				/* standard random number generator */
	GLfloat p[2] = { 7.5,5.0 };		/* An arbitrary initial point inside traingle */
	glClear(GL_COLOR_BUFFER_BIT);	/*clear the window */
	glBegin(GL_POINTS);
	for (k = 0; k < 500000; k++) {
		j = rand() % 3;				/* pick a vertex at random */
		p[0] = (p[0] + vertices[j][0]) / 2.0;
		p[1] = (p[1] + vertices[j][1]) / 2.0;
		glVertex2fv(p);
	}
	glEnd();
	glFlush();						/* clear buffers */
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);	/* white background */
	glColor3f(1.0, 0.0, 0.0);			/* draw in red */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}