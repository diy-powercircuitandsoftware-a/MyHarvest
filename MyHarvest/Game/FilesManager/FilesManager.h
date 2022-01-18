#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include "../../GameEngine/raylib/src/raylib.h"
#include "../UI/GameFont.h"
class FilesManager
{
public:
	
	char* GetGameData();
	bool HadSaveGame();
	bool LoadConfig();
	bool LoadSaveGame();
	char* GameTitleMusic;
	struct DisplayConfig
	{
		int Width;
		int Height;			
	};
	 
	DisplayConfig DisplayConfig;
	GameFont SelectorFont;

private:
	char* AssetPath;
};

#endif