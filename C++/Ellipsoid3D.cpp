#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define Pi 3.14159265359

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC) { 
	float tStep = (Pi) / (float)uiSlices;	
	float sStep = (Pi) / (float)uiStacks;	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	for (float t = -Pi / 2; t <= (Pi / 2) + .0001; t += tStep) { 
		glBegin(GL_TRIANGLE_STRIP);		
			for (float s = -Pi; s <= Pi + .0001; s += sStep) { 
				glVertex3f(
					fA * cos(t) * cos(s), 
					fB * cos(t) * sin(s), 
					fC * sin(t)
				);			
				glVertex3f(
					fA * cos(t + tStep) * cos(s), 
					fB * cos(t + tStep) * sin(s), 
					fC * sin(t + tStep)
				); 
			}		
		glEnd(); 
	} 
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3, -3, 3, 0, 0, 0, 0, 1, 0);

	DrawEllipsoid(50, 50, 5.0, 4.0, 6.0);

	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-12, 12, -12, 12, -10, 10);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ellipsoid");

	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}