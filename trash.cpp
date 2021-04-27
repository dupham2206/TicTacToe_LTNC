//int cntContinue(int x, int y, int dx, int dy, int statePlayer){
//        int cntCurrent = 0, cntFarLeft = 0, cntFarRight = 0;
//        int block = 0;
//        for(int i = 1; ; ++i){
//            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
//                ++block;
//                break;
//            }
//            if(boardState[x + i * dx][y + i * dy] == StateEmpty){
//                ++i;
//                cntFarLeft++;
//                while(1){
//                    if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){
//                        ++block; break;
//                    }
//                    if(boardState[x + i * dx][ y + i * dy] == StateEmpty) break;
//                    ++i; cntFarLeft += 2;
//                }
//                break;
//            }
//            cntCurrent += 2;
//        }
//        for(int i = -1; ; --i){
//            if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
//                ++block;
//                break;
//            }
//            if(boardState[x + i * dx][y + i * dy] == StateEmpty){
//                --i;
//                cntFarRight++;
//                while(1){
//                    if(!checkInsideBoard(x + i * dx, y + i * dy) || boardState[x + i * dx][ y + i * dy] == 3 - statePlayer){
//                        ++block; break;
//                    }
//                    if(boardState[x + i * dx][ y + i * dy] == StateEmpty) break;
//                    --i; cntFarRight += 2;
//                }
//                break;
//            }
//            cntCurrent += 2;
//        }
//        int cntWin = cntCurrent + 1 + max(cntFarLeft, cntFarRight);
//        if(block == 2){
//            if(cntWin >= 9){
//                return 8;
//            }
//            else return 0;
//
//        }
//        if(block == 1){
//            if(cntWin >= 9){
//                return 8;
//            }
//            if(cntWin >= 7){
//                return 4;
//            }
//            else return 0;
//        }
//        if(block == 0){
//            if(cntWin >= 6){
//                return 16;
//            }
//            if(cntWin >= 4){
//                return 2;
//            }
//            else {
//                return 0;
//            }
//        }
//    }
