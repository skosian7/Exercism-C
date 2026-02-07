 #include "nucleotide_count.h"

char *count(const char *dna_strand)
{
    char temp = 'a';
    int i = 0, An = 0, Cn = 0, Gn = 0, Tn = 0;
    
    char *invalid_input = malloc(sizeof(char)*1);
    invalid_input[0] = '\0';
    
    while(dna_strand[i] != '\0')
    {
        temp = dna_strand[i];
        switch (temp)
        {
            case 65:
            An++;
            break;
            case 67:
            Cn++;
            break;
            case 71:
            Gn++;
            break;
            case 84:
            Tn++;
            break;        
            default:            
            return invalid_input;
        }
        i++;
    }

    int len = 20;
    if((An+Cn+Gn+Tn)<=36)
    {
        len = 16;        
        char *my_count = malloc(sizeof(char)*len);
        char initial[] = "A:0 C:0 G:0 T:0";
    
        for(i = 0; i<15; i++)
        {
            my_count[i] = initial[i];
        }
        my_count[2] = An + 48;
        my_count[6] = Cn + 48;
        my_count[10] = Gn + 48;
        my_count[14] = Tn + 48;
        my_count[15]= '\0';

        return my_count;
    }

    char *my_count = malloc(sizeof(char)*len);

    my_count[0] = 'A';
    my_count[1] = ':';

    i = 2;    
    
    if(An<=9)
    {
        my_count[i] = An + 48;
        i++;
    }else{
        my_count[i+1] = (An%10) + 48;
        An /= 10;
        my_count[i] = (An%10) + 48;
        i += 2;
    }
    my_count[i] = ' ';
    i++;
    my_count[i] = 'C';
    i++;
    my_count[i] = ':';
    i++;

    if(Cn<=9)
    {
        my_count[i] = Cn + 48;
        i++;
    }else{
        my_count[i+1] = (Cn%10) + 48;
        Cn /= 10;
        my_count[i] = (Cn%10) + 48;
        i += 2;
    }
    my_count[i] = ' ';
    i++;
    my_count[i] = 'G';
    i++;
    my_count[i] = ':';
    i++;

    if(Gn<=9)
    {
        my_count[i] = Gn + 48;
        i++;
    }else{
        my_count[i+1] = (Gn%10) + 48;
        Gn /= 10;
        my_count[i] = (Gn%10) + 48;
        i += 2;
    }
    my_count[i] = ' ';
    i++;
    my_count[i] = 'T';
    i++;
    my_count[i] = ':';
    i++;
    
    if(Tn<=9)
    {
        my_count[i] = Tn + 48;
        i++;
    }else{
        my_count[i+1] = (Tn%10) + 48;
        Tn /= 10;
        my_count[i] = (Tn%10) + 48;
        i += 2;
    }
    my_count[i] = '\0';

    return my_count;
}