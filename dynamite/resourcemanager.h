/**
*	Filename: resourcemanager.h
*
*	Description: Main Header for ResourceManager.
*
*	Version: 15/11/2018
*
*	© 2018, Jens Heukers
*/


#pragma once
#include "renderer.h"
#include <iostream>
#include <map>

class Font; /// @brief Forward Declaration
class Texture; /// @brief Forward Declaration

class ResourceManager {
private:
	static ResourceManager* _instance; /// @brief the instance of the ResourceManager
	std::map<std::string, Texture*> textures; /// @brief the textures map
	std::map<std::string, Font*> fonts; /// @brief the fonts map

	/**
	* Constructor private due to singleton
	*/
	ResourceManager() {};
public:

	/**
	* Get the ResourceManager Singleton Instance.
	*/
	static ResourceManager* Instance();

	/**
	* Returns Surface if found, otherwise creates a new entry then returns, If allocate is true, it will allocate new memory for the resource
	*/
	Texture* GetTexture(std::string path, bool allocate);

	/**
	* Creates a font based on bitmapPath & csvFile then adds it to map, returns true if success else returns false
	* the first parameter tag will define on wich name it will be stored in the fonts map.
	*/
	bool AddFont(std::string tag,std::string bitmapPath, std::string csvFile);

	/**
	* Returns true if found else returns false
	*/
	bool HasFont(std::string tag);

	/**
	* Returns the font that matches name in the fonts map.
	*/
	Font* GetFont(std::string tag);
};