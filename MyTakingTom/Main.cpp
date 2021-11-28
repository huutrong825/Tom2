//#include <iostream>
//using namespace std;
//#include "glut.h"
//#include "Library/loadpng.h"
//#include "Library/process_image.h"
//#include "Library/gl_texture.h"
//
//#include <vector>
//
//#define scale 3
//#define width 720
//#define height 384
//#define CELL_SIZE 24
//#define  INTERVAL  15
//#define platforme_count 6
//#define cloud_count 3
//#define max_x 30
//#define max_y 24
//
//Rect rect_background = { 0, 720, 48, 384 }, rect_Ground = {0,720,0,48 };
//
//Image Ima_background, Ima_ground;
//
//int Map[max_y][max_x];
//
//class c_Platfomer
//{
//public:
//	static Image Ima_Save;
//	static void Load_Img() {
//		Load_Texture_Swap(&Ima_Save, "Image/Platformer.png");
//		Zoom_Image(&Ima_Save, scale);
//	}
//	Rect rct;
//	Image *img;
//	void Init(int x, int y) {
//		Map[y][x] = Map[y][x + 1] = Map[y][x + 2] = Map[y][x + 3] = 1;
//		img = &Ima_Save;
//		float x1 = (x + 2)*CELL_SIZE;
//		float y1 = y * CELL_SIZE;
//		rct.Left = x1 - img->w;
//		rct.Right = rct.Left + img->w;
//		rct.Bottom = y1;
//		rct.Top = rct.Bottom + img->h;
//	}
//	void draw() {
//		Map_Texture(img);
//		Draw_Rect(&rct);
//	}
//};
//
//Image c_Platfomer::Ima_Save;
//
//c_Platfomer Platformer[platforme_count];
//
//class c_Cloud
//{
//public:
//	static Image Ima_Save;
//	static void Load_Img() {
//		Load_Texture_Swap(&Ima_Save, "Image/Cloud.png");
//		Zoom_Image(&Ima_Save, scale);
//	}
//	Rect rct;
//	Image *img;
//	float x, y;
//
//	void Init(float x1, float y1) {
//		img = &Ima_Save;
//		x = x1;
//		y = y1;
//		Update_Rect();
//		rct.Bottom = y;
//		rct.Top = rct.Bottom + img->h;
//	}
//	void draw() {
//		Map_Texture(img);
//		Draw_Rect(&rct);
//	}
//	void Update_Rect()
//	{
//		rct.Left = x - img->w / 2;
//		rct.Right = rct.Left + img->w;
//	}
//	void update() {
//		x -= 0.3f;
//		if (x < -120.0f)
//			x += 1080.0f;
//		Update_Rect();
//	}
//};
//
//Image c_Cloud::Ima_Save;
//
//c_Cloud Clouds[cloud_count];
//
//class c_Frog
//{
//public:
//	static Image Ima_Save[2][2][2];
//	static float Map_Offset[2];
//	static float Map_Base_Angle[2];
//
//	Rect rct;
//	Image *img;
//
//	float x, y, vx, vy;
//	int Player;
//	
//};
//
//void display()
//{
//	
//	glClear(GL_COLOR_BUFFER_BIT); 
//	glLoadIdentity();
//	
//	
//	Map_Texture(&Ima_background);
//	Draw_Rect(&rect_background);
//	Map_Texture(&Ima_ground);
//	Draw_Rect(&rect_Ground);
//
//	for (int i = 0; i < 3; i++)
//		Clouds[i].draw();
//
//	for (int i = 0; i < platforme_count; i++)
//		Platformer[i].draw();
//
//	glutSwapBuffers();
//}
//
//void Init_Game()
//{
//	Load_Texture_Swap(&Ima_background, "Image/Background.png");
//	Zoom_Image(&Ima_background, scale);
//	Load_Texture_Swap(&Ima_ground, "Image/Ground.png");
//	Zoom_Image(&Ima_ground, scale);
//
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < max_x; j++)
//			Map[i][j] = 1;
//	for (int i = 2; i < max_y; i++)
//		for (int j = 0; j < max_x; j++)
//			Map[i][j] = 0;
//
//	c_Platfomer::Load_Img();
//	c_Cloud::Load_Img();
//	
//	Platformer[0].Init(7, 5);
//	Platformer[1].Init(19, 5);
//	Platformer[2].Init(4, 9);
//	Platformer[3].Init(22, 9);
//	Platformer[4].Init(9, 13);
//	Platformer[5].Init(17, 13);
//
//	
//	Clouds[0].Init(570.0f, 210.0f);
//	Clouds[1].Init(930.0f, 300.0f);
//	Clouds[2].Init(240.0f, 255.0f);
//
//}
//
//void init(void)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, width, 0, height);
//	glutSwapBuffers();
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_BLEND); 
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); /*hỗ trợ hình ảnh trong suốt*/
//	glEnable(GL_LINE_SMOOTH);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glutIgnoreKeyRepeat(GL_TRUE);
//	glEnable(GL_TEXTURE_2D);
//
//	Init_Game();
//}
//
//
//void Timer(int value)
//{
//	for (int i = 0; i < cloud_count; i++)
//		Clouds[i].update();
//	glutPostRedisplay();
//	glutTimerFunc(INTERVAL, Timer, 0);
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	int pos_x = (glutGet(GLUT_SCREEN_WIDTH) >> 1);
//	int pos_y = (glutGet(GLUT_SCREEN_HEIGHT) >> 1);
//	glutInitWindowSize(width, height);
//	glutInitWindowPosition(pos_x, pos_y);
//	glutCreateWindow("My Taking Tom 2");
//
//	init();
//	glutDisplayFunc(display);	
//	glutTimerFunc(0, Timer, 0);
//
//	glutMainLoop();
//	return 0;
//}
