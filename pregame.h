#ifndef PREGAME_H
#define PREGAME_H

#include<iostream>
#include "button.h"

class PreGame {
private:
    pair<int, int> choiceSizeOfBoard[10];
    int choiceNumberOfPieceConsecutiveToWin[10];
    int sizeOfChoiceMap = 4;
    Button ChoiceMap[6];
    Button ChoicePlayerAI[4];
    int currentButtonChoosingMap = 0;
    int currentButtonChoosingPlayerAI = 0; // 0 not choose, 1 is play with player, 2 is play with AI
    int stateOfBulletinBoard = EMPTY;
    Button EnterToGame;

public:
    void setUpPreGame(){
        // set up for size of map
        choiceSizeOfBoard[1] = {3 , 3};
        choiceNumberOfPieceConsecutiveToWin[1] = 3;
        choiceSizeOfBoard[2] = {5 , 5};
        choiceNumberOfPieceConsecutiveToWin[2] = 4;
        choiceSizeOfBoard[3] = {9 , 9};
        choiceNumberOfPieceConsecutiveToWin[3] = 5;
        choiceSizeOfBoard[4] = {12 , 12};
        choiceNumberOfPieceConsecutiveToWin[4] = 5;

        // set up for button map
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <= 2; ++j){
                int currentSetUp = (i - 1) * 2 + j;
                ChoiceMap[currentSetUp].setPositionTopLeft(SCREEN_WIDTH / 32 + (j - 1) * SCREEN_WIDTH * 11 / 48, SCREEN_HEIGHT * 7 / 12 + (i - 1) * SCREEN_HEIGHT / 8);
                ChoiceMap[currentSetUp].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
                ChoiceMap[currentSetUp].setTypeOfButton(CHOICE_MAP_PREGAME);
                ChoiceMap[currentSetUp].setStateButton(currentSetUp);
            }
        }
        // set up for button enter
        EnterToGame.setPositionTopLeft(13 * SCREEN_WIDTH / 32, 10 * SCREEN_HEIGHT / 12);
        EnterToGame.setLengthOfButton(SCREEN_WIDTH * 5 / 24 , SCREEN_WIDTH / 9);
        EnterToGame.setTypeOfButton(ENTER_PREGAME);
        EnterToGame.setStateButton(1);

        // set up for button player-ai
        ChoicePlayerAI[1].setPositionTopLeft(SCREEN_WIDTH * 89 / 128, SCREEN_HEIGHT * 14 / 24);
        ChoicePlayerAI[1].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
        ChoicePlayerAI[1].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
        ChoicePlayerAI[1].setStateButton(1);
        ChoicePlayerAI[2].setPositionTopLeft(SCREEN_WIDTH * 89 / 128, SCREEN_HEIGHT * 17 / 24);
        ChoicePlayerAI[2].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
        ChoicePlayerAI[2].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
        ChoicePlayerAI[2].setStateButton(2);
    }
    pair<int,int> getChooseSizeOfBoard(){
        return choiceSizeOfBoard[currentButtonChoosingMap];
    }
    int GetChoiceNumberOfPieceConsecutiveToWin(){
        int chooseMap = currentButtonChoosingMap;
        currentButtonChoosingMap = 0;
        return choiceNumberOfPieceConsecutiveToWin[chooseMap];
    }
    int getAIorPlayer(){
        int chooseAIorPlayer = currentButtonChoosingPlayerAI;
        currentButtonChoosingPlayerAI = 0;
        return chooseAIorPlayer - 1;
    }
    void handleEvent(SDL_Window* window, SDL_Renderer* renderer, bool &inGame){
        SDL_Event e;
        while( SDL_PollEvent( &e )){
            if(e.type == SDL_QUIT) quitSDL(window, renderer);
            if(e.type == SDL_MOUSEBUTTONDOWN){
                for(int i = 1; i <= sizeOfChoiceMap; ++i){
                    if(ChoiceMap[i].handleEventButton(e, CHOICE_MAP_PREGAME, i, i) == 1){ // State k thay doi nen de i va i
                        if(currentButtonChoosingMap)  ChoiceMap[currentButtonChoosingMap].setTypeOfButton(CHOICE_MAP_PREGAME);
                        ChoiceMap[i].setTypeOfButton(CHOICE_MAP_SUCCESS_PREGAME);
                        currentButtonChoosingMap = i;
                        render(renderer);
                    }
                }
                for(int i = 1; i <= 2; ++i){
                    if(ChoicePlayerAI[i].handleEventButton(e, CHOICE_PLAYER_AI_PREGAME , i, i) == 1){
                        if(currentButtonChoosingPlayerAI) ChoicePlayerAI[currentButtonChoosingPlayerAI].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
                        ChoicePlayerAI[i].setTypeOfButton(CHOICE_PLAYER_AI_SUCCESS_PREGAME);
                        currentButtonChoosingPlayerAI = i;
                        render(renderer);
                    }
                }
                if(EnterToGame.handleEventButton(e, ENTER_PREGAME, 1 , 1) == 1){
                    if(currentButtonChoosingMap && currentButtonChoosingPlayerAI){
                        if(currentButtonChoosingMap == 4 && currentButtonChoosingPlayerAI == 2){
                            stateOfBulletinBoard = CAN_NOT_PLAY_MAP1212_WITH_AI;
                            render(renderer);
                        }
                        else if(currentButtonChoosingMap == 2 && currentButtonChoosingPlayerAI == 2){
                            stateOfBulletinBoard = CAN_NOT_PLAY_MAP55_WITH_AI;
                            render(renderer);
                        }
                        else inGame = 1;
                    }
                    else if(currentButtonChoosingMap == 0 || currentButtonChoosingPlayerAI == 0){
                        if(currentButtonChoosingMap && !currentButtonChoosingPlayerAI){
                            stateOfBulletinBoard = NOT_CHOOSE_PLAYER;
                            render(renderer);
                        }
                        if(currentButtonChoosingPlayerAI && !currentButtonChoosingMap){
                            stateOfBulletinBoard = NOT_CHOOSE_MAP;
                            render(renderer);
                        }
                        if(!currentButtonChoosingMap && !currentButtonChoosingPlayerAI){
                            stateOfBulletinBoard = NOT_CHOOSE_PLAYER_AND_MAP;
                            render(renderer);
                        }
                    }
                }
            }
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_RenderClear(renderer);
        for(int i = 1; i <= sizeOfChoiceMap; ++i) ChoiceMap[i].render(renderer, 0, 0);
        for(int i = 1; i <= 2; ++i) ChoicePlayerAI[i].render(renderer, 0, 0);
        EnterToGame.render(renderer, 0, 0);
        RenderMedia(renderer, dataImageButton[HEADING_PREGAME][1], SCREEN_WIDTH / 8, 0, SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 3);
        RenderMedia(renderer, dataImageButton[CHOOSE_MAP_PREGAME][1],
                    SCREEN_WIDTH / 16, SCREEN_HEIGHT * 5 / 12, SCREEN_WIDTH * 5 / 16, SCREEN_HEIGHT / 6);
        RenderMedia(renderer, dataImageButton[CHOOSE_AI_PREGAME][1],
                    SCREEN_WIDTH * 10 / 16, SCREEN_HEIGHT * 5 / 12, SCREEN_WIDTH * 5 / 16, SCREEN_HEIGHT / 6);
        RenderMedia(renderer, dataImageButton[BULLETIN_BOARD_PREGAME][stateOfBulletinBoard],
                    3 * SCREEN_WIDTH / 4, 0, SCREEN_WIDTH/ 4, SCREEN_HEIGHT / 3);
        SDL_RenderPresent(renderer);

    }


};



#endif
