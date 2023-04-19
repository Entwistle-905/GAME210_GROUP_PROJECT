#include "Graphics.h"

SDL_Window* Graphics::window;
SDL_Renderer* Graphics::renderer;
SDL_Texture* Graphics::texture;

bool Graphics::Init()
{
	const int WINDOW_WIDTH = 960;
	const int WINDOW_HEIGHT = 665;

	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	// create little window with minimize and x to close 
	window = SDL_CreateWindow("Basic SDL Project",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (!window)
	{
		return false;
	}

	// fill in that window with a virtual canvas to draw on called a renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		return false;
	}

	TTF_Init();

	return true;
}

SDL_Renderer* Graphics::getRenderer()
{
	return renderer;
}


void Graphics::StartRender()
{
	// clear the screen color
	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	SDL_Surface* bg;
	bg = IMG_Load("./Resources/background.png");
	texture = SDL_CreateTextureFromSurface(renderer, bg);
	SDL_FreeSurface(bg);

	SDL_Rect bgPos;
	bgPos.x = 0;
	bgPos.y = 0;
	bgPos.w = 960;
	bgPos.h = 665;

	SDL_RenderCopy(renderer, texture, NULL, &bgPos);

}



void Graphics::LoadFrog(Frog frog[])
{
	SDL_Surface* frogsStanding[5];
	frogsStanding[0] = IMG_Load("./Resources/frog1_standing.png");
	frogsStanding[1] = IMG_Load("./Resources/frog2_standing.png");
	frogsStanding[2] = IMG_Load("./Resources/frog3_standing.png");
	frogsStanding[3] = IMG_Load("./Resources/frog4_standing.png");
	frogsStanding[4] = IMG_Load("./Resources/frog5_standing.png");
	
	SDL_Surface* frogsJumping[5];
	frogsJumping[0] = IMG_Load("./Resources/frog1_jumping.png");
	frogsJumping[1] = IMG_Load("./Resources/frog2_jumping.png");
	frogsJumping[2] = IMG_Load("./Resources/frog3_jumping.png");
	frogsJumping[3] = IMG_Load("./Resources/frog4_jumping.png");
	frogsJumping[4] = IMG_Load("./Resources/frog5_jumping.png");

	SDL_Texture* texture2;

	for (int i = 0; i < 5; i++)
	{
		texture = SDL_CreateTextureFromSurface(renderer, frogsStanding[i]);
		texture2 = SDL_CreateTextureFromSurface(renderer, frogsJumping[i]);
		SDL_FreeSurface(frogsStanding[i]);
		SDL_FreeSurface(frogsJumping[i]);

		SDL_Rect frogPos;
		frogPos.x = 117 + 155 * i;
		//frogPos.y = 385;
		
		if (i % 4 == 2)
		{
			frogPos.y = 385 - 20 * 2;
		}
		else if (i % 4 == 1 || i % 4 == 3)
		{
			frogPos.y = 385 - 20 * 1;
		}
		else if (i % 4 == 0)
		{
			frogPos.y = 385;
		}


		frog[i].setDefaultHeight(frogPos.y);
		frog[i].setPosition(frogPos);
		frog[i].setTexture(texture, texture2);
	}
}



void Graphics::LoadFrogIcon(Frog frogIcon, int x, int y, int n)
{
	SDL_Surface* surf;
	if (n == 0)
		surf = IMG_Load("./Resources/frog1_head.png");
	else if (n == 1)
		surf = IMG_Load("./Resources/frog2_head.png");
	else if (n == 2)
		surf = IMG_Load("./Resources/frog3_head.png");
	else if (n == 3)
		surf = IMG_Load("./Resources/frog4_head.png");
	else
		surf = IMG_Load("./Resources/frog5_head.png");

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);

	SDL_Rect IconPos;
	IconPos.x = x;
	IconPos.y = y;

	frogIcon.setPosition(IconPos);
	frogIcon.setTexture(texture);
	
}


void Graphics::SetColor(Colour color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0xFF);
}

void Graphics::DrawRect(Transform2D transform, Vec2D dimensions, bool isFilled)
{
	SDL_Rect Bounds;
	Bounds.x = transform.position.x;
	Bounds.y = transform.position.y;
	Bounds.w = dimensions.x;
	Bounds.h = dimensions.y;

	if (isFilled)
	{
		SDL_RenderFillRect(renderer, &Bounds);
	}
	else
	{
		SDL_RenderDrawRect(renderer, &Bounds);
	}
}

void Graphics::DrawLine(Transform2D transform, Vec2D dimensions)
{
	SDL_Rect Bounds;
	Bounds.x = transform.position.x;
	Bounds.y = transform.position.y;
	Bounds.w = dimensions.x;
	Bounds.h = dimensions.y;

	SDL_RenderDrawLine(renderer, transform.position.x, transform.position.y, dimensions.x, dimensions.y);
}

void Graphics::EndRender() 
{
	SDL_RenderPresent(renderer);
	// wait 2 frames
	SDL_Delay(2);
}

// example based on the code from: https://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2
void Graphics::printText(const char * text, float x, float y, int width, int height)
{
	TTF_Font* font = TTF_OpenFont("./Resources/Mario-kart-DS.ttf", 24);

	SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, White);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = x;  
	Message_rect.y = y; 
	Message_rect.w = width; 
	Message_rect.h = height; 

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void Graphics::cleanUpTTF()
{
	//TTF_CloseFont(font);				// Close font
	TTF_Quit();
}
