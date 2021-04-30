#ifndef PREGAME_H
#define PREGAME_H

#include<iostream>
#include "button.h"
#include "sdlsupport.h"

class PreGame {
private:
    pair<int, int> choiceSizeOfBoard[6];
    int choiceNumberOfPieceConsecutiveToWin[4];
    int sizeOfChoiceMap = 4;
    int sizeOfChoicePlayerAI = 2;
    int sizeOfChoiceLevel = 3;
    Button ChoiceMap[6]; // 4 button choice map
    Button ChoicePlayerAI[4]; // 2 button choose play with AI or play with another player
    Button ChoiceLevel[4];
    Button EnterToGame;
    int currentButtonChoosingMap = NOT_CHOOSE;
    int currentButtonChoosingPlayerAI = STATE_EMPTY; // Not choose
    int currentLevelChoosing = NOT_HAVE_ANYTHING;
    int stateOfBulletinBoard = EMPTY;

    void setUpForInfoOfMap(){
        choiceSizeOfBoard[MAP_33] = {3 , 3};
        choiceNumberOfPieceConsecutiveToWin[MAP_33] = 3;
        choiceSizeOfBoard[MAP_55] = {5 , 5};
        choiceNumberOfPieceConsecutiveToWin[MAP_55] = 4;
        choiceSizeOfBoard[MAP_99] = {9 , 9};
        choiceNumberOfPieceConsecutiveToWin[MAP_99] = 5;
        choiceSizeOfBoard[MAP_1212] = {12 , 12};
        choiceNumberOfPieceConsecutiveToWin[MAP_1212] = 5;
    }
    void setUpForButtonMap(){
        for(int i = 1; i <= 2; ++i){
            for(int j = 1; j <= 2; ++j){
                int currentSetUp = (i - 1) * 2 + j;
                ChoiceMap[currentSetUp].setPositionTopLeft(SCREEN_WIDTH / 32 + (j - 1) * SCREEN_WIDTH * 11 / 48, SCREEN_HEIGHT * 7 / 12 + (i - 1) * SCREEN_HEIGHT / 8);
                ChoiceMap[currentSetUp].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
                ChoiceMap[currentSetUp].setTypeOfButton(CHOICE_MAP_PREGAME);
                ChoiceMap[currentSetUp].setStateButton(currentSetUp);
            }
        }
    }
    void setUpForButtonPlayerAI(){
        ChoicePlayerAI[STATE_PLAYER].setPositionTopLeft(SCREEN_WIDTH * 89 / 128, SCREEN_HEIGHT * 14 / 24);
        ChoicePlayerAI[STATE_PLAYER].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
        ChoicePlayerAI[STATE_PLAYER].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
        ChoicePlayerAI[STATE_PLAYER].setStateButton(STATE_PLAYER);
        ChoicePlayerAI[STATE_AI].setPositionTopLeft(SCREEN_WIDTH * 89 / 128, SCREEN_HEIGHT * 17 / 24);
        ChoicePlayerAI[STATE_AI].setLengthOfButton(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 8);
        ChoicePlayerAI[STATE_AI].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
        ChoicePlayerAI[STATE_AI].setStateButton(STATE_AI);
    }
    void setUpForButtonEnterGame(){
        EnterToGame.setPositionTopLeft(13 * SCREEN_WIDTH / 32, 10 * SCREEN_HEIGHT / 12);
        EnterToGame.setLengthOfButton(SCREEN_WIDTH * 5 / 24 , SCREEN_WIDTH / 9);
        EnterToGame.setTypeOfButton(ENTER_PREGAME);
        EnterToGame.setStateButton(true);
    }
    void setUpForButtonChoiceLevel(){
        for(int i = 1; i <= 3; ++i){ // 0 is easy, 1 is medium, 2 is hard
            ChoiceLevel[i].setPositionTopLeft(SCREEN_WIDTH * 13 / 15, SCREEN_HEIGHT * 35 / 48 + (i - 1) * SCREEN_HEIGHT / 15);
            ChoiceLevel[i].setLengthOfButton(SCREEN_WIDTH / 9, SCREEN_HEIGHT / 12);
            ChoiceLevel[i].setTypeOfButton(CHOICE_LEVEL_PREGAME);
            ChoiceLevel[i].setStateButton(i);
        }
    }
    void checkEventForMapButton(SDL_Event &e, SDL_Renderer* renderer){
        for(int i = 1; i <= sizeOfChoiceMap; ++i){
            if(ChoiceMap[i].handleEventButton(e, CHOICE_MAP_PREGAME, i, i) == true){ // State k thay doi nen de i va i
                if(currentButtonChoosingMap)
                    ChoiceMap[currentButtonChoosingMap].setTypeOfButton(CHOICE_MAP_PREGAME);
                ChoiceMap[i].setTypeOfButton(CHOICE_MAP_SUCCESS_PREGAME);
                currentButtonChoosingMap = i;
                render(renderer);
            }
        }
    }
    void checkEventForPlayerAIButton(SDL_Event &e, SDL_Renderer* renderer){
        for(int i = 1; i <= sizeOfChoicePlayerAI; ++i){
            if(ChoicePlayerAI[i].handleEventButton(e, CHOICE_PLAYER_AI_PREGAME , i, i) == true){
                if(currentButtonChoosingPlayerAI)
                    ChoicePlayerAI[currentButtonChoosingPlayerAI].setTypeOfButton(CHOICE_PLAYER_AI_PREGAME);
                ChoicePlayerAI[i].setTypeOfButton(CHOICE_PLAYER_AI_SUCCESS_PREGAME);
                currentButtonChoosingPlayerAI = i;
                render(renderer);
            }
        }
    }
    void checkEventForEnterButton(SDL_Event &e, SDL_Renderer* renderer, bool &inGame){
        if(EnterToGame.handleEventButton(e, ENTER_PREGAME, true , true) == true){
            if(currentButtonChoosingMap && currentButtonChoosingPlayerAI){
                if(currentButtonChoosingMap == MAP_55 && currentButtonChoosingPlayerAI == STATE_AI){
                    Mix_PlayChannel(-1, dataChunk[ERROR], 0);
                    stateOfBulletinBoard = CAN_NOT_PLAY_MAP55_WITH_AI;
                    render(renderer);
                }
                else if((currentButtonChoosingMap == MAP_1212 || currentButtonChoosingMap == MAP_99) &&
                        currentButtonChoosingPlayerAI == STATE_AI && currentLevelChoosing == NOT_HAVE_ANYTHING){
                    Mix_PlayChannel(-1, dataChunk[ERROR], 0);
                    stateOfBulletinBoard = NOT_CHOOSE_LEVEL;
                    render(renderer);
                }

                else inGame = true;
            }
            else if(currentButtonChoosingMap == NOT_CHOOSE || currentButtonChoosingPlayerAI == STATE_EMPTY){
                Mix_PlayChannel(-1, dataChunk[ERROR], 0);
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
    void checkEventForLevelButton(SDL_Event &e, SDL_Renderer* renderer){
        if((currentButtonChoosingMap != MAP_1212 && currentButtonChoosingMap != MAP_99)
           || currentButtonChoosingPlayerAI != STATE_AI) return;
        for(int i = 1; i <= sizeOfChoiceLevel; ++i){
            if(ChoiceLevel[i].handleEventButton(e, CHOICE_LEVEL_PREGAME , i, i) == true){
                if(currentLevelChoosing)
                    ChoiceLevel[currentLevelChoosing].setTypeOfButton(CHOICE_LEVEL_PREGAME);
                ChoiceLevel[i].setTypeOfButton(CHOICE_LEVEL_PREGAME_SUCCESS);
                currentLevelChoosing = i;
                render(renderer);
            }
        }
    }

public:
    void setUpPreGame(){
        setUpForInfoOfMap();
        setUpForButtonMap();
        setUpForButtonPlayerAI();
        setUpForButtonEnterGame();
        setUpForButtonChoiceLevel();
    }
    pair<int,int> getChooseSizeOfBoard(){
        return choiceSizeOfBoard[currentButtonChoosingMap];
    }
    int GetChoiceNumberOfPieceConsecutiveToWin(){
        int chooseMap = currentButtonChoosingMap;
        currentButtonChoosingMap = STATE_EMPTY;
        return choiceNumberOfPieceConsecutiveToWin[chooseMap];
    }
    int getAIorPlayer(){
        int chooseAIorPlayer = currentButtonChoosingPlayerAI;
        currentButtonChoosingPlayerAI = STATE_EMPTY;
        return chooseAIorPlayer - 1;
    }
    int getLevel(){
        int level = currentLevelChoosing;
        currentLevelChoosing = 0;
        return level;
    }
    void handleEvent(SDL_Window* window, SDL_Renderer* renderer, bool &inGame){
        SDL_Event e;
        while( SDL_PollEvent( &e )){
            if(e.type == SDL_QUIT) quitSDL(window, renderer);
            if(e.type == SDL_MOUSEBUTTONDOWN){
                checkEventForMapButton(e, renderer);
                checkEventForPlayerAIButton(e, renderer);
                checkEventForEnterButton(e, renderer, inGame);
                checkEventForLevelButton(e, renderer);
            }
        }
    }
    void render(SDL_Renderer* renderer){
        SDL_RenderClear(renderer);
        // render choice buttons of map
        for(int i = 1; i <= sizeOfChoiceMap; ++i)
            ChoiceMap[i].render(renderer, false, false);
        // render choice buttons of AI and Player
        for(int i = 1; i <= sizeOfChoicePlayerAI; ++i)
            ChoicePlayerAI[i].render(renderer, false, false);
        // render choice level
        if((currentButtonChoosingMap == MAP_1212 || currentButtonChoosingMap == MAP_99)
            && currentButtonChoosingPlayerAI == STATE_AI){
            for(int i = 1; i <= 3; ++i)
                ChoiceLevel[i].render(renderer, false, false);
        }
        // render enter button
        EnterToGame.render(renderer, false, false);
        // render title of game
        RenderMedia(renderer, dataImage[HEADING_PREGAME][1],
                    SCREEN_WIDTH / 8, 0, SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 3);
        // render title of choose map
        RenderMedia(renderer, dataImage[CHOOSE_MAP_PREGAME][1],
                    SCREEN_WIDTH / 16, SCREEN_HEIGHT * 5 / 12, SCREEN_WIDTH * 5 / 16, SCREEN_HEIGHT / 6);
        // render title of choose AI and Player
        RenderMedia(renderer, dataImage[CHOOSE_AI_PREGAME][1],
                    SCREEN_WIDTH * 10 / 16, SCREEN_HEIGHT * 5 / 12, SCREEN_WIDTH * 5 / 16, SCREEN_HEIGHT / 6);
        // render bulletin board
        RenderMedia(renderer, dataImage[BULLETIN_BOARD_PREGAME][stateOfBulletinBoard],
                    SCREEN_WIDTH * 3 / 4, 0, SCREEN_WIDTH/ 4, SCREEN_HEIGHT / 3);
        SDL_RenderPresent(renderer);

    }
};



#endif

