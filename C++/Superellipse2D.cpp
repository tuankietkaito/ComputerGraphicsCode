#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
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

void DrawEllipse(unsigned int stacks, float W, float H, float k) {
	float sStep = 1 * Pi / 180;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (float n = 0; n <= 4; n += 0.6) {
		glBegin(GL_LINE_LOOP);
		for (float t = 0; t <= 2 * Pi + .0001; t += sStep) {
			glVertex2f(
				W * cos(t) * abs(powf(abs(cos(t)), 2 / n - 1)),
				H * sin(t) * abs(powf(abs(sin(t)), 2 / n - 1))
			);
		}
		glEnd();
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3, -3, 3, 0, 0, 0, 0, 1, 0);*/

	// DrawEllipsoid(50, 50, 5.0, 4.0, 6.0);

	DrawEllipse(150, 6, 6, 3);

	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Superellipse");

	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
//
//#define GL_SILENCE_DEPRECATION
//#include <stdio.h>
//#include <math.h>
//
//#include <GLUT/glut.h>
//#define PI 3.1415926
//
//
//void display() {
//
//	float x, y;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
//
//
//
//	for (float n = 0.5; n <= 1.9; n += 0.1) {
//
//		glBegin(GL_LINE_STRIP);
//		for (float angle = 0; angle <= 2 * PI; angle += 2 * PI / 400) {
//			x = cos(angle) * abs(pow(cos(angle), 2 / n - 1));
//			y = sin(angle) * abs(pow(sin(angle), 2 / n - 1));
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//
//
//	glFlush();
//}
//
//void init() {
//
//	glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2, 2, -2, 2, -10, 10);
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutCreateWindow("Elip_1");
//
//	glutDisplayFunc(display);
//
//	init();
//	glutMainLoop();
//	return 0;
//}
