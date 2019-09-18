#ifndef FONT_H
#define FONT_H

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Singleton.h"
#include "Config.h"

class FontManager : public ResourceManager<FontManager , sf::Font> 
	, public Singleton<FontManager>
{

	friend Singleton<FontManager>;

private:
	sf::Font* loadResource(const std::string& path);
	FontManager() :ResourceManager(DataConfig::ConfigPathResource::font_config) {};

};

#endif // !FONT_H