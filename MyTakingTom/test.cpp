//#include <iostream>
//using namespace std;
//#include "glut.h"
//
//
//
//void drawCir(float x,float y,float R)
//{
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 360; i++)
//		glVertex3f(R*cos(2 * 3.14 * i / 360) + x, R*sin(2 * 3.14*i / 360) + y, 0.0);
//	glEnd();
//
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, 400, 500, 0);
//}
//
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	
//	
//	drawCir(50,50,25);
//	drawCir(50, 50, 20);
//
//	drawCir(50,450, 25);
//	drawCir(150, 450, 25);
//	drawCir(250, 450, 25);
//	drawCir(350, 450, 25);
//
//	glFlush();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("My Taking Tom 2");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
