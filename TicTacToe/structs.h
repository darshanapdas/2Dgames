#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

typedef struct Input {

	int value,enter, del, pause, quit, resume, down, up, right, left;

} Input;

typedef struct Map {

	SDL_Texture *background;
    int beginx, beginy;

	int startX, startY;

	int maxX, maxY;
	int mapTimer;

} Map;

typedef struct GameObject {
    int x, y;
	int h, w;
} GameObject, Circle, Cross, Message;



#endif


