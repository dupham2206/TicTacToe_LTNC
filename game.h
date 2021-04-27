#ifndef GAME_H
#define GAME_H


#include<iostream>
#include "button.h"
#include "AI.h"

using namespace std;


class Game {
private:
    Button square[20][20];
    Button restartButton;
    Button returnMenuButton;
    AI botPlayer;
    int numberOfPieceConsecutiveToWin = 5;
    pair<int,int> sizeOfBoard;
    pair<int,int> squareHavingPlayed;
    int turnOfPlayer = 1;
    int winner = 0; // = 0: not endgame, 1: p1 win, 2: p2 win, 3: Draw
    bool PlayWithAI = 1;
    int AIadmitLose = 0;
    int stateOfBulletinBoard;
    //bool AIrun = 0;
public:
    bool checkFullLandOfPlayer(int posX, int posY, int dX, int dY, int landOfPlayer){
        for(int i = 0; i < numberOfPieceConsecutiveToWin; ++i){
            int recentX = posX + dX * i, recentY = posY + dY * i;
            if(recentX < 1 || recentX > sizeOfBoard.first ||
               recentY < 1 || recentY > sizeOfBoard.second ||
               square[recentX][recentY].getStateButton() != landOfPlayer)
                return 0;
        }
        return 1;
    }
    void setWhoPlay(int AIplay){
        PlayWithAI = AIplay;
        if(AIplay == 1) stateOfBulletinBoard = YOUR_TURN;
        else stateOfBulletinBoard = PLAYER1_TURN;
    }
    void setSizeOfBoard(int x,int y){
            sizeOfBoard.first = x;
            sizeOfBoard.second = y;
            botPlayer.setSizeOfBoard(x , y);
    }
    void setNumberOfPieceConsecutiveToWin(int number){
            numberOfPieceConsecutiveToWin = number;
            botPlayer.setNumStepToWin(number);
    }
    void setAllAttribute(){
        for(int i = 1; i <= sizeOfBoard.first; ++i){
            for(int j = 1; j <= sizeOfBoard.second; ++j){
                int len = min(SCREEN_HEIGHT / sizeOfBoard.first, SCREEN_HEIGHT / sizeOfBoard.second);
                square[i][j].setLengthOfButton(len, len);
                square[i][j].setPositionTopLeft((i - 1) * square[i][j].getLengthOfButton().first, (j - 1) * square[i][j].getLengthOfButton().second);
                square[i][j].setTypeOfButton(SQUARE_GAME);
                botPlayer.setBoardState(j , i, 0);
            }
        }
        restartButton.setPositionTopLeft(SCREEN_HEIGHT + SCREEN_HEIGHT / 32, SCREEN_HEIGHT - (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8);
        restartButton.setLengthOfButton( (SCREEN_WIDTH - SCREEN_HEIGHT ) * 3 / 4, (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8 );
        restartButton.setTypeOfButton(RESTART_GAME);
        restartButton.setStateButton(1);

        returnMenuButton.setPositionTopLeft(SCREEN_HEIGHT + SCREEN_HEIGHT / 32, SCREEN_HEIGHT - (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 4);
        returnMenuButton.setLengthOfButton( (SCREEN_WIDTH - SCREEN_HEIGHT ) * 3 / 4, (SCREEN_WIDTH - SCREEN_HEIGHT) * 3 / 8 );
        returnMenuButton.setTypeOfButton(RETURN_MENU_GAME);
        returnMenuButton.setStateButton(1);

    }
    void changeTurn(SDL_Renderer* renderer){
        turnOfPlayer = 3 - turnOfPlayer;
        if(PlayWithAI == 1){
            if(turnOfPlayer == 1) stateOfBulletinBoard = YOUR_TURN;
            else stateOfBulletinBoard = AI_TURN;
        }
        else {
            if(turnOfPlayer == 1) stateOfBulletinBoard = PLAYER1_TURN;
            else stateOfBulletinBoard = PLAYER2_TURN;

        }
        renderBulletinBoard(renderer);
    }

    int PlayerWinGame(){
        int cntSquarePlayed = 0;
        for(int i = 1; i <= sizeOfBoard.first; ++i){
            for(int j = 1; j <= sizeOfBoard.second; ++j){
                int landOfPlayer = square[i][j].getStateButton();
                if(landOfPlayer){ // square have X or O
                    ++cntSquarePlayed;
                    for(int k = 0; k < 8; ++k)
                        if(checkFullLandOfPlayer(i, j, directX[k], directY[k], landOfPlayer)) return landOfPlayer;
                }
            }
        }
        if(cntSquarePlayed == sizeOfBoard.first * sizeOfBoard.second) return 3;
        return 0;
    }
    void AiMove(SDL_Renderer* renderer){
        if(winner) return;
        pair<int,int> bestMove = botPlayer.bestMove();
        int y = bestMove.second, x = bestMove.first;
        square[x][y].setStateButton(turnOfPlayer);
        square[squareHavingPlayed.first][squareHavingPlayed.second].render(renderer, 0, 1);
        square[x][y].render(renderer, 1, 1);
        squareHavingPlayed = {x , y};
        botPlayer.setBoardState(y , x, turnOfPlayer);
        changeTurn(renderer);
        winner = PlayerWinGame();
        if(x == 0 && y == 0){
            winner = 1;
            stateOfBulletinBoard = ENDGAME_ADMIT_LOSE;
        }
        if(winner) endGame(renderer);
    }
    void handleEvent(SDL_Window* window, SDL_Renderer* renderer, bool &inGame){
        SDL_Event e;
        SDL_WaitEvent(&e);
        //if(PlayWithAI) return;
        //while(SDL_PollEvent( &e )){
            if(e.type == SDL_QUIT) quitSDL(window, renderer);
            if(e.type == SDL_MOUSEBUTTONDOWN){
                if(!winner){
                    for(int i = 1; i <= sizeOfBoard.first; ++i){
                        for(int j = 1; j <= sizeOfBoard.second; ++j){
                            if(square[i][j].handleEventButton(e,SQUARE_GAME,0, turnOfPlayer) == 1){
                                square[squareHavingPlayed.first][squareHavingPlayed.second].render(renderer, 0, 1);
                                square[i][j].render(renderer, 1, 1);
                                squareHavingPlayed = {i , j};
                                botPlayer.setBoardState(j , i, turnOfPlayer);
                                changeTurn(renderer);
                                winner = PlayerWinGame();
                                if(winner) endGame(renderer);
                                if(PlayWithAI) AiMove(renderer);
                                break;

                            }
                        }
                    }
                }
                if(returnMenuButton.handleEventButton(e , RETURN_MENU_GAME, 1, 1) == 1) inGame = 0;
                if(restartButton.handleEventButton(e, RESTART_GAME, 1, 1) == 1) restart(renderer);
                if(!winner) winner = PlayerWinGame();
                if(winner) endGame(renderer);
            }
        //}
    }
    void restart(SDL_Renderer* renderer){
        turnOfPlayer = 1;
        stateOfBulletinBoard = (PlayWithAI ? YOUR_TURN : PLAYER1_TURN);
        winner = 0;
        for(int i = 1; i <= sizeOfBoard.first; ++i){
            for(int j = 1; j <= sizeOfBoard.second; ++j){
                square[i][j].setStateButton(0);
                botPlayer.setBoardState(j , i, 0);
            }
        }
        render(renderer);
    }
    void renderBulletinBoard(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        RenderMedia(renderer, dataImageButton[BULLETIN_BOARD_PREGAME][stateOfBulletinBoard],
                    3 * SCREEN_WIDTH / 4, 0, SCREEN_WIDTH/ 4, SCREEN_HEIGHT / 3);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderPresent(renderer);
    }
    void endGame(SDL_Renderer* renderer){
        if(winner == 3){
            RenderMedia(renderer, dataImageButton[ENDGAME_GAME][DRAW],
                    3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
        }
        if(winner == 2){
            if(PlayWithAI){
                RenderMedia(renderer, dataImageButton[ENDGAME_GAME][YOU_LOSE],
                    3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
            }
            else {
                RenderMedia(renderer, dataImageButton[ENDGAME_GAME][PLAYER2_WIN],
                    3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
            }
        }
        else if(winner == 1) {
            if(PlayWithAI){
                RenderMedia(renderer, dataImageButton[ENDGAME_GAME][YOU_WIN],
                    3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
            }
            else {
                RenderMedia(renderer, dataImageButton[ENDGAME_GAME][PLAYER1_WIN],
                    3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 , SCREEN_WIDTH/ 4, SCREEN_WIDTH * 5 / 48);
            }
        }
        if(stateOfBulletinBoard != ENDGAME_ADMIT_LOSE) stateOfBulletinBoard = ENDGAME;
        renderBulletinBoard(renderer);
        SDL_RenderPresent(renderer);
    }
    void render(SDL_Renderer* renderer){
        SDL_RenderClear(renderer);
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // black
        for(int i = 1; i <= sizeOfBoard.first; ++i){
            for(int j = 1; j <= sizeOfBoard.second; ++j){
                square[i][j].render(renderer, 1, 1);
            }
        }
        restartButton.render(renderer, 1, 0);
        returnMenuButton.render(renderer, 1, 0);
        renderBulletinBoard(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
        SDL_RenderPresent(renderer);
    }
};




#endif //GAME_H
