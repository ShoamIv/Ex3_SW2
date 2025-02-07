/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Deck.hpp"
#include <random>
#include <algorithm>

std::vector<DevCard*>Deck::deck;
Deck* pt = nullptr;

Deck* Deck::getdeck() {
    if (pt==nullptr){
        pt=new Deck();
        return pt;
    }else
    return pt;
}

Deck::Deck() {
    deck.emplace_back(new VictoryPoint());
    deck.emplace_back(new VictoryPoint());
    deck.emplace_back(new VictoryPoint());
    deck.emplace_back(new VictoryPoint());
    deck.emplace_back(new Year_Of_Plenty());
    deck.emplace_back(new Year_Of_Plenty());
    deck.emplace_back(new Year_Of_Plenty());
    deck.emplace_back(new Monopoly());
    deck.emplace_back(new Monopoly());
    deck.emplace_back(new Monopoly());
    deck.emplace_back(new Road_building());
    deck.emplace_back(new Road_building());
    deck.emplace_back(new Road_building());
    deck.emplace_back(new Knight());
    deck.emplace_back(new Knight());
    deck.emplace_back(new Knight());
    shuffle();
}



Deck::~Deck()
{
    std::cout<<"cleaing the deck\n";
     for (int i = 0; i < deck.size(); ++i) {
        
        if (deck.at(i) != nullptr) {
            delete deck.at(i);
            deck.at(i) = nullptr; // Nullify the pointer to avoid double deletion issues
        }
    }
    deck.clear(); // Optional: Clear the container after deleting all elements
}

void Deck::shuffle() {
    unsigned seed= rand()%10+1;
    std::shuffle(Deck::deck.begin(),Deck::deck.end(),std::default_random_engine(seed));

    }

DevCard* Deck::ExtractCard() {
   if(deck.empty()) {
       throw std::runtime_error("Cannot draw, the deck is empty.");
   }
       unsigned seed=rand()%10+1;
       std::default_random_engine generator(seed);
       std::uniform_int_distribution<size_t>distribution(0,deck.size()-1);
       size_t random_index=distribution(generator);
       std::string name=deck.at(random_index)->Get_Card_name();
        for(DevCard* card: deck){
            if(card->Get_Card_name()==name){
                 auto * drawn=card;
                 deck.erase(deck.begin()+(int)random_index);
                 return drawn;
            }
        }
                return nullptr;

        /*
       if(name=="Knight"){
           auto * drawn=new Knight();
           auto * drawn=&deck.begin()+(int)random_index;
           deck.erase(deck.begin()+(int)random_index);

           return drawn;
       }
       if(name=="Monopoly"){
         auto * drawn=new Monopoly();
           deck.erase(deck.begin()+(int)random_index);
           return drawn;
        }
       if(name=="Year of Plenty"){
            auto * drawn=new Year_Of_Plenty();
           deck.erase(deck.begin()+(int)random_index);
          return drawn;
        }
        if(name=="Victory Point"){
            auto * drawn=new VictoryPoint();
            deck.erase(deck.begin()+(int)random_index);
            return drawn;
        }
        else if(name=="Road Building"){
            auto * drawn=new Road_building();
            deck.erase(deck.begin()+(int)random_index);
            return drawn;
        }
        return nullptr;
        */
    }

void Deck::clean_up()
{
 if (pt != nullptr) {
        delete pt;
        pt = nullptr;
    }
   
}
