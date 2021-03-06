//Rabidja 3 - nouvelle version int�gralement en SDL 2.0
//Copyright / Droits d'auteur : www.meruvia.fr - J�r�mie F. Bellanger


#include "prototypes.h"


SDL_Window *screen;
SDL_Renderer *renderer;


SDL_Renderer *getrenderer(void) {
	return renderer;
}




void init(char *title) {
	/* On cr�e la fen�tre, repr�sent�e par le pointeur jeu.window en utilisant la largeur et la
	hauteur d�finies dans les defines (defs.h).
	Nouveaut�s SDL2 : on peut centrer la fen�tre avec SDL_WINDOWPOS_CENTERED, et choisir la taille
	de la fen�tre, pour que la carte graphique l'agrandisse automatiquement. Notez aussi qu'on peut
	maintenant cr�er plusieurs fen�tres. */

	screen = SDL_CreateWindow(title,
		                          SDL_WINDOWPOS_CENTERED,
								  SDL_WINDOWPOS_CENTERED,
								  SCREEN_WIDTH, SCREEN_HEIGHT,
								  SDL_WINDOW_SHOWN);

	//On cr�e un renderer pour la SDL et on active la synchro verticale : VSYNC
	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

	// Si on n'y arrive pas, on quitte en enregistrant l'erreur dans stdout.txt
    if (screen == NULL || renderer == NULL)
    {
        printf("Unable to initialize screen %d x %d: %s\n", SCREEN_WIDTH,
				                                                    SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

	//Initialisation du chargement des images png avec SDL_Image 2
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image n'a pu �tre initialis�e! SDL_image Error: %s\n", IMG_GetError() );
		exit(1);
	}

	//On cache le curseur de la souris
	SDL_ShowCursor(SDL_DISABLE);

	//On initialise SDL_TTF 2 qui g�rera l'�criture de texte
	if (TTF_Init() < 0)
	{
		printf("Impossible d'initialiser SDL TTF: %s\n", TTF_GetError());
		exit(1);
	}
    loadFont("font/GenBasB.ttf", 32);
	//On initialise SDL_Mixer 2, qui g�rera la musique et les effets sonores
	int flags = MIX_INIT_MP3;
	int initted = Mix_Init(flags);
	if ((initted & flags) != flags)
	{
		printf("Mix_Init: Failed to init SDL_Mixer\n");
		printf("Mix_Init: %s\n", Mix_GetError());
		exit(1);
	}

	/* Open 44.1KHz, signed 16bit, system byte order,
	stereo audio, using 1024 byte chunks (voir la doc pour plus d'infos ;) ) */
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		exit(1);
	}

	// D�finit le nombre de pistes audio (channels) � mixer
	Mix_AllocateChannels(32);

}

void loadGame(void)
{

	initMaps();
	initMenus();
    initPlayerSprites();
    initCircle();
    initCross();
    initOwins();
    initXwins();

    setOnMenu(1);
}


void cleanup()
{

	cleanMaps();

	Mix_CloseAudio();
	Mix_Quit();

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(screen);
	screen = NULL;

	TTF_Quit();
	SDL_Quit();

}



