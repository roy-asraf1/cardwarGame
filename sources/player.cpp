#include "player.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

//outline constracturs

Player::Player() : name("new_player"),deckPlayer(),deckWonTurn() {
    win=0;
    loss=0;
    draw=0;
}
Player::Player(string name) : name(name),deckPlayer(),deckWonTurn() {
    win=0;
    loss=0;
    draw=0;
}
Player::Player(const Player& player):Player(player.name){

}
Player& Player::operator=(const Player & other)
{
    if (this != &other)
    {
        name = other.name;
    }
    return *this;
}
Player::Player(Player&& other)noexcept: name(other.name)
{
}

Player& Player::operator=(Player&& other)noexcept
{
    if (this != &other)
    {
        name = other.name;
    }
    return *this;
}
Player::~Player()
{
    cout<<"destructor successfull! - "<< name << endl;
}


void Player::addToStack(card card) {
    deckWonTurn.emplace_back(card);
}

void Player:: divideCard(card card){
    deckPlayer.emplace_back(card);
}
void Player:: removeCard(){
    if (!deckPlayer.empty()) {
        deckPlayer.pop_back();
    }
}
int Player::cardesTaken() {
    return deckWonTurn.size();
}
void Player::addWin() {
     win++;
}
int Player::getCountWin() {
     return win;
}
void Player::addLose() {
     loss++;
}
int Player::getCountLose() {
     return loss;
}
int Player::stacksize() {
    return deckPlayer.size();
}
string Player::getName() {
    return name;
}
vector <card> Player::getdeckPlayer()  {
    return deckPlayer;
}
card Player :: playCard(){
    return deckPlayer [deckPlayer.size()-1];
}


vector<card> Player:: winnerDeck(){
    return deckWonTurn;
}
void Player::setName(string name){
    this->name = name;
}

void Player:: updateDeckPlay(vector<card> newDeck){

    deckPlayer.clear();
    deckPlayer = newDeck;

}