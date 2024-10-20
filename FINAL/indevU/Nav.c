#include "Navheader.h"

int main(int argc,char *argv[])
{
    char* nome = argv[1];
    const char* term = ".solmaps";

    if(argc != 2)
    {
        return 1;
    }
    else
    {
        FILE*inputfile = fopen(nome,"r");
        const char* extension_ver = strrchr(nome, '.');
        if(extension_ver != NULL && strcmp(extension_ver,".maps") == 0 && inputfile !=NULL) 
        {
        
            char *out_file_name = Outputname(nome,term);  
            
            FILE*outputfile=fopen(out_file_name,"w");
            if(outputfile==NULL)exit(0);
            
            read_problem_sort(inputfile, outputfile);

            free(out_file_name);
            fclose(outputfile);
            fclose(inputfile);
        }
    }
    
}