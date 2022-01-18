#ifndef GAMEFONT_H
#define GAMEFONT_H
#include "../../GameEngine/raylib/src/raylib.h"
#include <string.h>

struct GameFont
{
	const char* fileName = "";
	 
	float size = 1;
	float spacing=12;
	void SetFont(const char* fileName, float size) {
		if (size > 0) {
			this->size = size;
		} 
	}
	Font GetFont() {
		if (strlen(fileName) > 0) {
			return	LoadFont(this->fileName);
		}
		return GetFontDefault();
	
	}
};
#endif
