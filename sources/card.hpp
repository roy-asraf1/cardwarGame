#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using namespace std;

namespace ariel {

    class card {
    private:
        int val;
        std::string shape;

    public:
        //constractor
        card(int val, std::string shape);

         //Copy Constructor
        card(const card& _card);

            // Move Constructor
        card(card&& other) noexcept;

        //copy assignment operator
        card& operator=(const card& other);

        //move assignment operator
        card& operator=(card&& other) noexcept;
        ~card();
        
        
        void setVal(int val);
        int getVal() ;
        string getShape();
        void setShape(string shape);
        void printCard();
    };
}

#endif 
