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
           
	int x=0;

    while (1)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;

        if(event.type==SDL_KEYDOWN)
        {
            //通过不同的键标检测来选择表面
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
                rect1.y-=1;
                break;
            case SDLK_DOWN:
                rect1.y+=1;
                break;
            case SDLK_LEFT:
                rect1.x--;
                break;
            case SDLK_RIGHT:
                rect1.x++;
                
                break;
            }
        }

        SDL_SetRenderDrawColor(render, 0, 0, 0, 0); //设置笔的颜色为 0，0，0
        SDL_RenderClear(render); //清除屏幕

        SDL_SetRenderDrawColor(render, 200, 200, x, 255); //设置笔的颜色为 200，100，255
        SDL_RenderDrawLine(render, 100, 400, 400, 400); //画一条线（100，400），（400，400）
		SDL_RenderDrawLine(render, 100, 420, 400, 420); //画一条线（100，420），（400，420）

        SDL_SetRenderDrawColor(render, x, 200, 200, 255); //设置笔的颜色为 200，100，255
        SDL_RenderDrawRect(render, &rect1); // 画一方格
        SDL_RenderFillRect(render, &rect1); //方格涂颜色
     
        SDL_SetRenderDrawColor(render, 200,x, 200, 255);//设置笔的颜色为 0，0，0
        rect2.x=x; //第二个方格的 x 坐标 等于不断增加的  x 值
        SDL_RenderDrawRect(render, &rect2); // 画一方格
        SDL_RenderFillRect(render, &rect2); //方格涂颜色
        
        SDL_RenderPresent(render); //显示画布
        
        SDL_Delay(1); //延迟1ms
        x=x+5;
        if (x>600) x=0; // 如果方格的x坐标超出屏幕，那么设置方格的x坐标为 0 
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
