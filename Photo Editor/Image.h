#pragma once

#include <Windows.h>
#include <FreeImage.h>

class Image {

public:

	BYTE *bits;
	unsigned int BPP;
	int width;
	int height;

	HBITMAP hb;
	void* pixels;


	Image(const char* filename);
	~Image();
};

