#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel {

    class Player {
    private:
        string name;
        vector<card> deckPlayer;
        vector<card> deckWonTurn;
        int win;
        int loss;
        int draw;

    public:
        std::vector<card>::iterator begin();
        std::vector<card>::iterator end();
        void drawCard(card );
        card playCard();
        void addToStack(card );
        int cardesTaken();
        int stacksize();
        string getName();
        vector <card> getdeckPlayer() ;
        void  setName(string name);
        void  divideCard(card card);
        void  removeCard();
        vector<card>  winnerDeck();
        void  updateDeckPlay(vector<card> newDeck);
            
        Player();
        Player(std::string name);
        Player(const Player& player);
        Player(Player&& other) noexcept;
        Player& operator=(const Player& other);
        Player& operator=(Player&& other) noexcept;
        
        void addWin();
        int getCountWin();
        void addLose();
        int getCountLose();
        ~Player();
        };

}

#endif // PLAYER_HPP
