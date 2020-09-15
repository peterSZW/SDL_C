// -static-libgcc -lmingw32 -lSDL2main -lSDL2 -lSDL2_test  -lSDL2_image

#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <conio.h>
 
#define W 800
#define H 600
#define SPEED 90

int main(int argc, char *argv[]) {
	int i, j;
	int done = 0;
	SDL_Event event;
	SDL_Window *win = NULL;
	SDL_Surface *surface = NULL;
	SDL_Surface *img = NULL;
	SDL_Renderer *rend = NULL;
	SDL_Texture *texture = NULL;
	SDL_Rect rect, walks[8];
 
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("DNF", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		W, H, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	surface = SDL_GetWindowSurface(win);
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
	img = IMG_Load("walk.png");
	if (img == NULL)
	{
		printf("error\n");
		system("pause");
		return 0;
	}
	texture = SDL_CreateTextureFromSurface(rend, img);
	rect.x = 0;
	rect.y = 0;
	rect.h = img->h;
	rect.w = img->w / 8;
	for (i = 0; i<8; i++) {
		walks[i].w = img->w / 8;
		walks[i].h = img->h;
		walks[i].x = i*walks[i].w;
		walks[i].y = 0;
	}
	i = 0;
 
	while (!done) {
		//_getch();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = 1;
			}//exit
		}//pollevent
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texture, &walks[i], &rect);
		i = (i + 1) % 8;
		rect.x = (rect.x + 5) % (rect.w * 8);
		SDL_RenderPresent(rend);
		SDL_Delay(SPEED);
	}//done
	SDL_DestroyWindow(win);
	SDL_Quit();
 
	system("pause");
	return 0;
}
//void draw(SDL_Renderer, SDL_Texture);
void ddraw(SDL_Renderer *rend, SDL_Texture *texture) {
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, texture, NULL, NULL);
	SDL_RenderPresent(rend);
}
