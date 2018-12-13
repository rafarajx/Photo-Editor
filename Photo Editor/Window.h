#pragma once

#include <Windows.h>
#include <map>

class Window {
private:
	MSG message;


public:
	int width, height;
	
	static std::map<void*, Window*> handles;

	Window(int width, int height);

	void create();
	void update();
};