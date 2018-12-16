#include "Image.h"

#include <iostream>

Image::Image(const char* filename){
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	fif = FreeImage_GetFileType(filename);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	
	if (fif == FIF_UNKNOWN) {
		printf("Problem loading image: fif == FIF_UNKNOWN");
	}

	FIBITMAP *dib(0);
	dib = FreeImage_Load(fif, filename);

	if (!dib) {
		printf("Problem loading image: !dib");
	}

	bits = FreeImage_GetBits(dib);

	BPP = FreeImage_GetBPP(dib);
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);

	BITMAPINFO dbmi;
	dbmi.bmiHeader = { };
	dbmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	dbmi.bmiHeader.biWidth = width;
	dbmi.bmiHeader.biHeight = height;
	dbmi.bmiHeader.biPlanes = 1;
	dbmi.bmiHeader.biBitCount = BPP;
	dbmi.bmiHeader.biCompression = BI_RGB;

	hb = CreateDIBSection(NULL, &dbmi, DIB_RGB_COLORS, &pixels, NULL, 0);
	if (hb == NULL) {
		MessageBox(NULL, "Problem width CreateDIBSection function", "Error", MB_OK);
		exit(0);
	}

	memcpy(pixels, bits, width * height * BPP / 8);
}

Image::~Image(){

}
