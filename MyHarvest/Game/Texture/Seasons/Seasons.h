#ifndef TEXTURE_SEASONS_H
#define TEXTURE_SEASONS_H
#include "../../../GameEngine/raylib/src/raylib.h"
#include <string>

namespace GameTexture {
	typedef struct Seasons
	{
		std::string path;
		Rectangle spring;
		Rectangle summer;
		Rectangle autumnand;
		Rectangle winter;
	}
	Seasons;
}
#endif

