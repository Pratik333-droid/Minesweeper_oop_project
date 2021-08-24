#pragma once
class Global{
public:
    static int  glob_board_size, glob_total_mines;
    static bool flag1;

    static inline bool  validityChecker (int a, int b)
    {
        return ((a < glob_board_size) && (b< glob_board_size) && a>=0 && b >=0);
    }
};


