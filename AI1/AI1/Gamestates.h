#pragma once
class gamestates
{
public:
	enum states

	{
		Menu,
		Play,
		Exit
	};
	bool transitioning = false;
	int currentState;
};