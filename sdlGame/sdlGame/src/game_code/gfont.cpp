#include "gfont.hpp"

GFont::GFont()
{};

GFont::GFont(SDL_Renderer *renderer, int size, std::string text, int x, int y, SDL_Color textCol) : size(size), text(text)
{
	TTF_Font *font = TTF_OpenFont(this->fontPath.c_str(), size);
	if (font == NULL) {
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
	}

	SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), textCol);

	this->textRect = { x, y, surface->w, surface->h };

	fontTex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

GFont::~GFont()
{

}

void GFont::setTextPos(int x, int y)
{
	this->textRect.x = x;
	this->textRect.y = y;
}

SDL_Rect *GFont::getTextRect()
{
	return &this->textRect;
}

void GFont::draw(SDL_Renderer *renderer, SDL_Rect *camRect) {

	SDL_Rect drawingRect = { this->textRect.x - camRect->x, this->textRect.y - camRect->y, this->textRect.w,
		this->textRect.h };

	SDL_RenderCopyEx(renderer, this->fontTex, NULL, &drawingRect, 0.0f, nullptr, SDL_FLIP_NONE);
}

void GFont::destroyFont()
{
	SDL_DestroyTexture(fontTex);
}