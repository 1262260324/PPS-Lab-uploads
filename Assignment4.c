// take in put from user
#include <stdio.h>
int main(){
    int r,c,i,j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int m1[r][c], m2[r][c], sum[r][c];

    printf("Enter elements for Matrix M1:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter elements for Matrix M2:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &m2[i][j]);
        }
    }

    //Addition of matrices
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf("\nMatrix\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("[%d\t", sum[i][j]);
            printf("]");
        }
        printf("\n");
    }
    return 0;
}