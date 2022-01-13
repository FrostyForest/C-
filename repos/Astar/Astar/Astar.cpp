#include <iostream>
#include <vector>
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

vector<vector<int>> distance_of_points = {
//x	 0	1  2  3  4  5  6    7    8    9    10   11   12   13 14 15 16 17 18 19 20   y
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//0
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//1
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//2
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//3
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//4
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//5
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//6
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//7
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//8
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//9
	{1, 1, 1, 1, 1, 1, 1, 999, 999, 999, 999, 999, 999, 999, 1, 1, 1, 1, 1, 1, 1},//10
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//11
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//12
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//13
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//14
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//15
	{1, 1, 1, 1, 1, 1, 1, 999,   1,   1,   1,   1,   1, 999, 1, 1, 1, 1, 1, 1, 1},//16
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//17
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//18
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//19
	{1, 1, 1, 1, 1, 1, 1,   1,   1,   1,   1,   1,   1,   1, 1, 1, 1, 1, 1, 1, 1},//20
};


int main() {
	initgraph(1000, 1000);	// 创建绘图窗口
	for (int y = 0; y < 21; y++) {//画出格子
		for (int x = 0; x < 21; x++) {
			rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
		}
	}
	for (int y = 0; y < 21; y++) {//画出障碍物
		for (int x = 0; x < 21; x++) {
			if (distance_of_points[y][x] == 999) {
				setfillcolor(RED);
				fillrectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
			}
		}
	}
	int sum = 0;//迭代次数
	vector<vector<int>> visited(21, vector<int>(21, 0));
	vector<vector<int>> unvisited(21, vector<int>(21, 1));
	vector<vector<int>> path(21, vector<int>(21, 0));
	vector<vector<vector<int>>> sheet1(21, vector<vector<int>>(21, vector<int>(4, INT_MAX)));//到达这个点之前经过那个点的y和x坐标和到起点的距离
	int x_begin = 12, y_begin = 4;//设置起点
	int x_end = 8, y_end = 11;//设置终点
	
	sheet1[y_begin][x_begin][0] = y_begin;
	sheet1[y_begin][x_begin][1] = x_begin;
	sheet1[y_begin][x_begin][2] = 0;//2为到起点距离
	sheet1[y_begin][x_begin][3] = abs(y_end - y_begin) + abs(x_end + x_begin);//3为到终点的曼哈顿距离
	while (visited[y_end][x_end] != 1) {
		setfillcolor(WHITE); fillrectangle(x_begin * 20, y_begin * 20, x_begin * 20 + 20, y_begin * 20 + 20);//起点为白色
		setfillcolor(YELLOW); fillrectangle(x_end * 20, y_end * 20, x_end * 20 + 20, y_end * 20 + 20);//终点为灰色
		int min_distance = INT_MAX;//表内最小距离
		int min_y = 0, min_x = 0;//表内距离最小点的坐标
		for (int y = 0; y < 21; y++) {//表内找到最小未访问点的坐标和距离
			for (int x = 0; x < 21; x++) {
				if (visited[y][x] == 1) continue;
				else {
					if (sheet1[y][x][3] < min_distance) {
						min_distance = sheet1[y][x][3];
						min_y = y; min_x = x;
					}
				}
			}
		}
		visited[min_y][min_x] = 1;
		setfillcolor(GREEN);
		fillrectangle(min_x * 20, min_y * 20, min_x * 20 + 20, min_y * 20 + 20);
		Sleep(1 * 100);
		sum++;//迭代次数+1
		//处理上点
		if (min_y + 1 <= 20) {
			int x_1 = min_x; int y_1 = min_y + 1;
			if (min_distance + distance_of_points[y_1][x_1] < sheet1[y_1][x_1][2]) {
				sheet1[y_1][x_1][2] = min(sheet1[y_1][x_1][2], min_distance + distance_of_points[y_1][x_1]);
				sheet1[y_1][x_1][0] = min_y; sheet1[y_1][x_1][1] = min_x;
			}
			sheet1[y_1][x_1][3] = sheet1[y_1][x_1][2] + abs(y_1 - y_end) + abs(x_1 - x_end);
		}
		//处理下点
		if (min_y - 1 >= 0) {
			int x_2 = min_x; int y_2 = min_y - 1;
			if (min_distance + distance_of_points[y_2][x_2] < sheet1[y_2][x_2][2]) {
				sheet1[y_2][x_2][2] = min(sheet1[y_2][x_2][2], min_distance + distance_of_points[y_2][x_2]);
				sheet1[y_2][x_2][0] = min_y; sheet1[y_2][x_2][1] = min_x;
			}
			sheet1[y_2][x_2][3] = sheet1[y_2][x_2][2] + abs(y_2 - y_end) + abs(x_2 - x_end);
		}
		//处理左点
		if (min_x - 1 >= 0) {
			int x_3 = min_x - 1; int y_3 = min_y;
			if (min_distance + distance_of_points[y_3][x_3] < sheet1[y_3][x_3][2]) {
				sheet1[y_3][x_3][2] = min(sheet1[y_3][x_3][2], min_distance + distance_of_points[y_3][x_3]);
				sheet1[y_3][x_3][0] = min_y; sheet1[y_3][x_3][1] = min_x;
			}
			sheet1[y_3][x_3][3] = sheet1[y_3][x_3][2] + abs(y_3 - y_end) + abs(x_3 - x_end);
		}
		//处理右点
		if (min_x + 1 <= 20) {
			int x_4 = min_x + 1; int y_4 = min_y;
			if (min_distance + distance_of_points[y_4][x_4] < sheet1[y_4][x_4][2]) {
				sheet1[y_4][x_4][2] = min(sheet1[y_4][x_4][2], min_distance + distance_of_points[y_4][x_4]);
				sheet1[y_4][x_4][0] = min_y; sheet1[y_4][x_4][1] = min_x;
			}
			sheet1[y_4][x_4][3] = sheet1[y_4][x_4][2] + abs(y_4 - y_end) + abs(x_4 - x_end);
		}
	}
	int x_r = x_end; int y_r = y_end;
	while (x_r != x_begin || y_r != y_begin) {//从终点开始反向输出路径坐标
		cout << x_r << " " << y_r << endl;
		setfillcolor(WHITE); fillrectangle(x_begin * 20, y_begin * 20, x_begin * 20 + 20, y_begin * 20 + 20);//起点为白色
		setfillcolor(YELLOW); fillrectangle(x_end * 20, y_end * 20, x_end * 20 + 20, y_end * 20 + 20);//终点为黄色
		setfillcolor(BLUE);//路径为蓝色
		fillrectangle(x_r * 20, y_r * 20, x_r * 20 + 20, y_r * 20 + 20);
		Sleep(5 * 100);
		path[y_r][x_r] = 1;
		int temper_x = x_r;
		x_r = sheet1[y_r][x_r][1];
		y_r = sheet1[y_r][temper_x][0];

	}
	path[y_begin][x_begin] = 1;
	for (int y = 0; y < 21; y++) {
		for (int x = 0; x < 21; x++) {
			cout << path[y][x] << " ";
		}
		cout << endl;
	}
	_getch();
	closegraph();
	return sum;//返回距离
}
