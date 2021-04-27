#ifndef SDLSUPPORT_H
#define SDLSUPPORT_H

#include<iostream>
using namespace std;

    SDL_Texture* loadMedia(SDL_Renderer* Renderer, string path){
        SDL_Texture* gTexture;
        SDL_Surface* loadedSurface = IMG_Load( path.c_str());
        if( loadedSurface == NULL ){
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else{
            gTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
            if( gTexture == NULL ){
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            }
            SDL_FreeSurface( loadedSurface );
        }
        return gTexture;
    }
    void RenderMedia(SDL_Renderer* renderer, SDL_Texture* gTexture, int topX, int topY, int width, int height){
        SDL_Rect Dest;
        Dest.x = topX + 1;
        Dest.y = topY + 1;
        Dest.w = width - 1;
        Dest.h = height - 1;
        SDL_RenderCopy( renderer, gTexture, NULL, &Dest );
//        SDL_RenderDrawLine(renderer, topX, topY, topX + width, topY);
//        SDL_RenderDrawLine(renderer, topX, topY, topX, topY + width);
//        SDL_RenderDrawLine(renderer, topX, topY + width, topX + width, topY + width);
//        SDL_RenderDrawLine(renderer, topX + width, topY, topX + width, topY + width);
    }

    void logSDLError(std::ostream& os, const std::string &msg, bool fatal){
        os << msg << " Error: " << SDL_GetError() << std::endl;
        if (fatal) {
            SDL_Quit();
            exit(1);
        }
    }
    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, string WINDOW_TITLE){
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logSDLError(std::cout, "SDL_Init", true);

        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


        //Khi thông thường chạy với môi trường bình thường ở nhà
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
        if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }


    void quitSDL(SDL_Window* window, SDL_Renderer* renderer){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }

    SDL_Texture* dataImageButton[20][20];

#endif

