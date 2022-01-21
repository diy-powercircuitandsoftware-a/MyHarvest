#include "ReadXMLConfig.h"
#include "../../GameEngine/raylib/src/raylib.h"
  



bool ReadXMLConfig::LoadConfig() {
 
	if (!std::ifstream("Data/Config.xml").good()) return false;
	
		try {
			rapidxml::file<> xmlFile("Data/Config.xml");
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());
			rapidxml::xml_node<>* rootnode = doc.first_node("MyHarvest");
			if (rootnode == nullptr)return false;
			rapidxml::xml_node<>* confignode = rootnode->first_node("Config");
			if (rootnode == nullptr)return false;
			rapidxml::xml_node<>* displaynode = confignode->first_node("Display");
			if (displaynode == nullptr)return false;
			rapidxml::xml_node<>* gamedata = confignode->first_node("GameData");
			if (gamedata == nullptr|| gamedata->first_attribute("assetpath") == nullptr)return false;			
			rapidxml::xml_node<>* seasonsnode = gamedata->first_node("Seasons");
			if (seasonsnode == nullptr)return false;

			rapidxml::xml_node<>* fontnode = gamedata->first_node("Font");
			rapidxml::xml_node<>* titlenode = gamedata->first_node("Title");
			this->AssetPath = gamedata->first_attribute("assetpath")->value();
			this->DisplaySize= (Size) {
				atoi(displaynode->first_node("Width")->value()),
				atoi(displaynode->first_node("Height")->value())
			};
			
			
			for (rapidxml::xml_node<>* child = fontnode->first_node(); child != NULL; child = child->next_sibling())
			{
			 
				this->FontConfigList[child->name()] = std::pair<std::string, float>{
					std::string(child->first_attribute("path")->value()),
					std::stof(child->first_attribute("size")->value()) };
				  
			}

			if (titlenode != nullptr) {
				rapidxml::xml_node<>* maintitlenode = titlenode->first_node("Main");
				if (maintitlenode != nullptr) {
					for (rapidxml::xml_attribute<>* attr = maintitlenode->first_attribute();
						attr; attr = attr->next_attribute())
					{
						this->TitleConfig[std::string(maintitlenode->name()) +"_" + attr->name()] = attr->value();						 
					}
					
				}
			}
			

			/*
			  
			if (confignode->first_node("GameData") != nullptr) {
				 
				 
				
				this->SeasonsIcon.Path = std::string(seasonsnode->first_attribute("path")->value());
				this->SeasonsIcon.Spring = (Rectangle){
					std::stof(fontnode->first_node("Spring")->first_attribute("x")->value()),
					std::stof(fontnode->first_node("Spring")->first_attribute("y")->value()),
					std::stof(fontnode->first_node("Spring")->first_attribute("width")->value()),
					std::stof(fontnode->first_node("Spring")->first_attribute("height")->value())
				};
				this->SeasonsIcon.Summer = (Rectangle){
					std::stof(fontnode->first_node("Summer")->first_attribute("x")->value()),
					std::stof(fontnode->first_node("Summer")->first_attribute("y")->value()),
					std::stof(fontnode->first_node("Summer")->first_attribute("width")->value()),
					std::stof(fontnode->first_node("Summer")->first_attribute("height")->value())
				};
				this->SeasonsIcon.Autumnand = (Rectangle){
					std::stof(fontnode->first_node("Autumnand")->first_attribute("x")->value()),
					std::stof(fontnode->first_node("Autumnand")->first_attribute("y")->value()),
					std::stof(fontnode->first_node("Autumnand")->first_attribute("width")->value()),
					std::stof(fontnode->first_node("Autumnand")->first_attribute("height")->value())
				};
				this->SeasonsIcon.Winter = (Rectangle){
					std::stof(fontnode->first_node("Winter")->first_attribute("x")->value()),
					std::stof(fontnode->first_node("Winter")->first_attribute("y")->value()),
					std::stof(fontnode->first_node("Winter")->first_attribute("width")->value()),
					std::stof(fontnode->first_node("Winter")->first_attribute("height")->value())
				};

			}		
			*/
			
			return true;
		}
		catch (const rapidxml::parse_error& e) {
			return false;
		}	
	
}
/*
void ReadXMLConfig::UpdateFont() {
	this->SelectorFont.UpdateFont();
	this->TitleFont.UpdateFont();
	this->LabelFont.UpdateFont();
}
*/
