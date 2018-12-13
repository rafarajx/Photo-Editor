#pragma once

#include <Windows.h>

#include "Control.h"

class Button : public Control{
public:
	const char* text;
	int x, y, w, h;

	Button(const char* text, unsigned int x, unsigned int y, unsigned int w, unsigned int h);

	void create(HWND hwnd) override;
};

