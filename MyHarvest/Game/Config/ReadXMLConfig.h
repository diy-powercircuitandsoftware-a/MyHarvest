#ifndef READXMLCONFIG_H
#define READXMLCONFIG_H

#include "../../GameEngine/raylib/src/raylib.h"
#include "FontConfig.h"
#include <iostream>
class ReadXMLConfig
{
public:
	struct DisplayConfig
	{
		int Width;
		int Height;
	};
	struct Seasons {
		std::string IconPath;
		Rectangle IconSpring;
		Rectangle IconSummer;
		Rectangle IconAutumnand;
		Rectangle IconWinter;
	};
	struct TitleAsset
	{
		std::string MainAudioPath;	  
	};
	std::string GetGameData();
	 
	bool LoadConfig();
	  
	 
	DisplayConfig DisplayConfig;
	FontConfig SelectorFont;
	FontConfig TitleFont;
	FontConfig LabelFont;
	void UpdateFont();
	TitleAsset TitleAsset;
private:
	std::string AssetPath;
};

#endif