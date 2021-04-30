#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL_image.h>
#include "sdlsupport.h"
using namespace std;

class Button {
private:
    int typeOfButton = -1;
    int stateButton = 0;
    SDL_Point positionTopLeft;
    pair<int,int> lengthOfButton;
public:
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
    if(stateButton){
        RenderMedia(renderer, dataImage[typeOfButton][stateButton],
                            positionTopLeft.x, positionTopLeft.y, lengthOfButton.first, lengthOfButton.second);
    }
    if(havePattern){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y,
                           positionTopLeft.x + lengthOfButton.first, positionTopLeft.y);
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y,
                           positionTopLeft.x, positionTopLeft.y + lengthOfButton.second);
        SDL_RenderDrawLine(renderer, positionTopLeft.x, positionTopLeft.y + lengthOfButton.second,
                           positionTopLeft.x + lengthOfButton.first, positionTopLeft.y + lengthOfButton.second);
        SDL_RenderDrawLine(renderer, positionTopLeft.x + lengthOfButton.first, positionTopLeft.y,
                           positionTopLeft.x + lengthOfButton.first, positionTopLeft.y + lengthOfButton.second);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if(haveRenderPresent) SDL_RenderPresent(renderer);
}
#endif

