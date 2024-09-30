#include "Navheader.h"


void Read_file_once(int *Linha_matr, int *Coluna_matr,char *nome)
{ 
    int Linha=0, Coluna=0, k=0, l_ini = 0, c_ini = 0, c_fin = 0, l_fin = 0;
    int P_linha = 0; 
    P_linha = *Linha_matr;
    int P_coluna= 0;
    P_coluna = *Coluna_matr;
    FILE*file = fopen(nome,"r");
    if(file == NULL)
    {
        exit (0);
    }
    else{
        while(1)
        {
            if(feof(file))
            {
                break;
            }
            if(fscanf(file,"%d %d %d %d %d", &Linha, &Coluna, &l_ini, &c_ini, &k)==5)
            {
                if(Linha >  P_linha)
                {    
                    *Linha_matr = Linha;
                }
                if(Coluna > P_coluna)
                {
                    *Coluna_matr = Coluna;
                }
            }   
            if(k == 0)
            {
                if(fscanf(file,"%d %d", &l_fin, &c_fin)==2);

            }
            for(int i = 0;i < Linha; i++)
            {
                for(int j = 0; j < Coluna; j++)
                {
                    if(fscanf(file, "%*d"));
                }
            }
        }
        fclose(file);
    }

}


void Read_File_Problem(char* nome, int **Matriz, char* out_file_name)
{
    int Linha=0, Coluna=0, l_ini=0, c_ini=0, k=0 ,l_fin=0, c_fin=0;
    int pontos = 0;
    FILE*file = fopen(nome,"r");
    FILE*outfile = fopen(out_file_name,"w");
    
    
    if(file == NULL)
    {
        exit (0);
    }
    else{
        while(1)
        {
            if(feof(file))
            {
                break;
            }
            if(fscanf(file,"%d %d %d %d %d", &Linha, &Coluna, &l_ini, &c_ini, &k)==5)
            {
                fprintf(outfile,"%d %d %d %d %d ", Linha, Coluna, l_ini, c_ini, k);
                if(k == 0)
                {
                        if(fscanf(file,"%d %d",&l_fin,&c_fin)==2)fprintf(outfile,"%d %d ", l_fin, c_fin);
                }
                for(int i = 0;i < Linha; i++)
                {
                    for(int j = 0; j < Coluna; j++)
                    {
                        if(fscanf(file,"%d", &Matriz[i][j])==1);
                    }
                }
                if(k == 0)
                {
                    if( l_fin <= Linha && c_fin <= Coluna && l_fin >= 0 && l_fin >= 0 && (l_ini!=l_fin || c_ini!=c_fin))
                    {   
                        Print_Tarefa3(Matriz, l_fin, c_fin, c_ini,l_ini, outfile);
                    }
                }
                else if(k < 0)
                {
                    if( l_ini <= Linha && c_ini <= Coluna &&  l_ini >= 0 && c_ini >= 0)
                    {
                        k = abs(k);
                        pontos = Tarefa1(Matriz,Linha,Coluna,k,l_ini,c_ini);
                        Print_Tarefas(pontos, outfile);
                    }
                    fprintf(outfile,"\n");
                }
                else if(k > 0 )
                {
                    if( l_ini <= Linha && c_ini <= Coluna &&  l_ini >= 0 && c_ini >= 0)
                    {                     
                        pontos = Tarefa2(Matriz,Linha,Coluna,k,l_ini,c_ini);
                        Print_Tarefas(pontos, outfile);
                    }
                    fprintf(outfile,"\n");
                }
                fprintf(outfile,"\n");
                
            }
        }
        fclose(outfile);
        fclose(file);
    }
}

char *Outputname(char *nome, const char *term){
    char *ext;

    
    char *tmp = (char*)malloc(sizeof (char) * strlen(nome)+ 1);

    strcpy(tmp,nome);
    
    ext = strrchr(tmp , '.');

    if (ext) { *ext = '\0'; }

    size_t new_size = strlen(tmp) + strlen(term) + 1;

    char *new_name = malloc(new_size);

    sprintf(new_name, "%s%s", tmp, term);

    
    free(tmp);

    
    return new_name;

}

void Print_Tarefas(int pontos, FILE*outfile)
{
    fprintf(outfile,"%d", pontos);
}

void Print_Tarefa3(int **Matriz_jogo,int l_fin, int c_fin, int c_ini, int l_ini, FILE*outfile)
{
    int l_way = 0;
    int c_way = 0;
    if(l_ini - l_fin>0)l_way=1;
    if(c_ini - c_fin>0)c_way=1;

    fprintf(outfile,"\n");

    if(l_way == 1 && c_way == 1)
    {
        for(int i = l_ini+1; i >= l_fin ; i--)
        {
            fprintf(outfile,"%d %d %d\n",i, c_ini, Matriz_jogo[i-1][c_ini-1]);
        }
        for(int i = c_ini+1; i >= c_fin ; i--)
        {
            fprintf(outfile,"%d %d %d\n",l_fin, i, Matriz_jogo[l_fin-1][i-1]);
        }
    }
    if(l_way == 1 && c_way == 0)
    {
        for(int i = l_ini+1; i >= l_fin ; i--)
        {
            fprintf(outfile,"%d %d %d\n",i, c_ini, Matriz_jogo[i-1][c_ini-1]);
        }
        for(int i = c_ini+1; i <= c_fin ; i++)
        {
            fprintf(outfile,"%d %d %d\n",l_fin, i, Matriz_jogo[l_fin-1][i-1]);
        }
    }
    if(l_way == 0 && c_way == 1)
    {
        for(int i = l_ini+1; i <= l_fin ; i++)
        {
            fprintf(outfile,"%d %d %d\n",i, c_ini, Matriz_jogo[i-1][c_ini-1]);
        }
        for(int i = c_ini+1; i >= c_fin ; i--)
        {
            fprintf(outfile,"%d %d %d\n",l_fin, i, Matriz_jogo[l_fin-1][i-1]);
        }
    }
    if(l_way == 0 && c_way == 0)
    {
        for(int i = l_ini+1; i <= l_fin ; i++)
        {
            fprintf(outfile,"%d %d %d\n",i, c_ini, Matriz_jogo[i-1][c_ini-1]);
        }
        for(int i = c_ini+1; i <= c_fin ; i++)
        {
            fprintf(outfile,"%d %d %d\n",l_fin, i, Matriz_jogo[l_fin-1][i-1]);
        }
    }
}

