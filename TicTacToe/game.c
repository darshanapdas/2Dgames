#include "prototypes.h"

Circle circleObj;
Cross crossObj;
Message Xwins, Owins;
SDL_Texture *circ_img, *cross_img, *Xwins_img, *Owins_img;

void initCircle(void) {
	circ_img = loadImage("graphics/cercle.png");
}

void initCross(void) {
	cross_img = loadImage("graphics/cross.png");
}

void initXwins(void) {
	Xwins_img = loadImage("graphics/Xwins.png");
}

void initOwins(void) {
	Owins_img = loadImage("graphics/Owins.png");
}

SDL_Texture* getCircle() {
    return circ_img;
}

SDL_Texture* getCross() {
    return cross_img;
}

SDL_Texture* getXwins() {
    return Xwins_img;
}

SDL_Texture* getOwins() {
    return Owins_img;
}
