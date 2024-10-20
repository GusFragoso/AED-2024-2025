#include "Navheader.h"

struct Matriz ** malloc_struct_matriz(int l_size, int c_size)
{
    struct Matriz** matriz_jogo = (struct Matriz**)malloc(l_size * sizeof (struct Matriz*));
    
    if(matriz_jogo == NULL)
    {
        free(matriz_jogo);
        exit(0);
    }
    for(int i=0; i < l_size; i++)
    {
        matriz_jogo[i] = (struct Matriz*)malloc(c_size * sizeof(struct Matriz));
        if(matriz_jogo[i]== NULL)
        {
            free(matriz_jogo[i]);
            exit(0);
        }
        for (int ii = 0; ii < c_size; ii++)
        {
            matriz_jogo[i][ii].Value = 0;
            matriz_jogo[i][ii].visto = 0;
        }
        
    }
    for(int i=0; i > l_size; i++)
    {
        for (int ii = 0; ii < c_size; ii++)
        {
            printf("%d ",matriz_jogo[i][ii].Value);
        }
        printf("\n");
        
    }
    
    return matriz_jogo;
}


void free_matriz(struct Matriz** matriz_jogo,int l_size)
{
    for(int i = 0;i<(l_size); i++)
    {
        free(matriz_jogo[i]);
    }
    free(matriz_jogo);
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
