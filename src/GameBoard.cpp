#include <iostream>
#include "../include/Stack.h"
#include "../include/CardTypes.h"
#include "../include/CardStack.h"
#include "../include/GameBoard.h"
#include <vector>

using namespace std;

BoardT::BoardT(){
    std::vector<CardStackT> temp = {};
    std::vector<CardT> temp1 = {};
    CardStackT temp2(temp1);
    this->T = temp;
    this->F = temp;
    this->D = temp2;
    this->W = temp2;

}

BoardT::BoardT(std::vector<CardT> deck){

    if(!(two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT {}))){
        throw invalid_argument("invalid argument");
    }

    std::vector<CardT> temp;
    for (int i = 0; i <= 39; i++){
        temp.push_back(deck[i]);
    }
    this->T = tab_deck(temp);
    this->F = init_seq(8);

    std::vector<CardT> temp2;
    for (int i = 40; i <= 103; i++){
        temp2.push_back(deck[i]);
    }
    CardStackT temp_deck(temp2);
    this->D = temp_deck;

    std::vector<CardT> temp3;
    CardStackT temp_waste(temp3);
    this->W = temp_waste;
}


bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1){
    

    if (c == Tableau){
        if (!(is_valid_pos(c, n0) & is_valid_pos(c, n1)) ){
            throw out_of_range("out of range for tableau");
        }
        return valid_tab_tab(n0, n1);
    }
    if (c == Foundation){
        if (!(is_valid_pos(c, n0) & is_valid_pos(c, n1)) ){
            throw out_of_range("out of range for Foundation");
        }
        return valid_tab_foundation(n0, n1);
    }
    if (c == Deck | c == Waste){
        return false;
    }
}


bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n){
    if (this->W.size() == 0){
        throw invalid_argument("waste size 0");
    }

    if (c == Tableau){
        if (!(is_valid_pos(c, n))){
            throw out_of_range("out of range for Tableau");
        }

        return valid_waste_tab(n);
    }
    if (c == Foundation){
        if (!(is_valid_pos(c, n))){
            throw out_of_range("out of range for Foundation");
        }
        return valid_waste_foundation(n);
    }
    if (c == Deck | c == Waste){
        return false;
    }
}


bool BoardT::is_valid_deck_mv(){
    return (this->D.size()>0);
}



void BoardT::tab_mv(CategoryT c, unsigned int n0, unsigned int n1){
    
    if (!(is_valid_tab_mv(c, n0, n1))){
        throw invalid_argument("invalid argument");
    }
    
    if (c == Tableau){
        this->T[n1] = this->T[n1].push(this->T[n0].top());
        this->T[n0] = this->T[n0].pop();
    }

    if (c == Foundation){
        this->F[n1] = this->F[n1].push(this->T[n0].top());
        this->T[n0] = T[n0].pop(); 
    }
}


void BoardT::waste_mv(CategoryT c, unsigned int n){

    if(!(is_valid_waste_mv(c,n))){
        throw invalid_argument("invalid argument");
    }

    if (c == Tableau){
        this->T[n] = this->T[n].push(this->W.top());
        this->W = this->W.pop();
    }

    if (c == Foundation){
        this->F[n] = this->F[n].push(this->W.top());
        this->W = this->W.pop();
    }
}
void BoardT::deck_mv(){

    if(!(is_valid_deck_mv())){
        throw invalid_argument("invalid argument");
    }

    this->W = this->W.push(this->D.top());
    this->D = this->D.pop();

}




CardStackT BoardT::get_tab(unsigned int i){

    if (!(is_valid_pos(Tableau, i))){
        throw out_of_range("out of range");
    }

    return this->T[i];

}
CardStackT BoardT::get_foundation(unsigned int i){

    if (!(is_valid_pos(Foundation, i))){
        throw out_of_range("out of range");
    }

    return this->F[i];

}
CardStackT BoardT::get_deck(){

    return this->D;

}
CardStackT BoardT::get_waste(){

    return this->W;

}



bool BoardT::valid_mv_exists(){   //Need to check for size later 
    
    if (is_valid_deck_mv()){
        return true;
    }

    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
            if (is_valid_tab_mv(Tableau, j, k)){
                return true;
            }
        }
    }

    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 8; k++){
            if (is_valid_tab_mv(Foundation, j, k)){
                return true;
            }
        }
    }

    for (int i = 0; i < 10; i++){
        if (is_valid_waste_mv(Tableau, i)){
            return true;
        }
    }

    for (int i = 0; i < 8; i++){
        if (is_valid_waste_mv(Foundation, i)){
            return true;
        }
    }
}


bool BoardT::is_win_state(){

    if (this->F.size() == 0){
        throw invalid_argument("waste size 0");
    }

    int counter = 0;
    for (int i = 0; i < 8; i++){
        counter += this->F[i].size();
    }

    if (counter == 104){
        return true;
    }
    return false;

    // int winstate = 0;
    // for (int i = 0; i < 8; i++){
    //     if (this->F[i].top().r == KING){
    //         winstate = 1;
    //     }
    //     else{
    //         winstate = 0;
    //         break;
    //     }
    // }

    // if (winstate == 1){
    //     return true;
    // }
    // return false;
}






























//Private functions 

bool BoardT::two_decks(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT W, CardStackT D){
    int heart_array [14] = {};
    int diamond_array [14] = {};
    int club_array [14] = {};
    int space_array [14] = {};

    for (CardStackT x : T){
        std::vector<CardT> y = x.toSeq();
        for (CardT z : y){
            if (z.s == Heart){
                heart_array[z.r] += 1;
            }

            if (z.s == Diamond){
                diamond_array[z.r] += 1;
            }

            if (z.s == Club){
                club_array[z.r] += 1;
            }
            if (z.s == Space){
                space_array[z.r] += 1;
            }
        }
    }

    for (CardStackT x : F){
        std::vector<CardT> y = x.toSeq();
        for (CardT z : y){
            if (z.s == Heart){
                heart_array[z.r] += 1;
            }

            if (z.s == Diamond){
                diamond_array[z.r] += 1;
            }

            if (z.s == Club){
                club_array[z.r] += 1;
            }
            if (z.s == Space){
                space_array[z.r] += 1;
            }
        }
    }

    std::vector<CardT> waste_seq = W.toSeq();
    for (CardT z : waste_seq){
        if (z.s == Heart){
            heart_array[z.r] += 1;
        }

        if (z.s == Diamond){
            diamond_array[z.r] += 1;
        }

        if (z.s == Club){
            club_array[z.r] += 1;
        }
        if (z.s == Space){
            space_array[z.r] += 1;
        }
    }


    std::vector<CardT> deck_seq = D.toSeq();
    for (CardT z : deck_seq){
        if (z.s == Heart){
            heart_array[z.r] += 1;
        }
        if (z.s == Diamond){
            diamond_array[z.r] += 1;
        }
        if (z.s == Club){
            club_array[z.r] += 1;
        }
        if (z.s == Space){
            space_array[z.r] += 1;
        }
    }



    for (int i = 1; i < 14; i++){
        if (heart_array[i] != 2){
            return false;
        }
        if (diamond_array[i] != 2){
            return false;
        }
        if (club_array[i] != 2){
            return false;
        }
        if (space_array[i] != 2){
            return false;
        }
    }
    return true;
}



unsigned int BoardT::cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT W, CardStackT D){
    int counter = 0;

    for (CardStackT x : T){
        std::vector<CardT> y = x.toSeq();
        int z = y.size();
        counter += z;
    }
    for (CardStackT x : F){
        std::vector<CardT> y = x.toSeq();
        int z = y.size();
        counter += z;
    }
    counter += W.size() + D.size();
    return counter;
}


std::vector<CardStackT> BoardT::tab_deck(std::vector<CardT> s) {            //puts it into tableau deck

    std::vector<CardT> tab1 = {s[0], s[1], s[2], s[3]};
    std::vector<CardT> tab2 = {s[4], s[5], s[6], s[7]};
    std::vector<CardT> tab3 = {s[8], s[9], s[10], s[11]};
    std::vector<CardT> tab4 = {s[12], s[13], s[14], s[15]};
    std::vector<CardT> tab5 = {s[16], s[17], s[18], s[19]};
    std::vector<CardT> tab6 = {s[20], s[21], s[22], s[23]};
    std::vector<CardT> tab7 = {s[24], s[25], s[26], s[27]};
    std::vector<CardT> tab8 = {s[28], s[29], s[30], s[31]};
    std::vector<CardT> tab9 = {s[32], s[33], s[34], s[35]};
    std::vector<CardT> tab10 = {s[36], s[37], s[38], s[39]};

    CardStackT tab_1(tab1);
    CardStackT tab_2(tab2);
    CardStackT tab_3(tab3);
    CardStackT tab_4(tab4);
    CardStackT tab_5(tab5);
    CardStackT tab_6(tab6);
    CardStackT tab_7(tab7);
    CardStackT tab_8(tab8);
    CardStackT tab_9(tab9);
    CardStackT tab_10(tab10);

    std::vector<CardStackT> tab_seq = {tab_1, tab_2, tab_3, tab_4, tab_5, tab_6, tab_7, tab_8, tab_9, tab_10};
    return tab_seq;
} 

std::vector<CardStackT> BoardT::init_seq(unsigned int s){
    std::vector<CardStackT> found_seq = {};
    for (int i = 0; i < s; i++){
        std::vector<CardT> temp = {};
        CardStackT temp_found(temp);
        found_seq.push_back(temp_found);
    }
    return found_seq;
}

bool BoardT::is_valid_pos(CategoryT c, unsigned int n){
    if (c == Tableau){
        if(this->T[n].size() <= 10){
            return true;
        }
        return false;
    }

    if (c == Foundation){
        if (this->F[n].size() <= 8){
            return true;
        }
        return false;
    }
}



bool BoardT::valid_tab_tab(unsigned int n0, unsigned int n1){
    if (this->T[n0].size() > 0){
        if (this->T[n1].size() > 0){
            return tab_placeable(this->T[n0].top(), this->T[n1].top());
        }
        
        if (this->T[n1].size() == 0){
            return true;
        }
    }

    if (this->T[n0].size() == 0){
        if (this->T[n1].size() > 0){
            return false;
        }        
        if (this->T[n1].size() == 0){
            return false;
        }
    }
    return false;
}


bool BoardT::valid_tab_foundation(unsigned int n0, unsigned int n1){
    if (this->T[n0].size() > 0){
        if (this->F[n1].size() > 0){
            return foundation_placeable(this->T[n0].top(), this->F[n1].top());
        }
        
        if (this->F[n1].size() == 0){
            return (this->T[n0].top().r == ACE);
        }
    }

    if (this->T[n0].size() == 0){
        if (this->F[n1].size() > 0){
            return false;
        }
        
        if (this->F[n1].size() == 0){
            return false;
        }
    }

    return false;
}


bool BoardT::valid_waste_tab(unsigned int n){
    if (this->T[n].size() > 0){
        return tab_placeable(this->W.top(), this->T[n].top());
    }
    if (this->T[n].size() == 0){
        return true;
    }
    return false;
}

bool BoardT::valid_waste_foundation(unsigned int n){
    if (this->F[n].size() > 0){
        return foundation_placeable(this->W.top(), this->F[n].top());
    }
    if (this->F[n].size() == 0){
        return (this->W.top().r == ACE);
    }
    return false;
}

bool BoardT::tab_placeable(CardT c, CardT d){
    if (c.s == d.s){
        if (c.r == d.r - 1){
            return true;
        }
        return false;
    }
    return false;
}
bool BoardT::foundation_placeable(CardT c, CardT d){
    if (c.s == d.s){
        if (c.r == d.r + 1){
            return true;
        }
        return false;
    }
    return false;
    
}
