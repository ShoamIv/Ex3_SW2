/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Player.hpp"
std::vector<Player*> Player::players;

Player::Player() {
    this->name="";
    this->Winning_p=0;
    this->road_token=2;
}

std::string Player::getName() {
    return this->name;
}

int Player::get_Winning_p() const {
    return this->Winning_p;
}

void Player::setName(std::string name1) {
    this->name=std::move(name1);
}

void Player::set_Winning_p(int increment) {
    this->Winning_p+=increment;
}

int Player::roll() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a uniform integer distribution in the range [1, 6]
    std::uniform_int_distribution<> distrib(1, 6);

    // Roll two dice
    int diceRoll=distrib(gen)+distrib(gen);
    return diceRoll;
}

void Player::Place_Settle(int hexagon, int vertex, Board& board) {
    Point* v = board.getHexagon().at(hexagon).getVertex().at(vertex);
    if((this->Settlements.size()>1 && this->Roads.size()>1)) {
        if (!Check_Res("Settlement")) {
            std::cout << "You do not have enough resources." << std::endl;
            return;
        }
        if(!Settlement::ValidBuilding(v)){
            std::cerr<<"Invalid Point to place settlement\n";
            return;
        }
    }
    // Create a Settlement object using pointers
    auto * s = new Settlement(this,v);
    std::cout<<this->getName()<< " Place a settlement at: ";
    s->get_Vertex()->print_p();std::cout<<std::endl;
    // Store the pointer to the Settlement object
    Settlements.push_back(s);
    v->setOwner(this->getName());
    v->set_building_type("Settle");
    this->Winning_p++;
}

void Player::Place_Settle(Point *v){
    if((this->Settlements.size()>1 && this->Roads.size()>1)) {
        if (!Check_Res("Settlement")) {
            std::cout << "You do not have enough resources." << std::endl;
            return;
        }
    }
    if(!Settlement::ValidBuilding(v)){
        std::cerr<<"Invalid Point to place settlement\n";
        return;
    }
    // Create a Settlement object using pointers
    auto * s = new Settlement(this, v);
    std::cout<<this->getName()<< " Place a settlement at: ";
    s->get_Vertex()->print_p();std::cout<<std::endl;
    // Store the pointer to the Settlement object
    Settlements.push_back(s);
    v->setOwner(this->getName());
    v->set_building_type("Settle");
    this->Winning_p++;
}

void Player::Place_Road(Point &p1,  Point &p2, Board& board) {
    if(road_token==0) {
        if (!Check_Res("Settlement")) {
            std::cout << "You do not have enough resources." << std::endl;
            return;
        }
    }
    else{road_token--;}
    Road * a=new Road(p1,p2,this->name,board);
    std::cout<<this->getName()<< " Place a Road at:(";
    p1.print_p();
    std::cout<<"),(";
    p2.print_p(); std::cout<<")"<<std::endl;
    Roads.push_back(a);
    a->getEdge().set_owner(this->getName());
}

void Player::Place_Road(Edge &e,Board& board){
    if(this->road_token == 0){
        if (!Check_Res("Settlement")) {
            std::cout << "You do not have enough resources." << std::endl;
            return;
        }
    }
    else{road_token--;}

    Road a=Road(e,this->name,board);
    std::cout<<this->getName()<< " Place a Road at:(";
    e.getPoints().at(0)->print_p();
    std::cout<<"),(";
    e.getPoints().at(1)->print_p(); std::cout<<")"<<std::endl;
    this->Roads.emplace_back(&a);
    e.set_owner(this->getName());
}

void Player::Place_City(Settlement* settle) {
    if(!Check_Res("City")){
        std::cout<<"You do not have enough resources."<<std::endl;
        return;
    }
    if (settle == nullptr || settle->GetOwner() != this) return;
    // Capture state from the old Settlement
    Point * location = (settle->get_Vertex());
    // Delete the old Setttlement
    delete settle;
    // Allocate and replace with a new City
    City * city = new City(this, location);
    std::cout<<this->getName()<< "Place a City at: ";
    city->get_Vertex()->print_p();std::cout<<std::endl;
    this->Cities.emplace_back(city);
    location->setOwner(this->getName());
    location->set_building_type("City");
    this->Winning_p++;
}

void Player::placeRoadInteractive(Board &board) {

        std::cout << "Enter the coordinates  for road:"<<std::endl;
        int x1, y1;
        int x2, y2;
        std::cin >> x1 >> y1;
        std::cin >> x2 >> y2;
        Point p1 (x1,y1);
        Point p2(x2,y2);
        this->Place_Road(p1,p2,board);
}

void Player::gainResource(int res, int increase) {
    this->resource.at(res)+=increase;
}

void Player::playCard(const std::string& card , Board &board) {
    if (!this->Cards.empty()) {
        bool flag=false;
        for(int i=0; i<this->Cards.size(); i++){
            if(Cards.at(i)->Get_Card_name()==card){
                Cards[i]->action(*this,board);
                std::cout<<this->getName()<<" Used: "<<card<<std::endl;
                Cards.erase(Cards.begin() + i);
                flag=true;
                break;
            }
        }
        if(!flag)
        std::cerr << "You do not have this card." << std::endl;
    } else {
        std::cerr << "You have no cards" << std::endl;
    }
}

void Player::placeSettleInteractive(Board &board) {
    std::cout << "Enter the Hexagon id:"<<std::endl;
    int hexagon,vertex;
    std::cin >> hexagon;
    std::cout << "Enter the vertex id:"<<std::endl;
    std::cin >> vertex;
    this->Place_Settle(hexagon,vertex,board);
}

void Player::offer(Player &p,const std::string& product1,const std::string& product2,int amount1,int amount2) {
    bool ans = false;
    std::string reply;
    std::cout << " Hello " << p.getName() << std::endl;
    std::cout << this->getName() << " wish to trade the details are: " << std::endl;
    std::cout << product1 << " amount: " << amount1 << "  in exchange of your: ";
    std::cout << product2 << " amount: " << amount2 << std::endl;
    std::cout << "please insert your reply:Yes/No. " << std::endl;
    std::cin >> reply;
    if (reply == "Yes")ans = true;
    else if (reply == "No")ans = false;else{
        std::cout <<"Reply Only Yes or No"<<std::endl;
        std::cin >> reply;
    }
    if (ans)Trade(p,product1, product2, amount1, amount2);
    else {
        std::cout << p.getName() << " refuse to the trade." << std::endl;
    }
}

void Player::Trade(Player &p,const std::string& product1, const std::string& product2, int amount1, int amount2) {
    std::string resources [5]={"Wood","Brick","Wool","Wheat","Ore"};//as enum.
    std::string cards [5]={"Knight","Road_building","Monopoly","VictoryPoint","Year_Of_Plenty"};
    bool flag=false;
    for(int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            if (product1 == resources[i] && product2 == resources[j]) {

                if( this->resource.at(i)-amount1<0){
                    std::cout<<"Not Enough Resources!\n";break;
                }
                if( p.resource.at(j)-amount2<0){
                    std::cout<<"Not Enough Resources!\n";break;
                }
                this->resource.at(j)+=amount2;
                this->resource.at(i)-=amount1;
                p.resource.at(i)+=amount1;
                p.resource.at(j)-=amount2;
                break;
            }

            if (product1 == resources[i] && product2 == cards[j]) {
                if( this->resource.at(i)-amount1<0){
                    std::cout<<"Not Enough Resources!\n";break;
                }
                if(!p.ensure_card_amount(product2,amount2)){
                    std::cout<<"Not Enough Cards!\n";break;
                }
                flag = true;
                p.resource.at(i) += amount1;
                for(int t=0; t<p.Cards.size(); t++) {
                    if (product2 == p.Cards.at(t)->Get_Card_name()) {
                        this->Cards.emplace_back(p.Cards.at(t));
                        p.Cards.erase(p.Cards.begin() + t);
                    }
                }
                Knight::Check_Knight(p);
            }


            if (product1 == cards[i] && product2 == resources[j]) {
                    if( p.resource.at(j)-amount2<0){
                        std::cout<<"Not Enough Resources!\n";break;
                    }
                    if(!this->ensure_card_amount(product1,amount1)){
                        std::cout<<"Not Enough Cards!\n";break;
                    }
                     flag=true;
                    this->resource.at(i)+=amount2;
                    for(int t=0; t<this->Cards.size(); t++) {
                        if (product1 == this->Cards.at(t)->Get_Card_name()) {
                         p.Cards.emplace_back( this->Cards.at(t));
                         this->Cards.erase(this->Cards.begin()+t);
                    }
                }
                Knight::Check_Knight(*this);
            }


            if (product1 == cards[i] && product2 == cards[j]) {
                if(!this->ensure_card_amount(product1,amount1)){
                    std::cout<<"Not Enough Cards!\n";break;
                }
                if(!p.ensure_card_amount(product2,amount2)){
                    std::cout<<"Not Enough Cards!\n";break;
                }
                flag=true;
                for(int t=0; t<this->Cards.size(); t++) {
                    if (product1 == this->Cards.at(t)->Get_Card_name()) {
                        p.Cards.emplace_back(this->Cards.at(t));
                        this->Cards.erase(this->Cards.begin() + t);
                    }
                }
                    for(int t=0; t<p.Cards.size(); t++) {
                        if (product2 == p.Cards.at(t)->Get_Card_name()) {
                            this->Cards.emplace_back(p.Cards.at(t));
                            p.Cards.erase(p.Cards.begin() + t);
                    }
                }
                Knight::Check_Knight(p);
                Knight::Check_Knight(*this);
            }
        }
    }
    if(!flag) {
        std::cout << "The Trade not accomplish, Check your Resources, Cards and typing.";
        return;
    }
}

bool Player::Check_Res(const std::string& complex) {
    if (complex == "Road") {
        if (this->resource.at(0) > 0 && this->resource.at(1) > 0)return true;
    }
    if (complex == "Settlement") {
        if (this->resource.at(0) > 0 && this->resource.at(1) > 0
            && this->resource.at(2) > 0 && this->resource.at(3) > 0)
            return true;
    }
    if (complex == "City") {
        if (this->resource.at(3) > 1 && this->resource.at(4) > 2)return true;
    }
    if (complex == "Card") {
        if (this->resource.at(2)>0 && this->resource.at(3) > 0 && this->resource.at(4) > 0) return true;
    }
    return false;
}

void Player::Buy_Card() {
    if(!Check_Res("Card")){
        std::cout<<"Not Enough Resources!\n";
        return;
    }
   DevCard * card= Deck::ExtractCard();
   std::cout<<this->getName()<<" Pull from deck:"<< card->Get_Card_name()<<std::endl;
   this->Cards.push_back(card);
}

bool Player::ensure_card_amount(const std::string& card_name,int amount) {
    int counter=0;
    for(auto & Card : this->Cards){
        if(Card->Get_Card_name()==card_name) counter++;
    }
    return amount==counter;
}

