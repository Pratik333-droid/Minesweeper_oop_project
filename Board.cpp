#include "Board.h"
#include <ctime>
#include <random>
#include <iomanip>
#include <iostream>

void Board :: boardInitializer (int fxc, int fyc)
{
    
    for (int i =0; i<Global::glob_board_size; i++)
    {
        for (int j = 0; j<Global::glob_board_size; j++)
        {
            hidden_board[i][j] = '-';
            display_board[i][j] = '-';

        }
        
    }
    srand (time (0));
    while (mines_count< Global::glob_total_mines)
    {
       
        for (int i =0; i<Global::glob_board_size; i++)
        {
            for (int j= 0; j<Global::glob_board_size; j++)
            {
                // if (board[i][j] = '')
                // mines_count+=1;
                if (i == fxc && j== fyc)
                continue;
                random = rand()% (Global::glob_board_size * Global::glob_board_size) + 1;
                if (((random < (Global::glob_total_mines + 1)/4) || (random > Global::glob_board_size* Global::glob_board_size - Global::glob_total_mines/2)) &&  hidden_board[i][j]!='*')
                {
                    hidden_board[i][j] = '*';
                    mines_count+=1;
                    if (mines_count == Global::glob_total_mines)
                    break;
                }
            }
            if (mines_count == Global::glob_total_mines)
            break;
        }
    }
    //display();
        
 }

 int Board :: neighbouringMinesCount (int x, int y)
 {
/*
                Count all the mines in the 8 adjacent
                cells
        
                    N.W   N   N.E
                    \   |   /
                     \  |  /
                 W-----Cell------E
                      / | \
                     /  |  \
                    S.W    S   S.E
        
                Cell-->Current Cell (row, col)
                N -->  North        (row-1, col)
                S -->  South        (row+1, col)
                E -->  East         (row, col+1)
                W -->  West            (row, col-1)
                N.E--> North-East   (row-1, col+1)
                N.W--> North-West   (row-1, col-1)
                S.E--> South-East   (row+1, col+1)
                S.W--> South-West   (row+1, col-1)
        */


        mines = 0;
        //checking for north
        if (Global::validityChecker (x, y-1) ==1)
        {
            if (hidden_board [x][y-1] == '*')
            mines+=1;
        }
        //checking for north east
            if (Global::validityChecker (x+1, y-1) ==1)
        {
            if (hidden_board [x+1][y-1] == '*')
            mines+=1;
        }
        //checking for nothwest
                if (Global::validityChecker (x-1, y-1) ==1)
        {
            if (hidden_board [x-1][y-1] == '*')
            mines+=1;
        }
        //checking for east
                if (Global::validityChecker (x+1, y) ==1)
        {
            if (hidden_board [x+1][y] == '*')
            mines+=1;
        }
        //checking for west
                if (Global::validityChecker (x-1, y) ==1)
        {
            if (hidden_board [x-1][y] == '*')
            mines+=1;
        }
        //checking for south
                if (Global::validityChecker (x, y+1) ==1)
        {
            if (hidden_board [x][y+1] == '*')
            mines+=1;
        }
        //checking for south west
                if (Global::validityChecker (x-1, y+1) ==1)
        {
            if (hidden_board [x-1][y+1] == '*')
            mines+=1;
        }
        //checking for south east
                if (Global::validityChecker (x+1, y+1) ==1)
        {
            if (hidden_board [x+1][y+1] == '*')
            mines+=1;
        }
        return mines ;
    
 }
bool Board :: gameOverOrNot (int x1, int y1)
{
    if (hidden_board[x1][y1] == '*')
    return 1;
   
    else
    return 0;
}
void showDisplayBoard (Board dispBboardy)   //friend function of Board
{

    std::cout <<std::endl;
    
    std::cout <<"    ";
    for (int i=0; i<Global::glob_board_size; i++)
    
    {
        std::cout <<std::setw(8)<<i+1;
    }
    std::cout <<std::endl<<std::endl; 
    for (int i = 0; i<Global::glob_board_size; i++)
    {
        std::cout<<std::setw(3)<<i+1<<"   ";
        for (int j = 0; j<Global::glob_board_size; j++)
        {
            std::cout <<"|";
            std::cout <<"   "<<dispBboardy.display_board[i][j]<<"   ";
            // std::cout <<"   "<<"-"<<"   ";
        }
        std::cout <<"|";
        std::cout <<std::endl;
        std::cout <<std::setw(7);
        for (int j = 0; j<Global::glob_board_size+1; j++)
        {
            std::cout <<"|"<<"       ";
            
        }

        std::cout <<std::endl;

    }
    //std::cout <<std::endl;
}
void showHiddenBoard (Board hidBoardy)  //friend function of Board class
{
    std::cout <<"    ";
    for (int i=0; i<Global::glob_board_size; i++)
    
    {
        std::cout <<std::setw(8)<<i+1;
    }
    std::cout <<std::endl<<std::endl;
    for (int i = 0; i<Global::glob_board_size; i++)
    {
        std::cout<<std::setw(3)<<i+1<<"   ";
        for (int j = 0; j<Global::glob_board_size; j++)
        {
            std::cout <<"|";
            std::cout <<"   "<<hidBoardy.hidden_board[i][j]<<"   ";
        }
        std::cout <<"|";
        std::cout <<std::endl;
        std::cout <<std::setw(7);
        for (int j = 0; j<Global::glob_board_size+1; j++)
        {
            std::cout <<"|"<<"       ";
            
        }

        std::cout <<std::endl;

    }
}
void valueAssigner (Board &brd, int p, int q, char chh='b') //default argument
{
    
    if (p>=0 && q>=0 && Global::flag1 ==0)
    {
        // std::cout <<"hami yaha xau"<<std::endl;
        brd.display_board[p][q] = chh;
        brd.hidden_board [p][q] = chh;
    }
    else
    {
        if (brd.display_board[abs(p)][abs(q)] == '-')
        {
            brd.display_board[abs(p)][abs(q)] = chh;
        }
        
        // board [abs(p)-1][abs(q)-1] = chh;
        else if (brd.display_board[abs(p)][abs(q)] == 'b')
        {
            brd.display_board[abs(p)][abs(q)] = '-';
        }
        else
        {
            std::cout <<"It makes no sense to flag cell"<<std::endl;
        }
    }
}
