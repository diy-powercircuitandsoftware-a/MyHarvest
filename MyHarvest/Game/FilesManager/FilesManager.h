#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include "../../GameEngine/raylib/src/raylib.h"
#include "../UI/GameFont.h"
class FilesManager
{
public:
	
	bool HadAsset();	
	bool LoadConfig();
	bool LoadSaveGame();
	struct DisplayConfig
	{
		int Width;
		int Height;	
		
	};
	 
	DisplayConfig displayconfig;
	GameFont SelectorFont ;
	
};

#endif