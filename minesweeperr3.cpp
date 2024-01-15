#include <iostream>
// #include "global.h"
#include "Board.h"
#include "TheGame.h"
// #include "User.h"
bool Global::flag1 = false;
int Global::glob_board_size = 10;
int Global::glob_total_mines = 20;
 void  gameTutorial ()
 {
     std::cout <<std::endl<<std::endl<<std::endl<<"                                  -------------------------------------------------GAME TUTORIAL----------------------------------------"<<std::endl<<std::endl;
     std::cout <<"                                1   To select the mine enter the co-ordinate (row number followed by column number)."<<std::endl<<std::endl;
     std::cout <<"                                2   If you want to select mine in 10th row and 14th column, simply enter 10 followed by 14"<<std::endl<<std::endl;
     std::cout <<"                                3   For example, If you want to flag any cell, simply enter the negative row number and the column number of the mine you want to flag."<<std::endl<<std::endl;
     std::cout <<"                                4   For example, if you want to flag cell at 17th row and 1st column, then you may enter any of the following co-ordinate"<<std::endl<<std::endl;
     std::cout <<"                                        -17 followed by 1 or "<<std::endl;     
     std::cout <<"                                         17 followed by -1 or"<<std::endl;
     std::cout <<"                                        -17 followed by -1"<<std::endl<<std::endl;
     std::cout <<"                                5   You can't flag any cell in the first input."<<std::endl<<std::endl;
     std::cout <<"                                6   You have 3 lives."<<std::endl<<std::endl;
     std::cout <<"                                7   You can enter any string or character to quit the game at any stage which is absolutely discouraged."<<std::endl<<std::endl;

     std::cout <<"                                -------------------------------------------------Enjoy the game. All the best--------------------------------------"<<std::endl<<std::endl<<std::endl;
 }


int main ()
{
    int fxcor=0, fycor=0, mines_no;
    char cha;
    User prat;
    TheGame game;
    gameTutorial();
    int lvl = prat.chooseLevel();
    Board msb1 (lvl);
    prat.takeFirstInput(&fxcor, &fycor);
    msb1.boardInitializer(fxcor, fycor);
    //showHiddenBoard(msb1);
    mines_no = msb1.neighbouringMinesCount (fxcor , fycor);
    cha = char (mines_no + 48);
    valueAssigner (msb1, fxcor, fycor, cha);
    showDisplayBoard(msb1);
    
    game.playGame(prat, msb1);
    return 0;
}