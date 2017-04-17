/*
 * Multiply two matrices.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include<stdio.h>
int main(){
    int a[4][3]={{1,2,3},{5,4,0},{1,2,3},{5,4,1}};
    int b[3][2]={{1,2},{5,3},{1,4}};
    int c[4][2],i,j,k,sum=0;

    for(k=0;k<2;k++){
        for(i=0;i<4;i++){
            for(j=0;j<3;j++){
                sum+=a[i][j]*b[j][k];
            }
            c[i][k]=sum;
            sum=0;
        }
    }
    printf("Multiplication-\n");
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

