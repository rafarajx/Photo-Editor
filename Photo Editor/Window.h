#pragma once

#include <Windows.h>
#include <map>
#include <vector>
#include <iostream>

#include "Button.h"

#define SCB(x) void (* ## x ## CB)(HWND hwnd); void set ## x ## Callback(void(* ## x ## CB)(HWND hwnd)) {this->x ## CB = x ## CB;}

class Window {
private:
	HWND hwnd;
	MSG message;
public:
	std::vector<Control*> controls;
	int width, height;
	
	static std::map<HWND, Window*> handles;

	Window(int width, int height);

	void create();
	void update();
	void add(Button *button);

	SCB(Create);
	SCB(Paint);
	SCB(Command);
};