#include "prototypes.h"

Map map;

void initMaps(void) {
	map.background = loadImage("graphics/background.png");
    map.mapTimer = TIME_BETWEEN_2_FRAMES * 3;
}

int getStartX(void) {
	return map.startX;
}

void setStartX(int valeur) {
	map.startX = valeur;
}

int getStartY(void) {
	return map.startY;
}

void setStartY(int valeur) {
	map.startY = valeur;
}

int getMaxX(void) {
	return map.maxX;
}

int getMaxY(void) {
	return map.maxY;
}

int getBeginX(void) {
	return map.beginx;
}

int getBeginY(void) {
	return map.beginy;
}

SDL_Texture *getBackground(void) {
	return map.background;
}

void cleanMaps(void) {
	if (map.background != NULL) {
		SDL_DestroyTexture(map.background);
		map.background = NULL;
	}
}
