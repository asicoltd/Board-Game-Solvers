#include<stdio.h>
int check( int x[], int size )
{
    int i, j, k;
    for(i = 0 ; i < size ; i++)
    {
        for(j = i; j < size ; j++)
        {
            if(x[i] == x[j+1])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int i, j;
    int sudoku[9][9];
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            scanf("%d",&sudoku[i][j]);
        }
    }
    int sum = 0;
    int x[10], k ;

    for( i = 0 ; i < 9 ; i++ )
    {
        for( j = 0 ; j < 9 ; j++ )
        {
            x[j] = sudoku[i][j];
        }
        sum += check(x,9);
        if( check(x,9) == 0 ){
            printf("Wrong Row:");
            for( k = 0 ; k < 9 ; k++ ){
                printf("%d ",x[k]);
            }
            printf("\n");
        }
    }
    for( i = 0 ; i < 9 ; i++ )
    {
        for( j = 0 ; j < 9 ; j++ )
        {
            x[j] = sudoku[j][i];
        }
        sum += check(x,9);
        if( check(x,9) == 0 ){
            printf("Wrong Column:");
            for( k = 0 ; k < 9 ; k++ ){
                printf("%d ",x[k]);
            }
            printf("\n");
        }
    }

    int l, m = 0,n,p;
    for( l = 0 ; l < 3 ; l++ )
    {
        for( k = 0 ; k < 3 ; k++ )
        {
            for( j = 0 ; j < 3 ; j++)
            {
                for( i = 0; i < 3 ; i++ )
                {
                    x[m] = sudoku[i+k*3][j+l*3];
                    m++;
                }
            }
            m = 0;
            sum += check(x,9);
            if( check(x,9) == 0 ){
            printf("Wrong Box:");
            for( n = 0 ; n < 3 ; n++ ){
                for( p = 0 ; p < 3 ; p++ ){
                    printf("%d ",x[n+p]);
                }
                printf("\n");
            }

        }

        }
    }
    if( sum == 27 )
    {
        printf("Valid Sudoku\n");
    }
    else
        printf("Invalid Sudoku\n");
    return 0;
}
/*
SUDOKU SAMPLE :
1 2 3 4 5 6 7 8 9
2 3 4 5 6 7 8 9 1
3 4 5 6 7 8 9 1 2
4 5 6 7 8 9 1 2 3
5 6 7 8 9 1 2 3 4
6 7 8 9 1 2 3 4 5
7 8 9 1 2 3 4 5 6
8 9 1 2 3 4 5 6 7
9 1 2 3 4 5 6 7 8

5 1 9 6 2 3 8 4 7
6 8 4 9 1 7 5 2 3
7 2 3 5 8 4 9 6 1
3 9 6 7 4 8 1 5 2
4 7 1 2 5 6 3 9 8
8 5 2 1 3 9 6 7 4
9 6 8 3 7 2 4 1 5
2 4 5 8 6 1 7 3 9
1 3 7 4 9 5 2 8 6
*/
