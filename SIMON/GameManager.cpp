#include "GameManager.h"
#include <stdlib.h>


GameManager::GameManager() 
{

}

GameManager::~GameManager()
{

}


void GameManager::randomText()
{
	//srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		randomNums.push(rand() % 5);
	}

	for (int i = 0; i < 5; i++)
	{
		//randomTexts[i] = checkInput(randomNums[i]);
	}
}

TEXT GameManager::checkInput(int a)
{
	switch (a)
	{
	case 0:
		return LT;
	case 1:
		return LB;
	case 2:
		return A;
	case 3:
		return RB;
	case 4:
		return RT;
	}
}

void GameManager::printRandomText()
{
	for (int i = 0; i < 5; i++)
	{
		//if (randomTexts[i] == LT)
		//	Graphics::LoadFrogIcon(frogIcons, 0, 30 + i * , 80);
		//else if (randomTexts[i] == LB)
		//	Graphics::printText("LB", 30 + i * 50, 80, 50, 30);
		//else if (randomTexts[i] == A)
		//	Graphics::printText(" A ", 30 + i * 50, 80, 50, 30);
		//else if (randomTexts[i] == RB)
		//	Graphics::printText("RB", 30 + i * 50, 80, 50, 30);
		//else if (randomTexts[i] == RT)
		//	Graphics::printText("RT", 30 + i * 50, 80, 50, 30);

		if (randomTexts[i] == LT)
			Graphics::printText("LT", 30 + i * 50, 80, 50, 30);
		else if (randomTexts[i] == LB)
			Graphics::printText("LB", 30 + i * 50, 80, 50, 30);
		else if (randomTexts[i] == A)
			Graphics::printText(" A ", 30 + i * 50, 80, 50, 30);
		else if (randomTexts[i] == RB)
			Graphics::printText("RB", 30 + i * 50, 80, 50, 30);
		else if (randomTexts[i] == RT)
			Graphics::printText("RT", 30 + i * 50, 80, 50, 30);
		
	}
}

void GameManager::jumpFrogs()
{
	//bool allStanding = false;

	for (int i = 0; i < 5; i++)
	{
		if (allStanding() && !randomNums.empty())		// add exception
		{
			if (randomNums.front() == LT)
				frogs[0].jump();
			else if (randomNums.front() == LB)
				frogs[1].jump();
			else if (randomNums.front() == A)
				frogs[2].jump();
			else if (randomNums.front() == RB)
				frogs[3].jump();
			else if (randomNums.front() == RT)
				frogs[4].jump();

			randomNums.pop();
		}

		frogs[i].move();
		frogs[i].display();
		/*
		how can I make them jump only once? use bool variable?
		*/
	}
}

bool GameManager::allStanding()
{
	for (int i = 0; i < 5; i++)
	{
		if (frogs[i].getState() == JUMPING)
		{
			return false;
		}
	}
	return true;
}

void GameManager::loadMedia()
{
	bgMusic = Mix_LoadMUS("./Resources/Oneul - when spring comes.mp3");
	if (bgMusic == NULL)
	{
		printf("Failed to load beat music! SDL_Mixer Error : %s\n", Mix_GetError());
		//return false;
	}

	gFrog = Mix_LoadWAV("./Resources/frog.mp3");
	if (gFrog == NULL)
	{
		printf("Failed to load sound effect! SDL_Mixer Error : %s\n", Mix_GetError());
		//return false;
	}
}


void GameManager::playMusic(Mix_Music* Music)
{

	// if there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(Music, -1);
	}
	else
	{
		// if the music is paused
		if (Mix_PausedMusic() == 1)
		{
			// resume the music
			Mix_ResumeMusic();
		}
		else // if the music is playing
		{
			Mix_PauseMusic();	// pause music
		}
	}

	// Mix_HaltMusic();		// stop the music

	//Mix_PlayChannel(-1, pika_fail, 0);
}


void GameManager::cleanUp()
{

	Graphics::cleanUpTTF();

	Mix_FreeChunk(gFrog);				// Free sound effect
	gFrog = NULL;

	Mix_FreeMusic(bgMusic);				// Free Music
	bgMusic = NULL;

	SDL_Quit();							// SDL2 itself
}