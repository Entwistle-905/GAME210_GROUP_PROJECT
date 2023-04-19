#pragma once

#include <queue>

#include "Graphics.h"
#include "SDL_Mixer.h"
#include "Frog.h"

enum TEXT
{
	LT,
	LB,
	A,
	RB,
	RT
};

class GameManager
{
public:
	GameManager();
	~GameManager();

	TEXT checkInput(int a);
	void randomText();
	void printRandomText();
	void jumpFrogs();
	bool allStanding();

	void loadMedia();
	void playMusic(Mix_Music* Music);

	void cleanUp();

	Frog frogs[5];
	Frog frogIcons[5];

	Mix_Music* bgMusic = NULL;			// Background music
	Mix_Chunk* gFrog = NULL;

private:
	queue<int> randomNums;
	int randomTexts[5];

};

