#include "game.hpp"
#include <random> // for std::default_random_engine, std::shuffle
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace ariel;
using namespace std;


Game::Game(Player& player1, Player& player2) : player1(player1), player2(player2),deck(),gameStats() {
    winner = "";
    turnOverview="";
    countOfTheTurn=0;
    createDeck();
    deck = shuffleDeck(deck);
    divideTheCards();
    draw = 0;
}

Game::Game(const Game& game) : player1(game.player1), player2(game.player2) {
    winner = "";
}

Game::~Game() {
    std::cout << "Destructor called" << std::endl;
}

void Game::createDeck() {
    deck.clear();
    for (int i = 1; i <= 13; i++) {
        deck.push_back(card(i, "hearts"));
        deck.push_back(card(i, "diamonds"));
        deck.push_back(card(i, "clubs"));
        deck.push_back(card(i, "spades"));
    }
    
}
vector<card> Game::shuffleDeck(vector<card> deckToShuffle) {
    // std::default_random_engine rng(std::time(nullptr));
    std::default_random_engine rng(static_cast<unsigned int>(std::time(nullptr)));

    std::shuffle(deckToShuffle.begin(), deckToShuffle.end(), rng);
    return deckToShuffle;
}

void Game:: divideTheCards(){
    
    int sizeOfTheDeck = deck.size();
    int i=0;
    while (i<sizeOfTheDeck/2)
    {
        player1.divideCard(deck.back());
        deck.pop_back();
        player2.divideCard(deck.back());
        deck.pop_back();
        i++;
    }
    
    
}
void Game::player1WinTheTurn(card card1,card card2,vector<card> cardtemp){

  
    
} 
void player2WinTheTurn(card,card,vector<card>);

vector<card> Game::getdeck() {
    return deck;
}



string Game::getTheWinner() {
    return winner;
}

int Game::getDeckSize() {
    return deck.size();
}

//change
void Game::printLastTurn() {
    if(player1.stacksize() > 0 && player2.stacksize() > 0){
        cout<< "game didnt start "<<endl;
    }
    else{
        cout << gameStats.back() << endl;
    }
}

void Game::printWiner(){

    if(player1.stacksize() == 0 && player2.stacksize() == 0 ){

        if (player1.cardesTaken() > player2.cardesTaken())
        {
            setTheWinner(player1.getName());
            cout << "the winner: "<< getTheWinner() <<endl;
        }
        else if(player1.cardesTaken() < player2.cardesTaken()){
            setTheWinner(player2.getName());
            cout << "the winner: "<< getTheWinner() <<endl;
        }
        else{
        setTheWinner("draw players");
        cout << " no winners "<<getTheWinner()<<endl;
        }
    }
}

void Game:: setTheWinner(string winnerName){
    winner = winnerName;
}

void Game::playTurn() {
    
    bool t = true;
   
    vector<card> tempcard;


    while(t)
    {

        if(!player1.getdeckPlayer().empty() && !player2.getdeckPlayer().empty()){
                countOfTheTurn++;
                card card1 = player1.playCard();
                card card2 = player2.playCard();
                player1.removeCard();
                player2.removeCard();
    
    if(card1.getVal() == card2.getVal()){
                tempcard.emplace_back(card1);
                tempcard.emplace_back(card2);
      
                draw++;
                turnOverview += player1.getName()+ " game " + to_string(card1.getVal())+ " shape " + card1.getShape() +
                            ", "+player2.getName() + " game " + to_string(card2.getVal())+ " shape " + card2.getShape()+
                            ". Draw. " ;

                if(player1.stacksize() <= 1 && player2.stacksize() <= 1){
                    player1.divideCard(card1);
                    player2.divideCard(card2);
                    while(player1.stacksize() != 0){
                        player1.addToStack(player1.playCard());
                        player1.removeCard();
                    }

                    while(player2.stacksize() != 0){
                        player2.addToStack(player2.playCard());
                        player2.removeCard();
                    }
                    tempcard.clear();
                }
                else{
                    
                    tempcard.emplace_back(player1.playCard());
                    player1.removeCard();
                    tempcard.emplace_back(player2.playCard());
                    player2.removeCard();
                }
                t = true;
            }
    else if (card1.getVal() > card2.getVal()) 
    {

            player1.addToStack(card2);
            player1.addToStack(card1);

            while(!tempcard.empty()){
                player1.addToStack(tempcard.back());
                tempcard.pop_back();
            }
            player1.addWin();
            player2.addLose();

            turnOverview += player1.getName()+ " game " + to_string(card1.getVal())+ " shape " + card1.getShape() +
                        ", "+player2.getName() + " game " + to_string(card2.getVal())+ " shape " + card2.getShape()+
                        ". "+player1.getName()+ " wins\n" ;
            gameStats.emplace_back(turnOverview);
            turnOverview = "";
            

        tempcard.clear();
            t=false;
    } 
    else if (card2.getVal() > card1.getVal()) {
       
    player2.addToStack(card2);
    player2.addToStack(card1);

    while(!tempcard.empty()){
        player2.addToStack(tempcard.back());
        tempcard.pop_back();
    }
    player2.addWin();
    this->player1.addLose();

    turnOverview += player1.getName()+ " game " + to_string(card1.getVal())+ " shape " + card1.getShape() +
                ", "+player2.getName() + " game " + to_string(card2.getVal())+ " shape " + card2.getShape()+
                ". "+player2.getName()+ " wins\n" ;
    gameStats.emplace_back(turnOverview);
    turnOverview = "";

        tempcard.clear();
            t=false;
    } 

}
       
    else{
        throw std::invalid_argument("The game is over");
            
        return;
    }   
        
 }
     
}
 


void Game::printLog() {
    vector<string>::iterator val;
    int size = gameStats.size();
    int i = 1; // Start index from 1 instead of 0
    if (size > 0) {
        cout << "----------------prints the log:------------" << endl;
        
        while (!gameStats.empty()) { // Loop until the vector is empty
            cout << i << ". " << gameStats.front() << endl; 
            val = gameStats.begin();
            gameStats.erase(val);
            i++;
        }
    }
    else {
        cout << "no statistics" << endl; 
    
    }

}


void Game::printStats() {
    std::cout << "Game stats:" << std::endl;
    // print number of cards remaining in the deck
    std::cout << "Deck size: " << getDeckSize() << std::endl;
    // print number of cards in each player's stack
    std::cout << player1.getName() << "'s stack size: " << player1.stacksize() << std::endl;
    std::cout << player2.getName() << "'s stack size: " << player2.stacksize() << std::endl;
}



void Game::playAll() {
    std::cout << "Starting game..." << std::endl;
    try{
        while (!player1.getdeckPlayer().empty()&& !player2.getdeckPlayer().empty()) {
            playTurn();

        }

        std::cout << "The winner is " << winner << "!" << std::endl;
        cout<< player1.cardesTaken() << endl;
        cout<< player2.cardesTaken() << endl;
        
        cout<< player2.cardesTaken() +player1.cardesTaken()<< endl;
        cout<< "number of turn = "<<countOfTheTurn << endl;
        cout<< "number of draw = "<<draw << endl;
        
    }
    catch(const std::invalid_argument& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }   

}
