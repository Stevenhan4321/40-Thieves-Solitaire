/*
 * Use this file for experimenting with your code,
 * testing things that don't work, debugging, etc.
 *
 * You can compile and run this via 'make experiment'
 *
 * This file will not be graded
 */
#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include "../include/GameBoard.h"
#include "../include/Stack.h"
using namespace std;
int main() {
  std::cout << "'make experiment' will run this main" << std::endl;

  // When you are finished your implementation, uncomment the code
  // below and make sure 'make experiment' compiles and runs.
  // This will ensure that your interface has the correct syntax and will be
  // compatible with our unit tests that we will run for grading.

  
  // Produce a new deck (consisting of two standard decks) and shuffle its
  // cards.
  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }
  std::random_shuffle(d.begin(), d.end());


  
  BoardT board(d);

  // CardStackT tableau = board.get_tab(6).toSeq();
  // vector<CardT> deck_seq = tableau.toSeq();

  // for (CardT x : deck_seq){
  //   cout << x.s <<" " << x.r << endl;
  // }

  // for (int i = 0; i < 12; i ++){
  //     board.deck_mv();
  // }
  // int x = board.get_tab(5).top().r;
  // board.waste_mv(Foundation, 1);
  // board.tab_mv(Foundation, 5, 1);

  // //cout << board.get_waste().top().s;
  // //cout << board.get_waste().top().r;


  // cout << board.get_foundation(1).top().r;


  // // std::cout << board.get_deck().top().s << endl;
  // // board.deck_mv();
  // // std::cout << board.get_deck().top().s << endl;



  
  try {
    std::cout << "Valid tab move? " << board.is_valid_tab_mv(Foundation, 0, 0) << std::endl;
  } catch (std::out_of_range &e) {}


  try {
    std::cout << "Valid waste move? " << board.is_valid_waste_mv(Foundation, 0) << std::endl;
  } catch (std::invalid_argument &e) {}


  std::cout << "Valid deck move? "   << board.is_valid_deck_mv() << std::endl;

  
  std::cout << "Is win state? "      << board.is_win_state() << std::endl;
  std::cout << "Valid move exists? " << board.valid_mv_exists() << std::endl;
  
  
  try {
    board.tab_mv(Tableau, 0, 1);
  } catch (std::invalid_argument &e) {}
  board.deck_mv();
  try {
    board.waste_mv(Tableau, 0);
  } catch (std::invalid_argument &e) {}
  CardStackT tableau = board.get_tab(0);
  CardStackT foundation = board.get_foundation(0);
  CardStackT deck = board.get_deck();
  CardStackT waste = board.get_waste();

  std::vector<CardT> vec = deck.toSeq();
  std::cout << "Sequence length: " << vec.size() << std::endl;
  std::cout << "Deck size: " << deck.size() << std::endl;
  std::cout << "Deck top: " << deck.top().s << " " << deck.top().r << std::endl;

  CardStackT foo(vec);
  foo = foo.push(d[0]);
  CardT bar = foo.top();
  std::cout << "Card: " << bar.s << " " << bar.r << std::endl;
  foo = foo.pop();
  




  return 0;
}
