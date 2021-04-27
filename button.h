#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL_image.h>
#include "sdlsupport.h"
using namespace std;


static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const string WINDOW_TITLE = "TICTACTOE GAME";
static const int directX[10] = {1, 1, 0, 1, 0, -1, -1, -1};
static const int directY[10] = {1, 0, 1, -1, -1, 1, 0, -1};

enum typeOfImage
{
    ENTER_PREGAME,
	CHOICE_MAP_PREGAME,
	CHOICE_MAP_SUCCESS_PREGAME,
	SQUARE_GAME,
	RESTART_GAME,
	RETURN_MENU_GAME,
	CHOICE_PLAYER_AI_PREGAME,
	CHOICE_PLAYER_AI_SUCCESS_PREGAME,
	CHOOSE_AI_PREGAME,
	CHOOSE_MAP_PREGAME,
	HEADING_PREGAME,
	PAUSE_GAME,
	BULLETIN_BOARD_PREGAME,
	ENDGAME_GAME
};

enum stateOfReporter {
    EMPTY,
    NOT_CHOOSE_PLAYER_AND_MAP,
    NOT_CHOOSE_PLAYER,
    NOT_CHOOSE_MAP,
    CAN_NOT_PLAY_MAP1212_WITH_AI,
    CAN_NOT_PLAY_MAP55_WITH_AI,
    YOUR_TURN,
    AI_TURN,
    PLAYER1_TURN,
    PLAYER2_TURN,
    ENDGAME,
    ENDGAME_ADMIT_LOSE,
};

enum stateOfEndGame {
    YOU_WIN,
    YOU_LOSE,
    DRAW,
    PLAYER1_WIN,
    PLAYER2_WIN
};
void setDataImage(SDL_Renderer* renderer){
    dataImageButton[ENTER_PREGAME][1] = loadMedia(renderer , "../TestSDL/EnterGameButton.png");
    dataImageButton[CHOICE_MAP_PREGAME][1] = loadMedia(renderer , "../TestSDL/choice33.png");
    dataImageButton[CHOICE_MAP_PREGAME][2] = loadMedia(renderer , "../TestSDL/choice55.png");
    dataImageButton[CHOICE_MAP_PREGAME][3] = loadMedia(renderer , "../TestSDL/choice99.png");
    dataImageButton[CHOICE_MAP_PREGAME][4] = loadMedia(renderer , "../TestSDL/choice1212.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][1] = loadMedia(renderer , "../TestSDL/choice33success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][2] = loadMedia(renderer , "../TestSDL/choice55success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][3] = loadMedia(renderer , "../TestSDL/choice99success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][4] = loadMedia(renderer , "../TestSDL/choice1212success.png");
    dataImageButton[CHOICE_PLAYER_AI_SUCCESS_PREGAME][1] = loadMedia(renderer , "../TestSDL/choicePlayPlayerSuccess.png");
    dataImageButton[CHOICE_PLAYER_AI_SUCCESS_PREGAME][2] = loadMedia(renderer , "../TestSDL/choicePlayAISuccess.png");
    dataImageButton[CHOICE_PLAYER_AI_PREGAME][1] = loadMedia(renderer , "../TestSDL/choicePlayPlayer.png");
    dataImageButton[CHOICE_PLAYER_AI_PREGAME][2] = loadMedia(renderer , "../TestSDL/choicePlayAI.png");
    dataImageButton[SQUARE_GAME][1] = loadMedia(renderer , "../TestSDL/player1_X.png");
    dataImageButton[SQUARE_GAME][2] = loadMedia(renderer , "../TestSDL/player2_O.png");
    dataImageButton[SQUARE_GAME][3] = loadMedia(renderer , "../TestSDL/player1_X_havePlayed.png");
    dataImageButton[SQUARE_GAME][4] = loadMedia(renderer , "../TestSDL/player2_O_havePlayed.png");
    dataImageButton[RESTART_GAME][1] = loadMedia(renderer, "../TestSDL/RestartGame.png");
    dataImageButton[RETURN_MENU_GAME][1] = loadMedia(renderer, "../TestSDL/returnMenu.png");
    dataImageButton[CHOOSE_AI_PREGAME][1] = loadMedia(renderer, "../TestSDL/chooseAI.png");
    dataImageButton[CHOOSE_MAP_PREGAME][1] = loadMedia(renderer, "../TestSDL/chooseMap.png");
    dataImageButton[HEADING_PREGAME][1] = loadMedia(renderer, "../TestSDL/heading.png");
    //dataImageButton[PAUSE_GAME][1] = loadMedia(renderer, "");
    dataImageButton[BULLETIN_BOARD_PREGAME][EMPTY] = loadMedia(renderer, "../TestSDL/bulletinBoard.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][NOT_CHOOSE_PLAYER_AND_MAP] = loadMedia(renderer, "../TestSDL/bulletinBoard_chooseAIandMap.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][NOT_CHOOSE_PLAYER] = loadMedia(renderer, "../TestSDL/bulletinBoard_chooseAI.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][NOT_CHOOSE_MAP] = loadMedia(renderer, "../TestSDL/bulletinBoard_chooseMap.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][CAN_NOT_PLAY_MAP1212_WITH_AI] = loadMedia(renderer, "../TestSDL/bulletinBoard_notSupportAIwith1212.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][CAN_NOT_PLAY_MAP55_WITH_AI] = loadMedia(renderer, "../TestSDL/bulletinBoard_notSupportAIwith55.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][YOUR_TURN] = loadMedia(renderer, "../TestSDL/bulletinBoard_yourTurn.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][AI_TURN] = loadMedia(renderer, "../TestSDL/bulletinBoard_AIturn.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][PLAYER1_TURN] = loadMedia(renderer, "../TestSDL/bulletinBoard_turnPlayer1.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][PLAYER2_TURN] = loadMedia(renderer, "../TestSDL/bulletinBoard_turnPlayer2.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][ENDGAME] = loadMedia(renderer, "../TestSDL/bulletinBoard_endGame.png");
    dataImageButton[BULLETIN_BOARD_PREGAME][ENDGAME_ADMIT_LOSE] = loadMedia(renderer, "../TestSDL/bulletinBoard_endGameAdmit.png");
    dataImageButton[ENDGAME_GAME][YOU_WIN] = loadMedia(renderer, "../TestSDL/bulletinBoard_youWin.png");
    dataImageButton[ENDGAME_GAME][YOU_LOSE] = loadMedia(renderer, "../TestSDL/bulletinBoard_youLose.png");
    dataImageButton[ENDGAME_GAME][DRAW] = loadMedia(renderer, "../TestSDL/bulletinBoard_draw.png");
    dataImageButton[ENDGAME_GAME][PLAYER1_WIN] = loadMedia(renderer, "../TestSDL/bulletinBoard_player1win.png");
    dataImageButton[ENDGAME_GAME][PLAYER2_WIN] = loadMedia(renderer, "../TestSDL/bulletinBoard_player2win.png");


}


class Button {
private:
    //int typeOfButton = -1;
    int stateButton = 0;
    SDL_Point positionTopLeft;
    pair<int,int> lengthOfButton;
public:
    int typeOfButton = -1;
    void setTypeOfButton(int type);
    void setPositionTopLeft(int _x,int _y);
    void setLengthOfButton(int lengthX, int lengthY);
    void setStateButton(int state);
    SDL_Point getPositionTopLeft();
    pair<int,int> getLengthOfButton();
    int getStateButton();
    bool handleEventButton(SDL_Event e, int typeOfButton, int statePre, int stateNext);
    bool checkInsideButton(int x,int y);
    void render(SDL_Renderer* renderer, bool haveRenderPresent, bool havePattern);
};
void Button::setTypeOfButton(int type){
    typeOfButton = type;
}
void Button::setPositionTopLeft(int _x,int _y){
    positionTopLeft.x = _x;
    positionTopLeft.y = _y;
}
void Button::setLengthOfButton(int lengthX, int lengthY){
    lengthOfButton = {lengthX, lengthY};
}
void Button::setStateButton(int state){
    stateButton = state;
}
SDL_Point Button::getPositionTopLeft(){
    return positionTopLeft;
}
pair<int,int> Button::getLengthOfButton(){
    return lengthOfButton;
}
int Button::getStateButton(){
    return stateButton;
}
bool Button::handleEventButton(SDL_Event e, int typeOfButton, int statePre, int stateNext){
    bool changed = 0;
    if(e.type == SDL_MOUSEBUTTONDOWN){
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(checkInsideButton(x, y) == 1){
            if(stateButton == statePre){
                stateButton = stateNext;
                changed = 1;
            }
        }
    }
    return changed;
}
bool Button::checkInsideButton(int x,int y){
    if(x <= positionTopLeft.x || x >= positionTopLeft.x + lengthOfButton.first) return false;
    if(y <= positionTopLeft.y || y >= positionTopLeft.y + lengthOfButton.second) return false;
    return true;
}
void Button::render(SDL_Renderer* renderer, bool haveRenderPresent, bool havePattern){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    if(stateButton){
        if(typeOfButton == SQUARE_GAME){
            if(!haveRenderPresent){
                RenderMedia(renderer, dataImageButton[typeOfButton][stateButton],
                            positionTopLeft.x, positionTopLeft.y, lengthOfButton.first, lengthOfButton.second);
            }
            else {
                RenderMedia(renderer, dataImageButton[typeOfButton][stateButton + 2],
                        positionTopLeft.x, positionTopLeft.y, lengthOfButton.first, lengthOfButton.second);
            }
        }
        else {
            RenderMedia(renderer, dataImageButton[typeOfButton][stateButton],
                            positionTopLeft.x, positionTopLeft.y, lengthOfButton.first, lengthOfButton.second);
        }
    }
    if(havePattern){
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y, positionTopLeft.x + lengthOfButton.first, positionTopLeft.y);
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y, positionTopLeft.x, positionTopLeft.y + lengthOfButton.second);
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y + lengthOfButton.second, positionTopLeft.x + lengthOfButton.first, positionTopLeft.y + lengthOfButton.second);
        SDL_RenderDrawLine(renderer, positionTopLeft.x + lengthOfButton.first, positionTopLeft.y, positionTopLeft.x + lengthOfButton.first, positionTopLeft.y + lengthOfButton.second);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if(haveRenderPresent) SDL_RenderPresent(renderer);
}
#endif
