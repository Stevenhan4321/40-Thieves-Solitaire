/**
 * \file Stack.h
 * \author Steven
 * \brief Stack Generic ADT
 */
#ifndef A3_STACK_H_
#define A3_STACK_H_
#include <vector>

/**
 * \brief Generic ADT for stack
 */
template <class T>
class Stack{
    private:
        /// vector type T 
        std::vector<T> s;

    public:
        /**
         * \breif default constructor
         */
        Stack();

        /**
         * \brief Stack Constructor
         * \param s takes in vector s of type T
         */
        Stack(std::vector<T> s);

        /**
         * \brief push onto stack
         * \param e type T variable 
         * \return new Stack 
         */
        Stack<T> push(T e);

        /**
         * \brief pops from the stack
         * \return new Stack
         */
        Stack<T> pop();

        /**
         * \breif gets top element from stack
         * \return type T
         */
        T top();

        /**
         * \brief gets size of stack
         * \return size of stack
         */
        unsigned int size();

        /**
         * \breif gets the sequence of stack 
         * \returns a vector of type T 
         */
        std::vector<T> toSeq();
};


#endif
