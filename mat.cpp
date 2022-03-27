#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"


using namespace std;
namespace ariel{
    // this func get 4 parm and return a carpet
    string mat(int col, int row, char one, char two){
        const int minChar = 33; // const int for if santence, ilegall chars
        const int maxChar = 126;
        string ans;
        int flag = 0; 
        if (col % 2 == 0 || row % 2 == 0){ // row and col must be odd
            throw runtime_error("incorrect input");
            //return "not good input";
        }
        if (col <= 0 || row <= 0){ // row and col must be positive
            throw runtime_error("incorrect input");
            //return "not good input";
        }
        // const int for these if sentences
        if (one > maxChar || one < minChar){
            throw runtime_error("The first char is incorrect, please enter other one");
        }
        if (two > maxChar || two < minChar){
            throw runtime_error("The second char is incorrect, please enter other one");
        }
        if (col == 1){
            for (int i=0; i<row; i++){
                ans += one;
                ans += '\n';
            }
            return ans;
        }
        vector<vector <char>> carpet(row,vector <char> (col)); // the DS for the carpet 
        for (int i=0; i<row/2; i++){ // like mirror
            for (int j=flag; j<col-flag; j++){ 
                // the first fill for the carpet's up part
                // the second fill for the carpet's down part 
                if (i%2 == 0){ // to choose the right char
                    carpet[i][j] = one; 
                    carpet[row-i-1][j] = one; 
                }
                else {
                    carpet[i][j] = two;
                    carpet[row-i-1][j] = two;
                } 
            }
            for(int j=flag; j<row-flag; j++){
                // the first fill for the carpet's right part
                // the second fill for the carpet's left part                
                if(i%2 == 0){
                    carpet[j][i] = one;
                    carpet[j][col-1-i] = one;
                }
                else{
                    carpet[j][i] = two;
                    carpet[j][col-1-i] = two;
                }
            }
            flag++;
        }
        // fill the middele row with the right char
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if (carpet[i][j] != one && carpet[i][j] != two){
                    if((flag) % 2 == 0){
                        carpet[i][j] = one;
                    }
                    else {
                        carpet[i][j] = two;
                    }
                }
            }
        }
        // fill the string 
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans += carpet[i][j];
            }
            ans += '\n';
        }
        return ans;

    }
}
