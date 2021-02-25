// kevin wong-hua
// p4.cpp
// Used to test jumpPrime and duelingJP objects
// First I will test jumpPrime objects with the different operators overloaded
// it will contain testSize numbers of jumpPrime objects which will have random values
// of range lowerBound to valueLowerBound + upperBoundDiff initialized
// Using functions to run test:
// testJumpPrimeAdditionOperators() will test all addition operators
// it will call addJumpPrimeTest(), which will generate jumpPrime objects and add them together
// addIntTest will test jumpPrime + int and int + jumpPrime
// the same logic will be used for other testing functions for jumpPrime
// will use different comparison operators to verify successful operations
// this test the comparison operators as well
// subtraction and division testing will need to be aware that attempting to construct a jumpPrime
// object with a int less than the lower bound will make it's encapsulated number a default value
//
// For testing duelingJP, when attempting to do something like adding two duelingJP: duelingJP result = test + test2;
// results in a access violation reading error which I believe has to do something with one of the copy or move constructors?
// I couldn't figure out the exact solution to it.
// But for further testing, I would pretty much do the same testing i did for jumpPrime
// And overload the output operator for testing

#include <iostream>
#include "jumpPrime.h"
#include "duelingJP.h"
using namespace std;


void generateArray(int* list, int size);
void initializeJumpPrimeArray(jumpPrime ar[]);
void printMyJumpPrimeArray(jumpPrime ar[]);

void testJumpPrimeAdditionOperators(jumpPrime ar[]);
void addJumpPrimeTest(jumpPrime ar[]);
void addIntTest(jumpPrime ar[]);

void testJumpPrimeSubtraction(jumpPrime ar[]);
void subtractJumpPrimeTest(jumpPrime ar[]);
void subtractIntTest(jumpPrime ar[]);

void testJumpPrimeMultiplication(jumpPrime ar[]);
void multiplyJumpPrimeTest(jumpPrime ar[]);
void multiplyIntTest(jumpPrime ar[]);

void testJumpPrimeDivision(jumpPrime ar[]);
void divideJumpPrimeTest(jumpPrime ar[]);
void divideIntTest(jumpPrime ar[]);


int const jumpPrimeTestSize = 10;
int const lowerBound = 99;
int const upperBoundDiff = 1400;
int const jumpPrimeLowerBound = 100;

int main() {
    int newArrSize = rand() % 5+ 10;
    int* newArr = new int[newArrSize];
    int newArrSize2 = rand() % 5+ 10;
    int* newArr2 = new int[newArrSize];

    unsigned k;
    k++;


    cout << "Creating an jumpPrime array of size: " << jumpPrimeTestSize << endl;
    jumpPrime testJP1[jumpPrimeTestSize];
    initializeJumpPrimeArray(testJP1);
    printMyJumpPrimeArray(testJP1);
    cout << endl << "Testing different operators on jumpPrime" << endl << endl;
    testJumpPrimeAdditionOperators(testJP1);
    testJumpPrimeSubtraction(testJP1);
    testJumpPrimeMultiplication(testJP1);
    testJumpPrimeDivision(testJP1);












    cout << "Creating duelingJP2 object with: " << newArrSize2 << " random values." << endl;
    cout << "[";
    generateArray(newArr, newArrSize);
    cout << "]" << endl;
    cout << "[";
    generateArray(newArr2, newArrSize2);
    cout << "]" << endl;

    duelingJP test = duelingJP(newArr,newArrSize);
    duelingJP test2 = duelingJP(newArr2,newArrSize2);
    duelingJP result = test + test2;

    cout << "number of collisions 1: " << test.getCollisions() << endl;
    cout << "number of inversions 1: " << test.getInversions() << endl;

    cout << "number of collisions 2: " << test2.getCollisions() << endl;
    cout << "number of inversions 2: " << test2.getInversions() << endl;

    //unique_ptr<duelingJP> test4 = test + test2;
    //duelingJP test3 = test + test2;

 //   cout << "number of collisions 2: " << test3.getCollisions() << endl;
 //   cout << "number of inversions 2: " << test3.getInversions() << endl;
    delete[] newArr;
    delete[] newArr2;
    return 0;
}

void generateArray(int* list, int size){
    for(int i=0 ;i <size;i++ ){
        list[i] = rand() % 200 + 1500;//1500 - 1699, closer range for more collisions/inversions
        cout<< " " << list[i] << " ";
    }
}

void initializeJumpPrimeArray(jumpPrime ar[]) {
    for (int i = 0; i < jumpPrimeTestSize; i++) {
        ar[i] = rand() % upperBoundDiff + lowerBound;
    }
}

void printMyJumpPrimeArray(jumpPrime ar[]){
    cout<< "jumpPrime array: [ ";
    for (int i =0;i<jumpPrimeTestSize;i++){
       cout << ar[i] << " ";
    }
    cout << "]" << endl;
}

void testJumpPrimeAdditionOperators(jumpPrime ar[]){
    addJumpPrimeTest(ar);
    addIntTest(ar);
    cout << endl;

}

void addJumpPrimeTest(jumpPrime ar[]){
    jumpPrime result[jumpPrimeTestSize];
    jumpPrime test[jumpPrimeTestSize];
    initializeJumpPrimeArray(test);

    int count = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result[i] = ar[i] + test[i];

        if(result[i] > test[i] && result[i] > ar[i])
        {
            count++;
        }
    }
    cout << "Addition (jumpPrime+jumpPrime) passed "  << count << "/" << jumpPrimeTestSize << " tests." << endl;

}

void addIntTest(jumpPrime ar[]){
    jumpPrime result1[jumpPrimeTestSize];
    jumpPrime result2[jumpPrimeTestSize];

    int addThis1 = rand() % 100 + 1; // 1 - 100
    int addThis2 = rand() % 100 + 1;

    int count1 = 0;
    int count2 = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result1[i] = ar[i] + addThis1;
        result2[i] = addThis2 + ar[i];

        if(result1[i] == ar[i] + addThis1) {
            count1++;
        }
        if(result2[i] == addThis2 + ar[i]) {
            count2++;
        }
    }
    cout << "Addition (jumpPrime+int) passed "  << count1 << "/" << jumpPrimeTestSize << " tests." << endl;
    cout << "Addition (int+jumpPrime) passed "  << count2 << "/" << jumpPrimeTestSize << " tests." << endl;

}

void testJumpPrimeSubtraction(jumpPrime ar[]){
    subtractJumpPrimeTest(ar);
    subtractIntTest(ar);
    cout << endl;
}
void subtractJumpPrimeTest(jumpPrime ar[]){
    jumpPrime result[jumpPrimeTestSize];
    jumpPrime test[jumpPrimeTestSize];
    initializeJumpPrimeArray(test);

    int count = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result[i] = ar[i] - test[i];
        if(ar[i] - test[i] < jumpPrimeLowerBound){
            count++;
        }
        else if(result[i] < test[i] || result[i] < ar[i])
        {
            count++;
        }
    }
    cout << "Subtraction (jumpPrime-jumpPrime) passed "  << count << "/" << jumpPrimeTestSize << " tests." << endl;

}

void subtractIntTest(jumpPrime ar[]){
    jumpPrime result1[jumpPrimeTestSize];
    jumpPrime result2[jumpPrimeTestSize];

    int someNum1 = rand() % 100 + 1; // 1 - 100
    int someNum2 = rand() % 100 + 1;

    int count1 = 0;
    int count2 = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result1[i] = ar[i] - someNum1;
        result2[i] = someNum2 - ar[i];

        if(result1[i] < someNum1 || result1[i] < ar[i])
        {
            count1++;
        }
        else if(ar[i] - someNum1 < jumpPrimeLowerBound){
            count1++;
        }

        if(result2[i] < someNum1 || result2[i] < ar[i]){
            count2++;
        }
        else if(someNum2 - ar[i] < jumpPrimeLowerBound){
            count2++;
        }

    }
    cout << "Subtraction (jumpPrime-int) passed "  << count1 << "/" << jumpPrimeTestSize << " tests." << endl;
    cout << "Subtraction (int-jumpPrime) passed "  << count2 << "/" << jumpPrimeTestSize << " tests." << endl;

}

void testJumpPrimeMultiplication(jumpPrime ar[]){
    multiplyJumpPrimeTest(ar);
    multiplyIntTest(ar);
    cout << endl;
}

void multiplyJumpPrimeTest(jumpPrime ar[]) {
    jumpPrime result[jumpPrimeTestSize];
    jumpPrime test[jumpPrimeTestSize];
    initializeJumpPrimeArray(test);

    int count = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result[i] = ar[i] * test[i];
        if(result[i] >= test[i] || result[i] >= ar[i])
        {
            count++;
        }
    }
    cout << "multiplication (jumpPrime*jumpPrime) passed "  << count << "/" << jumpPrimeTestSize << " tests." << endl;

}

void multiplyIntTest(jumpPrime ar[]) {
    jumpPrime result1[jumpPrimeTestSize];
    jumpPrime result2[jumpPrimeTestSize];

    int addThis1 = rand() % 100 + 1; // 1 - 100
    int addThis2 = rand() % 100 + 1;

    int count1 = 0;
    int count2 = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result1[i] = ar[i] * addThis1;
        result2[i] = addThis2 * ar[i];

        if(result1[i] == ar[i] * addThis1) {
            count1++;
        }
        if(result2[i] == addThis2 * ar[i]) {
            count2++;
        }
    }
    cout << "Multiplication (jumpPrime*int) passed "  << count1 << "/" << jumpPrimeTestSize << " tests." << endl;
    cout << "Multiplication (int*jumpPrime) passed "  << count2 << "/" << jumpPrimeTestSize << " tests." << endl;
}
void testJumpPrimeDivision(jumpPrime ar[]){
    divideJumpPrimeTest(ar);
    divideIntTest(ar);
    cout << endl;
}
void divideJumpPrimeTest(jumpPrime ar[]){
    jumpPrime result[jumpPrimeTestSize];
    jumpPrime test[jumpPrimeTestSize];
    initializeJumpPrimeArray(test);

    int count = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result[i] = ar[i] / test[i];
        if(ar[i] / test[i] < jumpPrimeLowerBound){
            count++;
        }
        else if(result[i] < test[i] || result[i] < ar[i])
        {
            count++;
        }
    }
    cout << "Division (jumpPrime/jumpPrime) passed "  << count << "/" << jumpPrimeTestSize << " tests." << endl;

}
void divideIntTest(jumpPrime ar[]){
    jumpPrime result1[jumpPrimeTestSize];
    jumpPrime result2[jumpPrimeTestSize];

    int someNum1 = rand() % 100 + 1; // 1 - 100
    int someNum2 = rand() % 100 + 1;

    int count1 = 0;
    int count2 = 0;

    for(int i =0;i<jumpPrimeTestSize;i++){
        result1[i] = ar[i] / someNum1;
        result2[i] = someNum2 / ar[i];

        if(result1[i] < someNum1 || result1[i] < ar[i])
        {
            count1++;
        }
        else if(ar[i] / someNum1 < jumpPrimeLowerBound){
            count1++;
        }

        if(result2[i] < someNum1 || result2[i] < ar[i]){
            count2++;
        }
        else if(someNum2 / ar[i] < jumpPrimeLowerBound){
            count2++;
        }

    }
    cout << "Division (jumpPrime/int) passed "  << count1 << "/" << jumpPrimeTestSize << " tests." << endl;
    cout << "Division (int/jumpPrime) passed "  << count2 << "/" << jumpPrimeTestSize << " tests." << endl;

}

