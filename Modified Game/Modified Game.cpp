// Modified Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdlib.h>
#include<time.h>
#include<ctype.h>

using namespace std;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int player_choice,computer_choice;
int row, column;
char turn = 'X';
bool draw = false;



void player_board() {

    system("CLS");
    cout << "\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

void computer_board() {

    system("CLS");
    cout << "\n\t\t\t\tFOR SINGLE PLAYER\n\t\t\t";
    cout << "PLAYER-[X]\t Computer-[O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}


void player_turn() {
    if (turn == 'X') {
        cout << "\n\tPlayer - 1 [X] turn : ";
    }
    else if (turn == 'O') {
        cout << "\n\tPlayer - 2 [O] turn : ";
    }
    

    cin >> player_choice;


    switch (player_choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
       
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
       
        cout << "Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }
    
}

void computer_turn() {
    if (turn == 'X') {
        cout << "\n\tPlayer-[X] turn : ";
        cin >> computer_choice;
    }
    else if (turn == 'O') {
        cout << "\n\tComputer-[O] turn : ";
        srand(time(NULL));
        computer_choice= rand() % 9;
    }
    

    


    switch (computer_choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
     
        cout << "Box already filled!\n Please choose another!!\n\n";
        computer_turn();
    }
    
}




bool gameover() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main()
{
    
    char need;
    cout << "\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\n What do you wanna play Single(S) or Multiplayer(M):";
    cin >> need;
    switch (need)
    {
    case 'M': 
        while (gameover()) {
        player_board();
        player_turn();
        }
        player_board();
        if (turn == 'X' && draw == false) {
                cout << "\n\nCongratulations!! Player with 'O' has won the game";
            }
        else if (turn == 'O' && draw == false) {
                cout << "\n\nCongratulations!! Player with 'X' has won the game";
            }
        else
                cout << "\n\nGAME DRAW!!!\n\n";
        break;
    case 'S':
        while (gameover()) {
            computer_board();
            computer_turn();
        }
        computer_board();
        if (turn == 'X' && draw == false) {
            cout << "\n\nCongratulations!! Computer with 'O' has won the game";
        }
        else if (turn == 'O' && draw == false) {
            cout << "\n\nCongratulations!! Player with 'X' has won the game";
        }
        else
            cout << "\n\nGAME DRAW!!!\n\n";
        break;
    default: cout << "Wrong choice";
        break;
    }


    //char ch;
    //cin >> ch;
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
