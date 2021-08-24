#pragma once

#include "User.h"
#include "Board.h"

class TheGame : public User
{


    int while_loop_iterator = 0;
    int no_of_mines, blocks_cleared= 1;
    char ch;
    public:
    void playGame (User, Board);
    
};