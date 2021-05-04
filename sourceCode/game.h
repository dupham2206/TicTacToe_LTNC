#ifndef GAME_H
#define GAME_H

#include<iostream>
#include "AI.h"
#include "AIextendHardMode.h"
#include "AIextendMediumMode.h"
#include "AIextendEasyMode.h"
#include "button.h"

using namespace std;


class Game {
    Button square[20][20];
    Button restartButton;
    Button returnMenuButton;
    AI* botPlayer;
    int stateOfBulletinBoard;
    int stateSound;
    int numberOfPieceConsecutiveToWin;
    pair<int,int> sizeOfBoard;
    pair<int,int> squareHavingPlayed;
    int turnOfPlayer = FIRST_PLAYER;
    int winner = NOT_ENDGAME;
    bool isPlayWithAI;
    const int directX[10] = {1, 1, 0, 1, 0, -1, -1, -1};
    const int directY[10] = {1, 0, 1, -1, -1, 1, 0, -1};
private:
    bool checkFullLandOfPlayer(int posX, int posY, int dX, int dY, int landOfPlayer);
    void setAttributeForAllSquares();
    void setAttributeForRestartButton();
    void setAttributeForReturnMenuButton();
    void changeTurn(SDL_Renderer* renderer);
    int PlayerWinGame();
    void AiMove(SDL_Renderer* renderer);
    void restart(SDL_Renderer* renderer);
    void renderBulletinBoard(SDL_Renderer* renderer);
    void endGame(SDL_Renderer* renderer);
public:
    void setWhoPlay(int AIplay);
    void setSizeOfBoard(int x,int y);
    void setNumberOfPieceConsecutiveToWin(int number);
    void setLevelOfAI(int stateLevel);
    void setStateSound(int state);
    void setAllAttribute();
    void handleEvent(SDL_Window* window, SDL_Renderer* renderer, bool &inGame);
    void render(SDL_Renderer* renderer);
};

bool Game::checkFullLandOfPlayer(int posX, int posY, int dX, int dY, int landOfPlayer){
    for(int i = 0; i < numberOfPieceConsecutiveToWin; ++i){
        int recentX = posX + dX * i, recentY = posY + dY * i;
        if(recentX < 1 || recentX > sizeOfBoard.first ||
           recentY < 1 || recentY > sizeOfBoard.second ||
           square[recentX][recentY].getStateButton() != landOfPlayer)
            return 0;
    }
    return 1;
}


void Game::setAttributeForAllSquares(){
    for(int i = 1; i <= sizeOfBoard.first; ++i){
        for(int j = 1; j <= sizeOfBoard.second; ++j){
            int len = min(SCREEN_HEIGHT / sizeOfBoard.first, SCREEN_HEIGHT / sizeOfBoard.second);
            square[i][j].setLengthOfButton(len, len);
            square[i][j].setPositionTopLeft((i - 1) * square[i][j].getLengthOfButton().first,
                                             (j - 1) * square[i][j].getLengthOfButton().second);
            square[i][j].setTypeOfButton(SQUARE_GAME);
            botPlayer->setBoardState(j , i, STATE_EMPTY);
        }
    }
}

void Game::setAttributeForRestartButton(){
    restartButton.setPositionTopLeft(SCREEN_HEIGHT + SCREEN_HEIGHT / 32,
                                     SCREEN_HEIGHT - (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8);
    restartButton.setLengthOfButton( (SCREEN_WIDTH - SCREEN_HEIGHT ) * 3 / 4,
                                    (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8 );
    restartButton.setTypeOfButton(RESTART_GAME);
    restartButton.setStateButton(1);
}
void Game::setAttributeForReturnMenuButton(){
    returnMenuButton.setPositionTopLeft(SCREEN_HEIGHT + SCREEN_HEIGHT / 32,
                                         SCREEN_HEIGHT - (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 4);
    returnMenuButton.setLengthOfButton( (SCREEN_WIDTH - SCREEN_HEIGHT ) * 3 / 4,
                                       (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8 );
    returnMenuButton.setTypeOfButton(RETURN_MENU_GAME);
    returnMenuButton.setStateButton(1);
}
void Game::changeTurn(SDL_Renderer* renderer){
    turnOfPlayer = FIRST_PLAYER + SECOND_PLAYER - turnOfPlayer;
    // change bulletin board
    if(isPlayWithAI == true){
        if(turnOfPlayer == FIRST_PLAYER) stateOfBulletinBoard = YOUR_TURN;
        else stateOfBulletinBoard = AI_TURN;
    }
    else {
        if(turnOfPlayer == FIRST_PLAYER) stateOfBulletinBoard = PLAYER1_TURN;
        else stateOfBulletinBoard = PLAYER2_TURN;

    }
    renderBulletinBoard(renderer);
}
int Game::PlayerWinGame(){
    int cntSquarePlayed = 0;
    for(int i = 1; i <= sizeOfBoard.first; ++i){
        for(int j = 1; j <= sizeOfBoard.second; ++j){
            int landOfPlayer = square[i][j].getStateButton();
            if(landOfPlayer){ // square have X or O
                ++cntSquarePlayed;
                for(int k = 0; k < 8; ++k)
                    if(checkFullLandOfPlayer(i, j, directX[k], directY[k], landOfPlayer)){
                        return landOfPlayer;
                    }
            }
        }
    }
    if(cntSquarePlayed == sizeOfBoard.first * sizeOfBoard.second)
        return TWO_PLAYER_DRAW;
    return NOT_ENDGAME;
}
void Game::AiMove(SDL_Renderer* renderer){
    if(winner != NOT_ENDGAME) return;
    pair<int,int> bestMove = botPlayer->bestMove();
    int y = bestMove.second, x = bestMove.first;
    square[x][y].setStateButton(turnOfPlayer);
    square[x][y].setTypeOfButton(SQUARE_GAME_HAVEPLAYED);
    square[squareHavingPlayed.first][squareHavingPlayed.second].setTypeOfButton(SQUARE_GAME);
    square[squareHavingPlayed.first][squareHavingPlayed.second].render(renderer, 0, 1);
    square[x][y].render(renderer, 1, 1);
    squareHavingPlayed = {x , y};
    if(stateSound == ON) Mix_PlayChannel(-1, dataChunk[CLICK], 0);
    botPlayer->setBoardState(y , x, turnOfPlayer);
    changeTurn(renderer);
    winner = PlayerWinGame();
    if(x == 0 && y == 0){
        winner = 1;
        stateOfBulletinBoard = ENDGAME_ADMIT_LOSE;
    }
    if(winner != NOT_ENDGAME) endGame(renderer);
}
void Game::restart(SDL_Renderer* renderer){
    turnOfPlayer = FIRST_PLAYER;
    stateOfBulletinBoard = (isPlayWithAI ? YOUR_TURN : PLAYER1_TURN);
    winner = NOT_ENDGAME;
    for(int i = 1; i <= sizeOfBoard.first; ++i){
        for(int j = 1; j <= sizeOfBoard.second; ++j){
            square[i][j].setStateButton(0);
            botPlayer->setBoardState(j , i, 0);
        }
    }
    render(renderer);
}
void Game::renderBulletinBoard(SDL_Renderer* renderer){
    RenderMedia(renderer, dataImage[BULLETIN_BOARD_PREGAME][stateOfBulletinBoard],
                3 * SCREEN_WIDTH / 4, 0, SCREEN_WIDTH/ 4, SCREEN_HEIGHT / 3);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}
void Game::endGame(SDL_Renderer* renderer){
    if(stateSound == ON) Mix_PlayChannel(-1, dataChunk[ENDGAME_MUSIC], 0);
    if(winner == TWO_PLAYER_DRAW){
        RenderMedia(renderer, dataImage[ENDGAME_GAME][DRAW],
                3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
    }
    if(winner == SECOND_PLAYER){
        if(isPlayWithAI){
            RenderMedia(renderer, dataImage[ENDGAME_GAME][YOU_LOSE],
                3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
        }
        else {
            RenderMedia(renderer, dataImage[ENDGAME_GAME][PLAYER2_WIN],
                3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
        }
    }
    else if(winner == FIRST_PLAYER) {
        if(isPlayWithAI){
            RenderMedia(renderer, dataImage[ENDGAME_GAME][YOU_WIN],
                3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
        }
        else {
            RenderMedia(renderer, dataImage[ENDGAME_GAME][PLAYER1_WIN],
                3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
        }
    }
    if(stateOfBulletinBoard != ENDGAME_ADMIT_LOSE) stateOfBulletinBoard = ENDGAME;
    renderBulletinBoard(renderer);
    SDL_RenderPresent(renderer);
}
void Game::setWhoPlay(int AIplay){
    isPlayWithAI = AIplay;
    if(AIplay == true) stateOfBulletinBoard = YOUR_TURN;
    else stateOfBulletinBoard = PLAYER1_TURN;
}
void Game::setSizeOfBoard(int x,int y){
        sizeOfBoard.first = x;
        sizeOfBoard.second = y;
        botPlayer->setSizeOfBoard(x , y);
}
void Game::setNumberOfPieceConsecutiveToWin(int number){
        numberOfPieceConsecutiveToWin = number;
        botPlayer->setNumStepToWin(number);
}
void Game::setLevelOfAI(int stateLevel){
    if(stateLevel == EASY || stateLevel == NOT_HAVE_ANYTHING) botPlayer = new AIextendEasyMode();
    if(stateLevel == MEDIUM) botPlayer = new AIextendMediumMode();
    if(stateLevel == HARD) botPlayer = new AIextendHardMode();
}
void Game::setStateSound(int state){
    stateSound = state;
}
void Game::setAllAttribute(){
    setAttributeForAllSquares();
    setAttributeForRestartButton();
    setAttributeForReturnMenuButton();
}
void Game::handleEvent(SDL_Window* window, SDL_Renderer* renderer, bool &inGame){
    SDL_Event e;
    SDL_WaitEvent(&e);
    if(e.type == SDL_QUIT) quitSDL(window, renderer);
    if(e.type == SDL_MOUSEBUTTONDOWN){
        if(winner == NOT_ENDGAME){
            for(int i = 1; i <= sizeOfBoard.first; ++i){
                for(int j = 1; j <= sizeOfBoard.second; ++j){
                    if(square[i][j].handleEventButton(e,SQUARE_GAME, 0, turnOfPlayer) == 1){
                        square[i][j].setTypeOfButton(SQUARE_GAME_HAVEPLAYED);
                        square[squareHavingPlayed.first][squareHavingPlayed.second].setTypeOfButton(SQUARE_GAME);
                        square[squareHavingPlayed.first][squareHavingPlayed.second].render(renderer, 0, 1);
                        square[i][j].render(renderer, 1, 1);
                        squareHavingPlayed = {i , j};
                        if(stateSound == ON) Mix_PlayChannel(-1, dataChunk[CLICK], 0);
                        botPlayer->setBoardState(j , i, turnOfPlayer);
                        changeTurn(renderer);
                        winner = PlayerWinGame();
                        if(winner != NOT_ENDGAME) endGame(renderer);
                        if(isPlayWithAI) AiMove(renderer);
                        break;

                    }
                }
            }
        }
        if(returnMenuButton.handleEventButton(e , RETURN_MENU_GAME, true, true) == true)
            inGame = false;
        if(restartButton.handleEventButton(e, RESTART_GAME, true, true) == true)
            restart(renderer);
    }
}
void Game::render(SDL_Renderer* renderer){
    SDL_RenderClear(renderer);
    for(int i = 1; i <= sizeOfBoard.first; ++i){
        for(int j = 1; j <= sizeOfBoard.second; ++j){
            square[i][j].render(renderer, true, true);
        }
    }
    restartButton.render(renderer, true, false);
    returnMenuButton.render(renderer, true, false);
    renderBulletinBoard(renderer);
    SDL_RenderPresent(renderer);
}



#endif //GAME_H

