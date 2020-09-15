#include <stdio.h>
#include <SDL.h>
#define SDL_MAIN_HANDLED
int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *render;
    SDL_Event event;
   
    SDL_Rect rect1 = {100, 100, 100, 100};
    SDL_Rect rect2 = {300, 100, 100, 100};
 
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, 0);
 
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, 200, 200, 100, 255);
    SDL_RenderDrawLine(render, 100, 420, 400, 420);
        
	int x=0;

    while (1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;

        SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render, 200, 200, 100, 255);
        SDL_RenderDrawLine(render, 100, 400, 400, 400);
		SDL_RenderDrawLine(render, 100, 420, 400, 420);
        rect2.x=x;
        SDL_RenderDrawRect(render, &rect1);
        SDL_RenderFillRect(render, &rect1);
     
        SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
        SDL_RenderDrawRect(render, &rect2);
        SDL_RenderFillRect(render, &rect2);
        SDL_RenderPresent(render);
        
        SDL_Delay(1);
        x=x+1;
        if (x>600) x=0;
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
