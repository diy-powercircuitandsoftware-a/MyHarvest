#include "FilesManager.h"
#include "../../GameEngine/xml/src/rapidxml_utils.hpp"
#include "../../GameEngine/raylib/src/raylib.h"

bool FilesManager::HadAsset() {
	return false;
}
 
bool FilesManager::LoadSaveGame() {
	return false;
	//return std::ifstream("Data/Save.xml").good();
}
bool FilesManager::LoadConfig() {
	
	// https://techoverflow.net/2019/04/17/how-to-get-attribute-value-in-rapidxml/

	if (std::ifstream("Data/Config.xml").good()) 
	{

		try {
			rapidxml::file<> xmlFile("Data/Config.xml");
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());

			rapidxml::xml_node<>* rootnode = doc.first_node("MyHarvest");
			rapidxml::xml_node<>* confignode = rootnode->first_node("Config");
			rapidxml::xml_node<>* displaynode = confignode->first_node("Display");		
			rapidxml::xml_node<>* fontnode = confignode->first_node("Font");

			this->displayconfig.Width = atoi(displaynode->first_node("Width")->value());
			this->displayconfig.Height = atoi(displaynode->first_node("Height")->value());
			this->SelectorFont.size = atoi(fontnode->first_node("SelectorFont")->first_attribute("size")->value());
			this->SelectorFont.font = LoadFont(fontnode->first_node("SelectorFont")->first_attribute("path")->value());


			
			return true;
		}
		catch (const rapidxml::parse_error& e) {
			return false;
		}



	}
	return false;
}