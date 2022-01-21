#ifndef READXMLCONFIG_H
#define READXMLCONFIG_H
#include "../../GameEngine/xml/src/rapidxml_utils.hpp"
#include "../Struct/Size.h"
#include "../Texture/Seasons/Seasons.h"
#include <map>
 
 
 

class ReadXMLConfig
{
public:
	bool LoadConfig();
	std::string AssetPath;
	Size DisplaySize;
	std::map<std::string, std::pair<std::string, float>>  FontConfigList;
	std::map < std::string, std::string> TitleConfig;
	GameTexture::Seasons SeasonsTexture;
};

#endif