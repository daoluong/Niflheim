#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ft2build.h>
#include FT_FREETYPE_H

using namespace std;

#pragma pack(1)

typedef struct _CharBitmap
{
	DWORD bmp_width;
	DWORD bmp_height;
	DWORD bearingX;
	DWORD bearingY;
	DWORD Advance;
	BYTE* bmpBuffer;
}CharBitmap;

#pragma pack()

class FT_Make
{
public:
	FT_Make(string font_path, DWORD font_height);
	CharBitmap GetCharBitmap(WCHAR wchar);
	~FT_Make();
private:
	FT_Library library;
	FT_Face face;
	FT_Error error;
	bool FT_Init(string font_path, DWORD font_height);
};