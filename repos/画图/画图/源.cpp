#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
int main() {
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	ellipse(10, 400, 300, 1);
	_getch();
	closegraph();			// 关闭绘图窗口
	return 0;
}