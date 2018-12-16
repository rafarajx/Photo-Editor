
#include <iostream>

#include "Window.h"

#include "Image.h"

using namespace std;

BITMAP bmp;

Image *img;

void paint(HWND hwnd) {

	HBITMAP hb = img->hb;
	
	PAINTSTRUCT     ps;
	HDC             hdc;
	BITMAP          bitmap;
	HDC             hdcMem;
	HGDIOBJ         oldBitmap;

	hdc = BeginPaint(hwnd, &ps);

	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hb);

	GetObject(hb, sizeof(bitmap), &bitmap);
	BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);

	EndPaint(hwnd, &ps);
	
	//DeleteObject(hb);

	RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
}

int main() {

	img = new Image("../res/rocks.png");

	Window window(600, 600);
	
	Button *b1 = new Button("bla", 10, 10, 80, 20);
	//window.add(b1);

	window.create();

	window.setPaintCallback(paint);
	
	while (true) {
		window.update();
	}
	
}