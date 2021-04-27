
#ifndef AI_H
#define AI_H
#include<iostream>
#include<algorithm>
using namespace std;
class AI {
private:
    enum stateOfaSquare {
        StateEmpty,
        StatePLAYER,
        StateAI
    };
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
        if(numStepToWin == 4) depth = 6;
        if(numStepToWin == 5) depth = 5;

        if(numStepToWin == 5){
            cntSizeOfValueEvaluate = 0;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == StateEmpty){
                        boardState[i][j] = StateAI;
                        valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue()
                        - manhattanDistanceToCenterSquare(i, j);
                        boardState[i][j] = StateEmpty;
                        ++cntSizeOfValueEvaluate;
                    }
                }
            }
            sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
            valueStandard = valueEvaluate[cntSizeOfValueEvaluate / 2];
        }
        for(int i = 1; i <= sizeOfBoard.second; ++i){
            for(int j = 1; j <= sizeOfBoard.first; ++j){
                if(boardState[i][j] == StateEmpty){
                    boardState[i][j] = StateAI;
                    if(numStepToWin == 5){
                        if(heuristicValue() - manhattanDistanceToCenterSquare(i, j) < valueStandard){
                                boardState[i][j] = StateEmpty;
                                continue;
                        }
                    }

                    score = minimax(false, -1e8, 1e8, depth - 1);
                    boardState[i][j] = StateEmpty;
                    if(score > bestScore) bestScore = score, thisMove = {j, i};

                    if(numStepToWin == 5){
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
        if(havePlayer_win(StateAI)) return 1e8;
        else if(havePlayer_win(StatePLAYER)) return -1e8;
        else if(gameOver(sizeOfBoard)) return 0;
        if(depth == 1) return heuristicValue();
        if(isTurnOfAI == 1){
            if(numStepToWin == 5){
                cntSizeOfValueEvaluate = 0;
                for(int i = 1; i <= sizeOfBoard.second; ++i){
                    for(int j = 1; j <= sizeOfBoard.first; ++j){
                        if(boardState[i][j] == StateEmpty){
                            boardState[i][j] = StateAI;
                            valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue()
                             - manhattanDistanceToCenterSquare(i, j);
                            boardState[i][j] = StateEmpty;
                            ++cntSizeOfValueEvaluate;
                        }
                    }
                }
                sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
                valueStandard = valueEvaluate[cntSizeOfValueEvaluate / 2];
            }
            bestScore = -1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == StateEmpty){
                        boardState[i][j] = StateAI;
                        if(numStepToWin == 5){
                            if(heuristicValue()- manhattanDistanceToCenterSquare(i, j) < valueStandard){
                                boardState[i][j] = StateEmpty;
                                continue;
                            }
                        }

                        score = minimax(false, alpha, beta, depth - 1);
                        boardState[i][j] = StateEmpty;
                        bestScore = max(bestScore, score);
                        alpha = max(alpha, bestScore);
                        if(alpha >= beta) return bestScore;

                        if(numStepToWin == 5){
                            ++cntChild;
                            if(cntChild > cntSizeOfValueEvaluate / 2) break;
                        }
                    }
                }
            }
            return bestScore;
        }
        else {
            if(numStepToWin == 5){
                cntSizeOfValueEvaluate = 0;
                for(int i = 1; i <= sizeOfBoard.second; ++i){
                    for(int j = 1; j <= sizeOfBoard.first; ++j){
                        if(boardState[i][j] == StateEmpty){
                            boardState[i][j] = StatePLAYER;
                            valueEvaluate[cntSizeOfValueEvaluate] = heuristicValue()
                            + manhattanDistanceToCenterSquare(i, j);
                            boardState[i][j] = StateEmpty;
                            ++cntSizeOfValueEvaluate;
                        }
                    }
                }
                sort(valueEvaluate, valueEvaluate + cntSizeOfValueEvaluate);
                valueStandard = valueEvaluate[cntSizeOfValueEvaluate / 2];
            }
            bestScore = 1e8;
            for(int i = 1; i <= sizeOfBoard.second; ++i){
                for(int j = 1; j <= sizeOfBoard.first; ++j){
                    if(boardState[i][j] == StateEmpty){
                        boardState[i][j] = StatePLAYER;

                        if(numStepToWin == 5){
                            if(heuristicValue() + manhattanDistanceToCenterSquare(i, j) > valueStandard){
                                boardState[i][j] = StateEmpty;
                                continue;
                            }
                        }

                        score = minimax(true, alpha, beta, depth - 1);
                        boardState[i][j] = StateEmpty;
                        bestScore = min(bestScore, score);
                        beta = min(beta, bestScore);
                        if(alpha >= beta) return bestScore;

                        if(numStepToWin == 5){
                            ++cntChild;
                            if(cntChild > cntSizeOfValueEvaluate / 2) break;
                        }
                    }
                }
            }
            return bestScore;
        }
    }
    int heuristicValue(){
        if(havePlayer_win(StateAI)) return 1e8;
        if(havePlayer_win(StatePLAYER)) return -1e8;
        if(gameOver(sizeOfBoard)) return 0;
        int value = 0;
        for(int x = 1; x <= sizeOfBoard.second; ++x){
            for(int y = 1; y <= sizeOfBoard.first; ++y){
                if(boardState[x][y] == StatePLAYER){
                    int curValue = 1;
                    int lengthCanBeWin = cntContinue(x, y, -1, -1, 1);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, -1, 0, 1);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, 0, -1, 1);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, -1, 1, 1);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    if(curValue != 1) value -= curValue;
                }
                if(boardState[x][y] == StateAI){
                    int curValue = 1;
                    int lengthCanBeWin = cntContinue(x, y, -1, -1, 2);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, -1, 0, 2);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, 0, -1, 2);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    lengthCanBeWin = cntContinue(x, y, -1, 1, 2);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                    if(curValue != 1) value += curValue;
                }
            }
        }
        return value;
    }

    int cntContinue(int x, int y, int dx, int dy, int statePlayer){
        int cntLeft = 0, cntRight = 0, cntFarLeft = 0, cntFarRight = 0;
        int blockLeft = 0, blockRight = 0;
        for(int i = 0; ; ++i){
            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                ++blockLeft;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == StateEmpty){
                    ++i; cntLeft++;
                    while(checkInsideBoard(x + i * dx, y + i * dy)){
                        if(boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){ ++blockLeft; break; }
                        if(boardState[x + i * dx][ y + i * dy] == StateEmpty) break;
                        ++i;++cntFarLeft;
                    }
                    break;
            }
            cntLeft++;
        }
        for(int i = 0; ; --i){
            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                ++blockRight;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == StateEmpty){
                    --i; cntRight++;
                    while(checkInsideBoard(x + i * dx, y + i * dy)){
                        if(boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){ ++blockRight; break; }
                        if(boardState[x + i * dx][ y + i * dy] == StateEmpty) break;
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

    checkInsideBoard(int x,int y){
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
    void check(pair<int,int> sizeOfBoard, int a){
        for(int i = 1; i <= sizeOfBoard.second; ++i)
            for(int j = 1; j <= sizeOfBoard.first; ++j)
                boardState[i][j] = 0;
        boardState[1][1] = 1;
        boardState[4][4] = 2;
        cout << heuristicValue() << " aaaaaaaaa" << "\n";
    }
};


#endif
