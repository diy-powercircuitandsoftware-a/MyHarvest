#include "FilesManager.h"
#include "../../GameEngine/xml/src/rapidxml_utils.hpp"
 

bool FilesManager::HadAsset() {
	return false;
}
bool FilesManager::HadConfig() {
	return std::ifstream("Data/Config.xml").good();
}
bool FilesManager::HadSave() {
	return std::ifstream("Data/Save.xml").good();
}
bool FilesManager::LoadConfig() {
	//https://gamedev.net/forums/topic/666611-reading-xml-files-with-rapidxml/5216620/
	// https://techoverflow.net/2019/04/17/how-to-get-attribute-value-in-rapidxml/
	rapidxml::file<> xmlFile("Data/Config.xml"); 
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());
	 
	rapidxml::xml_node<>* rootnode = doc.first_node("MyHarvest");
	rapidxml::xml_node<>* confignode = rootnode->first_node("Config");
	rapidxml::xml_node<>* displaynode = confignode->first_node("Display");
	this->displayconfig.FontSize = atoi( displaynode->first_node("FontSize")->value());
	this->displayconfig.Width = atoi(displaynode->first_node("Width")->value());
	this->displayconfig.Height = atoi(displaynode->first_node("Height")->value());
	return true;

}