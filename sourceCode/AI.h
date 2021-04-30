
#ifndef AI_H
#define AI_H
#include<iostream>
#include<algorithm>
#include "button.h"
using namespace std;
class AI {
protected:
    int cntStep = 0;
    const int dx[10] = {1, 1, 0, -1, 0, 1, -1, -1};
    const int dy[10] = {1, 0, 1, 1, -1, -1, 0, -1};
    int boardState[15][15];
    pair<int,int> sizeOfBoard;
    int numStepToWin;

    int valueEvaluate[200];
    int cntSizeOfValueEvaluate = 0;

public:
    void setBoardState(int i,int j, int value){
        boardState[i][j] = value;
    }
    void setSizeOfBoard(int x,int y){
        sizeOfBoard = {x, y};
    }
    void setNumStepToWin(int value){
        numStepToWin = value;
    }
    pair<int,int> bestMove(){
        cntStep = 0;
        pair<int,int> thisMove = {0, 0}; // 0,0 is the position not exist in map
        int score = 0, bestScore = -1e8; // -1e8 is StateLOSE
        int cntChild = 0;
        int valueStandard;
        int depth;
        if(numStepToWin == 3) depth = 9;
        else depth = 4;
        for(int i = 1; i <= sizeOfBoard.second; ++i){
            for(int j = 1; j <= sizeOfBoard.first; ++j){
                if(boardState[i][j] == STATE_EMPTY){
                    boardState[i][j] = STATE_AI;
                    score = minimax(false, -1e8, 1e8, depth - 1);
                    boardState[i][j] = STATE_EMPTY;
                    if(score > bestScore) bestScore = score, thisMove = {j, i};
                }
            }
        }
        cout << "\n" <<  bestScore << "\n" << cntStep << "\n";
        return thisMove;
    }
    int minimax(bool isTurnOfAI, int alpha, int beta, int depth){
        ++cntStep;
        int score = 0, bestScore = 0;
        int valueStandard, cntChild = 0;
        if(havePlayer_win(STATE_AI)) return 1e8;
        else if(havePlayer_win(STATE_PLAYER)) return -1e8;
        else if(gameOver()) return 0;
        if(depth == 1) return heuristicValue();
        if(isTurnOfAI == true){
            bestScore = -1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == STATE_EMPTY){
                        boardState[i][j] = STATE_AI;
                        score = minimax(false, alpha, beta, depth - 1);
                        boardState[i][j] = STATE_EMPTY;
                        bestScore = max(bestScore, score);
                        alpha = max(alpha, bestScore);
                        if(alpha >= beta) return bestScore;
                    }
                }
            }
            return bestScore;
        }
        else {
            bestScore = 1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == STATE_EMPTY){
                        boardState[i][j] = STATE_PLAYER;
                        score = minimax(true, alpha, beta, depth - 1);
                        boardState[i][j] = STATE_EMPTY;
                        bestScore = min(bestScore, score);
                        beta = min(beta, bestScore);
                        if(alpha >= beta) return bestScore;
                    }
                }
            }
            return bestScore;
        }
    }
    int heuristicValue(){
        int value = 0;
        for(int x = 1; x <= sizeOfBoard.second; ++x){
            for(int y = 1; y <= sizeOfBoard.first; ++y){
                if(boardState[x][y] == 1){ // STATE_PLAYER = 1
                    int curValue = 1;
                    for(int i = 0; i < 4; ++i){
                        int lengthCanBeWin = cntContinue(x, y, dx[i], dy[i], 1);
                        if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    }
                    if(curValue != 1) value -= curValue;
                }
                if(boardState[x][y] == 2){ // STATE_AI = 2
                    int curValue = 1;
                    for(int i = 0; i < 4; ++i){
                        int lengthCanBeWin = cntContinue(x, y, dx[i], dy[i], 2);
                        if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    }
                    if(curValue != 1) value += curValue;
                }
            }
        }
        return value;
    }
    virtual int cntContinue(int x, int y, int dx, int dy, int statePlayer){}
    bool checkInsideBoard(int x,int y){
        if(x < 1 || y < 1 || x > sizeOfBoard.second || y > sizeOfBoard.first) return 0;
        return 1;
    }
    bool havePlayer_win(int turnOfPlayer){
        bool yes = 0;
        for(int i = 1; i <= sizeOfBoard.second; ++i){
            for(int j = 1; j <= sizeOfBoard.first; ++j){
                if(boardState[i][j] == turnOfPlayer){
                    for(int k = 0; k < 4; ++k){
                        if(checkInsideBoard(i + (numStepToWin - 1) * dy[k],
                                             j + (numStepToWin - 1) * dx[k])){
                            yes = 1;
                            for(int m = 1; m < numStepToWin; ++m){
                                if(boardState[i + m * dy[k]][j + m * dx[k]] != turnOfPlayer){
                                    yes = 0;
                                    break;
                                }
                            }
                            if(yes == 1){
                                return true;
                            }

                        }
                    }
                }
            }
        }
        return false;
    }
    bool gameOver(){
        for(int i = 1; i <= sizeOfBoard.second; ++i)
            for(int j = 1; j <= sizeOfBoard.first; ++j)
                if(!boardState[i][j]) return 0;
        return 1;
    }
};


#endif

