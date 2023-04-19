// processing events
#include "EventHandler.h"
#include <ctime>
// creating a basic gameobject
#include "Objects/ColourBlock.h"
#include "../Graphics.h"
#include "../GameManager.h"


// GameState
bool GameRunning = true;

// argc and argv here are command line parameters passed to the program when running the program. 
// we won't actually use them but our 2D Graphics Library requires the main setup like this.
// Argc: the number of arguments pass
// argv[] : a char array of each of the params passed in ( each space is a new param)
int main( int argc, char *argv[] )
{
	srand(time(NULL));

	if (!Graphics::Init())
	{
		return false;
	}

	GameManager manager;

	Graphics::StartRender();

	Graphics::LoadFrog(manager.frogs);
	for (int i = 0; i < 5; i++)
	{
		manager.frogs[i].setState(STANDING);
		manager.frogs[i].display();
	}

	manager.randomText();
	//manager.printRandomText();

	// Main game loop
	while (GameRunning) 
	{
		Graphics::StartRender();
		// handle button events
		EventHandler::Update(&manager);

		//manager.printRandomText();
		manager.jumpFrogs();

		Graphics::printText("score ", 30, 20, 120, 30);

		// apply the changes to the screen 
		Graphics::EndRender();

		SDL_Delay(150);
	}

	//close off the SDL window
	manager.cleanUp();

	return true;
}
