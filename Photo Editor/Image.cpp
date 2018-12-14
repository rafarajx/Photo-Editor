#include "Image.h"

#include <iostream>

using namespace std;

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

	for (int i = 0; i < width * 3; i += 3) {
		cout << (int)bits[i] << " " << (int)bits[i + 1] << " " << (int)bits[i + 2] << endl;
	}
	
}

Image::~Image(){

}
