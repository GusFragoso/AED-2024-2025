#include "Navheader.h"

void read_struct_Matriz(struct Matriz ** matriz_jogo, int Linha, int Coluna, int k, int l_ini ,int c_ini, int l_ini_save, int c_ini_save, int l_fin_save ,int c_fin_save, FILE*input_file)
{
    for(int i = 0;i < Linha;i++)
    {   
        for(int j = 0;j < Coluna;j++)
        {   
            if(i >= l_ini_save-1 && i<= l_fin_save-1 && j >= c_ini_save-1 && j <= c_fin_save-1)
            {
                int value=0;
                if(fscanf(input_file,"%d",&value)==1)
                {
                    matriz_jogo[i-l_ini_save][j-c_ini_save].Value = value;
                    printf("%d",matriz_jogo[i-l_ini_save][j-c_ini_save].Value);
                    matriz_jogo[i][j].visto = 0;
                }
            }
            else
            {
                if(fscanf(input_file,"%*d")==0);
            }
        }
    }
  
}   

void read_problem_sort(FILE*inputfile, FILE*outputfile)
{
    int Linha=0, Coluna = 0, Mode_Def = 0, l_ini = 0, c_ini = 0, k = 0, Energia_ini = 0;


    while(!feof(inputfile))
    {
        if(fscanf(inputfile,"%d %d %d %d %d %d %d", &Linha, &Coluna, &Mode_Def , &l_ini , &c_ini, &k,&Energia_ini) == 7)
        {
            int l_ini_save = l_ini - k;
            int c_ini_save = c_ini - k;
            int l_fin_save = l_ini + k;
            int c_fin_save = c_ini + k;
            
            if(l_ini_save<0)l_ini_save=0;
            if(c_ini_save<0)c_ini_save=0;
            if(l_fin_save>=Linha)l_fin_save=Linha;
            if(c_fin_save>=Coluna)c_fin_save=Coluna;

            int l_size = l_fin_save - l_ini_save;
            int c_size = c_fin_save - c_ini_save;
            printf("%d %d\n",l_size,c_size);
            


            fprintf(outputfile, "%d %d %d %d %d %d %d\n", Linha, Coluna, Mode_Def , l_ini , c_ini, k, Energia_ini);
            struct Matriz** matriz_jogo= malloc_struct_matriz(l_size,c_size);
            read_struct_Matriz(matriz_jogo, Linha, Coluna, k, l_ini, c_ini, l_ini_save, c_ini_save, l_fin_save, c_fin_save,inputfile);
            

            if(Mode_Def == -2)
            {
                fprintf(outputfile,"OMG TAREFA 2\n");
                for(int i = 0; i < l_size; i++)
                {
                    for(int j = 0; j < c_size; j++)
                    {
                        fprintf(outputfile,"%d ",matriz_jogo[i][j].Value);
                    }
                    fprintf(outputfile,"\n");
                }

            }
            else if(Mode_Def > 0)
            {
                for(int i = 0; i < l_size; i++)
                {
                    for(int j = 0; j < c_size; j++)
                    {
                        fprintf(outputfile,"%d ",matriz_jogo[i][j].Value);
                    }
                    fprintf(outputfile,"\n");
                }
                for(int i = 0; i < l_size; i++)
                {
                    for(int j = 0; j < c_size; j++)
                    {
                        fprintf(outputfile,"%d",matriz_jogo[i][j].visto);
                    }
                    fprintf(outputfile,"\n");
                }
            }
            free_matriz(matriz_jogo, l_size);
        }
        
    }
}

