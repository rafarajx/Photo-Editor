#pragma once

#include <Windows.h>

class Control{
public:
	HWND hwnd;

	virtual void create(HWND hwnd);
};

