#include "Navheader.h"

#define exch(A, B) {Array_pontos t = A; A = B; B = t; }
#define less(A, B) (A < B)

int read_struct_Matriz(struct Matriz ** matriz_jogo, int Linha, int Coluna, int k, int l_ini ,int c_ini, int l_ini_save, int c_ini_save, int l_fin_save ,int c_fin_save, FILE*input_file)
{
    int num_pontos = 0;
    for(int i = 0;i < Linha;i++)
    {   
        for(int j = 0;j < Coluna;j++)
        {   
            if(i > l_ini_save-1 && i< l_fin_save && j > c_ini_save-1 && j < c_fin_save)
            {
                int value=0;
                if(fscanf(input_file,"%d ",&value)==1)
                {   
                    if(value>0)
                    {
                        int dist = abs(i - (l_ini - 1))+abs(j - (c_ini -1));
                        if(dist<=k)
                        {
                            num_pontos += 1;
                        }
                    }
                    matriz_jogo[i-l_ini_save][j-c_ini_save].Value = value;
                    matriz_jogo[i-l_ini_save][j-c_ini_save].visto = 0;
                }
            }
            else
            {
                if(fscanf(input_file,"%*d ")==0)
                {
                    continue;
                }
            }
        }
    }
    return num_pontos;
}   

void read_problem_sort(FILE*inputfile, FILE*outputfile)
{
    int Linha=0, Coluna = 0, Mode_Def = 0, l_ini = 0, c_ini = 0, k = 0, Energia_ini = 0;
    int *n_quero_trabalhar = (int *)malloc(sizeof(int));
    int *Max_energia = (int *)malloc(sizeof(int));
    int *k_pontos = (int *)malloc(sizeof(int));

    while(!feof(inputfile))
    {
        if(fscanf(inputfile,"%d %d %d %d %d %d %d ", &Linha, &Coluna, &Mode_Def , &l_ini , &c_ini, &k,&Energia_ini) == 7)
        {
            
            fprintf(outputfile, "%d %d %d %d %d %d %d", Linha, Coluna, Mode_Def , l_ini , c_ini, k, Energia_ini);
            
            int ver = ver_problema(Linha, Coluna, Mode_Def, l_ini, c_ini, k, Energia_ini);
            if(ver == 1)
            {

                *n_quero_trabalhar = 0;
                *Max_energia = -1;

                int l_ini_save = l_ini - k - 1;
                int c_ini_save = c_ini - k - 1;
                int l_fin_save = l_ini + k;
                int c_fin_save = c_ini + k;
                
                if(l_ini_save<0)l_ini_save=0;
                if(c_ini_save<0)c_ini_save=0;
                if(l_fin_save>=Linha)l_fin_save=Linha;
                if(c_fin_save>=Coluna)c_fin_save=Coluna;


                int l_size = l_fin_save - l_ini_save;
                int c_size = c_fin_save - c_ini_save;
                int l_coords = l_ini - l_ini_save - 1;
                int c_coords = c_ini - c_ini_save - 1;

                
                
                struct Matriz** matriz_jogo= malloc_struct_matriz(l_size,c_size);
                struct Coords* Bispo = malloc_coord_array(k);
                struct Coords* Papa = malloc_coord_array(k);
                
                for (int i = 0; i < k+1; i++) 
                {
                    Papa[i].energia = -1;  
                    Papa[i].i = -1;       
                    Papa[i].j = -1;      
                }

                int k_pontos = read_struct_Matriz(matriz_jogo, Linha, Coluna, k, l_ini, c_ini, l_ini_save, c_ini_save, l_fin_save, c_fin_save,inputfile);      
                
                struct Array_pontos* Array_pontos = (struct Array_pontos*)malloc(((k_pontos) * sizeof(struct Array_pontos))); 
                
                encontra_pontos(matriz_jogo, Array_pontos, l_size, c_size, l_coords, c_coords, k);  

                
                quicksort(Array_pontos,0,k_pontos-1);
                
                if(Mode_Def == -2 )
                {
                    dfs_T2(matriz_jogo, Array_pontos,l_coords, c_coords, l_size, c_size, k, k,Energia_ini, Mode_Def,n_quero_trabalhar, Bispo, Papa, Max_energia,k_pontos);
                    write_out_file(outputfile,k,Papa,l_ini_save,c_ini_save, Max_energia);
                }
                else if(Mode_Def > 0)
                {
                    dfs_T2(matriz_jogo, Array_pontos,l_coords, c_coords, l_size, c_size, k, k, Energia_ini, Mode_Def, n_quero_trabalhar , Bispo, Papa, Max_energia,k_pontos);
                    write_out_file(outputfile,k,Papa,l_ini_save,c_ini_save,Max_energia);
                }
            free_matriz(matriz_jogo, l_size);
            free(Papa);
            free(Bispo);
            free(Array_pontos);
            }
            else
            {
                if(ver == 2)
                {
                    fprintf(outputfile," %d",*Max_energia);
                }
                fprintf(outputfile,"\n\n");
                for(int i = 0; i < Linha; i++)
                {
                    for( int j = 0; j < Coluna; j++)
                    {
                        if(fscanf(inputfile, "%*d ")==1)continue;
                    }
                }
            }
        }
        
    }
    free(n_quero_trabalhar);
    free(Max_energia);
    free(k_pontos);
}

void dfs_T2(Matriz **Matriz_jogo, Array_pontos* Array_pontos,int l_coords, int c_coords, int Linha, int Coluna, int k, int k_ver,int Energia_ini, int Mode_Def ,int *n_quero_trabalhar, Coords *Bispo, Coords *Papa, int* Max_energy, int k_pontos)
{
    int anda = 1;
    
    
    if (*n_quero_trabalhar == 1) return;
    


    if (k_ver != k)
    {
        Energia_ini += Matriz_jogo[l_coords][c_coords].Value;
    }

    if(Energia_ini <= 0)
    {
        Matriz_jogo[l_coords][c_coords].visto = 0;
        return;
    }

    Bispo[k].energia = Matriz_jogo[l_coords][c_coords].Value;
    Bispo[k].i = l_coords;
    Bispo[k].j = c_coords;
    
    Matriz_jogo[l_coords][c_coords].visto = 1;
    
    anda = anda_n_anda(Matriz_jogo,Array_pontos,l_coords,c_coords,k,k_pontos,Max_energy,Energia_ini);

    if(anda == 0 && *Max_energy > 0)
    {
        Matriz_jogo[l_coords][c_coords].visto = 0;
        return;
    }
    


    if (k == 0)
    {
        if(Mode_Def > 0)
        {
            if(Energia_ini>=Mode_Def)
            {
                *n_quero_trabalhar = 1;
                *Max_energy = Energia_ini;
                for (int i = 0; i < k_ver+1; i++) 
                {
                    Papa[i].energia = Bispo[i].energia;  
                    Papa[i].i = Bispo[i].i;       
                    Papa[i].j = Bispo[i].j;      
                }
            }
        }
        else
        {
            if (Energia_ini > *Max_energy )
            {   
                *Max_energy = Energia_ini;
                for (int i = 0; i < k_ver+1; i++) 
                {
                    Papa[i].energia = Bispo[i].energia;  
                    Papa[i].i = Bispo[i].i;       
                    Papa[i].j = Bispo[i].j;      
                }
            }
        }


        Matriz_jogo[l_coords][c_coords].visto = 0;
        return;
    }


    if (l_coords - 1 >= 0 )
    {
        if(Matriz_jogo[l_coords-1][c_coords].visto == 0)
        dfs_T2(Matriz_jogo, Array_pontos, l_coords-1, c_coords, Linha, Coluna, k-1, k_ver, Energia_ini, Mode_Def,n_quero_trabalhar, Bispo, Papa, Max_energy,k_pontos);
    }
    if (l_coords + 1 < Linha )
    {   
        if(Matriz_jogo[l_coords+1][c_coords].visto == 0)
        dfs_T2(Matriz_jogo, Array_pontos,l_coords+1, c_coords, Linha, Coluna, k-1, k_ver,Energia_ini, Mode_Def,n_quero_trabalhar, Bispo, Papa, Max_energy,k_pontos);
    }
    if (c_coords - 1 >= 0)
    {
        if(Matriz_jogo[l_coords][c_coords-1].visto == 0)
            dfs_T2(Matriz_jogo, Array_pontos,l_coords, c_coords-1, Linha, Coluna, k-1, k_ver, Energia_ini, Mode_Def,n_quero_trabalhar, Bispo, Papa, Max_energy,k_pontos);
    }
    if (c_coords + 1 < Coluna)
    {   
        if(Matriz_jogo[l_coords][c_coords+1].visto == 0)
            dfs_T2(Matriz_jogo, Array_pontos,l_coords, c_coords+1, Linha, Coluna, k-1, k_ver ,Energia_ini, Mode_Def,n_quero_trabalhar, Bispo, Papa, Max_energy,k_pontos);
    }
    
    Matriz_jogo[l_coords][c_coords].visto = 0;

    return;
}


void write_out_file(FILE*outputfile,int k, Coords *Papa, int l_ini_save, int c_ini_save, int* Max_Energy)
{
    if(*Max_Energy == -1)
    {
        fprintf(outputfile," %d\n", *Max_Energy);
    }
    else
    {
        fprintf(outputfile," %d\n", *Max_Energy);
        for(int i = k - 1; i >= 0; i--)
        {
            fprintf(outputfile,"%d %d %d\n", (Papa[i].i+l_ini_save+1), (Papa[i].j + c_ini_save +1), Papa[i].energia);
        }
    }
    fprintf(outputfile,"\n");
}

int ver_problema(int Linha, int Coluna, int Mode_Def, int l_ini, int c_ini, int k, int Energia)
{
    if(l_ini > 0 && l_ini <= Linha && c_ini > 0 && c_ini <= Coluna)
        {
            if(Mode_Def == -2 || Mode_Def > 0)
                {
                    if(k > 0)
                    {
                        if(Energia > 0)
                        {
                            return 1;
                        }
                    }
                    if(k> Linha*Coluna)
                    {
                        return 2;
                    }
                }    
        }

    return 0;
}

void encontra_pontos(Matriz** Matriz_jogo, Array_pontos* Array_pontos, int l_size, int c_size, int l_coords, int c_coords, int k)
{
    int count = 0; 
    
    for(int i = 0; i<l_size;i++)
    {
        for (int j = 0; j < c_size; j++)
        {
            if(Matriz_jogo[i][j].Value > 0 && (abs(i - l_coords)+abs(j - c_coords)) <= k)
            {
                Array_pontos[count].Value = Matriz_jogo[i][j].Value;
                Array_pontos[count].i = i;
                Array_pontos[count].j = j;
                count ++;
            }  
        }
    }
    return;
}

int anda_n_anda(Matriz **Matriz_jogo, Array_pontos*Array_pontos, int l_coords, int c_coords, int k, int k_pontos, int * max_energy, int Energia_ini)
{   
    int anda = 0;
    int max_teorico=Energia_ini;  
    int k_vistos = 0;

    for(int i = k_pontos; i >= 0;i--)
    {

        int dist=abs(l_coords-Array_pontos[i].i)+abs(c_coords-Array_pontos[i].j);
        if(dist <= k && max_teorico < *max_energy && Matriz_jogo[Array_pontos[i].i][Array_pontos[i].j].visto == 0)
        {
            k_vistos += 1;
            max_teorico += Array_pontos[i].Value;
            if(k_vistos > k)
            {
                break;
            }
        }
        if(max_teorico >= *max_energy)
        {
            anda = 1;
            return anda;
        }
    }
    

    return anda; 
}

void quicksort(Array_pontos* arr, int l, int r)
{
int i;
if (r <= l) return;
i = partition(arr, l, r);
quicksort(arr, l, i-1);
quicksort(arr, i+1, r);
}

// Quicksort function
int partition(Array_pontos* a, int l, int r)
{
int i, j;
Array_pontos v;
v = a[r]; i = l-1; j = r;
for (;;) {
    while (less(a[++i].Value, v.Value)) ;
    while (less(v.Value, a[--j].Value))
    if (j == l) break;
    if (i >= j) break;
    exch(a[i], a[j]);
}
exch(a[i], a[r]);
return i;
}



