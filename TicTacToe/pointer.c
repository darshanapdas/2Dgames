#include "prototypes.h"

Mouse mou;
SDL_Texture *MouseSprite;

//Renvoie le Mouse mou (h�ros)
Mouse *getmou(void)
{
	return &mou;
}


//Renvoie les coordonn�es x du h�ros
int getmoux(void)
{
	return mou.x;
}


//Renvoie les coordonn�es y du h�ros
int getmouy(void)
{
	return mou.y;
}


//Change la valeur des coordonn�es x du h�ros
void setmoux(int valeur)
{
	mou.x = valeur;
}


//Change la valeur des coordonn�es y du h�ros
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

