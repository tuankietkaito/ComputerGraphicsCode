#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0, 1, 0);

	/*
	x = r * sin(theta) * cos(phi);
	z = r * cos(theta) * cos(phi);
	y = r * sin(phi);
	*/

	float c = PI / 180;
	float phir, phir20, theta, thetar;
	float x, y, z;
	float angle = 5;
	for (float phi = -90 + angle; phi <= 90 - angle; phi += angle) {
		phir = c * phi;
		phir20 = c * (phi + angle);
		glBegin(GL_QUAD_STRIP);		// Can be used for GL_TRIANGLE_STRIP
			for (float theta = -180; theta <= 180; theta += angle) {
				thetar = c * theta;

				x = sin(thetar) * cos(phir);
				z = cos(thetar) * cos(phir);
				y = sin(phir);
				glVertex3d(x, y, z);

				x = sin(thetar) * cos(phir20);
				z = cos(thetar) * cos(phir20);
				y = sin(phir20);
				glVertex3d(x, y, z);
			}
		glEnd();
	}

	float c80;
	glVertex3d(0, 1, 0);
	c80 = c * (90 - angle);
	y = sin(c80);
	glBegin(GL_TRIANGLE_FAN);
		for (float theta = 180; theta >= -180; theta -= angle) {
			thetar = c * theta;
			x = sin(thetar) * cos(c80);
			z = cos(thetar) * cos(c80);
			glVertex3d(x, y, z);
		}
	glEnd();

	glVertex3d(0, -1, 0);
	c80 = c * (90 - angle);
	y = -sin(c80);
	glBegin(GL_TRIANGLE_FAN);
		for (float theta = -180; theta >= 180; theta += angle) {
			thetar = c * theta;
			x = sin(thetar) * cos(c80);
			z = cos(thetar) * cos(c80);
			glVertex3d(x, y, z);
		}
	glEnd();

	glFlush();
}
void init() {
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);

	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.2, 1.2, -1.2, 1.2, -10, 10);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sphere");

	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}