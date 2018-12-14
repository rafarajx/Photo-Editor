#pragma once

#include <FreeImage.h>

#include <Windows.h>

class Image {

public:

	unsigned int BPP;
	unsigned int width;
	unsigned int height;

	BYTE *bits;


	Image(const char* filename);
	~Image();
};

