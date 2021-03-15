#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 480, 0, 640);
}

void display() {
	GLfloat midX = 240;
	GLfloat midY = 320;

	GLfloat y = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glColor3f(1.0, 0.0, 0.0);	// Point color Red
	glPointSize(5);				// Point size 5

	glBegin(GL_POINTS);
		for (GLfloat x = -200; x <= 200; x += 0.05) {
			y = x * x;
			glVertex2f(midX + x, midY + y);
		}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Quadratic Formula");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}