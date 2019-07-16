/**
 * \file CardTypes.h
 * \author
 * \brief all the exported constants 
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \breif Describes the total number of cards 
 */
#define TOTAL_CARDS 104

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \breif Types of suits 
 */
enum SuitT {Heart, Diamond, Club, Space};

/**
 * \breif Categories of board
 */
enum CategoryT {Tableau, Foundation, Deck, Waste};

/**
 * \breif card type
 */
struct CardT{
    SuitT s;
    RankT r;
};


#endif
