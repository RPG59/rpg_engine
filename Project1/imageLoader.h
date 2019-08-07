#pragma once

#include <string>
#include <freeImage/FreeImage.h>

static BYTE* loadImage(const char* path, GLsizei* widht, GLsizei* height)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP* dib = nullptr;
	fif = FreeImage_GetFileType(path, 0);

	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(path);
	if (fif == FIF_UNKNOWN)
		return nullptr;

	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, path);
	if (!dib)
		return nullptr;

	BYTE * res = FreeImage_GetBits(dib);
	*widht = FreeImage_GetWidth(dib);
	*height = FreeImage_GetHeight(dib);

	return res;

}
