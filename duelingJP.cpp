//Kevin Wong-Hua
//duelingJP.cpp
//
// Created by kevin on 9/24/2020.
//

// Implementation
// Currently if an jumpPrime object is inactive it will be zeroed out
// Could implement an internal revive for the encapsulated jumpPrime objects.
//
// Addition of duelingJP + duelingJP, concatenates lhs array list with rhs array list
// Addition of duelingJP + jumpPrime, concatenates lhs array list with a jumpPrime with the same num at the end
// Can do the other way as well, a jumpPrime + duelingPrime will concatenate the jumpPrime to the front of the array
// Same will apply with adding integer and duelingJP
// Addition of duelingJP + int, concatenates lhs array list with a jumpPrime with that num at the end
// Addition of duelingJP + int[] array is not supported because can't pass array size
//
// Since addition is supported, addition assignment operator should also be :
// duelingJP += duelingJP, duelingJP += jumpPrime, duelingJP += int will be supported as we expect
// only the lhs to be changed and we concatenate to the lhs duelingJP array
// Other unary operators are not supported
//
// Can add to the jumpPrime array but can't remove any from it, subtraction not supported
// Since we can't access the encapsulated num in jumpPrime
// If we would want to support subtraction, can implement it to affect cardinality but I don't think its intuitive
//
// Can also overload -- but I think it fits better as a pop() function if needed
// Since if -- is supported, client may expect ++ to be supported, but it doesn't make sense to increment
//
// Comparison operators will compare the inversions and collisions statistics as that is the main functionality of duelingJP
// Since it compares the inversions and collisions statistics, equality operators can only be supported of comparison of duelingJP
// Mixed mode will not be supported for comparison operators


using namespace std;
#include "duelingJP.h"

duelingJP::duelingJP(int list[], int len)
{
    if(list == NULL || len == 0){
        active = false;
        inversions = -1;
        collisions = -1;
        JPList = nullptr;
    }else {
        size = len;
        givenList = new int[len];
        givenList = list;
        this->JPList = new jumpPrime *[size];
        initializeJP();
        findCollisions();
        findInversions();
    }
}

duelingJP::duelingJP(jumpPrime* list[], int len) {
    if (list == NULL || len == 0) {
        active = false;
        inversions = -1;
        collisions = -1;
        JPList = nullptr;
    } else {
        size = len;
        givenList = nullptr;
        this->JPList = new jumpPrime *[size];
        for(int i =0;i<size;i++){
            JPList[i] = list[i];
        }
        findCollisions();
        findInversions();
    }
}

void duelingJP::copy(const duelingJP &src) {
    deallocateHeaps();
    size = src.size;
    JPList = new jumpPrime *[size];
    if (src.JPList != nullptr) {
        for (int i = 0; i < size; i++) {
            JPList[i] = src.JPList[i];
        }
    } else { JPList = nullptr; }
}

//copy constructor/deep copy
duelingJP::duelingJP(const duelingJP& src) {
    copy(src);
}
//move constructor
duelingJP::duelingJP(duelingJP&& src){
    JPList = src.JPList;
    src.JPList = nullptr;

    size = src.size;
    src.size = size;
}
//destructor
duelingJP::~duelingJP(){
    deallocateHeaps();
}

duelingJP & duelingJP::operator=(const duelingJP &rhs) {
    if(this == & rhs) return *this;

    deallocateHeaps();
    copy(rhs);
    return *this;
}

// Move assignment
// transfers ownership of rhs heaps
duelingJP & duelingJP::operator=(duelingJP &&rhs) {
    if(&rhs == this)
        return *this;

    deallocateHeaps();
    JPList = rhs.JPList;
    rhs.JPList = nullptr;

    return *this;
}

void duelingJP::findCollisions() {
    for(int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if(JPList[i]->up() == JPList[j]->up()){
                // cout << "JPList[i]->up(): " << JPList[i]->up() << " JPList[j]->up(): " << JPList[j]->up() << endl;
                collisions++;
            }
        }
    }
}

void duelingJP::findInversions(){
    for(int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if(JPList[i]->up() == JPList[j]->down()){
                inversions++;
            }
        }
    }
}

int duelingJP::getCollisions(){
    return collisions;
}

int duelingJP::getInversions(){
    return inversions;
}

void duelingJP::deallocateHeaps()
{
    if(JPList != nullptr) {
        for(int i=0; i<size; i++) {
            delete JPList[i];
        }
    }
    delete [] JPList;
    delete [] givenList;
}

void duelingJP::initializeJP(){
    for(int i = 0; i<size; i++){
        JPList[i] = new jumpPrime(givenList[i]);
    }
}

duelingJP duelingJP::operator + (const duelingJP& rhs){
    jumpPrime** temp = new jumpPrime*[this->size + rhs.size];

    std::copy(this->JPList,this->JPList + this->size, temp);
    std::copy(rhs.JPList,rhs.JPList + rhs.size, temp + rhs.size);

    return duelingJP(temp,this->size + rhs.size);
}

duelingJP operator + (duelingJP& lhs, jumpPrime* rhs){
    jumpPrime** tmp = new jumpPrime*[1];
    tmp[0] =  rhs;
    return lhs + duelingJP(tmp  , 1);
}
duelingJP operator + (jumpPrime* lhs, duelingJP& rhs){
    jumpPrime** tmp = new jumpPrime*[1];
    tmp[0] =  lhs;
    return duelingJP(tmp  , 1) + rhs;
}

duelingJP operator + (duelingJP& lhs, int rhs){
    int tmp[] = {rhs};
    return lhs + duelingJP( tmp , 1);
}
duelingJP operator + (int lhs, duelingJP& rhs){
    int tmp[] = {lhs};
    return duelingJP( tmp , 1) + rhs;
}

bool operator == (const duelingJP& lhs, const duelingJP& rhs){
    return lhs.inversions == rhs.inversions && lhs.collisions == rhs.collisions;
}

bool operator != (const duelingJP& lhs, const duelingJP& rhs){
    return !(lhs.inversions == rhs.inversions && lhs.collisions == rhs.collisions);
}

bool operator >(const duelingJP& lhs, const duelingJP& rhs){
    return lhs.inversions > rhs.inversions && lhs.collisions > rhs.collisions;
}

bool operator <= (const duelingJP& lhs, const duelingJP& rhs){
    return lhs.inversions <= rhs.inversions && lhs.collisions <= rhs.collisions;
}

bool operator < (const duelingJP& lhs, const duelingJP& rhs){
    return lhs.inversions < rhs.inversions && lhs.collisions < rhs.collisions;
}

bool operator >= (const duelingJP& lhs, const duelingJP& rhs){
    return lhs.inversions >= rhs.inversions && lhs.collisions >= rhs.collisions;
}

duelingJP duelingJP::operator+=(const duelingJP& rhs){
    jumpPrime** temp = new jumpPrime*[this->size + rhs.size];

    std::copy(this->JPList,this->JPList + this->size, temp);
    std::copy(rhs.JPList,rhs.JPList + rhs.size, temp + rhs.size);

    for(int i=0;i<size;i++){
        delete JPList[i];
    }
    delete[] JPList;

    JPList = temp;
    return *this;
}
duelingJP duelingJP::operator+=(jumpPrime* rhs){

    *this = *this + rhs;
    return *this;
}

duelingJP duelingJP::operator+=(int rhs){

    *this = *this + rhs;
    return *this;
}
