 #include "protein_translation.h"

protein_t protein(const char *const rna)
{
    const char * list_aa[][4] = {  {"AUG", NULL, NULL, NULL},
                               {"UUU", "UUC", NULL, NULL},
                               {"UUA", "UUG", NULL, NULL},
                               {"UCU", "UCC", "UCA", "UCG"},
                               {"UAU", "UAC", NULL, NULL},
                               {"UGU", "UGC", NULL, NULL},
                               {"UGG", NULL, NULL, NULL},
                               {"UAA", "UAG", "UGA", NULL}};

        
    protein_t my_protein;
    my_protein.valid = false;
    my_protein.count = 0;

    
    char temp[4] = "XXX";
    
    //empty string rna
    if(strlen(rna)==0)
    {
        my_protein.valid = true;
        return my_protein;
    }

    
    int k = 0, count = 0;
    
    while (rna[k]!='\0')
    {
        //temp is a sequence of aa
        temp[0] = rna[k];
        temp[1] = rna[k+1];        
        temp[2] = rna[k+2];
        k += 3;
        
        int found = 73;

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                 
                if(list_aa[i][j] != NULL)
                {
                    found = strcmp(temp, list_aa[i][j]);
                    if(i!=7 && found == 0)
                    {
                        my_protein.valid = true;
                        my_protein.amino_acids[count] = i;
                        count++;
                        my_protein.count = (size_t)count;
                    }else if(i==7 && found == 0)
                    {
                        my_protein.valid = true;
                        return my_protein;
                    }
                }
            }
        }
    }

//check it is not the sequence like "AUGU"
    if(strlen(rna)%3 != 0) 
    {
        protein_t myi_protein;
        myi_protein.valid = false;
        return myi_protein;
    }

    return my_protein;
}