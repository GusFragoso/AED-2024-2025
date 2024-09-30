#include "Navheader.h"

int** mem_alloc_matriz(int x, int y)
{
    int **Matriz = (int**)malloc(x * sizeof(int *));
    if(Matriz == NULL)
    {
        free(Matriz);
        exit (0);
    }
    for(int i = 0; i<x; i++)
    {
        Matriz[i] = (int*)malloc(y * sizeof(int));
        if(Matriz[i] == NULL)
        {
            free(Matriz[i]);        
            exit (0);
        }
    }        
    return Matriz;     
}


void free_matriz(int **Matriz, int x,int y)
{
    for(int i = 0;i<x; i++)
    {
        free(Matriz[i]);
    }
    free(Matriz);
}