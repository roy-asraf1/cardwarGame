#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

//outline constracturs

card::card(int val, string shape) {
    this->val = val;
    this->shape = shape;
}
card:: card(const card& _card):val(_card.val),shape(_card.shape){

}
card& card:: operator=(const card& other){
    if(this != &other){
        val = other.val;
        shape = other.shape;
    }
    return *this;
}

card:: card(card&& other) noexcept:val(other.val),shape(other.shape){

}
card& card:: operator=(card&& other) noexcept{
    if(this != &other){
        val = other.val;
        shape = other.shape;
    }
    return *this;
}
card::~card()
{
}

void card::setVal(int val) {
    this->val = val;
}

int card::getVal() {
    return val;
}

string card::getShape() {
    return shape;
}

void card::setShape(std::string shape) {
    this->shape = shape;
}

void card::printCard() {
    cout << this->val << " , " << this->shape << endl;
}
