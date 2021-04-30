#ifndef AIEXTENDMEDIUMMODE_H
#define AIEXTENDMEDIUMMODE_H
#include "AI.h"
class AIextendMediumMode: public AI {
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
        return cntWin;
    }
};
#endif

