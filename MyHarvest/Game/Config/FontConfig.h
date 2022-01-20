#ifndef FONTCONFIG_H
#define FONTCONFIG_H
#include <iostream>
#include "../../GameEngine/raylib/src/raylib.h"

typedef  struct  FontConfig
{
	Font font  ;
	std::string fontpath;
	float size;
	float spacing;
	 
	Font GetFont() {
		return this->font;
		
	 }
	void UpdateFont() {
		if (this->fontpath == "") {
			this->font = GetFontDefault();
			this->size = this->font.baseSize;
			this->spacing = this->size * 0.12;
		}
		else {
			this->font = LoadFontEx(this->fontpath.c_str(), this->size, 0, 0);
		}
		
	}
	 
}FontConfig;
#endif
