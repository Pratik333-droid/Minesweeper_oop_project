#pragma once
#include "global.h"
class Board
{
    
    int random, xcor, ycor, gamestats[3][2]= {{10,15},{15,50},{20,99}}; 
    int mines_count =0, mines =0;
    public:
    char hidden_board [20][20], display_board[20][20]; // what if I give 1,1 here.
    
    Board (){};
    Board (int game_level)
    {
        
        Global::glob_board_size = gamestats[game_level-1][0];
        Global::glob_total_mines = gamestats[game_level-1][1];
        char hidden_board[gamestats[game_level-1][0]][gamestats[game_level-1][0]];
        char display_board [gamestats[game_level-1][0]][gamestats[game_level-1][0]];
    }
    void boardInitializer(int, int);
    int neighbouringMinesCount (int, int);
    //friend bool validityChecker (int, int)
    bool gameOverOrNot (int, int);
    friend void showHiddenBoard (Board);
    friend void showDisplayBoard (Board);
    friend void valueAssigner (Board&, int , int , char);
};