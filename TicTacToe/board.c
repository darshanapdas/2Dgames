#include "prototypes.h"

GameObject player;
SDL_Texture *playerSpriteSheet;

//Renvoie le GameObject player (héros)
GameObject *getPlayer(void) {
	return &player;
}


//Renvoie les coordonnées x du héros
int getPlayerx(void) {
	return player.x;
}


//Renvoie les coordonnées y du héros
int getPlayery(void) {
	return player.y;
}


//Change la valeur des coordonnées x du héros
void setPlayerx(int valeur) {
	player.x = valeur;
}


//Change la valeur des coordonnées y du héros
void setPlayery(int valeur) {
	player.y = valeur;
}

void initPlayerSprites(void) {
	playerSpriteSheet = loadImage("graphics/PlayingField.png");
}

SDL_Texture* getBoard() {
    return playerSpriteSheet;
}



void cleanPlayer(void)
{
	if (playerSpriteSheet != NULL)
	{
		SDL_DestroyTexture(playerSpriteSheet);
		playerSpriteSheet = NULL;
	}
}
