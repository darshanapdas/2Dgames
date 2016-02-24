#include "prototypes.h"

GameObject player;
SDL_Texture *playerSpriteSheet;

//Renvoie le GameObject player (h�ros)
GameObject *getPlayer(void) {
	return &player;
}


//Renvoie les coordonn�es x du h�ros
int getPlayerx(void) {
	return player.x;
}


//Renvoie les coordonn�es y du h�ros
int getPlayery(void) {
	return player.y;
}


//Change la valeur des coordonn�es x du h�ros
void setPlayerx(int valeur) {
	player.x = valeur;
}


//Change la valeur des coordonn�es y du h�ros
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
