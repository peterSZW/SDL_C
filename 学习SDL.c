#include "SDL2/SDL.h"
#include <stdio.h>
 
//屏幕的宽高常量
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
 
int main(int argc, char* args[])
{
    //我们要渲染的窗口
    SDL_Window* window = NULL;
 
    //窗口的表面
    SDL_Surface* screenSurface = NULL;
    //初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        exit(-1);
    }
 
    //创建窗口
  window = SDL_CreateWindow("MY FIRST SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        SDL_Quit();
        return -1;
    }
 
    //获取窗口表面
    screenSurface = SDL_GetWindowSurface(window);
 
    //表面涂上白色
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
 
    //更新表面
    SDL_UpdateWindowSurface(window);
 
    //等待两秒
    SDL_Delay(2000);
 
    //销毁窗口
    SDL_DestroyWindow(window);
 
    //退出SDL子系统
    SDL_Quit();
    return 0;
}
