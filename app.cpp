#include <iostream>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv)
{
    SDL_Window* window = nullptr;
    SDL_Surface* screensurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "sdl failed init: " << SDL_GetError();
        return 0;
    }

    window = SDL_CreateWindow("physics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "window failed: " << SDL_GetError();
    }
    else
    {
        std::cout << "init success";

        screensurface = SDL_GetWindowSurface(window);

        SDL_FillRect(screensurface, nullptr, SDL_MapRGB(screensurface->format, 0xFF, 0xDE, 0xDE));

        SDL_UpdateWindowSurface(window);

        // bgfx init
        bgfx::PlatformData pdata;
        //pdata.ndt = nullptr;
        ////pdata.nwh = window;
        //bgfx::setPlatformData(pdata);
        //bgfx::renderFrame();
        //bgfx::Init init;
        //init.resolution.width = SCREEN_WIDTH;
        //init.resolution.height = SCREEN_HEIGHT;
        //init.resolution.reset = BGFX_RESET_VSYNC;
        //if (!bgfx::init(init)) {
        //    SDL_DestroyWindow(window);
        //    SDL_Quit();
        //    return 0;
        //}
        //bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0xFFCCFFFF);
        //bgfx::setViewRect(0, 0, 0, bgfx::BackbufferRatio::Equal);

        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}