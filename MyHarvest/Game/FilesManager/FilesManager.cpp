#include "FilesManager.h"
#include "../../GameEngine/xml/src/rapidxml.hpp"
#include <fstream>
#include <string>
bool FilesManager::HadAsset() {
	return std::ifstream("Data/Asset.xml").good();
 
}
bool FilesManager::HadConfig() {
	return std::ifstream("Data/Config.xml").good();

}
bool FilesManager::HadSave() {
	return std::ifstream("Data/Save.xml").good();
 
}
bool FilesManager::LoadConfig() {
	return std::ifstream("Data/Config.xml").good();

}