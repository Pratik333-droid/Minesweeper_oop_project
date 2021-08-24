#pragma once

class User
{
private:
    int fx , fy, mines_no, level, loop_iterator = 0;

public:
    int xcor, ycor, lives=3;
    bool quit =0;
    int chooseLevel ();
    void takeFirstInput(int *, int *);
    void takeInput();

};