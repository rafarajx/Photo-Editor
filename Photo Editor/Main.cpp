
#include <iostream>

#include "Window.h"

using namespace std;

int main() {

	Window w1(600, 600);

	w1.create();
	
	while (true) {
		w1.update();
	}

}