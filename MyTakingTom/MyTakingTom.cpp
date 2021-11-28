//#include "global.h"
//#include "graphics.h"
//#pragma comment(lib, "graphics.lib")
//#include <ctime>
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 7, M = 8;
//const int X = 130, Y = 150, W = 65; // xBegin, yBegin, width
//int u_old = 0, v_old = 0;
//int score = 0, cntRes = 0, cntChange = 3, cntLoad = 0;
//int level = 1;
//Global g;
//
//vector< vector<int> > f(N + 2, vector<int>(M + 2, 0));
//
//vector< pair<string, int> > dataP; // Data <usename, score>
//ifstream fi("score.dat");
//ofstream fo("score.dat", ios::app);
//
////draw
//void lineDDA(int x1, int y1, int x2, int y2, int color)
//{
//	int Dx = x2 - x1, Dy = y2 - y1;
//	float x_inc, y_inc;
//	float step = max(abs(Dx), abs(Dy));
//	x_inc = Dx / step;
//	y_inc = Dy / step;
//	float x = x1, y = y1;
//	putpixel(x, y, color);
//
//	int k = 1;
//	while (k <= step) {
//		k++;
//		x += x_inc;
//		y += y_inc;
//		putpixel(Round(x), Round(y), color);
//	}
//}
//void drawRect(int x1, int y1, int x2, int y2, int color) {
//	lineDDA(x1, y1, x2, y1, color);
//	lineDDA(x2, y1, x2, y2, color);
//	lineDDA(x2, y2, x1, y2, color);
//	lineDDA(x1, y2, x1, y1, color);
//}
//void del_bdDw(int u, int v);
//void bdDw(int u, int v) {
//	del_bdDw(u_old, v_old);
//	u_old = u, v_old = v;
//	if (f[u][v] == 0)
//		return;
//	int x, y;
//	int len = W / 4;
//
//	x = X + (v - 1) * (W + 10);
//	y = Y + (u - 1) * (W + 10);
//
//	lineDDA(x - 2, y - 2, x - 2 + len, y - 2, 15);
//	lineDDA(x - 2, y - 2, x - 2, y - 2 + len, 15);
//
//	lineDDA(x + W + 2, y - 2, x + W + 2 - len, y - 2, 15);
//	lineDDA(x + W + 2, y - 2, x + W + 2, y - 2 + len, 15);
//
//	lineDDA(x + W + 2, y + W + 2, x + W + 2 - len, y + W + 2, 15);
//	lineDDA(x + W + 2, y + W + 2, x + W + 2, y + W + 2 - len, 15);
//
//	lineDDA(x - 2, y + W + 2, x - 2, y + W + 2 - len, 15);
//	lineDDA(x - 2, y + W + 2, x - 2 + len, y + W + 2, 15);
//}
//void del_bdDw(int u, int v) {
//	if (f[u][v] == 0)
//		return;
//	int x, y;
//	int len = W / 4;
//
//	x = X + (v - 1) * (W + 10);
//	y = Y + (u - 1) * (W + 10);
//
//	lineDDA(x - 2, y - 2, x - 2 + len, y - 2, 0);
//	lineDDA(x - 2, y - 2, x - 2, y - 2 + len, 0);
//
//	lineDDA(x + W + 2, y - 2, x + W + 2 - len, y - 2, 0);
//	lineDDA(x + W + 2, y - 2, x + W + 2, y - 2 + len, 0);
//
//	lineDDA(x + W + 2, y + W + 2, x + W + 2 - len, y + W + 2, 0);
//	lineDDA(x + W + 2, y + W + 2, x + W + 2, y + W + 2 - len, 0);
//
//	lineDDA(x - 2, y + W + 2, x - 2, y + W + 2 - len, 0);
//	lineDDA(x - 2, y + W + 2, x - 2 + len, y + W + 2, 0);
//}
//void delDw(int u, int v) {
//	int x = X + (v - 1) * (W + 10) + (W / 2);
//	int y = Y + (u - 1) * (W + 10) + (W / 2);
//	setfillstyle(1, 0);
//	int k = W / 2 + 5;
//	bar(x - k, y - k, x + k, y + k);
//}
//void dwBack() {
//	drawRect(10, 10, 100, 60, 15);
//
//	setfillstyle(1, CYAN);
//	floodfill(55, 40, 15);
//	setcolor(15);
//	setbkcolor(CYAN);
//	settextstyle(10, 0, 3);
//	settextjustify(1, 1);
//	outtextxy(55, 40, "Back");
//	setbkcolor(0);
//}
//
//// vector F
//void initF();
//void resetF();
//// layout
//void layoutGame(string user);
//void layoutGame_test(string user);
//void layoutMenu();
//void layoutHighScore();
//void layoutAbout();
//void layoutHelp();
//void layoutEnterUsename();
//void layoutFinish();
//void drawGame() {
//	int xd = X, yd = Y;
//	int d = 10;
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= M; ++j) {
//			if (f[i][j] == 1) {
//				g.drawTrungDay(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 2) {
//				g.drawHuong(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 3) {
//				g.drawRong(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 4) {
//				g.drawBuom(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 5) {
//				g.drawPikachu(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 6) {
//				g.drawNuoc(xd, yd);
//				xd += W + d;
//			}
//			if (f[i][j] == 7) {
//				g.drawXanh(xd, yd);
//				xd += W + d;
//			}
//		}
//		yd += W + d;
//		xd = X;
//	}
//}
//
////solve
//int convertToInt(string s) {
//	int res = 0;
//	s += ' ';
//	int i = 0;
//	while (s[i] != ' ') {
//		res = res * 10 + s[i] - '0';
//		i++;
//	}
//	return res;
//}
//void showScore();
//void readData() {
//	string s;
//	while (!fi.eof()) {
//		getline(fi, s);
//		string userName = s.substr(0, s.find('#'));
//		int score = convertToInt(s.substr(s.find('#') + 1, s.length()));
//		dataP.push_back(make_pair(userName, score));
//	}
//}
//void updateLevel_1(int x1, int y1, int x2, int y2);
//void updateLevel_2(int x1, int y1, int x2, int y2);
//void updateLevel_3(int x1, int y1, int x2, int y2);
//void updateLevel_4(int x1, int y1, int x2, int y2);
//void updateLevel_5(int x1, int y1, int x2, int y2);
//bool check1(int x1, int y1, int x2, int y2) { // x1 = x2 OF y1 = y2
//	if (x1 != x2 && y1 != y2)
//		return false;
//	// check col (y1 = y2)
//	if (y1 == y2) {
//		if (x1 > x2)
//			swap(x1, x2);
//		for (int i = x1 + 1; i <= (x2 - 1); ++i) // 6 9 7 9, i = 7, 7 <= 6
//			if (f[i][y1] != 0)
//				return false;
//	}
//
//	//check row (x1 = x2);
//	if (x1 == x2) {
//		if (y1 > y2)
//			swap(y1, y2);
//		for (int i = y1 + 1; i <= (y2 - 1); ++i)
//			if (f[x1][i] != 0)
//				return false;
//	}
//	return true;
//}
//bool check2(int x1, int y1, int x2, int y2) {
//	if (y1 > y2) {
//		swap(y1, y2);
//		swap(x1, x2);
//	}
//
//	// TH rieng
//	if (x1 + 1 == x2 && y1 + 1 == y2)
//		if (f[x1][y2] != 0 && f[x2][y1] != 0)
//			return false;
//		else;
//	else
//		if (x1 - 1 == x2 && y1 + 1 == y2)
//			if (f[x2][y1] != 0 && f[x1][y2] != 0)
//				return false;
//
//	bool b1 = true;
//	if (x1 < x2)
//		if (check1(x1, y1, x2 + 1, y1) && check1(x2, y1, x2, y2) ||
//			check1(x1, y1, x1, y2 + 1) && check1(x1, y2, x2, y2))
//			return true;
//
//	if (x1 > x2)
//		if (check1(x1, y1, x2 - 1, y1) && check1(x2, y1, x2, y2) ||
//			check1(x1, y1, x1, y2 + 1) && check1(x1, y2, x2, y2))
//			return true;
//	return false;
//}
//bool check3(int x1, int y1, int x2, int y2) {
//	if (y1 > y2) {
//		swap(y1, y2);
//		swap(x1, x2);
//	}
//	// Tren
//	for (int i = x1 - 1; i >= 0; i--) {
//		if (f[i][y1] != 0)
//			break;
//		if (check2(i, y1, x2, y2))
//			return true;
//	}
//	// Phai
//	for (int i = y1 + 1; i <= M + 1; ++i) {
//		if (f[x1][i] != 0)
//			break;
//		if (check2(x1, i, x2, y2))
//			return true;
//	}
//	// Duoi
//	for (int i = x1 + 1; i <= N + 1; ++i) {
//		if (f[i][y1] != 0)
//			break;
//		if (check2(i, y1, x2, y2)) // 6 5 6 8 -> check2(7 5 -> 6 8);
//			return true;
//	}
//	// Trai
//	for (int i = y1 - 1; i >= 0; i--) {
//		if (f[x1][i] != 0)
//			break;
//		if (check2(x1, i, x2, y2))
//			return true;
//	}
//	return false;
//}
//void checkPoint(int x1, int y1, int x2, int y2) {
//	if (x1 == x2 && y1 == y2)
//		return;
//	bool res = false;
//	if (f[x1][y1] != f[x2][y2])
//	{
//		del_bdDw(u_old, v_old);
//		return;
//	}
//	if (check1(x1, y1, x2, y2))
//		res = true;
//	else if (check2(x1, y1, x2, y2))
//		res = true;
//	else if (check3(x1, y1, x2, y2))
//		res = true;
//
//	if (res) {
//		//show score
//		score += 10;
//		int x2_1 = X + (M * W) + ((M - 1) * 10) + 10;
//		int x1_2 = x2_1 + (getmaxx() - x2_1) / 2;
//		setcolor(15), setbkcolor(0);
//		settextstyle(10, 0, 6);
//		settextjustify(1, 1);
//		string stScore = to_string((long long)score);
//		char *charrScore = &stScore[0];
//		outtextxy(x1_2, 240, charrScore);
//
//		cntRes += 2;
//		del_bdDw(u_old, v_old);
//		if (level == 1)
//			updateLevel_1(x1, y1, x2, y2);
//		else if (level == 2)
//			updateLevel_2(x1, y1, x2, y2);
//		else if (level == 3)
//			updateLevel_3(x1, y1, x2, y2);
//		else if (level == 4)
//			updateLevel_4(x1, y1, x2, y2);
//		else if (level == 5)
//			updateLevel_5(x1, y1, x2, y2);
//	}
//	else {
//		del_bdDw(u_old, v_old);
//	}
//
//}
//bool checkUsename(string st) {
//	for (int i = 0; i < (int)dataP.size(); ++i)
//		if (st == dataP[i].first)
//			return false;
//	return true;
//}
//void EnterUsername();
//
//int main() {
//	int gd = IBM8514, gm = IBM8514HI;
//	initgraph(&gd, &gm, "");
//
//	readData();
//	layoutMenu();
//
//	getch();
//	closegraph();
//	fi.close();
//	fo.close();
//	return 0;
//}
//void initF() {
//	srand(time(NULL));
//	vector<int> cnt(8, 0);
//	for (int i = 1; i <= N; ++i)
//		for (int j = 1; j <= M; ++j) {
//			while (1) {
//				int n = rand() % 7 + 1;
//				if (cnt[n] == (N * M) / 7)
//					continue;
//				else {
//					f[i][j] = n;
//					cnt[n]++;
//					break;
//				}
//			}
//		}
//}
//void resetF() {
//	int x2_1;
//	int x1_2;
//	if (cntChange == 0) {
//		return;
//	}
//	if (cntChange == 1) {
//		cntChange--;
//		x2_1 = X + (M * W) + ((M - 1) * 10) + 10;
//		x1_2 = x2_1 + (getmaxx() - x2_1) / 2;
//		drawRect(x1_2 - 90, 375, x1_2 + 90, 375 + 65, 15); // doi
//		setfillstyle(1, DARKGRAY), floodfill(x1_2, 400, 15);
//		settextjustify(1, 1), setbkcolor(DARKGRAY), settextstyle(10, 0, 3);
//		outtextxy(x1_2 - 15, 415, "CHANGE:");
//		outtextxy(x1_2 + 55, 415, "0");
//	}
//	else {
//		//drawRect(x1_2 - 90, 375, x1_2 + 90, 375 + 65, 15); // doi
//		cntChange--;
//		x2_1 = X + (M * W) + ((M - 1) * 10) + 10;
//		x1_2 = x2_1 + (getmaxx() - x2_1) / 2;
//		drawRect(x1_2 - 90, 375, x1_2 + 90, 375 + 65, 15); // doi
//		setfillstyle(1, GREEN), floodfill(x1_2, 400, 15);
//		settextjustify(1, 1), setbkcolor(GREEN), settextstyle(10, 0, 3);
//		outtextxy(x1_2 - 15, 415, "CHANGE:");
//		string stCntChange = to_string((long long)cntChange);
//		char *charrCntChange = &stCntChange[0];
//		outtextxy(x1_2 + 55, 415, charrCntChange);
//	}
//
//	vector<int> arr;
//
//	for (int i = 1; i <= N; ++i)
//		for (int j = 1; j <= M; ++j)
//			if (f[i][j] != 0)
//				arr.push_back(f[i][j]);
//
//	vector<bool> b(arr.size(), false);
//	srand(time(NULL));
//
//	for (int i = 1; i <= N; ++i)
//		for (int j = 1; j <= M; ++j)
//			if (f[i][j] != 0) {
//				while (1) {
//					int k = rand() % arr.size();
//					if (b[k] == false) {
//						f[i][j] = arr[k];
//						b[k] = true;
//						delDw(i, j);
//						int xd = X + (j - 1) * (W + 10);
//						int yd = Y + (i - 1) * (W + 10);
//						if (arr[k] == 1) {
//							g.drawTrungDay(xd, yd);
//						}
//						if (arr[k] == 2) {
//							g.drawHuong(xd, yd);
//						}
//						if (arr[k] == 3) {
//							g.drawRong(xd, yd);
//						}
//						if (arr[k] == 4) {
//							g.drawBuom(xd, yd);
//						}
//						if (arr[k] == 5) {
//							g.drawPikachu(xd, yd);
//						}
//						if (arr[k] == 6) {
//							g.drawNuoc(xd, yd);
//						}
//						if (arr[k] == 7) {
//							g.drawXanh(xd, yd);
//						}
//						break;
//					}
//				}
//			}
//}
//void layoutGame(string user) {
//	cleardevice();
//	dwBack();
//
//	// outtext PIKACHU
//	settextjustify(1, 1);
//	settextstyle(10, 0, 6); setcolor(14);
//	outtextxy(getmaxx() / 2, 50, "PIKACHU CLASSIS");
//	// vien xung quanh cac pokemon
//	int x1_1 = X - 10, y1_1 = Y - 10;
//	int x2_1 = X + (M * W) + ((M - 1) * 10) + 10;
//	int y2_1 = Y + (N * W) + ((N - 1) * 10) + 10;
//	setcolor(15);
//	setlinestyle(1, 0, 3);
//	line(x1_1, y1_1, x2_1, y1_1);
//	line(x2_1, y1_1, x2_1, y2_1);
//	line(x2_1, y2_1, x1_1, y2_1);
//	line(x1_1, y2_1, x1_1, y1_1);
//
//	// box change
//	int x1_2 = x2_1 + (getmaxx() - x2_1) / 2;
//	drawRect(x1_2 - 90, 375, x1_2 + 90, 375 + 65, 15); // doi
//	setfillstyle(1, GREEN), floodfill(x1_2, 400, 15);
//	settextjustify(1, 1), setbkcolor(GREEN), settextstyle(10, 0, 3);
//	outtextxy(x1_2 - 15, 415, "CHANGE:");
//	outtextxy(x1_2 + 55, 415, "3");
//
//	// show round
//	setcolor(15), setbkcolor(0);
//	settextstyle(10, 0, 3);
//	settextjustify(1, 1);
//	outtextxy(x1_2 - 30, 550, "Round: ");
//	string stLevel = to_string((long long)level);
//	char *charrLevel = &stLevel[0];
//	setcolor(LIGHTRED);
//	outtextxy(x1_2 + 30, 550, charrLevel);
//
//	// show name player
//	setcolor(15), setbkcolor(0);
//	settextjustify(0, 0);
//	settextstyle(10, 0, 3);
//	outtextxy(30, 750, "Player: ");
//	string st = user;
//	char *charr = &st[0];
//	outtextxy(150, 750, charr);
//
//	// show score
//	settextstyle(10, 0, 5);
//	settextjustify(1, 1), setcolor(11);
//	outtextxy(x1_2, 170, "SCORE");
//
//	setcolor(15), setbkcolor(0);
//	settextstyle(10, 0, 6);
//	settextjustify(1, 1);
//	string stScore = "0";
//	char *charrScore = &stScore[0];
//	outtextxy(x1_2, 240, charrScore);
//
//	// use mouse
//	initF();
//	drawGame();
//
//	vector<int> a;
//	int u, v;
//
//	clock_t aa, bb;
//	const int TIME = 40;
//	int cntTime = 0;
//
//	// bar time
//	drawRect(X - 10, 95, X + W * M + 10 * (M - 1) + 3, 115, 15);
//	setfillstyle(1, GREEN), floodfill(X + 10, 100, 15);
//	int xTime = X + W * M + 10 * (M - 1) + 3;
//
//	//while (true){
//	aa = clock();
//	while (cntTime < TIME) {
//		if (cntRes == (N * M)) {
//			cntRes = 0;
//			// update score
//			score += (TIME - cntTime) * 5;
//
//			setcolor(15), setbkcolor(0);
//			settextstyle(10, 0, 6);
//			settextjustify(1, 1);
//			string stScore = to_string((long long)score);
//			char *charrScore = &stScore[0];
//			outtextxy(x1_2, 240, charrScore);
//
//			level++;
//			if (level == 6)
//				break;
//
//			initF();
//			drawGame();
//
//			// update round
//			setcolor(15), setbkcolor(0);
//			settextstyle(10, 0, 3);
//			settextjustify(1, 1);
//			stLevel = to_string((long long)level);
//			charrLevel = &stLevel[0];
//			setcolor(LIGHTRED);
//			outtextxy(x1_2 + 30, 550, charrLevel);
//
//			// reset time
//			cntTime = 0;
//			xTime = X + W * M + 10 * (M - 1) + 3;
//			drawRect(X - 10, 95, X + W * M + 10 * (M - 1) + 3, 115, 15);
//			setfillstyle(1, GREEN), floodfill(X + 10, 100, 15);
//
//		}
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (10 <= x && x <= 100 && 10 <= y && y <= 60)
//			{
//				//setbkcolor(0);
//				layoutMenu();
//			}
//			if (x1_2 - 90 <= x && x <= x1_2 + 90 && 375 <= y && y <= 375 + 65) {
//				setcolor(15);
//				resetF();
//			}
//			int x_tmp = X, y_tmp = Y;
//			int i = 1, j = 1;
//			for (; i <= N; ++i) {
//				;
//				for (j = 1; j <= M; ++j) {
//					if (x_tmp <= x && x <= x_tmp + W && y_tmp <= y && y <= y_tmp + W) {
//						goto tt;
//					}
//					x_tmp += W + 10;
//				}
//				x_tmp = X;
//				y_tmp += W + 10;
//			}
//			del_bdDw(u_old, v_old);
//			i = -1, j = -1;
//		tt:
//			if (i != -1 && j != -1) {
//				bdDw(i, j); // ve border
//				a.push_back(i);
//				a.push_back(j);
//				if (a.size() == 4) {
//					checkPoint(a[0], a[1], a[2], a[3]);
//					a.clear();
//				}
//			}
//			else {
//				a.clear();
//			}
//		}
//		if (xTime <= 280) {
//			setfillstyle(1, LIGHTRED);
//			bar(X - 9, 96, xTime, 115);
//		}
//		bb = clock();
//		if (((bb - aa) / CLOCKS_PER_SEC) == 1) {
//			cntTime++;
//			setfillstyle(1, 0);
//			bar(xTime - 15, 96, xTime, 115);
//			xTime -= 15;
//			aa = bb;
//		}
//	}
//	score += (TIME - cntTime) * 5;
//	string tmp2 = user;
//	pair<string, int> ttt = make_pair(tmp2, score);
//	dataP.push_back(ttt);
//	fo << "\n" << user + "#" + to_string((long long)score);
//	setbkcolor(0);
//	layoutFinish();
//}
//bool cmp(pair<string, int> p1, pair<string, int> p2) {
//	return p1.second > p2.second;
//}
//void showScore() {
//	// sort score
//	sort(dataP.begin(), dataP.end(), cmp);
//
//	int x = 300, y = 250; // 600 
//	settextjustify(0, 0);
//
//	for (int i = 0; i < 5; ++i) {
//		setcolor(WHITE);
//		settextstyle(10, 0, 3);
//		if (i == 0) {
//			setcolor(YELLOW);
//			settextstyle(10, 0, 4);
//		}
//		char *ch = &dataP[i].first[0];
//		outtextxy(x, y, ch);
//		x = 650;
//
//		string st = to_string((long long)dataP[i].second);
//		char *ch2 = &st[0];
//		outtextxy(x, y, ch2);
//
//		x = 300;
//		y += 75;
//	}
//}
//void layoutMenu() {
//	setcolor(15), setbkcolor(0);
//	cleardevice();
//	int xMid = getmaxx() / 2;
//	int yBegin = 200;
//
//	setcolor(14), settextstyle(10, 0, 8), settextjustify(1, 1);
//	outtextxy(xMid + 50, 100, "PIKACHU");
//	g.drawPikachu(xMid - 210, 40);
//	drawRect(xMid - 210, 40, xMid - 210 + 65, 105, 0);
//
//
//	settextjustify(1, 1);
//	settextstyle(10, 0, 3);
//	//setcolor(CYAN);
//	setfillstyle(1, CYAN);
//	setbkcolor(CYAN);
//	drawRect(xMid - 150, yBegin, xMid + 150, yBegin + 50, 15); // new game
//	floodfill(xMid, yBegin + 25, 15);
//	outtextxy(xMid, yBegin + 30, "New game");
//
//	yBegin += 70;
//	drawRect(xMid - 150, yBegin, xMid + 150, yBegin + 50, 15); // high score
//	floodfill(xMid, yBegin + 25, 15);
//	outtextxy(xMid, yBegin + 30, "High score");
//
//	yBegin += 70;
//	drawRect(xMid - 150, yBegin, xMid + 150, yBegin + 50, 15); // help
//	floodfill(xMid, yBegin + 25, 15);
//	outtextxy(xMid, yBegin + 30, "Help");
//
//	yBegin += 70;
//	drawRect(xMid - 150, yBegin, xMid + 150, yBegin + 50, 15); // about
//	floodfill(xMid, yBegin + 25, 15);
//	outtextxy(xMid, yBegin + 30, "About");
//
//	yBegin += 70;
//	drawRect(xMid - 150, yBegin, xMid + 150, yBegin + 50, 15); // exit
//	floodfill(xMid, yBegin + 25, 15);
//	outtextxy(xMid, yBegin + 30, "Exit");
//
//	//use mouse
//	while (true) {
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (xMid - 150 <= x && x <= xMid + 150) {
//				if (200 <= y && y <= 250) {
//					score = 0, level = 1, cntChange = 3, cntRes = 0;
//					layoutEnterUsename();
//					EnterUsername();
//				}
//				if (270 <= y && y <= 320) {
//					layoutHighScore();
//				}
//				if (340 <= y && y <= 390) {
//					layoutHelp();
//				}
//				if (410 <= y && y <= 460) {
//					layoutAbout();
//				}
//				if (480 <= y && y <= 530) {
//					exit(0);
//				}
//			}
//		}
//	}
//}
//void layoutHighScore() {
//	setcolor(15), setbkcolor(0);
//	cleardevice();
//	dwBack();
//
//	setcolor(CYAN), settextstyle(10, 0, 7), settextjustify(1, 1);
//	outtextxy(getmaxx() / 2, 150, "High score");
//
//	showScore();
//
//	// use mouse
//	while (true)
//	{
//		if (ismouseclick(WM_LBUTTONDOWN))
//		{
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (10 <= x && x <= 100 && 10 <= y && y <= 60)
//			{
//				layoutMenu();
//			}
//		}
//	}
//}
//void layoutAbout()
//{
//	setbkcolor(0);
//	setcolor(15);
//	cleardevice();
//	dwBack();
//
//	settextjustify(1, 1), setcolor(14), settextstyle(10, 0, 5);
//	outtextxy(getmaxx() / 2, 150, "ABOUT THE GAME");
//
//	int x = 100, y = 240;
//
//	settextjustify(0, 0), settextstyle(10, 0, 3); setcolor(15);
//	outtextxy(x, y, "Pikachu is one of the types of intellectual games that have");
//	outtextxy(x, y + 30, "attracted generations of people with the feature showing both");
//	outtextxy(x, y + 60, "the classic and modern with a rich and beautiful interfacethe");
//	outtextxy(x, y + 90, "classic and modern with a rich and beautiful interface.");
//
//	outtextxy(x, y + 150, "About pictures and sound: Pikachu Game Pikachu owns a");
//	outtextxy(x, y + 180, "treasure trove of rich images of all kinds of characters in the");
//	outtextxy(x, y + 210, "anime Pokemon.Surely eye-catching that makes you unable to");
//	outtextxy(x, y + 240, "take your eyes off once you start the game.");
//
//	outtextxy(x, y + 300, "Besides, the sound of the game is also very dramatic and");
//	outtextxy(x, y + 330, "attractive, providing a comfortable experience for players.");
//
//	// use mouse
//	while (true)
//	{
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (10 <= x && x <= 100 && 10 <= y && y <= 60)
//			{
//				setbkcolor(0);
//				layoutMenu();
//			}
//		}
//	}
//}
//void layoutHelp()
//{
//	setcolor(15), setbkcolor(0);
//	cleardevice();
//	dwBack();
//
//	settextjustify(1, 1), setcolor(14), settextstyle(10, 0, 5);
//	outtextxy(getmaxx() / 2, 150, "HELP FOR THE PLAYER");
//
//
//	int x = 100, y = 240;
//
//	settextjustify(0, 0), settextstyle(10, 0, 3); setcolor(15);
//	outtextxy(x, y, "The rectangular interface of the game opens with images of");
//	outtextxy(x, y + 30, "different types of animals in the famous Pokemon anime. ");
//
//	outtextxy(x, y + 80, "You have to find pictures of similar animals and tap on 2");
//	outtextxy(x, y + 110, "images for both images to disappear from the screen.");
//
//	outtextxy(x, y + 160, "When you click to select 2 similar beasts there is a rule");
//	outtextxy(x, y + 190, "that you must create a link between them.This link must");
//	outtextxy(x, y + 220, "be a straight line or an animal seam not to bend more");
//	outtextxy(x, y + 250, "than 2 times to meet the requirements.");
//	outtextxy(x, y + 300, "When there are no animals, you'll be taken to the next screen.");
//
//	// use mouse
//	while (true)
//	{
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (10 <= x && x <= 100 && 10 <= y && y <= 60)
//			{
//				setbkcolor(0);
//				layoutMenu();
//			}
//		}
//	}
//}
//void layoutEnterUsename() {
//	// layout enter usename
//	setbkcolor(0), setcolor(15);
//	cleardevice();
//	int x = getmaxx() / 2;
//	int y = getmaxy() / 2;
//	drawRect(x - 400, y - 150, x + 400, y, 15);
//	settextjustify(0, 0);
//	settextstyle(10, 0, 4);
//	setcolor(14);
//	outtextxy(x - 370, y - 60, "Your name: ");
//
//	//
//}
//void EnterUsername() {
//	int x = getmaxx() / 2;
//	int y = getmaxy() / 2;
//	setcolor(15);
//	string st;
//	char *charr;
//	while (true) {
//		char c = getch();
//		switch (c)
//		{
//		case 8: // backspace
//		//	st.pop_back();
//			if (st.length() == 0)
//				break;
//			st[st.length() - 1] = ' ';
//			charr = &st[0];
//			setcolor(15);
//			settextjustify(0, 0);
//			settextstyle(10, 0, 4);
//			outtextxy(x - 60, y - 60, charr);
//			st.pop_back();
//			break;
//
//		case 13: // enter
//			if (st.size() > 15) { // check length
//				settextstyle(8, 0, 3);
//				settextjustify(1, 1);
//				setcolor(LIGHTRED);
//				outtextxy(x, y - 160, "So ky tu tu 1 ~ 15");
//				setcolor(WHITE);
//			}
//			else {
//				pair<string, int> tmp = make_pair(st, 0);
//				dataP.push_back(tmp);
//				layoutGame(st);
//			}
//			break;
//
//		case 27: // escape
//			layoutMenu();
//			break;
//
//		default:
//			st.push_back(c);
//			if (st.length() > 20) {
//				st.pop_back();
//				break;
//			}
//			charr = &st[0];
//			settextstyle(10, 0, 4);
//			settextjustify(0, 0);
//			outtextxy(x - 60, y - 60, charr);
//			break;
//		}
//	}
//}
//void layoutFinish() {
//	cleardevice();
//	dwBack();
//	setcolor(15);
//	setfillstyle(1, BLACK);
//	settextjustify(1, 1);
//	settextstyle(10, 0, 4);
//	string st = "Your score " + to_string((long long)score);
//	char *charr = &st[0];
//	outtextxy(getmaxx() / 2, getmaxy() / 2, charr);
//	// use mouse
//	while (true) {
//		if (ismouseclick(WM_LBUTTONDOWN)) {
//			int x, y;
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			if (10 <= x && x <= 100 && 10 <= y && y <= 60)
//			{
//				setbkcolor(0);
//				layoutMenu();
//			}
//		}
//	}
//}
//
//void updateLevel_1(int x1, int y1, int x2, int y2) {
//	// xoa x1, y1;
//	delDw(x1, y1);
//	// xoa x2, y2
//	delDw(x2, y2);
//	f[x1][y1] = 0;
//	f[x2][y2] = 0;
//}
//void updateLevel_2(int x1, int y1, int x2, int y2) {
//	if (y1 == y2) {
//		f[x1][y1] = 0, f[x2][y2] = 0;
//		if (x1 > x2)
//			swap(x1, x2);
//		for (int i = x1; i <= N; ++i)
//			if (f[i][y1] == 0) {
//				for (int j = i + 1; j <= N; ++j) {
//					if (f[j][y1] != 0) {
//						swap(f[i][y1], f[j][y1]);
//						break;
//					}
//				}
//			}
//		// cap nhat cot y1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = x1; i <= N; ++i)
//		{
//			delDw(i, y1);
//			if (f[i][y1] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y1] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y1] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y1] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y1] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y1] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y1] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//	}
//	else {
//		for (int i = x1; i <= N; ++i) {
//			if (f[i + 1][y1] == 0) {
//				f[i][y1] = 0;
//				break;
//			}
//			f[i][y1] = f[i + 1][y1];
//		}
//		for (int i = x2; i <= N; ++i) {
//			if (f[i + 1][y2] == 0) {
//				f[i][y2] = 0;
//				break;
//			}
//			f[i][y2] = f[i + 1][y2];
//		}
//		// cap nhat cot y1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = x1; i <= N; ++i)
//		{
//			delDw(i, y1);
//			if (f[i][y1] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y1] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y1] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y1] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y1] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y1] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y1] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//		// cap nhat cot y2
//		xd = X + (y2 - 1) * (W + 10);
//		yd = Y + (x2 - 1) * (W + 10);
//		for (int i = x2; i <= N; ++i)
//		{
//			delDw(i, y2);
//			if (f[i][y2] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y2] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y2] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y2] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y2] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y2] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y2] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//	}
//}
//void updateLevel_3(int x1, int y1, int x2, int y2) {
//	if (y1 == y2) {
//		f[x1][y1] = 0, f[x2][y2] = 0;
//		if (x1 < x2)
//			swap(x1, x2);
//		for (int i = x1; i >= 1; --i)
//			if (f[i][y1] == 0) {
//				for (int j = i - 1; j >= 1; --j) {
//					if (f[j][y1] != 0) {
//						swap(f[i][y1], f[j][y1]);
//						break;
//					}
//				}
//			}
//		// cap nhat cot y1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y;
//		for (int i = 1; i <= x1; ++i)
//		{
//			delDw(i, y1);
//			if (f[i][y1] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y1] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y1] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y1] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y1] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y1] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y1] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//	}
//	else {
//		for (int i = x1; i >= 1; --i) {
//			if (f[i - 1][y1] == 0) {
//				f[i][y1] = 0;
//				break;
//			}
//			f[i][y1] = f[i - 1][y1];
//		}
//		for (int i = x2; i >= 1; --i) {
//			if (f[i - 1][y2] == 0) {
//				f[i][y2] = 0;
//				break;
//			}
//			f[i][y2] = f[i - 1][y2];
//		}
//		// cap nhat cot y1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y;
//		for (int i = 1; i <= x1; ++i)
//		{
//			delDw(i, y1);
//			if (f[i][y1] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y1] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y1] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y1] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y1] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y1] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y1] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//		// cap nhat cot y2
//		xd = X + (y2 - 1) * (W + 10);
//		yd = Y;
//		for (int i = 1; i <= x2; ++i)
//		{
//			delDw(i, y2);
//			if (f[i][y2] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[i][y2] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[i][y2] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[i][y2] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[i][y2] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[i][y2] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[i][y2] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			yd += W + 10;
//		}
//	}
//}
//void updateLevel_4(int x1, int y1, int x2, int y2) {
//	if (x1 == x2) {
//		f[x1][y1] = 0, f[x2][y2] = 0;
//		if (y1 > y2)
//			swap(y1, y2);
//		for (int i = y1; i <= M; ++i)
//			if (f[x1][i] == 0) {
//				for (int j = i + 1; j <= M; ++j) {
//					if (f[x1][j] != 0) {
//						swap(f[x1][i], f[x1][j]);
//						break;
//					}
//				}
//			}
//		// cap nhat dong x1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = y1; i <= M; ++i)
//		{
//			delDw(x1, i);
//			if (f[x1][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x1][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x1][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x1][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x1][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x1][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x1][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//	}
//	else {
//		for (int i = y1; i <= M; ++i) {
//			if (f[x1][i + 1] == 0) {
//				f[x1][i] = 0;
//				break;
//			}
//			f[x1][i] = f[x1][i + 1];
//		}
//		for (int i = y2; i <= M; ++i) {
//			if (f[x2][i + 1] == 0) {
//				f[x2][i] = 0;
//				break;
//			}
//			f[x2][i] = f[x2][i + 1];
//		}
//		// cap nhat dong x1
//		int xd = X + (y1 - 1) * (W + 10);
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = y1; i <= M; ++i)
//		{
//			delDw(x1, i);
//			if (f[x1][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x1][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x1][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x1][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x1][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x1][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x1][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//		// cap nhat dong x2
//		xd = X + (y2 - 1) * (W + 10);
//		yd = Y + (x2 - 1) * (W + 10);
//		for (int i = y2; i <= M; ++i)
//		{
//			delDw(x2, i);
//			if (f[x2][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x2][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x2][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x2][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x2][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x2][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x2][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//	}
//}
//void updateLevel_5(int x1, int y1, int x2, int y2) {
//	if (x1 == x2) {
//		f[x1][y1] = 0, f[x2][y2] = 0;
//		if (y1 < y2)
//			swap(y1, y2);
//		for (int i = y1; i >= 1; --i)
//			if (f[x1][i] == 0) {
//				for (int j = i - 1; j >= 1; --j) {
//					if (f[x1][j] != 0) {
//						swap(f[x1][i], f[x1][j]);
//						break;
//					}
//				}
//			}
//		// cap nhat dong x1
//		int xd = X;
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = 1; i <= y1; ++i)
//		{
//			delDw(x1, i);
//			if (f[x1][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x1][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x1][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x1][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x1][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x1][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x1][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//	}
//	else {
//		for (int i = y1; i >= 1; --i) {
//			if (f[x1][i - 1] == 0) {
//				f[x1][i] = 0;
//				break;
//			}
//			f[x1][i] = f[x1][i - 1];
//		}
//		for (int i = y2; i >= 1; --i) {
//			if (f[x2][i - 1] == 0) {
//				f[x2][i] = 0;
//				break;
//			}
//			f[x2][i] = f[x2][i - 1];
//		}
//		// cap nhat dong x1
//		int xd = X;
//		int yd = Y + (x1 - 1) * (W + 10);
//		for (int i = 1; i <= y1; ++i)
//		{
//			delDw(x1, i);
//			if (f[x1][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x1][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x1][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x1][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x1][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x1][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x1][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//		// cap nhat dong x2
//		xd = X;
//		yd = Y + (x2 - 1) * (W + 10);
//		for (int i = 1; i <= y2; ++i)
//		{
//			delDw(x2, i);
//			if (f[x2][i] == 1) {
//				g.drawTrungDay(xd, yd);
//			}
//			else if (f[x2][i] == 2) {
//				g.drawHuong(xd, yd);
//			}
//			else if (f[x2][i] == 3) {
//				g.drawRong(xd, yd);
//			}
//			else if (f[x2][i] == 4) {
//				g.drawBuom(xd, yd);
//			}
//			else if (f[x2][i] == 5) {
//				g.drawPikachu(xd, yd);
//			}
//			else if (f[x2][i] == 6) {
//				g.drawNuoc(xd, yd);
//			}
//			else if (f[x2][i] == 7) {
//				g.drawXanh(xd, yd);
//			}
//			xd += W + 10;
//		}
//	}
//}