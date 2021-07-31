//
//  ChessSquareColor.c
//  GeekBrainsCProject
//
//  Created by Denis Mordvinov on 30.07.2021.
//

#include "ChessSquareColor.h"



void checkSquaresSameColor(char point1[], char point2[]) {
    
    int point1Result, point2Result;
    point1Result = checkPointColor(point1);
    point2Result = checkPointColor(point2);
    if (point1Result == point2Result) {
        puts("Square colors are the same");
    }else {
        puts("Square colors are different");
    }
}

int checkPointColor(char point[]){
    // Return 0  - black square
    // Return 1  - white square
    if (point[0] == 'a' || point[0] == 'c' || point[0] == 'e' || point[0] == 'g') {
        if (point[1] == '1' || point[1] == '3' || point[1] == 5 || point[1] == 7){
            return 0;
        }else{
            return 1;
        }
        
    }else{
        if (point[1] == '1' || point[1] == '3' || point[1] == 5 || point[1] == 7){
            return 1;
        }else {
            return 0;
        }
    }
}

