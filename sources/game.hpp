#ifndef GAME_H
#define GAME_H


# include <stdexcept>
# include <string>
# include <iostream>
# include <stack>
# include <vector>
# include "player.hpp"
# include "card.hpp"
# include "game.hpp"
using namespace std;

namespace ariel{
class Game
{

private:
    Player& player1;
    Player& player2;
    vector<card> deck;
    int draw;
    string winner;
    int countOfTheTurn;
    string turnOverview;
    vector<string> gameStats;

public:
    Game(Player & player1,Player & player2);
    Game(const Game&);
    Game(Game&& other)noexcept;
    Game& operator=(const Game& other) ;
    Game& operator=(Game&& other)noexcept; // Define move assignment operator
   
   ~Game();

    vector<card> shuffleDeck(vector<card>);    
    vector<card> getdeck();

    string getTheWinner();
    void setTheWinner(string winner);
    void player1WinTheTurn(card,card,vector<card>);
    void player2WinTheTurn(card,card,vector<card>);
    void createDeck();
    int getDeckSize();
    void printLastTurn();
    void playTurn();
    void printWiner();
    void printLog();
    void printStats();
    void playAll();
    void divideTheCards();
    void setNameWinner(string winnerName);
   



};

}

#endif

