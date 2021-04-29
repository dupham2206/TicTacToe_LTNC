
#ifndef AI_H
#define AI_H
#include<iostream>
#include<algorithm>
#include "button.h"
using namespace std;
class AI {
private:
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
    int manhattanDistanceToCenterSquare(int x , int y){
        return abs(x - (sizeOfBoard.second + 1)/2) + abs(y - (sizeOfBoard.first + 1)/2);

    }
    pair<int,int> bestMove(){
        cntStep = 0;
        pair<int,int> thisMove = {0, 0}; // 0,0 is the position not exist in map
        int score = 0, bestScore = -1e8; // -1e8 is StateLOSE
        int cntChild = 0;
        int valueStandard;
        int depth;

        if(numStepToWin == 3) depth = 9;
        if(numStepToWin == 5) depth = 4;

        if(numStepToWin == 6){
            cntSizeOfValueEvaluate = 0;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == STATE_EMPTY){
                        boardState[i][j] = STATE_AI;
                        valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue();
                        cout << i << " " << j << " " << valueEvaluate[cntSizeOfValueEvaluate] << "\n";
                        boardState[i][j] = STATE_EMPTY;
                        ++cntSizeOfValueEvaluate;
                    }
                }
            }
            sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
            valueStandard = valueEvaluate[cntSizeOfValueEvaluate / 2];
        }
        for(int i = 1; i <= sizeOfBoard.second; ++i){
            for(int j = 1; j <= sizeOfBoard.first; ++j){
                if(boardState[i][j] == STATE_EMPTY){
                    boardState[i][j] = STATE_AI;
                    if(numStepToWin == 6){
                        if(heuristicValue() < valueStandard){
                                boardState[i][j] = STATE_EMPTY;
                                continue;
                        }
                    }

                    score = minimax(false, -1e8, 1e8, depth - 1);
                    boardState[i][j] = STATE_EMPTY;
                    if(score > bestScore) bestScore = score, thisMove = {j, i};

                    if(numStepToWin == 6){
                        cntChild++;
                        if(cntChild > cntSizeOfValueEvaluate / 2) break;
                    }
                }
            }
        }
        cout << "\n" << bestScore << "\n" << cntStep << "\n";
        return thisMove;
    }
    int minimax(bool isTurnOfAI, int alpha, int beta, int depth){
        ++cntStep;
        int score = 0, bestScore = 0;
        int valueStandard, cntChild = 0;
        if(havePlayer_win(STATE_AI)) return 1e8;
        else if(havePlayer_win(STATE_PLAYER)) return -1e8;
        else if(gameOver(sizeOfBoard)) return 0;
        if(depth == 1) return heuristicValue();
        if(isTurnOfAI == true){
            if(numStepToWin == 6){
                cntSizeOfValueEvaluate = 0;
                for(int i = 1; i <= sizeOfBoard.second; ++i){
                    for(int j = 1; j <= sizeOfBoard.first; ++j){
                        if(boardState[i][j] == STATE_EMPTY){
                            boardState[i][j] = STATE_AI;
                            valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue();
                            boardState[i][j] = STATE_EMPTY;
                            ++cntSizeOfValueEvaluate;
                        }
                    }
                }
                sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
                valueStandard = valueEvaluate[cntSizeOfValueEvaluate * 2 / 3];
            }
            bestScore = -1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == STATE_EMPTY){
                        boardState[i][j] = STATE_AI;
                        if(numStepToWin == 6){
                            if(heuristicValue() < valueStandard){
                                boardState[i][j] = STATE_EMPTY;
                                continue;
                            }
                        }

                        score = minimax(false, alpha, beta, depth - 1);
                        boardState[i][j] = STATE_EMPTY;
                        bestScore = max(bestScore, score);
                        alpha = max(alpha, bestScore);
                        if(alpha >= beta) return bestScore;

                        if(numStepToWin == 6){
                            ++cntChild;
                            if(cntChild > cntSizeOfValueEvaluate / 3) break;
                        }
                    }
                }
            }
            return bestScore;
        }
        else {
            if(numStepToWin == 6){
                cntSizeOfValueEvaluate = 0;
                for(int i = 1; i <= sizeOfBoard.second; ++i){
                    for(int j = 1; j <= sizeOfBoard.first; ++j){
                        if(boardState[i][j] == STATE_EMPTY){
                            boardState[i][j] = STATE_PLAYER;
                            valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue();

                            boardState[i][j] = STATE_EMPTY;
                            ++cntSizeOfValueEvaluate;
                        }
                    }
                }
                sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
                valueStandard = valueEvaluate[cntSizeOfValueEvaluate / 3];
            }
            bestScore = 1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == STATE_EMPTY){
                        boardState[i][j] = STATE_PLAYER;

                        if(numStepToWin == 6){
                            if(heuristicValue() > valueStandard){
                                boardState[i][j] = STATE_EMPTY;
                                continue;
                            }
                        }

                        score = minimax(true, alpha, beta, depth - 1);
                        boardState[i][j] = STATE_EMPTY;
                        bestScore = min(bestScore, score);
                        beta = min(beta, bestScore);
                        if(alpha >= beta) return bestScore;

                        if(numStepToWin == 6){
                            ++cntChild;
                            if(cntChild > cntSizeOfValueEvaluate / 3) break;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
    int heuristicValue(){
        if(havePlayer_win(STATE_AI)) return 1e8;
        if(havePlayer_win(STATE_PLAYER)) return -1e8;
        if(gameOver(sizeOfBoard)) return 0;
        int value = 0;
        for(int x = 1; x <= sizeOfBoard.second; ++x){
            for(int y = 1; y <= sizeOfBoard.first; ++y){
                if(boardState[x][y] == 1){ // STATE_PLAYER = 1
                    int curValue = 1;
                    for(int i = 0; i < 4; ++i){
                        int lengthCanBeWin = cntContinueHard(x, y, dx[i], dy[i], 1);
                        if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    }
                    if(curValue != 1) value -= curValue;
                }
                if(boardState[x][y] == 2){ // STATE_AI = 2
                    int curValue = 1;
                    for(int i = 0; i < 4; ++i){
                        int lengthCanBeWin = cntContinueHard(x, y, dx[i], dy[i], 2);
                        if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    }
                    if(curValue != 1) value += curValue;
                }
            }
        }
        return value;
    }
    int cntContinueMedium(int x, int y, int dx, int dy, int statePlayer){
        int cntLeft = 0, cntRight = 0, cntFarLeft = 0, cntFarRight = 0;
        int blockLeft = 0, blockRight = 0;
        for(int i = 0; ; ++i){
            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                ++blockLeft;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                    ++i; cntLeft++;
                    while(checkInsideBoard(x + i * dx, y + i * dy)){
                        if(boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){ ++blockLeft; break; }
                        if(boardState[x + i * dx][ y + i * dy] == STATE_EMPTY) break;
                        ++i;++cntFarLeft;
                    }
                    break;
            }
            cntLeft++;
        }
        ////
        for(int i = 0; ; --i){
            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                ++blockRight;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                    --i; cntRight++;
                    while(checkInsideBoard(x + i * dx, y + i * dy)){
                        if(boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){ ++blockRight; break; }
                        if(boardState[x + i * dx][ y + i * dy] == STATE_EMPTY) break;
                        --i; ++cntFarRight;
                    }
                    break;
            }
            cntRight++;
        }
        int cntWin = cntLeft + cntRight - 1 + max(cntFarLeft, cntFarRight) - blockLeft - blockRight;
        if(blockLeft + blockRight == 2 && cntWin <= 4) return 0;
        if(cntWin <= 1) return 0;
        return cntWin;
    }
    int cntContinueHard(int x, int y, int dx, int dy, int statePlayer){
        int cntWin = 0, block = 0;
        bool HaveEmpty = 0;
        for(int i = 1; i <= 4; ++i){
            if(!checkInsideBoard(x + i * dx, y + i * dy)){
                block++;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == statePlayer) cntWin += 3;
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                if(HaveEmpty == 0){
                    cntWin++;  HaveEmpty = 1;
                }
                else break;
            }
            if(boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                block++;
                break;
            }
        }
        HaveEmpty = 0;
        for(int i = -1; i >= -4; --i){
            if(!checkInsideBoard(x + i * dx, y + i * dy)){
                block++;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == statePlayer) cntWin += 3;
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                if(HaveEmpty == 0){
                    cntWin++;   HaveEmpty = 1;
                }
                else break;
            }
            if(boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                block++;
                break;
            }
        }
        cntWin += 3;
        if(block == 2){
            if(cntWin >= 13) cntWin = 16;
            else if(cntWin >= 11) cntWin = 2;
            else return 0;
        }
        if(block == 1){
            if(cntWin >= 13) cntWin = 16;
            else if(cntWin >= 10) cntWin = 2;
            else return 0;
        }
        if(block == 0){
            if(cntWin >= 13) cntWin = 128;
            else if(cntWin >= 11) cntWin = 16;
            else if(cntWin >= 8) cntWin = 2;
            else return 0;
        }
        if(statePlayer == 1) return cntWin * 2;
        else return cntWin;
    }
    bool checkInsideBoard(int x,int y){
        if(x < 1 || y < 1 || x > sizeOfBoard.second || y > sizeOfBoard.first) return 0;
        return 1;
    }
    bool havePlayer_win(int turnOfPlayer){
        bool yes = 0;
        int sizX = sizeOfBoard.first, sizY = sizeOfBoard.second;
        for(int i = 1; i <= sizY; ++i){
            for(int j = 1; j <= sizX; ++j){
                if(boardState[i][j] == turnOfPlayer){
                    for(int k = 0; k < 4; ++k){
                        if(i + (numStepToWin - 1) * dy[k] <= sizY && i + (numStepToWin - 1) * dy[k] >= 1 &&
                           j + (numStepToWin - 1) * dx[k] <= sizX && j + (numStepToWin - 1) * dx[k] >= 1){
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
    bool gameOver(pair<int,int> sizeOfBoard){
        for(int i = 1; i <= sizeOfBoard.second; ++i)
            for(int j = 1; j <= sizeOfBoard.first; ++j)
                if(!boardState[i][j]) return 0;
        return 1;
    }
};


#endif

