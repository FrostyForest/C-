#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
int main() {
	initgraph(1000, 1000);	// ������ͼ���ڣ���СΪ 640x480 ����
	for (int y = 0; y < 21; y++) {
		for (int x = 0; x < 21; x++) {
			rectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
		}
	}
	Sleep(5 * 1000);
	setfillcolor(GREEN);
	for (int y = 0; y < 21; y++) {
		for (int x = 0; x < 21; x++) {
			fillrectangle(x * 20, y * 20, x * 20 + 20, y * 20 + 20);
		}
	}
	_getch();
	closegraph();			// �رջ�ͼ����
	return 0;
}