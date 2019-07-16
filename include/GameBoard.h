/**
 * \file GameBoard.h
 * \author Steven Han 
 * \brief ADT for game board
 */
#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_
#include "CardTypes.h"
#include "CardStack.h"
#include <vector>

/**
 * \brief game board ADT 
 */
class BoardT{

    private:
        std::vector<CardStackT> T; 
        std::vector<CardStackT> F; 
        CardStackT D; 
        CardStackT W;
        std::vector<CardStackT> tab_deck(std::vector<CardT> s);
        std::vector<CardStackT> init_seq(unsigned int n);
        bool two_decks(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT W, CardStackT D);
        unsigned int cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT W, CardStackT D);
        bool valid_tab_tab(unsigned int n0, unsigned int n1);
        bool valid_tab_foundation(unsigned int n0, unsigned int n1);
        bool valid_waste_tab(unsigned int n);
        bool valid_waste_foundation(unsigned int n);
        bool tab_placeable(CardT c, CardT d);
        bool foundation_placeable(CardT c, CardT d);
        bool is_valid_pos(CategoryT c, unsigned int n);

    public:
        /**
         * \brief default Board Constructor 
         */
        BoardT();

        /**
         * \brief Board Constructor 
         * \param deck Sequence of CardT
         */
        BoardT(std::vector<CardT> deck);

        /**
         * \brief checks if it is a valid tableau move 
         * \param c Category you are moving to
         * \param n0 from which tableau stack
         * \param n1 to which tableau stack 
         * \return true of false 
         */
        bool is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1);

        /**
         * \brief if you can move from waste
         * \param c Category you are moving to 
         * \param n index of the stack you moving to
         * \return if you can move or not 
         */
        bool is_valid_waste_mv(CategoryT c, unsigned int n);

        /**
         * \brief checks if you can move from deck
         * \return yes or no answer 
         */
        bool is_valid_deck_mv();

        /**
         * \brief move from the tableau 
         * \param c which pile you are moving to 
         * \param n0 index from tableau 
         * \param n1 index of the category you are moving to
         */
        void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);

        /**
         * \brief move from waste pile to other piles
         * \param c category you want to move to 
         * \param n index of which pile you are moving to
         */
        void waste_mv(CategoryT c, unsigned int n);

        /**
         * \brief move from deck to waste pile
         */
        void deck_mv();

        /**
         * \brief returns the cards in tableau category 
         * \param i index of tableau sequence 
         * \return the stack of cards in the tableau 
         */
        CardStackT get_tab(unsigned int i);

        /**
         * \brief returns cards in foundation category 
         * \param i index of foundation sequence 
         * \return the stack of cards in the foundation stack
         */
        CardStackT get_foundation(unsigned int i);

        /**
         * \brief returns the cards in the deck
         * \return the stack of cards in the deck
         */
        CardStackT get_deck();

        /**
         * \brief returns in cards in the waste pile
         * \return the stack of cards in the waste pile
         */
        CardStackT get_waste();

        /**
         * \brief checks to see if valid moves exist 
         * \return yes or not answer if there is valid move 
         */
        bool valid_mv_exists();

        /**
         * \brief checks if you won 
         * \return true or false to see if you won
         */
        bool is_win_state();   

};



#endif
