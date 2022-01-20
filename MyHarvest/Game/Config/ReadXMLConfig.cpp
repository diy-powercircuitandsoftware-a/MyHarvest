#include "ReadXMLConfig.h"
#include "../../GameEngine/xml/src/rapidxml_utils.hpp"
#include "../../GameEngine/raylib/src/raylib.h"


std::string ReadXMLConfig::GetGameData() {
	return this->AssetPath;
}

bool ReadXMLConfig::LoadConfig() {
 
	if (std::ifstream("Data/Config.xml").good()) 
	{

		try {
			rapidxml::file<> xmlFile("Data/Config.xml");
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());
			rapidxml::xml_node<>* rootnode = doc.first_node("MyHarvest");
			rapidxml::xml_node<>* confignode = rootnode->first_node("Config");
			rapidxml::xml_node<>* displaynode = confignode->first_node("Display");		
			this->DisplayConfig.Width = atoi(displaynode->first_node("Width")->value());
			this->DisplayConfig.Height = atoi(displaynode->first_node("Height")->value());
			if (confignode->first_node("GameData") != nullptr) {
				rapidxml::xml_node<>* gamedata = confignode->first_node("GameData");
				if (strlen(gamedata->first_attribute("assetpath")->value())>0) {
					this->AssetPath = gamedata->first_attribute("assetpath")->value();
					this->TitleAsset.MainAudioPath = this->AssetPath;
				    this->TitleAsset.MainAudioPath= this->TitleAsset.MainAudioPath+	gamedata->first_node("Title")->first_node("Main")->first_attribute("audiopath")->value();			
				}
				rapidxml::xml_node<>* fontnode = gamedata->first_node("Font");
				if (fontnode->first_node("SelectorFont")->first_attribute("size") != nullptr && fontnode->first_node("SelectorFont")->first_attribute("path") != nullptr) {
					this->SelectorFont.fontpath = this->AssetPath + std::string(fontnode->first_node("SelectorFont")->first_attribute("path")->value());
					this->SelectorFont.size = std::stof(fontnode->first_node("SelectorFont")->first_attribute("size")->value());				
				}
				if (fontnode->first_node("TitleFont")->first_attribute("size") != nullptr && fontnode->first_node("TitleFont")->first_attribute("path") != nullptr) {
					this->TitleFont.fontpath = this->AssetPath + std::string(fontnode->first_node("TitleFont")->first_attribute("path")->value());
					this->TitleFont.size= std::stof(fontnode->first_node("TitleFont")->first_attribute("size")->value());
				}
				if (fontnode->first_node("LabelFont")->first_attribute("size") != nullptr && fontnode->first_node("LabelFont")->first_attribute("path") != nullptr) {
					this->LabelFont.fontpath = this->AssetPath + std::string( fontnode->first_node("LabelFont")->first_attribute("path")->value());
					this->LabelFont.size= std::stof(fontnode->first_node("LabelFont")->first_attribute("size")->value());
				}
			
			}		
			return true;
		}
		catch (const rapidxml::parse_error& e) {
			return false;
		}
	}
	return false;
}
void ReadXMLConfig::UpdateFont() {
	this->SelectorFont.UpdateFont();
	this->TitleFont.UpdateFont();
	this->LabelFont.UpdateFont();
}