#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"


using namespace std;
namespace ariel{
    string mat(int col, int row, char one, char two){
        const int minChar = 33;
        const int maxChar = 126;
        string ans;
        int flag = 0;
        if (col % 2 == 0 || row % 2 == 0){
            throw runtime_error("incorrect input");
            //return "not good input";
        }
        if (col <= 0 || row <= 0){
            throw runtime_error("incorrect input");
            //return "not good input";
        }
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
        vector<vector <char>> carpet(row,vector <char> (col));

        
        for (int i=0; i<row/2; i++){
            for (int j=flag; j<col-flag; j++){
                if (i%2 == 0){
                    carpet[i][j] = one;
                    carpet[row-i-1][j] = one;
                }
                else {
                    carpet[i][j] = two;
                    carpet[row-i-1][j] = two;
                } 
            }
            for(int j=flag; j<row-flag; j++){
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
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans += carpet[i][j];
            }
            ans += '\n';
        }
        //cout<< ans<< endl;
        return ans;

        // if (col % 2 == 0) { 
        //     return "ok";
        // }    
        // return "not ok";
    }
}
