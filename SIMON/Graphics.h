#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "../Source/Objects/ObjData.h"
#include "Frog.h"


class Graphics
{
public:
	// should be called only once on boot.
	static bool Init();

	// needs to be called once at the start and end of game loops rendering
	static void StartRender();
	static void EndRender();

	static void LoadFrog(Frog frog[]);
	static void LoadFrogIcon(Frog frogIcon, int x, int y, int n);

	//drawing specific functions
	static void SetColor(Colour color);
	static void DrawRect(Transform2D transform, Vec2D dimensions, bool isFilled = false);
	static void DrawLine(Transform2D transform, Vec2D dimensions);
	static void printText(const char* text, float x, float y, int width, int height);

	static void cleanUpTTF();

	static SDL_Renderer* getRenderer();

private:
	// some SDL specific variables:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static SDL_Texture* texture;

};

