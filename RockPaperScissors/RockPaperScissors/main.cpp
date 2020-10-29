/*
 RockPaperScissors
 C++ Version
 Name: Francisco Lira
 Date:  06/25/19
 Inputs: player1 and player2
 Output: Winner
 Copyright © 2019 Francisco  Lira. All rights reserved.
*/

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
 
    char player1, player2;
    char playAgain = 'Y' && 'y';
    
    cout << "Enter R P or S for Rock, Paper or Scissors " << endl;
    do
    {
        cout << "Player 1 (R P S): ";
        cin >> player1;
        player1 = toupper(player1);
        
        cout << "player 2 (R P S): ";
        cin >> player2;
        player2 =toupper(player2);
        
        if (player1 == 'R' || player1 == 'r')
        {
            if (player2 ==  'R'||player2 ==  'r')
                cout << "Tie Game, Nobody Wins :( " << endl;
            else if (player2 == 'P'||player2 == 'p')
                cout << "Paper beats Rock which means that player 2 wins :)" << endl;
            else if (player2 == 'S'||player2 == 's')
                cout << "Rock beats scissors which means that Player 1 Wins :)" << endl;
            else
                cout << "Illegal selection for Player 2" << endl;
        }
        else if (player1 == 'P' || player1 == 'p')
        {
            if (player2 ==  'R'||player2 ==  'r')
                cout << "Paper beats Rock which means that player 1 wins :)" << endl;
            else if (player2 == 'P' || player2 == 'p')
                cout << "Tie Game, Nobody Wins :( " << endl;
            else if (player2 == 'S' || player2 == 's')
                cout << "Scissors beats Paper which means that Player 2 Wins :)" << endl;
            else
                cout << "Illegal selection for Player 2" << endl;
        }
        else if (player1 == 'S')
        {
            if (player2 ==  'R' || player2 =='r')
                cout << "Rock beats scissors which means that Player 2 Wins :)" << endl;
            else if (player2 == 'P' || player2 == 'p')
                cout << "Scissors beats Paper which means that Player 1 Wins :)" << endl;
            else if (player2 == 'S' || player2 == 's')
                cout << "Tie Game, Nobody Wins :( " << endl;
            else
                cout << "Illegal selection for Player 2" << endl;
        }
        else
        {
                cout << "Illegal selection for player 1" << endl;
        }
                
        cout << "Do you wish to play again? (If Yes, type \"Y\", if No, type \"N\"): ";
                cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y')
        {
            playAgain = true;
        }
       else if (playAgain == 'n' || 'N')
        {
            playAgain = false;
        }
       
    }
    while (playAgain == true);
    return 0;
}
