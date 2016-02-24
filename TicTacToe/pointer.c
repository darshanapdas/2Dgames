#include "prototypes.h"

Mouse mou;
SDL_Texture *MouseSprite;

//Renvoie le Mouse mou (héros)
Mouse *getmou(void)
{
	return &mou;
}


//Renvoie les coordonnées x du héros
int getmoux(void)
{
	return mou.x;
}


//Renvoie les coordonnées y du héros
int getmouy(void)
{
	return mou.y;
}


//Change la valeur des coordonnées x du héros
void setmoux(int valeur)
{
	mou.x = valeur;
}


//Change la valeur des coordonnées y du héros
void setmouy(int valeur)
{
	mou.y = valeur;
}

void initMouseSprites(void)
{
	MouseSprite = loadImage("graphics/mouse.png");

}

void drawMouse(void)
{
    	drawImage(MouseSprite, 15, 15);
}


void cleanmou(void)
{
	if (MouseSprite != NULL)
	{
		SDL_DestroyTexture(MouseSprite);
		MouseSprite = NULL;
	}
}

