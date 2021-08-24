# include "TheGame.h"
#include <iostream>
using namespace std;

void TheGame:: playGame (User prashant, Board gameboard)
    {

        while ( while_loop_iterator < 500)
        {

            prashant.takeInput ();
            if ((prashant.xcor == 0 || prashant.ycor ==0) && (prashant.quit == 1 ))
            {
                cout <<"You decided to quit. Sorry to let you go."<<endl;
                cout <<"You managed to clear "<<blocks_cleared<< " blocks nonetheless"<<endl;
                showHiddenBoard(gameboard); //hidden board is the board containing mines....
                break;
            }
            
            try
            {
                if (prashant.xcor >= 0 && prashant.ycor >=0)
                {
                    if (Global::flag1 == 1)
                    {
                        valueAssigner (gameboard, prashant.xcor, prashant.ycor, 'b');
                        showDisplayBoard(gameboard);
                        Global::flag1 = 0;
                        continue;
                    }
                    if(Global::validityChecker (prashant.xcor, prashant.ycor) == 0)
                    {
                        throw ("error");
                        //if negative input here

                    }
                    if (gameboard.gameOverOrNot (prashant.xcor, prashant.ycor) == 1) // here's the issue
                    {
                        if (prashant.lives ==1)
                        {

                        
                        cout <<endl<<endl;
                        cout <<"!!!!!!!!!!!!!!**********Game Over. Better luck next time**********!!!!!!!!!!!!!!!"<<endl<<endl;
                        cout <<"You successfully managed to clear "<<blocks_cleared<<" blocks nonetheless."<<endl;
                        showHiddenBoard(gameboard);
                        break;
                        }
                        else
                        {
                            prashant.lives-=1;
                            cout <<endl<<"!!! YOU CLICKED ON A MINE !!!"<<endl;
                            cout <<"remaining lives = "<<prashant.lives<<endl;
                          
                            valueAssigner(gameboard, -prashant.xcor, -prashant.ycor,'B');       //what about passing * here?
                            showDisplayBoard(gameboard);
                            continue;

                        }
                    }
                    else if (gameboard.display_board[prashant.xcor][prashant.ycor] == 'b')
                    {
                        cout <<"The grid is flagged as bomb. Please unflag it so as to select that grid."<<endl;
                        cout <<"Blocks cleared = "<<blocks_cleared<<endl;
                        cout <<"Remaining blocks to be cleared = "<<Global::Global::glob_board_size*Global::Global::glob_board_size-Global::glob_total_mines-blocks_cleared<<endl;
                        continue;
                    }
                    else if (gameboard.display_board[prashant.xcor][prashant.ycor] != '-')
                    {
                        cout <<"The co-ordinate is already selected. Please enter a new co-ordinate."<<endl;
                        cout <<"Blocks cleared = "<<blocks_cleared<<endl;
                        cout <<"Remaining blocks to be cleared = "<<Global::Global::glob_board_size*Global::Global::glob_board_size-Global::glob_total_mines-blocks_cleared<<endl;

                        continue;
                    }


                    else 
                    {
                        blocks_cleared +=1;
                        cout <<endl<<"Blocks cleared = "<<blocks_cleared<<endl;
                        cout <<"Remaining blocks to be cleared = "<<Global::glob_board_size*Global::glob_board_size-Global::glob_total_mines-blocks_cleared<<endl;

                    }

                    if (blocks_cleared == (Global::glob_board_size * Global::glob_board_size - Global::glob_total_mines) )
                    {
                        cout <<"Congratulations! You won the game.....CLAP!!!! CLAP!!!! "<<endl;
                        cout <<"You have successfully cleared all the "<<Global::glob_board_size*Global::glob_board_size-Global::glob_total_mines<<" blocks."<<endl;
                        showHiddenBoard(gameboard);
                        break;
                    }
                    no_of_mines = gameboard.neighbouringMinesCount (prashant.xcor , prashant.ycor);
                    // cout <<"No of mines at ("<<prashant.xcor<<", "<<prashant.ycor<<") is "<< no_of_mines<<" ";
                    ch = char(no_of_mines + 48);
                    // cout <<ch<<endl;
                    valueAssigner (gameboard, prashant.xcor, prashant.ycor, ch);
                    cout <<"Total lives = "<<prashant.lives<<endl;
                    showDisplayBoard (gameboard);
                    while_loop_iterator+=1;
                }

                else
                {
                    // msb1.xcor+=1; 
                    // msb1.ycor+=1;
                    //loophole here;
                    if (Global::validityChecker (-prashant.xcor, -prashant.ycor) == 0)
                    {
                        cout <<"Invalid input. Please enter valid input"<<endl;
                        continue;      
                    }
                    valueAssigner (gameboard, prashant.xcor, prashant.ycor, 'b');
                    // cout <<"total no of blocks cleared = "<<blocks_cleared<<endl; 
                    cout <<endl<<"Blocks cleared = "<<blocks_cleared<<endl;
                    cout <<"Remaining blocks to be cleared = "<<Global::glob_board_size*Global::glob_board_size-Global::glob_total_mines-blocks_cleared<<endl;
                    showDisplayBoard(gameboard);
                }
            }
            
            catch (...)
            {
                cout <<"Invalid input. Please enter valid input"<<endl;
                continue;    
            }
        }
    }

