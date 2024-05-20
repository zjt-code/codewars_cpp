
#include<stdio.h>
#include<stdlib.h>

// szls: size of ls
int chooseBestSum(int t, int k, int ls[], int szls) {
    // your code
    if(szls <2 ) return -1;

    int **p_group = (int **)malloc((szls-1) * k* sizeof(int *));

    //malloc memory

    // for( int z =0; z<((szls-1)*k); z++)
    // {
    //     p_group[z] = (int *)malloc(sizeof(int)*k);
    // }
    // for(int x =0; x < (szls-k); x++)
    // {
    //         for(int y =x+1; y< k; y++)

    // }

    //free memory

    for(int x =0; x<((szls-1)*k); x++)
    free(p_group[x]);
    free(p_group);


}



int main()
{




    return 0;
}