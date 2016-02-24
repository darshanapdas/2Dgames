
//Rabidja 3 - nouvelle version int�gralement en SDL 2.0
//Copyright / Droits d'auteur : www.meruvia.fr - J�r�mie F. Bellanger


#include "prototypes.h"

GameObject player;
SDL_Texture *playerSpriteSheet;


//Renvoie le GameObject player (h�ros)
GameObject *getPlayer(void)
{
	return &player;
}


//Renvoie les coordonn�es x du h�ros
int getPlayerx(void)
{
	return player.x;
}


//Renvoie les coordonn�es y du h�ros
int getPlayery(void)
{
	return player.y;
}


//Change la valeur des coordonn�es x du h�ros
void setPlayerx(int valeur)
{
	player.x = valeur;
}


//Change la valeur des coordonn�es y du h�ros
void setPlayery(int valeur)
{
	player.y = valeur;
}




//Charge la spritesheet (=feuille de sprites) de notre h�ros
//au d�but du jeu
void initPlayerSprites(void)
{
	playerSpriteSheet = loadImage("graphics/cercle.png");
}


//Lib�re le sprite du h�ros � la fin du jeu
void cleanPlayer(void)
{
	if (playerSpriteSheet != NULL)
	{
		SDL_DestroyTexture(playerSpriteSheet);
		playerSpriteSheet = NULL;
	}
}


void initializePlayer(void)
{

	//PV � 3
	player.life = 3;


	player.frameNumber = 0;
	//...la valeur de son chrono ou timer
	player.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
	//... et son nombre de frames max (8 pour l'anim' IDLE
	// = ne fait rien)
	player.frameMax = 8;

	player.x = getBeginX();
	player.y = getBeginY();

	/* Hauteur et largeur de notre h�ros */
	player.w = PLAYER_WIDTH;
	player.h = PLAYER_HEIGTH;




}


void drawPlayer(void)
{
	/* Gestion du timer */
	// Si notre timer (un compte � rebours en fait) arrive � z�ro
	if (player.frameTimer <= 0)
	{
		//On le r�initialise
		player.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;

		//Et on incr�mente notre variable qui compte les frames de 1 pour passer � la suivante
		player.frameNumber++;

		//Mais si on d�passe la frame max, il faut revenir � la premi�re :
		if (player.frameNumber >= player.frameMax)
			player.frameNumber = 0;

	}
	//Sinon, on d�cr�mente notre timer
	else
		player.frameTimer--;


	//Ensuite, on peut passer la main � notre fonction

	/* Rectangle de destination � dessiner */
	SDL_Rect dest;

	// On soustrait des coordonn�es de notre h�ros, ceux du d�but de la map, pour qu'il colle
	//au scrolling :
	dest.x = player.x - getStartX();
	dest.y = player.y - getStartY();
	dest.w = player.w;
	dest.h = player.h;

	/* Rectangle source */
	SDL_Rect src;

	//Pour conna�tre le X de la bonne frame � dessiner, il suffit de multiplier
	//la largeur du sprite par le num�ro de la frame � afficher -> 0 = 0; 1 = 40; 2 = 80...
	src.x = player.frameNumber * player.w;
	src.w = player.w;
	src.h = player.h;

}
