#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNÇÕES DO MEM.C
int** mem_alloc_matriz(int x, int y);
void free_matriz(int **Matriz, int y,int x);


//FUNÇÕES DO read_write.C
void Read_file_once(int* Linha_matr, int* Coluna_matr,char *nome);
void Read_File_Problem(char* nome, int **Matriz, char* out_file_name);
char *Outputname(char *nome, const char *term);
void Print_Tarefas(int pontos, FILE*outfile);
void Print_Tarefa3(int **Matriz_jogo,int l_fin, int c_fin, int c_ini, int l_ini, FILE*outfile);

//FUNÇÕES DO FUNC.C
int Tarefa1(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini);
int Tarefa2(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini);