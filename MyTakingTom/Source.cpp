#include <iostream>
using namespace std;
#include "glut.h"
#include "Library/loadpng.h"
#include "Library/process_image.h"
#include "Library/gl_texture.h"

#include <vector>

#define scale 3
#define width 400
#define height 500

#define  INTERVAL  15

Rect rect_cat = { 50, 350,0, 400 }, rect_Ground = { 0,400,0.0f,250 }, rct_tham = { 50,350,10,240 };
Rect rct_bon = { -100.0f,200,50,350 }, rct_background = { 0,400,0,500 }, rct_tuthuoc = { 30,250,200,500 };
Image Ima_cat, Ima_ground, Ima_tham, Ima_bon, Ima_background, img_thuoc;


void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	/*Map_Texture(&Ima_background);
	Draw_Rect(&rct_background);*/

	Map_Texture(&Ima_ground);
	Draw_Rect(&rect_Ground);

	Map_Texture(&img_thuoc);
	Draw_Rect(&rct_tuthuoc);

	Map_Texture(&Ima_tham);
	Draw_Rect(&rct_tham);

	Map_Texture(&Ima_bon);
	Draw_Rect(&rct_bon);

	Map_Texture(&Ima_cat);
	Draw_Rect(&rect_cat);
	

	glutSwapBuffers();

	
}

void Init_Game()
{
	Load_Texture_Swap(&Ima_ground, "TOM_IMA/sand-01.png");
	Zoom_Image(&Ima_ground, scale);

	Load_Texture_Swap(&Ima_cat, "TOM_IMA/cat-01.png");
	Zoom_Image(&Ima_cat, scale);

	Load_Texture_Swap(&Ima_tham, "TOM_IMA/tham-01.png");
	Zoom_Image(&Ima_tham, scale);

	Load_Texture_Swap(&Ima_bon, "TOM_IMA/poor-01.png");
	Zoom_Image(&Ima_bon, scale);
	
	Load_Texture_Swap(&Ima_background, "TOM_IMA/background.png");
	Zoom_Image(&Ima_background, scale);

	Load_Texture_Swap(&img_thuoc, "TOM_IMA/tuthuoc-01.png");
	Zoom_Image(&img_thuoc, scale);
}

void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glutSwapBuffers();
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); /*hỗ trợ hình ảnh trong suốt*/
	glEnable(GL_LINE_SMOOTH);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glutIgnoreKeyRepeat(GL_TRUE);
	glEnable(GL_TEXTURE_2D);

	Init_Game();
}


void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(INTERVAL, Timer, 0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0,0);
	glutCreateWindow("My Taking Tom 2");

	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, Timer, 0);

	glutMainLoop();
	return 0;
}
