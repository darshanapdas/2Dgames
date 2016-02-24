
//Rabidja 3 - nouvelle version intégralement en SDL 2.0
//Copyright / Droits d'auteur : www.meruvia.fr - Jérémie F. Bellanger


#include "prototypes.h"

GameObject player;
SDL_Texture *playerSpriteSheet;


//Renvoie le GameObject player (héros)
GameObject *getPlayer(void)
{
	return &player;
}


//Renvoie les coordonnées x du héros
int getPlayerx(void)
{
	return player.x;
}


//Renvoie les coordonnées y du héros
int getPlayery(void)
{
	return player.y;
}


//Change la valeur des coordonnées x du héros
void setPlayerx(int valeur)
{
	player.x = valeur;
}


//Change la valeur des coordonnées y du héros
void setPlayery(int valeur)
{
	player.y = valeur;
}




//Charge la spritesheet (=feuille de sprites) de notre héros
//au début du jeu
void initPlayerSprites(void)
{
	playerSpriteSheet = loadImage("graphics/cercle.png");
}


//Libère le sprite du héros à la fin du jeu
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

	//PV à 3
	player.life = 3;


	player.frameNumber = 0;
	//...la valeur de son chrono ou timer
	player.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;
	//... et son nombre de frames max (8 pour l'anim' IDLE
	// = ne fait rien)
	player.frameMax = 8;

	player.x = getBeginX();
	player.y = getBeginY();

	/* Hauteur et largeur de notre héros */
	player.w = PLAYER_WIDTH;
	player.h = PLAYER_HEIGTH;




}


void drawPlayer(void)
{
	/* Gestion du timer */
	// Si notre timer (un compte à rebours en fait) arrive à zéro
	if (player.frameTimer <= 0)
	{
		//On le réinitialise
		player.frameTimer = TIME_BETWEEN_2_FRAMES_PLAYER;

		//Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante
		player.frameNumber++;

		//Mais si on dépasse la frame max, il faut revenir à la première :
		if (player.frameNumber >= player.frameMax)
			player.frameNumber = 0;

	}
	//Sinon, on décrémente notre timer
	else
		player.frameTimer--;


	//Ensuite, on peut passer la main à notre fonction

	/* Rectangle de destination à dessiner */
	SDL_Rect dest;

	// On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
	//au scrolling :
	dest.x = player.x - getStartX();
	dest.y = player.y - getStartY();
	dest.w = player.w;
	dest.h = player.h;

	/* Rectangle source */
	SDL_Rect src;

	//Pour connaître le X de la bonne frame à dessiner, il suffit de multiplier
	//la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
	src.x = player.frameNumber * player.w;
	src.w = player.w;
	src.h = player.h;

}
