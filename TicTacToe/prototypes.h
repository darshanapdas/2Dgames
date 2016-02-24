#include "structs.h"

#ifndef PROTOTYPES
#define PROTOTYPES


//extern void changeLevel(void);
extern void cleanMaps(void);
extern void cleanPlayer(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern void drawImage(SDL_Texture *, int, int);
//extern void drawMap(int);
extern void drawPlayer(void);
//extern void drawTile(SDL_Texture *image, int destx, int desty, int srcx, int srcy);
extern void gestionInputs(int *turn, Input *input);
extern SDL_Texture *getBackground(void);
extern int getBeginX(void);
extern int getBeginY(void);
extern void getInput(Input *input);
extern void drawStartAIMenu(void);
extern int getMaxX(void);
extern int getMaxY(void);
extern GameObject *getPlayer(void);
extern int getPlayerDirection(void);
extern int getPlayerx(void);
extern int getPlayery(void);
extern SDL_Renderer *getrenderer(void);
extern int getStartX(void);
extern int getStartY(void);
extern void cleanmou(void);
extern void drawMouse(void);
extern void initMouseSprites(void);
extern int getmoux(void);
extern int getmouy(void);
extern void init(char *);
//extern void initializePlayer(void);
extern void initMaps(void);
extern void initPlayerSprites(void);
extern void loadGame(void);
extern SDL_Texture *loadImage(char *name);
//extern void loadMap(char *name);
extern void setNombreDeVies(int valeur);
extern void setNombreDetoiles(int valeur);
extern void loadFont(char *name, int size);

//extern void SetValeurDuNiveau(int valeur);
extern int checkWinner(int turn, int inputValue);
#endif
