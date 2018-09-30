#include "Mesh2D.h"



void Mesh2D::initialise(int spriteWidth, int spriteHeight, int texWidth, int texHeight, int frameIndex)
{
	spriteWidthMesh = spriteWidth;
	spriteHeightMesh = spriteHeight;
	texWidthMesh = texWidth;
	texHeightMesh = texHeight;

	textureWidth = float(spriteWidthMesh) / texWidthMesh;
	textureHeight = float(spriteHeightMesh) / texHeightMesh;
	int numPerRow = texWidthMesh / spriteWidthMesh;
	textureX = (frameIndex % numPerRow) * textureWidth;
	textureY = (frameIndex / numPerRow + 1) * textureHeight;

	GLuint VBO;
	GLuint EBO;
	GLfloat vertices[] = {
		// Positions               // Colors             // Tex Coords
		-0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX,                textureY,                 // Top Left
		-0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY,                 // Bottom Left
		 0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY + textureHeight, // Bottom Right
		 0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,	    textureX, textureY + textureHeight                 // Top Right
	};

	GLuint indices[] =
	{
		0, 1, 2,  //Right Triangle
		0, 2, 3 //Left Triangle

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); // Bind VAO 

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)( 3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void Mesh2D::update(int frameIndex, int animationIndex, bool isInAction)
{
	if (animationIndex != 0)
	{
		if (isInAction)
		{
			int numPerRow = texWidthMesh / spriteWidthMesh;
			if (textureX >= 0.85)
			{
				setIsAnimationComplete(true);
				return;
			}
		}

		if (animationIndex == 1)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 4 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 2)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 1 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 3)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 2 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 4)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 3 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 5)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 5 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 6)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 6 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 7)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 7 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 8)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 8 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 9)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 9 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 10)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 10 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 11)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 11 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 12)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 12 * textureHeight;
			setIsAnimationComplete(false);
		}
		if (animationIndex == 13)
		{
			int spriteIndex = frameIndex * 0.15;
			int numPerRow = texWidthMesh / spriteWidthMesh;
			textureX = (spriteIndex % numPerRow) * textureWidth;
			textureY = 13 * textureHeight;
			setIsAnimationComplete(false);
		}
		

		//if (textureX > 300)
		//{
		//	textureX = 0;
		//}

		GLuint VBO;
		GLuint EBO;

		GLfloat vertices[] = {
			// Positions               // Colors             // Tex Coords
			-0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX,                textureY,                 // Top Left
			-0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY,                 // Bottom Left
			 0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY + textureHeight, // Bottom Right
			 0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,	    textureX, textureY + textureHeight                 // Top Right
		};


		GLuint indices[] =
		{
			0, 1, 2,  //Right Triangle
			0, 2, 3 //Left Triangle

		};

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO); // Bind VAO 

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}
}

const GLuint Mesh2D::getVAO()
{
	return VAO;
}

void Mesh2D::setIsAnimationComplete(bool isComplete)
{
	isAnimationComplete = isComplete;
}

bool Mesh2D::getIsAnimationComplete()
{
	return isAnimationComplete;
}


Mesh2D::Mesh2D()
{
}


Mesh2D::~Mesh2D()
{
}
