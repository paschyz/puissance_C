#include <stdio.h>
#include <stdlib.h>

#define x 6
#define y 7

int main() {


    char grille[x][y];

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++)

         {
            if(j==y-1){
                printf("|  |", grille[i][j]);
            }else{
                printf("|  ", grille[i][j]);
            }
           }


    printf("\n"); }
    return 0;
}
