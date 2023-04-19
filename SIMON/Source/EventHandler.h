#pragma once

#include <Windows.h>
#include <Xinput.h>

#include "SDL.h"
#include "../GameManager.h"

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	static void Update(GameManager* gm);

	static XINPUT_STATE controller;
};


