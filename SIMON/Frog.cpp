#include "Frog.h"
#include "Graphics.h"


Frog::Frog()
{

};

Frog::~Frog()
{

};

void Frog::setTexture(SDL_Texture* tex1)
{
	texture = tex1;
}

void Frog::setTexture(SDL_Texture* tex1, SDL_Texture* tex2)
{
	textures[0] = tex1;
	textures[1] = tex2;
}


void Frog::setPosition(SDL_Rect pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Frog::setState(STATE st)
{
	state = st;
}

void Frog::setDefaultHeight(int a)
{
	defaultHeight = a;
}

void Frog::jump()
{
	if (state == STANDING)
	{
		// set the velocity y
		velocity.y = 20;
		state = JUMPING;
	}

}

void Frog::move()
{
	position.y -= velocity.y;
	velocity.y -= 4;

	if (position.y >= defaultHeight)
	{
		velocity.y = 0;
		state = STANDING;
	}
}

void Frog::display()
{
	if (state == STANDING)
	{
		position.w = 110;
		position.h = 130;
	}
	else if (state == JUMPING)
	{
		position.w = 110;
		position.h = 135;
	}

	SDL_RenderCopy(Graphics::getRenderer(), textures[state], NULL, &position);
}

void Frog::displayIcon()
{
	position.w = 100;
	position.h = 75;

	SDL_RenderCopy(Graphics::getRenderer(), textures[state], NULL, &position);
}

