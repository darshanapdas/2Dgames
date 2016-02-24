#include "prototypes.h"


/*void gestionInputs(int *turn, Input *input)
{
	//On gère le clavier (on rajoutera plus tard la gestion
	//des joysticks ;) )
	getInput(&turn, input);
}*/

void getInput(Input *input) {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {


		switch (event.type) {
            case SDL_QUIT:
                exit(0);
            break;

			case SDL_KEYDOWN:
			    switch (event.key.keysym.sym) {


					case SDLK_ESCAPE:
						exit(0);
					break;

                    case SDLK_1:
                    case SDLK_KP_1:
                    {
                        input->value = 1;
						//turn = (turn + 1)%2;
                        break;
                    }

                    case SDLK_2:
					case SDLK_KP_2:
                    {
					    input->value = 2;
						//turn = (turn + 1)%2;
                        break;

					}

                    case SDLK_3:
					case SDLK_KP_3:
                    {
					    input->value = 3;
						//turn = (turn + 1)%2;
                        break;

					}

                    case SDLK_4:
					case SDLK_KP_4:
                    {
					    input->value = 4;
						//turn = (turn + 1)%2;
						break;
					}

                    case SDLK_5:
					case SDLK_KP_5:
					{
					    input->value = 5;
						//turn = (turn + 1)%2;
                        break;

					}
                    case SDLK_6:
					case SDLK_KP_6:
					{
						input->value = 6;
						//turn = (turn + 1)%2;
                        break;
                    }

                    case SDLK_7:
					case SDLK_KP_7:
                    {
						input->value = 7;
						//turn = (turn + 1)%2;
						break;
					}


                    case SDLK_8:
					case SDLK_KP_8:
					{
					    input->value = 8;
                        //turn = (turn + 1)%2;
					    break;
					}


                    case SDLK_9:
					case SDLK_KP_9:
                    {
						input->value = 9;
						//turn = (turn + 1)%2;
                        break;
                    }
					case SDLK_BACKSPACE:
						input->pause = 1;
					break;

                    case SDLK_RETURN:
                        input->enter = 1;

					case SDLK_UP:
                        input->up = 1;

                    case SDLK_DOWN:
                        input->down = 1;

                    case SDLK_LEFT:
                        input->left = 1;

                    case SDLK_RIGHT:
                        input->right = 1;


					default:
                    break;
				}
			break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym) {

                    case SDLK_DELETE:
						input->del = 1;
					break;

                    case SDLK_KP_1:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_2:
                    {
                        input->value = 0;
                        break;
                    }

                    case SDLK_KP_3:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_4:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_5:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_6:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_7:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_8:
                    {
                        input->value = 0;
                        break;
                    }
                    case SDLK_KP_9:
                    {
                        input->value = 0;
                        break;
                    }

                    case SDLK_BACKSPACE:
                        input->pause = 0;

                    case SDLK_UP:
                        input->up = 0;

                    case SDLK_DOWN:
                        input->down = 0;

                    case SDLK_LEFT:
                        input->left = 0;

                    case SDLK_RIGHT:
                        input->right = 0;

                    case SDLK_RETURN:
                        input->enter = 0;

					default:
					break;
				}

                break;

                default:
                break;

		}

	}

}


