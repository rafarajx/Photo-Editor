
#include <iostream>

#include "Window.h"

using namespace std;

int main() {

	Window w1(600, 600);
	w1.create();

	Button b1("tralala", 10, 10, 80, 20);
	w1.add(b1);

	while (true) {
		w1.update();
	}

}