#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matriz
{
    int Value;
    unsigned char visto; 
}Matriz;

typedef struct Coords
{
    int i;
    int j;
    int energia;

}Coords;

typedef struct Array_pontos
{
    int i;
    int j;
    int Value;
}Array_pontos;



//FUNÇÕES DO MEM.C

struct Matriz ** malloc_struct_matriz(int l_size, int c_size);
void free_matriz(struct Matriz ** matriz_jogo,int l_size);
char *Outputname(char *nome, const char *term);
struct Coords * malloc_coord_array(int k);


//FUNÇÕES DO read_write.C
void read_problem_sort(FILE*inputfile, FILE*output_file);
int read_struct_Matriz(struct Matriz ** matriz_jogo, int Linha, int Coluna, int k, int l_ini ,int c_ini, int l_ini_save, int c_ini_save, int l_fin_save ,int c_fin_save, FILE*input_file);
void dfs_T2(Matriz **Matriz_jogo, Array_pontos* Array_pontos,int l_coords, int c_coords, int Linha, int Coluna, int k, int k_ver,int Energia_ini, int Mode_Def ,int *n_quero_trabalhar,Coords *Bispo, Coords *Papa, int* Max_energy, int k_pontos);
void write_out_file(FILE*outputfile,int k, Coords *Papa, int l_ini_save, int c_ini_save, int* Max_Energy);
int ver_problema(int Linha, int Coluna, int Mode_Def, int l_ini, int c_ini, int k, int Energia);
void encontra_pontos(Matriz** Matriz_jogo, Array_pontos* Array_pontos, int l_size, int c_size, int l_coords, int c_coords, int k);
int anda_n_anda(Matriz **Matriz_jogo, Array_pontos*Array_pontos, int l_coords, int c_coords, int k, int k_pontos, int * max_energy, int Energia_ini);
int partition(Array_pontos *arr, int low, int high);
void quicksort(Array_pontos *arr, int low, int high);

