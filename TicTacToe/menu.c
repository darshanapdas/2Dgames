#include "prototypes.h"

int onMenu, choice,choice2,choice3;
SDL_Texture *titlescreen,*end;


int getOnMenu(void) {
	return onMenu;
}

void setOnMenu(int value) {
	onMenu = value;
}

void initMenus(void) {
    drawThing(getBackground(), 0, 0);
    char text[200];
    sprintf(text, "Tic Tac Toe");
    drawString(text,  310, 50, 0, 0, 0, 255);
}

void cleanMenus(void) {
	// Libère la texture de l'écran-titre
	if (titlescreen!= NULL) {
		SDL_DestroyTexture(titlescreen);
		titlescreen = NULL;
	}
}

void drawStartMenu(Input *input) {
    SDL_FreeSurface(getBackground());
    SDL_FreeSurface(getBoard());
    SDL_FreeSurface(getCircle());
    SDL_FreeSurface(getCross());


    drawImage(getBackground(), 0, 0);

    char text[200], text2[200];
    sprintf(text, "Play");
    drawString(text,  350, 200, 0, 0, 0, 255);

    sprintf(text2, "Quit");
    drawString(text2,  350, 250, 0, 0, 0, 255);
    SDL_Delay(1);
}


