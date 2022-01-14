#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
int main() {
	initgraph(1000, 1000);	// 创建绘图窗口，大小为 640x480 像素
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
	closegraph();			// 关闭绘图窗口
	return 0;
}