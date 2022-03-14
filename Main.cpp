#include <iostream>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main(){
    int row = -1, col = -1;
    char char1 = ';', char2 = ';';
    cout << "Hello and welcome to our carpet market" << endl;
    cout << "plese enter the size for your dream carpet" << endl;
    cout << "lines: " << endl;
    cin >> row;
    cout << "column: " << endl;
    cin >> col;
    cout << "please enter two symbols to design the carpet" << endl;
    cout << "symbol 1:" << endl;
    cin >> char1;
    cout << "symbol 2: " << endl; 
    cin >> char2;

    try{
        string carpet = mat(col, row, char1, char2);
        cout << "your dream carpet is ready!!!!" << endl;
        cout << carpet << endl;
    }
    catch (runtime_error){
        cout << "incorrect input" << endl;
    }

    return 0;
}