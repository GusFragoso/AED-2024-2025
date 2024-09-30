#include "Navheader.h"

int main(int argc,char *argv[])
{
    int *Linha = malloc(sizeof(int*));
    *Linha = 0;
    int *Coluna = malloc(sizeof(int*));
    *Coluna = 0;
    char* nome = argv[1];
    const char* term = ".sol1maps";
    const char* extension_ver = strrchr(nome, '.');


    if(argc != 2)
    {
        free(Linha);
        free(Coluna);
        exit (0);
    }
    else if(extension_ver != NULL && strcmp(extension_ver,".1maps") == 0) 
    {
        char *out_file_name = (char *) malloc(sizeof(char) * (strlen(nome) + strlen(term) + 1)); 

        
        Read_file_once(Linha,Coluna,nome);
        
        int Coluna_matr = *Coluna;
        int Linha_matr = *Linha;
        out_file_name = Outputname(nome,term);   

        int **Matriz_jogo = mem_alloc_matriz(Linha_matr,Coluna_matr);
        
        Read_File_Problem(nome, Matriz_jogo, out_file_name);
        
        free_matriz(Matriz_jogo,Linha_matr,Coluna_matr);
        free(out_file_name);
        free(Linha);
        free(Coluna);
    }
}