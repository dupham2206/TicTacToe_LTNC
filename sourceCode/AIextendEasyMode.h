#ifndef AIEXTENDEASYMODE_H
#define AIEXTENDEASYMODE_H
#include "AI.h"

class AIextendEasyMode: public AI {
public:
    int cntContinue(int x, int y, int dx, int dy, int statePlayer){
        if(statePlayer == 2) return 0; // AI cant attack player
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
        return cntWin;
    }
};
#endif

