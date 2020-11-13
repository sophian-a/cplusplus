#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "config.h"
#include "internals.h"
#include "display.h"
#include "food.h"


void backgroundSetup(const int& nx, const int& ny, int* background){
	for (int i=0; i<nx; i++) {
		for (int j=0; j<ny; j++) {
			if (i==0 or i==nx-1 or j==0 or j==ny-1) {
				background[i+j*nx]=1;
			}
			else {
				background[i+j*nx]=0;
			}
		}
	}
}

void add_snake(int* snake, int* bg, int& snl, const int& nx, const int& ny){
	int x;
	int y;
	for(int i=0; i<2*snl; i++){
		x = snake[i];
		y = snake[snl+i];
    	bg[x + y*nx]=1;
    }
}

void remove_snake(int* snake, int* bg, int& snl, const int& nx, const int& ny){
	int x;
	int y;
	for(int i=0; i<2*snl; i++){
		x = snake[i];
		y = snake[snl+i];
    	bg[x + y*nx]=0;
    }
}

// On utilise les touches zqsd pour les flèches
void snake_movement(char key, int* dxdy){
	if (key=='z') {
		//dxdy={0,1};
		dxdy[0]=0;
		dxdy[1]=1;
	}
	if (key=='q') {
		//dxdy={-1,0};
		dxdy[0]=-1;
		dxdy[1]=0;
	}
	if (key=='s') {
		//dxdy={0,-1};
		dxdy[0]=0;
		dxdy[1]=-1;
	}
	if (key=='d') {
		//dxdy={1,0};
		dxdy[0]=1;
		dxdy[1]=0;
	}
}

bool verifyBorder(int* snake, const int& nx, const int& ny){
	for (int i=0; i<SNAKE_LEN; i++) {
		if (snake[i]<=0 or snake[i]>=nx) {
			return false;
		}
	}
	for (int i=SNAKE_LEN; i<2*SNAKE_LEN;i++) {
		if (snake[i]<=0 or snake[i]>=ny) {
			return false;
		}
	}
	return true;
}

void setupSnake(int* snake, int& snake_len, const int& nx, const int& ny){
	snake[0] = rand()%(nx-snake_len-1) + snake_len;
    snake[SNAKE_LEN] = rand()%(ny-2) + 1;
	for (int i=1; i<snake_len; i++) {
		snake[i]=snake[0]-i;
		snake[SNAKE_LEN+i]=snake[SNAKE_LEN];
	}
	for (int j=snake_len; j<SNAKE_LEN; j++){
		snake[j]=1;
		snake[SNAKE_LEN + j]=1;
	}
}

void update_snake_coordinates(int* snake, int& snl, int* dxdy){
	for (int i=snl-1; i>0; i--){
		snake[i]=snake[i-1];
		snake[SNAKE_LEN+i]=snake[SNAKE_LEN+i-1];
	}
	snake[0]=snake[0]+dxdy[0];
	snake[SNAKE_LEN]=snake[SNAKE_LEN]+dxdy[1];
}

void startGame(const int& lap, const int& nx, const int& ny, int& snl, int* snake, int* bg){
    char key;
    int dxdy[2] = {1,0};
    int food[2] = {0,0};

    createFood( bg, food, nx, ny );

    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            std::cin >> key; 
            snake_movement(key, dxdy);
        }
        backgroundClear();
        add_snake(snake, bg, snl, nx, ny);
        printFrame(nx, ny, bg);
        remove_snake(snake, bg, snl, nx, ny);
        bool out =  verifyBorder(snake, nx, ny);
        if( out == false){
            std::cerr << "" << std::endl;
            exit(1);
        }
        bool eat = eatFood(food, snake);
        if(eat){
            createFood(bg, food, nx, ny);
            snl++;
        }
        update_snake_coordinates(snake, snl, dxdy);

    }
}



int main(){
    const int nx = 50;
    const int ny = 25;
    const int lap=200;

    int snake_len = 3;
    int background[nx*ny] ;
    for( int i=0; i<nx*ny; i++){
        background[i] = -1;
    }
    int snake[2*SNAKE_LEN];

    backgroundSetup(nx, ny, background);
    setupSnake(snake, snake_len, nx, ny);


    startGame(lap, nx, ny, snake_len, snake, background);

}



