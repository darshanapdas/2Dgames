
#include "prototypes.h"



/* Declaration of our font */
TTF_Font *font;


void loadFont(char *name, int size)
{
	/* Use SDL_TTF to load the font at the specified size */

	font = TTF_OpenFont(name, size);

	if (font == NULL)
	{
		printf("Failed to open Font %s: %s\n", name, TTF_GetError());
		exit(1);
	}

}


void closeFont(void)
{
	// Close the font once we're done with it

	if (font != NULL)
	{
		TTF_CloseFont(font);
	}
}


void drawString(char *text, int x, int y, int r, int g, int b, int a)
{
	SDL_Rect dest;
	SDL_Surface *surface; //To wrote text
	SDL_Texture *texture; //To convert the surface into a texture
	SDL_Color foregroundColor;

	/* color of the text in RGBA */
	foregroundColor.r = r;
	foregroundColor.g = g;
	foregroundColor.b = b;
	foregroundColor.a = a;


	// We use SDL_TTF to handle a  SDL_Surface from a  (string)
	surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);

	if (surface != NULL)
	{

		// Conversion of the image into a  texture
		texture = SDL_CreateTextureFromSurface(getrenderer(), surface);

		// On delete the pointer
		/* On free the SDL_Surface to avoid escape of memory */
		SDL_FreeSurface(surface);
		surface = NULL;

		// We draw this texture on the screen
		dest.x = x;
		dest.y = y;

		SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
		SDL_RenderCopy(getrenderer(), texture, NULL, &dest);
        SDL_RenderPresent(getrenderer());
		//We delete the texture
		SDL_DestroyTexture(texture);

	}
	else
	{
		printf("The string can't be wrote %s: %s\n", text, TTF_GetError());

		exit(0);
	}
}

