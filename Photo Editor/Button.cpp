#include "Button.h"

Button::Button(const char* text, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
	: text(text), x(x), y(y), w(w), h(h){

}

void Button::create(HWND hwnd) {

	hwnd = CreateWindow(
		"BUTTON",
		text,
		WS_VISIBLE | WS_CHILD,
		x, y, w, h,
		hwnd, NULL, NULL, NULL
	);
}
