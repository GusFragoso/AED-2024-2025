#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matriz
{
    int Value;
    unsigned char visto; 
}Matriz;
//FUNÇÕES DO MEM.C

struct Matriz ** malloc_struct_matriz(int l_size, int c_size);
void free_matriz(struct Matriz ** matriz_jogo,int l_size);
char *Outputname(char *nome, const char *term);


//FUNÇÕES DO read_write.C
void read_problem_sort(FILE*inputfile, FILE*output_file);
void read_struct_Matriz(struct Matriz ** matriz_jogo, int Linha, int Coluna, int k, int l_ini ,int c_ini, int l_ini_save, int c_ini_save, int l_fin_save ,int c_fin_save, FILE*input_file);


//FUNÇÕES DO FUNC.C
int Tarefa1(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini);
int Tarefa2(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini);
