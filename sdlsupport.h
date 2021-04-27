#ifndef SDLSUPPORT_H
#define SDLSUPPORT_H

#include<iostream>
#include "SDL_mixer.h"
using namespace std;

SDL_Texture* loadMedia(SDL_Renderer* Renderer, string path){
    SDL_Texture* gTexture;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str());
    if( loadedSurface == NULL ){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else{
        gTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
        if( gTexture == NULL ){
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface( loadedSurface );
    }
    return gTexture;
}
void RenderMedia(SDL_Renderer* renderer, SDL_Texture* gTexture, int topX, int topY, int width, int height){
    SDL_Rect Dest;
    Dest.x = topX + 1;
    Dest.y = topY + 1;
    Dest.w = width - 1;
    Dest.h = height - 1;
    SDL_RenderCopy( renderer, gTexture, NULL, &Dest );
}

void logSDLError(std::ostream& os, const std::string &msg, bool fatal){
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, string WINDOW_TITLE){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
}


void quitSDL(SDL_Window* window, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* dataImageButton[20][20];
Mix_Chunk* dataChunk[10];
Mix_Music* dataMusic[10];
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
    SQUARE_GAME_HAVEPLAYED,
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

enum stateOfEndGameBULLETINBOARD {
    YOU_WIN,
    YOU_LOSE,
    DRAW,
    PLAYER1_WIN,
    PLAYER2_WIN
};

enum stateOfaSquare {
    STATE_EMPTY,
    STATE_PLAYER,
    STATE_AI
};

enum stateButtonMap {
    NOT_CHOOSE,
    MAP_33,
    MAP_55,
    MAP_99,
    MAP_1212
};

enum stateOfPlayer {
    NOT_ENDGAME,
    FIRST_PLAYER,
    SECOND_PLAYER,
    TWO_PLAYER_DRAW,
};
enum chunk {
    CLICK,
    ENDGAME_MUSIC
};
void setDataImage(SDL_Renderer* renderer){
    dataImageButton[ENTER_PREGAME][1] = loadMedia(renderer , "../TestSDL/EnterGameButton.png");
    dataImageButton[CHOICE_MAP_PREGAME][MAP_33] = loadMedia(renderer , "../TestSDL/choice33.png");
    dataImageButton[CHOICE_MAP_PREGAME][MAP_55] = loadMedia(renderer , "../TestSDL/choice55.png");
    dataImageButton[CHOICE_MAP_PREGAME][MAP_99] = loadMedia(renderer , "../TestSDL/choice99.png");
    dataImageButton[CHOICE_MAP_PREGAME][MAP_1212] = loadMedia(renderer , "../TestSDL/choice1212.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][MAP_33] = loadMedia(renderer , "../TestSDL/choice33success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][MAP_55] = loadMedia(renderer , "../TestSDL/choice55success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][MAP_99] = loadMedia(renderer , "../TestSDL/choice99success.png");
    dataImageButton[CHOICE_MAP_SUCCESS_PREGAME][MAP_1212] = loadMedia(renderer , "../TestSDL/choice1212success.png");
    dataImageButton[CHOICE_PLAYER_AI_SUCCESS_PREGAME][STATE_PLAYER] = loadMedia(renderer , "../TestSDL/choicePlayPlayerSuccess.png");
    dataImageButton[CHOICE_PLAYER_AI_SUCCESS_PREGAME][STATE_AI] = loadMedia(renderer , "../TestSDL/choicePlayAISuccess.png");
    dataImageButton[CHOICE_PLAYER_AI_PREGAME][STATE_PLAYER] = loadMedia(renderer , "../TestSDL/choicePlayPlayer.png");
    dataImageButton[CHOICE_PLAYER_AI_PREGAME][STATE_AI] = loadMedia(renderer , "../TestSDL/choicePlayAI.png");
    dataImageButton[SQUARE_GAME][FIRST_PLAYER] = loadMedia(renderer , "../TestSDL/player1_X.png");
    dataImageButton[SQUARE_GAME][SECOND_PLAYER] = loadMedia(renderer , "../TestSDL/player2_O.png");
    dataImageButton[SQUARE_GAME_HAVEPLAYED][FIRST_PLAYER] = loadMedia(renderer , "../TestSDL/player1_X_havePlayed.png");
    dataImageButton[SQUARE_GAME_HAVEPLAYED][SECOND_PLAYER] = loadMedia(renderer , "../TestSDL/player2_O_havePlayed.png");
    dataImageButton[RESTART_GAME][1] = loadMedia(renderer, "../TestSDL/RestartGame.png");
    dataImageButton[RETURN_MENU_GAME][1] = loadMedia(renderer, "../TestSDL/returnMenu.png");
    dataImageButton[CHOOSE_AI_PREGAME][1] = loadMedia(renderer, "../TestSDL/chooseAI.png");
    dataImageButton[CHOOSE_MAP_PREGAME][1] = loadMedia(renderer, "../TestSDL/chooseMap.png");
    dataImageButton[HEADING_PREGAME][1] = loadMedia(renderer, "../TestSDL/heading.png");
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
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1){
        printf("%s", Mix_GetError());
    }
    dataChunk[CLICK] = Mix_LoadWAV("click.wav");
    dataChunk[ENDGAME_MUSIC] = Mix_LoadWAV("endGame.wav");
}

#endif

