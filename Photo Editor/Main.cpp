
#include <iostream>

#include "Window.h"

using namespace std;

void paint(HWND hwnd) {

}

int main() {
	Window window(600, 600);
	
	Button *b1 = new Button("bla", 10, 10, 80, 20);
	window.add(b1);

	window.create();

	window.setPaintCallback(paint);
	
	while (true) {
		window.update();
	}
}