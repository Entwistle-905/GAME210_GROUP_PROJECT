#pragma once

#include "SDL.h"
#include "SDL_image.h"


enum STATE
{
	STANDING,
	JUMPING
};

class Frog
{
public:
	Frog();
	~Frog();

	void setTexture(SDL_Texture* tex1);
	void setTexture(SDL_Texture* tex1, SDL_Texture* tex2);
	void setPosition(SDL_Rect pos);
	void setState(STATE st);
	void setDefaultHeight(int a);
	STATE getState() { return state; }

	void jump();
	void move();
	void display();
	void displayIcon();

private:
	SDL_Texture* texture;
	SDL_Texture* textures[2];
	SDL_Rect position = {};
	SDL_Rect velocity = {};

	STATE state;

	int defaultHeight;

};

