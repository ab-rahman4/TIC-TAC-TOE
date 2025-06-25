#include <iostream>
using namespace std;
int currentplayer;
char currentmarker;
int playerwon = 0;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void swapplayer(){

if (currentplayer == 1)
{
    currentplayer = 2;
}
else currentplayer = 1;
if (currentmarker == 'O')
{
    currentmarker = 'X';
}
else currentmarker = 'O';

}
int winner(){
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return currentplayer;
        }
        

    
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentplayer;
        }
    
        if (board[0][0] == board[1][1] &&  board[1][1] == board[2][2])
        {
            return currentplayer;
        }
    
        if (board[0][2] == board[1][1] &&  board[1][1] == board[2][0])
        {
            return currentplayer;
        }
    }
    return 0;
}    
bool alreadyexist(int slot)
{
    int rows = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[rows][col] != 'X' && board[rows][col] != 'O')
    {
        board[rows][col] = currentmarker;
        return true;
    }
    else
        return false;
}
void printboard()
{

    cout << "         " << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "         " << "---|---" << "|---" << endl;
    cout << "         " << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "         " << "---|---" << "|---" << endl;
    cout << "         " << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
void game()
{
    cout << "Choose your marker X/0 :";
    char marker;
    cin >> marker;
    while (marker != 'X' && marker != 'O')
    {
        if (marker != 'X' && marker != 'O')
    {
        cout << "No Such Marker exists.Try again : ";
    cin >> marker;
        
    }
    }
    
   
    currentplayer = 1;
    currentmarker = marker;
    printboard();
    int slot;
    for (int i = 0; i < 9; i++)
    {
        cout << "Its player " << currentplayer << "'s turn." << endl;
        cout << endl
             << "Choose the position to place marker : ";
        cin >> slot;
        if (slot <= 0 || slot > 9)
        {
            i--;
            cout << "No such place exist in board";
            continue;
        }
        if (!alreadyexist(slot))
        {
            cout << "This place is already occupied.";
            i--;
            continue;
        }
        printboard();
        playerwon = winner();
        if (playerwon == 1)
        {
            cout<<"The winner is player 1 Congratulations...";
            break;
        }
        if (playerwon == 2)
        {
            cout<<"The winner is player 2 Congratulations...";
            break;
        }
        swapplayer();
      
        
    }
     if (playerwon == 0)
       {
        cout<<"The match tie!. Nobody wins.";
       }
        
}
int main()
{
    game();
}
