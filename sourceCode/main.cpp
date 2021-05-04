#include <iostream>
#include <SDL.h>
#include "game.h"
#include"pregame.h"
using namespace std;


int main(int argc, char* argv[]){
    bool inGame = 0;
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_RenderClear(renderer);
    setData(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    PreGame PreTictactoe;
    while(1){
        if(!inGame){
            PreTictactoe.setUpPreGame();
            PreTictactoe.render(renderer);
            while(!inGame) PreTictactoe.handleEvent(window, renderer, inGame);
        }
        if(inGame){
            Game Tictactoe;
            Tictactoe.setLevelOfAI(PreTictactoe.getLevel());
            Tictactoe.setSizeOfBoard(PreTictactoe.getChooseSizeOfBoard().first,
                                      PreTictactoe.getChooseSizeOfBoard().second);
            Tictactoe.setNumberOfPieceConsecutiveToWin(PreTictactoe.GetChoiceNumberOfPieceConsecutiveToWin());
            Tictactoe.setWhoPlay(PreTictactoe.getAIorPlayer());
            Tictactoe.setStateSound(PreTictactoe.getStateSound());
            Tictactoe.setAllAttribute();
            Tictactoe.render(renderer);
            while(inGame) Tictactoe.handleEvent(window, renderer, inGame);
        }
    }
    //SDL_RenderClear(renderer);
   //Khi thông thường chạy với môi trường bình thường ở nhà
    //SDL_RenderPresent(renderer);
   //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
   //SDL_UpdateWindowSurface(window);

    // Your drawing code here
    // use SDL_RenderPresent(renderer) to show it

    return 0;
}
