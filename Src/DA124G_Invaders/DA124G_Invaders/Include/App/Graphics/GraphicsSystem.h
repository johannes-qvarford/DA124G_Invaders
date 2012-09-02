#ifndef GRAPHICS_SYSTEM_H
#define GRAPHICS_SYSTEM_H
#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class GraphicsSystem
{
public:

	GraphicsSystem( sf::Window& window );
	~GraphicsSystem();

	void setBackground( const char* filename );
	sf::Sprite createSprite( const char* filename );
	void destroySprite( sf::Sprite sprite );

private:

	typedef std::list< sf::Sprite > SpriteList;

	SpriteList m_sprites;
};

extern GraphicsSystem g_gfx;
#endif