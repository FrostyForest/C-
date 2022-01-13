#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> distance_of_points={
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


int main(){
	int sum=0;//��������
	vector<vector<int>> visited(21, vector<int>(21, 0));
	vector<vector<int>> unvisited(21, vector<int>(21, 1));
	vector<vector<int>> path(21, vector<int>(21, 0));
	vector<vector<vector<int>>> sheet1(21, vector<vector<int>>(21, vector<int>(3, INT_MAX)));//���������֮ǰ�����Ǹ����y��x����͵����ľ���
	int x_begin = 8, y_begin = 11;
	int x_end = 8, y_end = 9;
	sheet1[y_begin][x_begin][0] = y_begin;
	sheet1[y_begin][x_begin][1] = x_begin;
	sheet1[y_begin][x_begin][2] = 0;
	while (visited[y_end][x_end] != 1) {
		int min_distance = INT_MAX;//������С����
		int min_y=0, min_x = 0;//���ھ�����С�������
		for (int y = 0; y < 21; y++) {//�ҵ���Сδ���ʵ������;���
			for (int x = 0; x < 21; x++) {
				if (visited[y][x] == 1) continue;
				else {
					if (sheet1[y][x][2] < min_distance) {
						min_distance = sheet1[y][x][2];
						min_y = y; min_x = x;
						
						
					}
				}
			}
		}
		visited[min_y][min_x] = 1;
		sum++;//��������+1
		//�����ϵ�
		if (min_y + 1 <= 20) {
			int x_1 = min_x; int y_1 = min_y + 1;
			if (min_distance + distance_of_points[y_1][x_1] < sheet1[y_1][x_1][2]) {
				sheet1[y_1][x_1][2] = min(sheet1[y_1][x_1][2], min_distance + distance_of_points[y_1][x_1]);
				sheet1[y_1][x_1][0] = min_y; sheet1[y_1][x_1][1] = min_x;
			}
			
		}
		//�����µ�
		if (min_y - 1 >= 0) {
			int x_2 = min_x; int y_2 = min_y - 1;
			if (min_distance + distance_of_points[y_2][x_2] < sheet1[y_2][x_2][2]) {
				sheet1[y_2][x_2][2] = min(sheet1[y_2][x_2][2], min_distance + distance_of_points[y_2][x_2]);
				sheet1[y_2][x_2][0] = min_y; sheet1[y_2][x_2][1] = min_x;
			}
		}
		//�������
		if (min_x - 1 >= 0) {
			int x_3 = min_x - 1; int y_3 = min_y;
			if (min_distance + distance_of_points[y_3][x_3] < sheet1[y_3][x_3][2]) {
				sheet1[y_3][x_3][2] = min(sheet1[y_3][x_3][2], min_distance + distance_of_points[y_3][x_3]);
				sheet1[y_3][x_3][0] = min_y; sheet1[y_3][x_3][1] = min_x;
			}
		}
		//�����ҵ�
		if (min_x + 1<=20) {
			int x_4 = min_x + 1; int y_4 = min_y;
			if (min_distance + distance_of_points[y_4][x_4] < sheet1[y_4][x_4][2]) {
				sheet1[y_4][x_4][2] = min(sheet1[y_4][x_4][2], min_distance + distance_of_points[y_4][x_4]);
				sheet1[y_4][x_4][0] = min_y; sheet1[y_4][x_4][1] = min_x;
			}
		}
	}
	int x_r = x_end; int y_r = y_end;
	while (x_r != x_begin || y_r != y_begin) {//���յ㿪ʼ�������·������
		cout << x_r << " " << y_r << endl;
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

	return sum;//���ؾ���
}
