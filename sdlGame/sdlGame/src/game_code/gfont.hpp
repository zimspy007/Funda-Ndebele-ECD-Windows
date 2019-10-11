#ifndef _GFONT_HPP
#define _GFONT_HPP

#include "game.hpp"
#include "sdl_vector.hpp"

class GFont{
public:
	GFont();

	GFont(SDL_Renderer *renderer, int size, std::string text, int x, int y, SDL_Color textCol);

	~GFont();

	void setTextPos(int x, int y);

	SDL_Rect *getTextRect();

	void draw(SDL_Renderer *renderer, SDL_Rect *camRect);

	void destroyFont();
		
private:	
	SDL_Texture *fontTex;

	SDL_Rect textRect;
	
	std::string text;

	std::string fontPath = "media/fonts/arial.ttf";

	int size = 24;
};

#endif