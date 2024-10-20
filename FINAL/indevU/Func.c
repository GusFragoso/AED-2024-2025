#include "Navheader.h"

int Tarefa1(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini)
{   
    int l_ini_procura = l_ini - k -1;
    int c_ini_procura = c_ini - k -1;
    int c_fin_procura = c_ini + k -1;
    int l_fin_procura = l_ini + k -1;
    int cel_maior = 0;
    
    if(l_ini_procura<0)l_ini_procura=0;
    if(c_ini_procura<0)c_ini_procura=0;
    if(l_fin_procura>=L)l_fin_procura=L-1;
    if(c_fin_procura>=C)c_fin_procura=C-1;
 


    for(int i = l_ini_procura;i<=l_fin_procura;i++)
    {   
        for(int j = c_ini_procura;j<=c_fin_procura;j++)
        {
            int dist = abs(i - (l_ini-1)) + abs(j - (c_ini-1));
            if(Matriz_jogo[i][j] > cel_maior && dist <= k && dist > 0)
            {
                cel_maior = Matriz_jogo[i][j];
            }
        }   
    }
   
    return cel_maior;
}

int Tarefa2(int **Matriz_jogo, int L, int C, int k, int l_ini, int c_ini)
{
    int l_ini_procura = l_ini - k -1;
    int c_ini_procura = c_ini - k -1;
    int c_fin_procura = c_ini + k -1;
    int l_fin_procura = l_ini + k -1;
    int pontos = 0;
    
    if(l_ini_procura<0)l_ini_procura=0;
    if(c_ini_procura<0)c_ini_procura=0;
    if(l_fin_procura>=L)l_fin_procura=L-1;
    if(c_fin_procura>=C)c_fin_procura=C-1;



    for(int i = l_ini_procura;i<=l_fin_procura;i++)
    {   
        for(int j = c_ini_procura;j<=c_fin_procura;j++)
        {
            int dist = abs(i - (l_ini-1)) + abs(j - (c_ini-1));
            if(Matriz_jogo[i][j] > 0 && dist <= k && dist > 0)
            {
                pontos += Matriz_jogo[i][j];
            }
        }   
    }
   
    return pontos;
}
