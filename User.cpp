#include "User.h"
#include "global.h"
#include <iostream>

void User :: takeInput ()
{
    
    std::cout <<"Please enter the x co-ordinate"<<std::endl;
    std::cin >>xcor;
    std::cout <<"Please enter the y co-ordinate"<<std::endl;
    std::cin >>ycor;
    // if (num == 'q')
    // {
    //     std::cout <<"quit"<<std::endl;
    if (xcor > 0 && ycor > 0)
    {
   
        xcor-=1;
        ycor-=1;
    }
    else if (xcor==0 || ycor==0)
    {
        quit = 1;
    }
    else 
    {
        if (abs(xcor)==1 && abs(ycor)==1)
        {
            Global::flag1 = 1;
        }
        xcor = -(abs(xcor) - 1);
        ycor = -(abs (ycor) - 1);
    }

    
}

int User :: chooseLevel ()
{
    
    while (loop_iterator < 10)
    {
        try
        {
            std::cout <<"                                    Choose your level"<<std::endl<<std::endl;
            std::cout <<"                                    Beginner 10 x 10 Board and 20 Mines"<<std::endl<<std::endl;
            std::cout <<"                                    Intermediate  15 x 15 Board and 50 Mines"<<std::endl<<std::endl;
            std::cout <<"                                    Advanced  20 x 20 Board and 99 Mines"<<std::endl<<std::endl;
            std::cout <<"                                    Press 1 to play beginner level."<<std::endl<<std::endl;
            std::cout <<"                                    Press 2 to play intermediate level."<<std::endl<<std::endl;
            std::cout <<"                                    Press 3 to play advanced level."<<std::endl<<std::endl;
            loop_iterator+=1;
            // std::cout <<"This is executed"<<std::endl;
            
            std::cin>>level;
            // std::cout <<"Hami yaha xam"<<std::endl;
            // std::cout <<"Level = "<<level;

            if (level == 0)
            {
                std::cout <<"You decided to quit. Sorry to let you go."<<std::endl;
                break;
            }
            
            if (level < 1 || level > 3)
            throw ("invalid");
        }
        catch (...)
        {
            std::cout <<"                                    Invalid input. Please enter a valid input. "<<std::endl<<std::endl;
            continue;
        }
        break;
    }
    return level;
    
}
void User :: takeFirstInput (int* fxcor, int *fycor)
{

    while (1)
    {
        try
        {
        
            std::cout <<"Enter the first co-ordinates"<<std::endl;
            std::cout <<"Enter the first x-coordinate"<<std::endl;
            std::cin>>fx;
            std::cout <<"Enter the first y-coordinate"<<std::endl;
            std::cin>>fy;
            *fxcor=fx - 1;
            *fycor=fy - 1; ///here's the issue
            fy-=1;
            fx-=1;
            
            if (Global::validityChecker (fx, fy) == 0)
            throw("$#!**");      
        }
        catch(...)
        {
            std::cout <<"Invalid input. Please enter valid input"<<std::endl;
            continue;
        }
        
        break;

    }

}

