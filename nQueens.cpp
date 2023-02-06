/*
 * Name: Jackson Champion
 * Date Submitted:22 Nov 22
 * Lab Section: 005
 * Assignment Name: Lab 9 Recursion to solve the N-Queens problem
 */

#include <iostream>
using namespace std;

//verifies the positions a queen can move
bool isSafe(int** array,int x, int y,int n) {

    //Checks rows
    for(int i=0;i<n;i++) {
        if(array[x][i]==1){
            return false;
        }
    }

    for(int i=x,j=y;i>=0 && j >= 0;i--,j--) {
        if(array[i][j] == 1) {
            return false;
        }
    }

    for(int i=x,j=y;i<n&&j>=0;i++,j--) {
        if(array[i][j]==1) {
            return false;
        }
    }

    return true; //If all 
}

//counts number of distinct solutions
int countSolutions(int ** array,int n,int col) {
    int row;
    int count = 0;

    if(col == n) { 
        return 1;
    }

    for(int i=0;i<n;i++) {
        row=i;
        
        if(isSafe(array,row,col,n)==true) {
            array[row][col]=1;
            count += countSolutions(array,n, col+1);
            array[row][col]=0; 
        }
    }
    
    return count;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n){
    int ** queenarr = new int *[n];
    
    for(int i=0;i<n;i++) {
        queenarr[i]= new int[n];
        
        for(int j=0;j<n;j++) {
            queenarr[i][j]=0;
        }
    }

    delete *queenarr; //deallocates dynamic memory
    return countSolutions(queenarr,n,0); //Return number of solutions
}