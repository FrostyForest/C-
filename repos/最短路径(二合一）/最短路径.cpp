#include <iostream>
#include <vector>
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <time.h> 
#include <cstdlib>
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
	int sum_of_times = 0;//100????????????
	int c = 0;//????f(n)
	for (int i = 0; i < 100;i++) {
		srand((unsigned)time(NULL));
		int x_random = rand()%21, y_random = rand() % 21;
		while (x_random == 7 || x_random == 13||y_random==10) {
			x_random = rand() % 21; y_random = rand() % 21;
		}
		int x_begin = x_random, y_begin = y_random;//????????
		x_random = rand() % 21; y_random = rand() % 21;
		while (x_random == 7 || x_random == 13 || y_random == 10) {
			x_random = rand() % 21; y_random = rand() % 21;
		}
		int x_end = x_random, y_end = y_random;//????????
		initgraph(500, 500);	// ????????????
		for (int y = 0; y < 21; y++) {//????????
			for (int x = 0; x < 21; x++) {
				rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
			}
		}
		for (int y = 0; y < 21; y++) {//??????????
			for (int x = 0; x < 21; x++) {
				if (distance_of_points[y][x] == 999) {
					setfillcolor(RED);
					fillrectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
				}
			}
		}
		int sum = 0;//????????
		vector<vector<int>> visited(21, vector<int>(21, 0));
		vector<vector<int>> unvisited(21, vector<int>(21, 1));
		vector<vector<int>> path(21, vector<int>(21, 0));
		vector<vector<vector<int>>> sheet1(21, vector<vector<int>>(21, vector<int>(4, INT_MAX)));//??????????0????????????????????????????y??????1??x??????2??????????????????????,??g(n)??3????????????????????,??h(n)
		

		sheet1[y_begin][x_begin][0] = y_begin;
		sheet1[y_begin][x_begin][1] = x_begin;
		sheet1[y_begin][x_begin][2] = 0;//2????????????
		sheet1[y_begin][x_begin][3] = abs(y_end - y_begin) + abs(x_end + x_begin) * c;//3????????????????????*c
		while (visited[y_end][x_end] != 1) {
			setfillcolor(WHITE); fillrectangle(x_begin * 20, y_begin * 20, x_begin * 20 + 20, y_begin * 20 + 20);//??????????
			setfillcolor(YELLOW); fillrectangle(x_end * 20, y_end * 20, x_end * 20 + 20, y_end * 20 + 20);//??????????
			int min_distance = INT_MAX;//????????????
			int min_y = 0, min_x = 0;//????????????????????
			for (int y = 0; y < 21; y++) {//????????????????????????????????
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
			Sleep(1);//????????
			sum++;//????????+1
			//????????
			if (min_y + 1 <= 20) {
				int x_1 = min_x; int y_1 = min_y + 1;
				if (sheet1[min_y][min_x][2] + distance_of_points[y_1][x_1] < sheet1[y_1][x_1][2]) {//????????
					sheet1[y_1][x_1][2] = min(sheet1[y_1][x_1][2], sheet1[min_y][min_x][2] + distance_of_points[y_1][x_1]);
					sheet1[y_1][x_1][0] = min_y; sheet1[y_1][x_1][1] = min_x;
				}
				sheet1[y_1][x_1][3] = sheet1[y_1][x_1][2] + (abs(y_1 - y_end) + abs(x_1 - x_end)) * c;//f(n)=g(n)+h(n)
			}
			//????????
			if (min_y - 1 >= 0) {
				int x_2 = min_x; int y_2 = min_y - 1;
				if (sheet1[min_y][min_x][2] + distance_of_points[y_2][x_2] < sheet1[y_2][x_2][2]) {//????????
					sheet1[y_2][x_2][2] = min(sheet1[y_2][x_2][2], sheet1[min_y][min_x][2] + distance_of_points[y_2][x_2]);
					sheet1[y_2][x_2][0] = min_y; sheet1[y_2][x_2][1] = min_x;
				}
				sheet1[y_2][x_2][3] = sheet1[y_2][x_2][2] + (abs(y_2 - y_end) + abs(x_2 - x_end)) * c;//f(n)=g(n)+h(n)
			}
			//????????
			if (min_x - 1 >= 0) {
				int x_3 = min_x - 1; int y_3 = min_y;
				if (sheet1[min_y][min_x][2] + distance_of_points[y_3][x_3] < sheet1[y_3][x_3][2]) {//????????
					sheet1[y_3][x_3][2] = min(sheet1[y_3][x_3][2], sheet1[min_y][min_x][2] + distance_of_points[y_3][x_3]);
					sheet1[y_3][x_3][0] = min_y; sheet1[y_3][x_3][1] = min_x;
				}
				sheet1[y_3][x_3][3] = sheet1[y_3][x_3][2] + (abs(y_3 - y_end) + abs(x_3 - x_end)) * c;//f(n)=g(n)+h(n)
			}
			//????????
			if (min_x + 1 <= 20) {
				int x_4 = min_x + 1; int y_4 = min_y;
				if (sheet1[min_y][min_x][2] + distance_of_points[y_4][x_4] < sheet1[y_4][x_4][2]) {//????????
					sheet1[y_4][x_4][2] = min(sheet1[y_4][x_4][2], sheet1[min_y][min_x][2] + distance_of_points[y_4][x_4]);
					sheet1[y_4][x_4][0] = min_y; sheet1[y_4][x_4][1] = min_x;
				}
				sheet1[y_4][x_4][3] = sheet1[y_4][x_4][2] + (abs(y_4 - y_end) + abs(x_4 - x_end)) * c;//f(n)=g(n)+h(n)
			}
		}
		int x_r = x_end; int y_r = y_end;
		while (x_r != x_begin || y_r != y_begin) {//??????????????????????????
			//cout << x_r << " " << y_r << endl;
			setfillcolor(WHITE); fillrectangle(x_begin * 20, y_begin * 20, x_begin * 20 + 20, y_begin * 20 + 20);//??????????
			setfillcolor(YELLOW); fillrectangle(x_end * 20, y_end * 20, x_end * 20 + 20, y_end * 20 + 20);//??????????
			setfillcolor(BLUE);//??????????
			fillrectangle(x_r * 20, y_r * 20, x_r * 20 + 20, y_r * 20 + 20);
			Sleep(1);//????????????
			path[y_r][x_r] = 1;
			int temper_x = x_r;
			x_r = sheet1[y_r][x_r][1];
			y_r = sheet1[y_r][temper_x][0];

		}
		path[y_begin][x_begin] = 1;
		//cout << sheet1[y_end][x_end][2] << endl;//????????????????
		//cout << sum << endl;//????????????
		closegraph();
		sum_of_times = sum_of_times + sum;
	}
	return sum_of_times/100;
}
