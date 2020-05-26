int check(int sud[9][9]){
    int i, j, k, l;
    for( i = 0 ; i < 9 ; i++ ){
        for( j = 0 ; j < 9 ; j++ ){
            for( k = j ; k < 8 ; k++ ){
               if( sud[i][j] == sud[i][k+1] && sud[i][j] != 0 || sud[i][j] > 9 ){
                return 0;
               }
            }
        }
    }
    for( i = 0 ; i < 9 ; i++ ){
        for( j = 0 ; j < 9 ; j++ ){
            for( k = j ; k < 8 ; k++ ){
               if( sud[j][i] == sud[k+1][i] && sud[j][i] != 0 || sud[j][i] > 9 ){
                return 0;
               }
            }
        }
    }
    int x[9], m = 0;
    for( l = 0 ; l < 3 ; l++ ){
        for( k = 0 ; k < 3 ; k++ ){
            for( i = 0 ; i < 3 ; i++ ){
                for( j = 0 ; j < 3 ; j++ ){
                    x[m] = sud[i+k*3][j+l*3];
                    m++;
        }
    }
            for( i = 0 ; i < 9 ; i++ ){
                for( j = i ; j < 8 ; j++ ){
                    if( x[i] == x[j+1] && x[i] != 0 || sud[i][j] > 9 ){
                        return 0;
                    }
                }
            }
            m = 0;
        }
    }
    return 1;
}

    int main(){
    int i, j, k, l, pos = 0, count = 0, count2 = 0;
int sud[9][9];
for( i = 0 ; i < 9 ; i++ ){
    for( j = 0 ; j < 9 ; j++ ){
        scanf("%d",&sud[i][j]);
    }
}
if( check(sud) == 0 ){ printf("Invalid Sudoku\n"); return 0; }
for( i = 0 ; i < 9 ; i++ ){
    for( j = 0 ; j < 9 ; j++ ){
        if( sud[i][j] == 0 ){count++;}
    }
}
    int y[count][2], m = 0;
    for( i = 0 ; i < 9 ; i++ ){
        for( j = 0 ; j < 9 ; j++ ){
            if( sud[i][j] == 0 ){
             y[m][0] = i;
             y[m][1] = j;
             m++;
            }
        }
    }
    int num = 1;
    for( i = 0 ; i < count ; i++ ){
            x:
        sud[y[i][0]][y[i][1]] = num;
        if( check(sud) == 0 && num <= 9 ){
            num++;
            goto x;
        }
        if( check(sud) == 0 && num > 9 ){
            sud[y[i][0]][y[i][1]] = 0;
            i--;
            sud[y[i][0]][y[i][1]]++;
            num = sud[y[i][0]][y[i][1]];
            goto x;
        }
        num = 1;
    }

     printf("\n");
        for( i = 0 ; i < 9 ; i++ ){
        for( j = 0 ; j < 9 ; j++ ){
            printf("%d ",sud[i][j]);
        }
        printf("\n");
        }
    return 123;
}
/*
HARDEST SAMPLE:

0 0 1 0 0 0 0 0 0
3 0 7 6 0 5 1 0 9
0 5 0 0 1 0 0 8 0
0 7 0 4 0 3 0 1 0
0 0 9 0 0 0 5 0 0
0 1 0 9 0 8 0 7 0
0 4 0 0 2 0 0 6 0
1 0 8 5 0 6 3 0 7
0 0 0 0 0 0 0 0 0
*/
