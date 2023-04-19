#include "EventHandler.h"
#include <stdio.h>
#include <string.h>

XINPUT_STATE EventHandler::controller = {};

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::Update(GameManager* gm)
{
	

	ZeroMemory(&controller, sizeof(XINPUT_STATE));

	if (XInputGetState(0, &controller) == ERROR_SUCCESS)
	{
		bool Apressed = (controller.Gamepad.wButtons & XINPUT_GAMEPAD_A);
		bool RBpressed = (controller.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
		bool LBpressed = (controller.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
		bool RTpressed = (controller.Gamepad.bRightTrigger >= 128.0f);
		bool LTpressed = (controller.Gamepad.bLeftTrigger >= 128.0f);
	
		if (Apressed)
		{
			gm->frogs[2].jump();
		}
	}

	
}

