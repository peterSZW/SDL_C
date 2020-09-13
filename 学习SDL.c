#include "SDL2/SDL.h"
#include <stdio.h>
 
//��Ļ�Ŀ�߳���
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
 
int main(int argc, char* args[])
{
    //����Ҫ��Ⱦ�Ĵ���
    SDL_Window* window = NULL;
 
    //���ڵı���
    SDL_Surface* screenSurface = NULL;
    //��ʼ��SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        exit(-1);
    }
 
    //��������
  window = SDL_CreateWindow("MY FIRST SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        SDL_Quit();
        return -1;
    }
 
    //��ȡ���ڱ���
    screenSurface = SDL_GetWindowSurface(window);
 
    //����Ϳ�ϰ�ɫ
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
 
    //���±���
    SDL_UpdateWindowSurface(window);
 
    //�ȴ�����
    SDL_Delay(2000);
 
    //���ٴ���
    SDL_DestroyWindow(window);
 
    //�˳�SDL��ϵͳ
    SDL_Quit();
    return 0;
}
