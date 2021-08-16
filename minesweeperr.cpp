#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int  glob_board_size, glob_total_mines;
bool flag=0;
//  Beginner – 10 * 10 Board and 20 Mines
// Intermediate – 15 * 15 Board and 50 Mines
// Advanced – 20* 20 Board and 99 Mines
inline bool validityChecker (int, int);
class MinesweeperBoard
{

    int random, xcor, ycor, gamestats[3][2]= {{10,15},{15,50},{20,99}}; 
    char hidden_board [20][20], display_board[20][20];
    int mines =0;
    public:
    MinesweeperBoard ();
    MinesweeperBoard (int game_level)
    {
        // const int board_size = glob_board_size = gamestats[game_level-1][0];
        // const int total_mines = glob_total_mines = gamestats[game_level-1][1];
        glob_board_size = gamestats[game_level-1][0];
        glob_total_mines = gamestats[game_level-1][1];
        char hidden_board[gamestats[game_level-1][0]][gamestats[game_level-1][0]];
        char display_board [gamestats[game_level-1][0]][gamestats[game_level-1][0]];


        // if (game_level == 1)
        // {
        //     const int board_size = 10;
        //     const int total_mines = 20;
        //     glob_board_size = 10;
        //     glob_total_mines = 20;
        //     char hidden_board[board_size][board_size];

        //     char display_board [board_size][board_size];
        // }
        // else if (game_level == 2)
        // {
        //     const int board_size = 15;
        //     const int total_mines = 50;
        //     glob_board_size = 15;
        //     glob_total_mines = 50;
        //     char hidden_board[board_size][board_size];

        //     char display_board [board_size][board_size];
        // }
        // else 
        // {
        //     const int board_size = 20;
        //     const int total_mines = 99;
        //     glob_board_size = 20;
        //     glob_total_mines = 99;
        //     char hidden_board[board_size][board_size];

        //     char display_board [board_size][board_size];
        // }
        
    }
    void boardInitializer(int, int);
    void showHiddenBoard ();
    void showDisplayBoard ();
    void takeInput ();
    friend void playgame (MinesweeperBoard);
    inline bool gameOverOrNot (int p, int q)
    {
        if (hidden_board[p][q] == '*')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void valueAssigner (int p, int q, char chh='b') //default argument
    {
        
        if (p>=0 && q>=0 && flag ==0)
        {
            display_board[p][q] = chh;
            hidden_board [p][q] = chh;
        }
        else
        {
            if (display_board[abs(p)][abs(q)] == '-')
            {
                display_board[abs(p)][abs(q)] = chh;
            }
            
            // board [abs(p)-1][abs(q)-1] = chh;
            else if (display_board[abs(p)][abs(q)] == 'b')
            {
                display_board[abs(p)][abs(q)] = '-';
            }
            else
            {
                cout <<"It makes no sense to flag that coordinate since its obvious that it doesn't contain mine."<<endl;
            }
        }

    }
    int neighbouringMinesCount (int x, int y)
    {
        /*
                Count all the mines in the 8 adjacent
                cells
        
                    N.W   N   N.E
                    \   |   /
                    \  |  /
                    W----Cell----E
                        / | \
                    /   |  \
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
 
        //checking for north
        int mines =0;
        if (validityChecker (x, y-1) ==1)
        {
            if (hidden_board [x][y-1] == '*')
            mines+=1;
        }
        //checking for north east
            if (validityChecker (x+1, y-1) ==1)
        {
            if (hidden_board [x+1][y-1] == '*')
            mines+=1;
        }
        //checking for nothwest
                if (validityChecker (x-1, y-1) ==1)
        {
            if (hidden_board [x-1][y-1] == '*')
            mines+=1;
        }
        //checking for east
                if (validityChecker (x+1, y) ==1)
        {
            if (hidden_board [x+1][y] == '*')
            mines+=1;
        }
        //checking for west
                if (validityChecker (x-1, y) ==1)
        {
            if (hidden_board [x-1][y] == '*')
            mines+=1;
        }
        //checking for south
                if (validityChecker (x, y+1) ==1)
        {
            if (hidden_board [x][y+1] == '*')
            mines+=1;
        }
        //checking for south west
                if (validityChecker (x-1, y+1) ==1)
        {
            if (hidden_board [x-1][y+1] == '*')
            mines+=1;
        }
        //checking for south east
                if (validityChecker (x+1, y+1) ==1)
        {
            if (hidden_board [x+1][y+1] == '*')
            mines+=1;
        }
        return mines ;
    }

    
};


void MinesweeperBoard :: takeInput ()
{
    
    cout <<"Please enter the x co-ordinate"<<endl;
    cin >>xcor;
    cout <<"Please enter the y co-ordinate"<<endl;
    cin >>ycor;
    // if (num == 'q')
    // {
    //     cout <<"quit"<<endl;
    if (xcor >= 0 && ycor >= 0)
    {
   
        xcor-=1;
        ycor-=1;
    }

    else 
    {
        if (abs(xcor)==1 && abs(ycor)==1)
        {
            flag = 1;
        }
        xcor = -(abs(xcor) - 1);
        ycor = -(abs (ycor) - 1);
    }

    
}

inline bool validityChecker (int a, int b)
{
    
    return ((a < glob_board_size) && (b< glob_board_size) && a>=0 && b >=0);

}
void MinesweeperBoard :: showDisplayBoard ()
{

    // cout <<endl;
    cout <<"    ";
    for (int i=0; i<glob_board_size; i++)
    
    {
        cout <<setw(8)<<i+1;
    }
    cout <<endl<<endl; 
    for (int i = 0; i<glob_board_size; i++)
    {
        cout<<setw(3)<<i+1<<"   ";
        for (int j = 0; j<glob_board_size; j++)
        {
            cout <<"|";
            cout <<"   "<<display_board[i][j]<<"   ";
        }
        cout <<"|";
        cout <<endl;
        cout <<setw(7);
        for (int j = 0; j<glob_board_size+1; j++)
        {
            cout <<"|"<<"       ";
            
        }

        cout <<endl;

    }
    //cout <<endl;
}
void MinesweeperBoard :: showHiddenBoard ()
{
    cout <<"    ";
    for (int i=0; i<glob_board_size; i++)
    
    {
        cout <<setw(8)<<i+1;
    }
    cout <<endl<<endl;
    for (int i = 0; i<glob_board_size; i++)
    {
        cout<<setw(3)<<i+1<<"   ";
        for (int j = 0; j<glob_board_size; j++)
        {
            cout <<"|";
            cout <<"   "<<hidden_board[i][j]<<"   ";
        }
        cout <<"|";
        cout <<endl;
        cout <<setw(7);
        for (int j = 0; j<glob_board_size+1; j++)
        {
            cout <<"|"<<"       ";
            
        }

        cout <<endl;

    }
}

void MinesweeperBoard :: boardInitializer (int fxc, int fyc)
{
    int random;
    
    int mines_count =0;
    
    for (int i =0; i<glob_board_size; i++)
    {
        for (int j = 0; j<glob_board_size; j++)
        {
            hidden_board[i][j] = '-';
            display_board[i][j] = '-';

        }
        
    }
    srand (time (0));
    while (mines_count< glob_total_mines)
    {
       
        for (int i =0; i<glob_board_size; i++)
        {
            for (int j= 0; j<glob_board_size; j++)
            {
                // if (board[i][j] = '')
                // mines_count+=1;
                if (i == fxc && j== fyc)
                continue;
                random = rand()% (glob_board_size * glob_board_size) + 1;
                if (((random < (glob_total_mines + 1)/4) || (random > glob_board_size* glob_board_size - glob_total_mines/2)) &&  hidden_board[i][j]!='*')
                {
                    hidden_board[i][j] = '*';
                    mines_count+=1;
                    if (mines_count == glob_total_mines)
                    break;
                }
            }
            if (mines_count == glob_total_mines)
            break;
        }
    }
    //display();
        
 }

 void playgame (MinesweeperBoard msb1)
 {
    int while_loop_iterator = 0;
    int no_of_mines, blocks_cleared= 1;
    char ch;
    while ( while_loop_iterator < 500)
    {

        msb1.takeInput ();

        if (msb1.xcor >= 0 && msb1.ycor >=0)
        {
            if (flag == 1)
            {
                msb1.valueAssigner (msb1.xcor, msb1.ycor);
                msb1.showDisplayBoard();
                flag=0;
                continue;
            }
            if(validityChecker (msb1.xcor, msb1.ycor) == 0)
            {
                cout <<"Invalid input. Please enter valid input"<<endl;
                continue;
                //if negative input here

            }
            if (msb1.gameOverOrNot (msb1.xcor, msb1.ycor) == 1)
            {
                cout <<endl<<endl;
                cout <<"!!!!!!!!!!!!!!**********Game Over. Better luck next time**********!!!!!!!!!!!!!!!"<<endl<<endl;
                cout <<"You successfully managed to clear "<<blocks_cleared<<" blocks nonetheless."<<endl;
                msb1.showHiddenBoard();
                break;
            }
            else if (msb1.display_board[msb1.xcor][msb1.ycor] == 'b')
            {
                cout <<"The grid is flagged as bomb. Please unflag it so as to select that grid."<<endl;
                cout <<"Blocks cleared = "<<blocks_cleared<<endl;
                cout <<"Remaining blocks to be cleared = "<<glob_board_size*glob_board_size-glob_total_mines-blocks_cleared<<endl;
                continue;
            }
            else if (msb1.display_board[msb1.xcor][msb1.ycor] != '-')
            {
                cout <<"The co-ordinate is already selected. Please enter a new co-ordinate."<<endl;
                cout <<"Blocks cleared = "<<blocks_cleared<<endl;
                cout <<"Remaining blocks to be cleared = "<<glob_board_size*glob_board_size-glob_total_mines-blocks_cleared<<endl;

                continue;
            }


            else 
            {
                blocks_cleared +=1;
                cout <<endl<<"Blocks cleared = "<<blocks_cleared<<endl;
                cout <<"Remaining blocks to be cleared = "<<glob_board_size*glob_board_size-glob_total_mines-blocks_cleared<<endl;

            }

            if (blocks_cleared == (glob_board_size * glob_board_size - glob_total_mines) )
            {
                cout <<"Kangrachulasons!!! Vary Saksex fool Parsan......CLAP!!!! CLAP!!!! "<<endl;
                cout <<"You have successfully cleared all the "<<glob_board_size*glob_board_size-glob_total_mines<<" blocks."<<endl;
                msb1.showHiddenBoard();
                break;
            }
            no_of_mines = msb1.neighbouringMinesCount (msb1.xcor , msb1.ycor);
            ch = char(no_of_mines + 48);
            msb1.valueAssigner (msb1.xcor, msb1.ycor, ch);
            msb1.showDisplayBoard ();
            while_loop_iterator+=1;
        }

        else
        {
            // msb1.xcor+=1; 
            // msb1.ycor+=1;
            //loophole here;
            if (validityChecker (-msb1.xcor, -msb1.ycor) == 0)
            {
                cout <<"Invalid input. Please enter valid input"<<endl;
                continue;      
            }
            msb1.valueAssigner (msb1.xcor, msb1.ycor); 
            // cout <<"total no of blocks cleared = "<<blocks_cleared<<endl; 
            cout <<endl<<"Blocks cleared = "<<blocks_cleared<<endl;
            cout <<"Remaining blocks to be cleared = "<<glob_board_size*glob_board_size-glob_total_mines-blocks_cleared<<endl;
            msb1.showDisplayBoard();
        }
    }




    
 }
 int chooseLevel ()
{
    int level;
    cout <<"Choose your level"<<endl;
    cout<<"Beginner 10 * 10 Board and 20 Mines"<<endl<<"Intermediate  15 * 15 Board and 50 Mines"<<endl
    <<"Advanced  20 * 20 Board and 99 Mines"<<endl;
    cout <<"Press 1 to play beginner level."<<endl<<"Press 2 to play intermediate level."<<endl<<"Press 3 to play advanced level."<<endl;
    cin>>level;
    while (level < 1 || level > 3)
    {
        cout <<"Invalid input. Please enter a valid input. "<<endl;
        cout <<"Press 1 to play beginner level."<<endl<<"Press 2 to play intermediate level."<<endl<<"Press 3 to play advanced level."<<endl;
        cin>>level;
    }
    return level;

}

void gameTutorial ()
{
    cout <<endl<<endl<<endl<<"-------------------------------------------------GAME TUTORIAL----------------------------------------"<<endl;
    cout<<"To select the mine enter the co-ordinate (row number followed by column number). For example, "<<endl;
    cout <<"If you want to select mine in 10th row and 14th column, simply enter 10 followed by 14"<<endl;
    cout <<"If you want to flag any cell, simply enter the negative row number and the column number of the mine you want to flag."<<endl;
    cout <<"For example, if you want to flag cell at 17th row and 1st column, then you may enter any of the following co-ordinate"<<endl;
    cout <<"-17 followed by 1 or "<<endl<<"17 followed by -1 or"<<endl<<"-17 followed by -1"<<endl;
    cout <<"you can't flag any cell in the first input"<<endl;
    cout <<"-------------------------------------------------Enjoy the game. All the best--------------------------------------"<<endl<<endl<<endl;
}
int main ()
{
    gameTutorial();
    int lvl = chooseLevel ();
    MinesweeperBoard msb1 (lvl);
    int fxcor, fycor, mines_no;
    char cha;
    cout <<"Enter the first co-ordinates"<<endl;
    cout <<"Enter the first x-coordinate"<<endl;
    cin>>fxcor;
    cout <<"Enter the first y-coordinate"<<endl;
    cin>>fycor;
    fxcor-=1;
    fycor-=1;
    while (validityChecker (fxcor, fycor) == 0)
    {
        cout <<"Invalid input. Please enter valid input"<<endl;
        cin >>fxcor;
        cin>>fycor;
        fxcor-=1;
        fycor-=1;
        
    }
    
    msb1.boardInitializer(fxcor, fycor);
    mines_no = msb1.neighbouringMinesCount (fxcor , fycor);
    cha = char (mines_no + 48);
    msb1.valueAssigner (fxcor, fycor, cha);
    //msb1.display ();
    cout <<"you have successfully cleared 1 cell. You are yet to clear "<<glob_board_size*glob_board_size-glob_total_mines-1<<" cells."<<endl;
    msb1.showDisplayBoard();
    playgame (msb1);
    return 0;

}