#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
int main() {
	initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
	ellipse(10, 400, 300, 1);
	_getch();
	closegraph();			// �رջ�ͼ����
	return 0;
}