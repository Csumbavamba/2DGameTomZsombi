#pragma once

#include "GameObject.h"

class TextLabel;


class GameMenu : public GameObject // TODO - Get rid of memory leak
{
public:
	GameMenu();
	GameMenu(std::string menuTitle1, std::string menuTitle2);
	~GameMenu();

	void Initialise();
	void Render(GLuint program);
	void Update(float deltaTime);

	bool FirstClicked() const;
	bool SecondClicked() const;
	void Reset();


private:

	bool firstClicked;
	bool secondClicked;

	TextLabel * startButton = NULL;
	TextLabel * quitButton = NULL;
};

