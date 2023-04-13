#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <ctime>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;



TEST_CASE("check time off the game: "){
    clock_t start, end;
    start = clock();
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    end = clock();
    double timeTotal = double(end - start) / CLOCKS_PER_SEC;
    CHECK(timeTotal < 5.0); // Check if total time is moreover

}
//***************game functions checks********************
TEST_CASE("CHECK if void function "){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    
    CHECK(std::is_void<decltype(game.playAll())>::value);
    CHECK(std::is_void<decltype(game.playTurn())>::value);
    CHECK(std::is_void<decltype(game.printLastTurn())>::value);
    CHECK(std::is_void<decltype(game.printLog())>::value);
    CHECK(std::is_void<decltype(game.printStats())>::value);
    CHECK(std::is_void<decltype(game.printWiner())>::value);

}


TEST_CASE("check printWiner"){
   
    // check if -> winner=p1.name||p2.name
    
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    string winner;
    if (p1.cardesTaken()>p2.cardesTaken()){
        winner = p1.getName();
    }
    else
        winner = p2.getName();
    CHECK(game.getWinner() == winner);
    
}

TEST_CASE("CHECK the value of the cards"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    int min = 14, max = 0;
    bool negative = false;

    vector<card> deck = game.getDeck();

    for (const auto& card : deck) {
        if (card.getVal() < min) {
            min = card.getVal();
        }
        if (card.getVal() > max) {
            max = card.getVal();
        }
    }

    CHECK(min == 1);
    CHECK(max == 13);
    CHECK(negative == false);

}
TEST_CASE("CHECK throws:"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(p1.cardesTaken());
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.shuffleDeck());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("initialize Stack:")
{
   
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    

    CHECK(p1.stacksize()<52);
    CHECK(p2.stacksize()<52);
    CHECK(p1.stacksize()>0);
    CHECK(p2.stacksize()>0);

}
