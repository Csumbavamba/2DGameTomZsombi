#include "GameMenu.h"
#include "TextLabel.h"
#include "Input.h"
#include "GameManager.h"
#include "BoxCollider.h"

// Matrix calculators
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

GameMenu::GameMenu() {};

GameMenu::GameMenu(std::string menuTitle1, std::string menuTitle2)
{
	std::string font = "Dependencies/Fonts/SnackerComic.ttf";

	firstClicked = false;
	secondClicked = false;

	startButton = new TextLabel(menuTitle1, font, glm::vec2(-40.0f, 100.0f));
	quitButton = new TextLabel(menuTitle2, font, glm::vec2(-20.0f, -100.0f));
}



GameMenu::~GameMenu()
{
	delete startButton;
	startButton = NULL;

	delete quitButton;
	quitButton = NULL;
}

void GameMenu::Initialise()
{
	startButton->Initialise();
	quitButton->Initialise();
}

void GameMenu::Render(GLuint program)
{
	startButton->Render();
	quitButton->Render();
}

void GameMenu::Update(float deltaTime)
{
	// Get the location of the mouse
	glm::vec2 mousePosition = Input::GetMousePosition();
	glm::vec3 mouseTransformedPosition = glm::vec3(mousePosition.x, mousePosition.y, 0.0f);


	// If the location of the mouse collide with Start --> change to Game Mode
	if (startButton->GetCollider()->IsColliding(mouseTransformedPosition))
	{
		// If Mouse clicked
		if (Input::GetMouseState(MOUSE_LEFT) == DOWN)
		{
			// Change Menu state
			firstClicked = true;
		}
	}

	// If the location of the mouse collide with Quit --> Quit Game
	if (quitButton->GetCollider()->IsColliding(mouseTransformedPosition))
	{
		// If mouse clicked
		if (Input::GetMouseState(MOUSE_LEFT) == DOWN)
		{
			// Quit game
			secondClicked = true;
		}
	}
}

bool GameMenu::FirstClicked() const
{
	return firstClicked;
}

bool GameMenu::SecondClicked() const
{
	return secondClicked;
}

void GameMenu::Reset()
{
	firstClicked = false;
	secondClicked = false;
}
