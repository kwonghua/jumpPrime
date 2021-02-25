// Kevin wong-hua
// jumpPrime.cpp
// Created by kevin on 9/23/2020.
// used for p2
//
//    Implementation Invariant
// When jumpPrime 'jumps' the new number is direction is determined by the closest prime number, upPrime or downPrime
// The new number encapsulated is the difference between the current and the closest prime number plus 10
// Currently the maximum jumps allowed is 3.
// Permanently deactivated objects will act forever inactive.
//
// basic unary operators:
// Addition overloads, adds += to the encapsulated num
// since addition is supported, subtraction should be expected as well
// multiplication is similar to addition and division is similar to subtraction, and those are also supported
// supports lhs jumpPrime and int lhs unary with rhs jumpPrime and rhs int
// so int + jumpPrime, jumpPrime + int, and jumpPrime + jumpPrime order of operations supported
//
// Assignment overloading:
// jumpPrime lhs +=, -=, *=, /=, will be supported with int rhs or jumpPrime rhs
// int lhs is not supported for assignment because when assignment operator is overloaded the left operand is changed
// we can add integers to jumpPrime and integer + jumpPrime
// either way will result in a jumpPrime with its the result num encapsulated
//
// all operators overloaded will return a jumpPrime with the resulting num encapsulated
// sometimes may not expect the expected result for example something non-destructive like subtraction or division
// can return a jumpPrime with a number less than the lower bound which will result in a jumpPrime with default value
//
// output overloading is supported only used for testing in main and violates encapsulation
//
// I decided not to overload modulus because if it returns a jumpPrime it will either (1) return it one with default value
// because the output will always(?) be less than 100 which makes a jumpPrime with default values or (2) return
// a jumpPrime with lhs value. for example: 10 % 11 = 11. It doesn't make very much sense to me to support it.
// Could return a integer value but it doesn't fit the functionality of jumpPrime.


#include "jumpPrime.h"
jumpPrime::jumpPrime() {

        num  = 45;
        findUp();
        findDown();
        jumpValue = (upPrime - downPrime);
}

jumpPrime::jumpPrime(int n){
    if (n < lowerNumBound)
        num = defaultValue;
    else
        num = n;

    findUp();
    findDown();
    jumpValue = (upPrime - downPrime);
}
jumpPrime & jumpPrime::operator=(const jumpPrime &src){
    if(this != &src){
        active = src.active;
        num = src.num;
        queries = src.queries;
        jumpValue  = src.jumpValue;
        upPrime = src.upPrime;
        downPrime = src.downPrime;
        jumpCount = src.jumpCount;
        deactivated = src.deactivated;
    }
    return *this;
}
int jumpPrime::up()
{
    if (!active || deactivated)
    {
        return 0;
    }

    if (queries == jumpValue)
    {
        jump();
    }

    queries++;
    return upPrime;
}

int jumpPrime::down()
{
    if (!active || deactivated)
    {
        return 0;
    }
    if (queries == jumpValue)
    {
        jump();
    }

    queries++;
    return downPrime;
}

bool jumpPrime::revive()
{
    if (!active && !deactivated)
        active = true;

    else
    {
        deactivated = true;
        active = false;
    }

    return active;
}

bool jumpPrime::reset()
{
    if(!active || deactivated)
    {
        return false;
    }

    queries = 0;
    jumpCount = 0;

    return true;
}

bool jumpPrime::isActive()
{
    return active;
}


bool jumpPrime::isPrime(int n)
{
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 ||
            n % (i + 2) == 0)
            return false;

    return true;
}

void jumpPrime::findUp()
{
    int prime = num;
    bool found = false;

    while (!found)
    {
        prime++;

        if (isPrime(prime))
            found = true;
    }

    upPrime = prime;

}

void jumpPrime::findDown() {
    int prime = num;
    bool found = false;

    while (!found) {
        prime--;

        if (isPrime(prime))
            found = true;
    }

    downPrime = prime;
}

bool jumpPrime::jump()
{
    if (jumpCount == jumpBound)
    {
        jumpCount = 0;
        active = false;
        return false;
    }

    if((num - downPrime) < (upPrime - num))
    {
        num = (10 + (num - downPrime)) + num;

        if (num < lowerNumBound)
        {
            deactivated = true;
            active = false;
            return false;
        }
    }

    else
    {
        num = (10+ (upPrime - num)) + num;
    }

    queries = 0;
    findDown();
    findUp();
    jumpValue = (upPrime - downPrime);
    jumpCount++;

    return true;
}

jumpPrime operator+(const jumpPrime& lhs, int val){
    return jumpPrime(lhs.num + val);
}

jumpPrime operator+(const jumpPrime& lhs, const jumpPrime& rhs){
    return jumpPrime(lhs.num + rhs.num);
}

jumpPrime operator-(const jumpPrime& lhs, const jumpPrime& rhs){
    return lhs.num + (-rhs.num);
}

jumpPrime operator+(int val, const jumpPrime& rhs){
    return jumpPrime(rhs.num + val);
}

jumpPrime operator-(const jumpPrime& lhs, int val){
    return lhs + (-val);
}

jumpPrime operator-(int val, const jumpPrime& rhs){
    return rhs.num + (-val);
}

jumpPrime& jumpPrime::operator++() {
    num++;
    return *this;
}

jumpPrime jumpPrime::operator++(int) {
    jumpPrime temp = *this;
    ++*this;
    return temp;
}
jumpPrime& jumpPrime::operator--() {
    num--;
    return *this;
}
jumpPrime jumpPrime::operator--(int) {
    jumpPrime temp = *this;
    --*this;
    return temp;
}
bool operator == (const jumpPrime& lhs, const jumpPrime& rhs){
    return lhs.num == rhs.num;
}

bool operator != (const jumpPrime& lhs, const jumpPrime& rhs){
    return !(lhs == rhs);
}

bool operator > (const jumpPrime& lhs, const jumpPrime& rhs)
{
    return lhs.num > rhs.num;
}

bool operator >= (const jumpPrime& lhs, const jumpPrime& rhs)
{
    return lhs.num >= rhs.num;
}

bool operator < (const jumpPrime& lhs, const jumpPrime& rhs)
{
    return lhs.num < rhs.num;
}

bool operator <= (const jumpPrime& lhs, const jumpPrime& rhs)
{
    return lhs.num <= rhs.num;
}

bool operator == (const jumpPrime& lhs, int val){
    return lhs.num == val;
}

bool operator == (int val, const jumpPrime& rhs){
    return val == rhs.num;
}

bool operator != (const jumpPrime& lhs, int val){
    return !(lhs.num == val);
}

bool operator != (int val, const jumpPrime& rhs){
    return !(val == rhs.num);
}

bool operator > (const jumpPrime& lhs, int val){
    return lhs.num > val;
}

bool operator > (int val, const jumpPrime& rhs){
    return val > rhs.num;
}

bool operator <= (const jumpPrime& lhs, int val){
    return lhs.num <= val;
}

bool operator <= (int val, const jumpPrime& rhs){
    return val <= rhs.num;
}
bool operator < (const jumpPrime& lhs, int val){
    return lhs.num > val;
}

bool operator < (int val, const jumpPrime& rhs){
    return val > rhs.num;
}
bool operator >= (const jumpPrime& lhs, int val){
    return lhs.num <= val;
}

bool operator >= (int val, const jumpPrime& rhs){
    return val <= rhs.num;
}

jumpPrime operator * (const jumpPrime& lhs, const jumpPrime& rhs){
    return jumpPrime(lhs.num * rhs.num);
}

jumpPrime operator * (const jumpPrime& lhs, int val){
    return jumpPrime(lhs.num * val);
}

jumpPrime operator * (int val, const jumpPrime& rhs){
    return jumpPrime(rhs.num * val);
}

jumpPrime operator / (const jumpPrime& lhs, const jumpPrime& rhs){
    return jumpPrime(lhs.num / rhs.num);
}

jumpPrime operator / (const jumpPrime& lhs, int val){
    return jumpPrime(lhs.num / val);
}

jumpPrime operator / (int val, const jumpPrime& rhs){
    return jumpPrime(val / rhs.num);
}


jumpPrime& jumpPrime::operator += (int rhs){
    this->num += rhs;
    return *this;
}

jumpPrime& jumpPrime::operator -= (int rhs){
    this->num -= rhs;
    return *this;
}
jumpPrime& jumpPrime::operator *= (int rhs){
    this->num *= rhs;
    return *this;
}

jumpPrime& jumpPrime::operator /= (int rhs){
    this->num /= rhs;
    return *this;
}

jumpPrime& jumpPrime::operator += (const jumpPrime& rhs){
    this->num += rhs.num;
    return *this;
}
jumpPrime& jumpPrime::operator -= (const jumpPrime& rhs){
    this->num -= rhs.num;
    return *this;
}
jumpPrime& jumpPrime::operator *= (const jumpPrime& rhs){
    this->num *= rhs.num;
    return *this;
}
jumpPrime& jumpPrime::operator /= (const jumpPrime& rhs){
    this->num /= rhs.num;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const jumpPrime& jp){
    os << jp.num;
    return os;
}
