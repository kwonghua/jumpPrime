//Kevin Wong-Hua
//duelingJP.h
//
// Created by kevin on 9/24/2020.
//


//              Public Interface
// duelingJP is an object that encapsulates a number of jumpPrime objects.
// it takes in an array of integers and size of that array to initialize the jumpPrime objects
// can also take in an array of jumpPrime objects and the size of that array
// Users can request the number of "collisions' and "inversions" the jumpPrime objects have created.
//
// Interface invariant
// getCollisions()
// returns numbers of collisions from the jumpPrime objects
//
// getInversions()
// returns numbers of inversions from the jumpPrime objects
#include "jumpPrime.h"

#ifndef INC_3200_P2_DUELINGJP_H
#define INC_3200_P2_DUELINGJP_H
class duelingJP{
public:
    duelingJP(int list[], int len);
    duelingJP(jumpPrime* list[], int len);
    duelingJP(const duelingJP &src);
    duelingJP(duelingJP &&src);

    ~duelingJP();
    duelingJP& operator=(const duelingJP& rhs);
    duelingJP& operator=(duelingJP&& rhs);

    // void up();
    int getCollisions();
    int getInversions();

    duelingJP operator+(const duelingJP& rhs); // Addition operator duelingJP + duelingJP
    friend duelingJP operator+(duelingJP& lhs, jumpPrime* rhs); // Addition operator duelingJP + jumpPrime
    friend duelingJP operator+(jumpPrime* lhs, duelingJP& rhs); // Addition operator jumpPrime + duelingJP

    friend duelingJP operator+(duelingJP& lhs, int rhs);        // Addition operator duelingJP + int
    friend duelingJP operator+(int lhs, duelingJP& rhs);        // Addition operator int + duelingJP

    friend bool operator == (const duelingJP& lhs, const duelingJP& rhs); // equality operator duelingJP == duelingJP
    friend bool operator != (const duelingJP& lhs, const duelingJP& rhs); // not-equal-to operator duelingJP != duelingJP

    friend bool operator > (const duelingJP& lhs, const duelingJP& rhs);  // greater than duelingJP > duelingJP
    friend bool operator <= (const duelingJP& lhs, const duelingJP& rhs); // less than/equal to operator duelingJP <= duelingJP

    friend bool operator < (const duelingJP& lhs, const duelingJP& rhs);  // greater than duelingJP < duelingJP
    friend bool operator >= (const duelingJP& lhs, const duelingJP& rhs); // less than/equal to operator duelingJP >= duelingJP

    duelingJP operator+=(const duelingJP& rhs);     // Addition assignment operator duelingJP += duelingJP
    duelingJP operator+=(jumpPrime* rhs);           // Addition assignment operator duelingJP += jumpPrime
    duelingJP operator+=(int rhs);                  // Addition assignment operator duelingJP += int
private:

    bool active = true;
    int size;
    int collisions = 0;
    int inversions = 0;
    jumpPrime** JPList; //list of jumpPrime objects
    int* givenList; //array passed in to initialize jumpPrime objects

    void findCollisions();
    void findInversions();

    void deallocateHeaps();

    void initializeJP();
    void copy(const duelingJP &source);
};

#endif //INC_3200_P2_DUELINGJP_H
