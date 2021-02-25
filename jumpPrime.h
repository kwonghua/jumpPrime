//Kevin Wong-hua
//jumpPrime.h
// Created by kevin on 9/23/2020.
//
//       public interface
// jumpPrime is an object that will encapsulate any number that is at least 3 digits long, otherwise a default value will be used.
// jumpPrime's encapsulated number will 'jump' after a number of queries, that number is determined by the distance between the two prime numbers.
// jumpPrime has two queries which will give you the closest prime number higher or lower to the encapsulated number.
// jumpPrime will become inactive when the number of 'jumps' reaches the default value of 3.
// User can revive an inactive jumpPrime object. An attempt to revive an active jumpPrime object will cause that object to be permanently deactivated.
// User can reset an ACTIVE jumpPrime object, resetting the number of queries and jumps made.
//
// Interface Invariant
// up()
// post: returns closest prime number that is higher than the encapsulated number
// returns 0 if inactive
//
// down()
// post: returns closest prime number that is lower than the encapsulated number
// returns 0 if inactive
//
// revive()
// Revives an jumpPrime object. An attempt to revive an active jumpPrime object causes that object to be permanently deactivated.
// Returns true on a successful revive attempt
// post: state may be changed
//
// reset()
// Resets an ACTIVE jumpPrime object, resetting it's queries count and number of jumps made.
// Returns true when successfully resetted.
//
// isActive()
// returns if object is active
#ifndef INC_3200_P2_JUMPPRIME_H
#define INC_3200_P2_JUMPPRIME_H
#include <iostream>
class jumpPrime
{
    public:
    jumpPrime(int n);
    jumpPrime();
    jumpPrime& operator=(const jumpPrime &src);
    int up();
    int down();
    bool revive();
    bool reset();
    bool isActive();


    friend jumpPrime operator + (const jumpPrime& lhs, const jumpPrime& rhs); // Addition operator jumpPrime + jumpPrime
    friend jumpPrime operator - (const jumpPrime& lhs, const jumpPrime& rhs); // Subtraction operator jumpPrime - jumpPrime

    friend jumpPrime operator + (const jumpPrime& lhs, int val);          // Addition operator jumpPrime + int
    friend jumpPrime operator + (int val, const jumpPrime& rhs);          // Addition operator int + jumpPrime

    friend jumpPrime operator - (const jumpPrime& lhs, int val);          // Subtraction operator jumpPrime - int
    friend jumpPrime operator - (int val, const jumpPrime& rhs);          // Subtraction operator int - jumpPrime

    friend bool operator == (const jumpPrime& lhs, const jumpPrime& rhs); // equality operator jumpPrime == jumpPrime
    friend bool operator != (const jumpPrime& lhs, const jumpPrime& rhs); // not-equal-to operator jumpPrime != jumpPrime

    friend bool operator > (const jumpPrime& lhs, const jumpPrime& rhs);  // greater than jumpPrime > jumpPrime
    friend bool operator <= (const jumpPrime& lhs, const jumpPrime& rhs); // less than/equal to operator jumpPrime <= jumpPrime

    friend bool operator < (const jumpPrime& lhs, const jumpPrime& rhs); // less than jumpPrime < jumpPrime
    friend bool operator >= (const jumpPrime& lhs, const jumpPrime& rhs); // greater than/equal to jumpPrime >= jumpPrime

    friend bool operator == (const jumpPrime& lhs, int val);           // == operator jumpPrime == int
    friend bool operator == (int val, const jumpPrime& rhs);           // == operator int == jumpPrime

    friend bool operator != (const jumpPrime& lhs, int val);           // != jumpPrime != int
    friend bool operator != (int val, const jumpPrime& rhs);           // != int != jumpPrime

    friend bool operator > (const jumpPrime& lhs, int val);            // jumpPrime > int
    friend bool operator > (int val, const jumpPrime& rhs);            // int > jumpPrime

    friend bool operator <= (const jumpPrime& lhs, int val);           // jumpPrime <= int
    friend bool operator <= (int val, const jumpPrime& rhs);           // int <= jumpPrime

    friend bool operator < (const jumpPrime& lhs, int val);            // jumpPrime < int
    friend bool operator < (int val, const jumpPrime& rhs);            // int < jumpPrime

    friend bool operator >= (const jumpPrime& lhs, int val);           // jumpPrime >= int
    friend bool operator >= (int val, const jumpPrime& rhs);           // int >= jumpPrime

    friend jumpPrime operator * (const jumpPrime& lhs, const jumpPrime& rhs); // multiplication operator jumpPrime * jumpPrime
    friend jumpPrime operator * (const jumpPrime& lhs, int val);              // multiplication operator jumpPrime * int
    friend jumpPrime operator * (int val, const jumpPrime& rhs);              // multiplication operator int * jumpPrime

    friend jumpPrime operator / (const jumpPrime& lhs, const jumpPrime& rhs); // division operator jumpPrime / jumpPrime
    friend jumpPrime operator / (const jumpPrime& lhs, int val);              // division operator jumpPrime / int
    friend jumpPrime operator / (int val, const jumpPrime& rhs);              // division operator int / jumpPrime


    jumpPrime& operator ++ ();                             // Prefix increment operator
    jumpPrime operator ++ (int);                           // Postfix increment operator

    jumpPrime& operator -- ();                            // Prefix decrement operator
    jumpPrime operator -- (int);                          // Postfix decrement operator

    jumpPrime& operator += (int rhs);                    // addition assignment operator jumpPrime += int
    jumpPrime& operator -= (int rhs);                    // subtraction assignment operator jumpPrime -= int

    jumpPrime& operator *= (int rhs);                    // multiplication assignment operator jumpPrime *= int
    jumpPrime& operator /= (int rhs);                    // division assignment operator jumpPrime /= int

    jumpPrime& operator += (const jumpPrime& rhs);                    // addition assignment operator jumpPrime += jumpPrime
    jumpPrime& operator -= (const jumpPrime& rhs);                    // subtraction assignment operator jumpPrime -= jumpPrime

    jumpPrime& operator *= (const jumpPrime& rhs);                    // multiplication assignment operator jumpPrime *= jumpPrime
    jumpPrime& operator /= (const jumpPrime& rhs);                    // division assignment operator jumpPrime /= jumpPrime


    friend std::ostream& operator<<(std::ostream& os, const jumpPrime& jp);

private:
    bool isPrime(int n);
    void findUp();
    void findDown();
    bool jump();

    bool active = true;
    int num;
    int queries = 0;
    const int lowerNumBound = 100;
    int jumpValue;
    int upPrime;
    int downPrime;
    int jumpBound = 3;
    int jumpCount = 0;
    bool deactivated = false;
    const int defaultValue = 2488;

};
#endif //INC_3200_P2_JUMPPRIME_H
