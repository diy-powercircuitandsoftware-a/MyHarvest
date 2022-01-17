#ifndef GAMEFONT_H
#define GAMEFONT_H
#include "../../GameEngine/raylib/src/raylib.h"
struct GameFont
{
	
	Font font = GetFontDefault();
	int size = GetFontDefault().baseSize;
};
#endif
