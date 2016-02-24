#include "prototypes.h"

int Places[3][3];
Input input;
int endGame;
int go = 1;

void initPlaces() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            Places[i][j] = -1;
        }
    }
}

int drawMarks(Input* input, int *turn) {
        int img = -1;
    //turn == 0 --> player0 , turn == 1 --> playerX
        if(input->value == 7 && *turn == 0 && Places[0][0] == -1) {
            Places[0][0] = *turn;
            drawThing(getCircle(), 50 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }

            return img;
        }
        else if(input->value == 7 && *turn == 1 && Places[0][0] == -1) {
            Places[0][0] = *turn;
            drawThing(getCross(), 50 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 8 && *turn == 0 && Places[0][1] == -1) {
            Places[0][1] = *turn;
            drawThing(getCircle(), 200 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        else if(input->value == 8 && *turn == 1 && Places[0][1] == -1) {
            Places[0][1] = *turn;
            drawThing(getCross(), 200 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 9 && *turn == 0 && Places[0][2] == -1) {
            Places[0][2] = *turn;
            drawThing(getCircle(), 350 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 9 && *turn == 1 && Places[0][2] == -1) {
            Places[0][2] = *turn;
            drawThing(getCross(), 350 , 50);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 4 && *turn == 0 && Places[1][0] == -1) {
            Places[1][0] = *turn;
            drawThing(getCircle(), 50 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        else if(input->value == 4 && *turn == 1 && Places[1][0] == -1) {
            Places[1][0] = *turn;
            drawThing(getCross(), 50 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 5 && *turn == 0 && Places[1][1] == -1) {
            Places[1][1] = *turn;
            drawThing(getCircle(), 200 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 5 && *turn == 1 && Places[1][1] == -1) {
            Places[1][1] = *turn;
            drawThing(getCross(), 200 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 6 && *turn == 0 && Places[1][2] == -1) {
            Places[1][2] = *turn;
            drawThing(getCircle(), 350 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 6 && *turn == 1 && Places[1][2] == -1) {
            Places[1][2] = *turn;
            drawThing(getCross(), 350 , 200);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 1 && *turn == 0 && Places[2][0] == -1) {
            Places[2][0] = *turn;
            drawThing(getCircle(), 50 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 1 && *turn == 1 && Places[2][0] == -1) {
            Places[2][0] = *turn;
            drawThing(getCross(), 50 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;

            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }

        if(input->value == 2 && *turn == 0 && Places[2][1] == -1) {
            Places[2][1] = *turn;
            drawThing(getCircle(), 200 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 2 && *turn == 1 && Places[2][1] == -1) {
            Places[2][1] = *turn;
            drawThing(getCross(), 200 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        if(input->value == 3 && *turn == 0 && Places[2][2] == -1) {
            Places[2][2] = *turn;
            drawThing(getCircle(), 350 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;

            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        else if(input->value == 3 && *turn == 1 && Places[2][2] == -1) {
            Places[2][2] = *turn;
            drawThing(getCross(), 350 , 350);
            img = checkWinner(*turn, input->value);
            *turn = (*turn + 1)%2;
            if (img == 0){
                drawThing(getOwins(), 470, 150);
                go = 0;
            }
            else if(img == 1){
                drawThing(getXwins(), 470, 150);
                go = 0;
            }
            return img;
        }
        return -1;
}

int checkWinner(int turn, int inputVal) {
    int player = turn;

    if(inputVal == 7) {
        if(Places[0][1] == player && Places[0][2] == player)
            return player;
        if(Places[1][0] == player && Places[2][0] == player)
            return player;
        if(Places[1][1] == player && Places[2][2] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 9) {
        if(Places[0][1] == player && Places[0][0] == player)
            return player;
        if(Places[1][2] == player && Places[2][2] == player)
            return player;
        if(Places[1][1] == player && Places[2][0] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 1) {
        if(Places[1][0] == player && Places[0][0] == player)
            return player;
        if(Places[2][1] == player && Places[2][2] == player)
            return player;
        if(Places[1][1] == player && Places[0][2] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 3) {
        if(Places[2][1] == player && Places[2][0] == player)
            return player;
        if(Places[1][2] == player && Places[0][2] == player)
            return player;
        if(Places[1][1] == player && Places[0][0] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 4) {
        if(Places[0][0] == player && Places[2][0] == player)
            return player;
        if(Places[1][1] == player && Places[1][2] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 6) {
        if(Places[1][1] == player && Places[1][0] == player)
            return player;
        if(Places[0][2] == player && Places[2][2] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 8) {
        if(Places[0][0] == player && Places[0][2] == player)
            return player;
        if(Places[1][1] == player && Places[2][1] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 2) {
        if(Places[1][1] == player && Places[0][1] == player)
            return player;
        if(Places[2][0] == player && Places[2][2] == player)
            return player;
        else
            return -1;
    }
    else if(inputVal == 5) {
        if(Places[0][0] == player && Places[2][2] == player)
            return player;
        if(Places[0][2] == player && Places[2][0] == player)
            return player;
        if(Places[0][1] == player && Places[2][1] == player)
            return player;
        if(Places[1][0] == player && Places[1][2] == player)
            return player;
        else
            return -1;
    }
    return -1;
}


int main(int argc, char *argv[]) {

	unsigned int frameLimit = SDL_GetTicks() + 16;
	int turn;
	init("Tic Tac Toe");
	loadGame();

	atexit(cleanup);

	//go = 1;
    turn = 1;
    endGame = -1;

    initPlaces();



    while (1) {

        getInput(&input);

        if(getOnMenu() == 1) {
            drawStartMenu(&input);
            if(input.enter == 1) {
                drawGame();
                setOnMenu(0);
            }
        }
        else {
            drawMarks(&input, &turn);
            if(go == 0) {
                printf("\nGo is now 0\n");
                go = 1;
                initPlaces();
                setOnMenu(1);
            }
        }

		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
	}
	exit(0);

}
