 #include "sum_of_multiples.h"

//compare function for qsort()
int compare(const void* a, const void* b) {
    // Casting pointers to int and subtract to get the result
    return (*(int*)b - *(int*)a);
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int summ = 0;
    unsigned int temp = 0, temp_f = 0, temp_m = 0;
    int i, j;
    int number_of_f = (int) number_of_factors;
     
    
    //empty factors array
    if(number_of_factors == 0) return summ;
    
    //factors are 0s
    for(i=0; i<number_of_f; i++)
    {
        temp+=factors[i];
    }
    if(temp==0) return summ;
    
    //find the smallest value in factors that is not 0
    unsigned int my_factors[number_of_f];
    for(i = 0; i < number_of_f; i++)
    {
        my_factors[i] = factors[i];
    }
    qsort(my_factors, number_of_f, sizeof(unsigned int), compare);
    unsigned int smallest_f;
    if(my_factors[number_of_f-1] == 0)
    {
        smallest_f = my_factors[number_of_f-2];
    }else{
        smallest_f = my_factors[number_of_f-1];
    }
    int number_of_m = limit/smallest_f;
    

    //create a 2D array with malloc()
    unsigned int **mult = malloc(sizeof(unsigned int*) * number_of_f);
    for(i=0; i<number_of_f; i++)
    {
        mult[i] = malloc(sizeof(unsigned int) * number_of_m);
    }

    //set all values to 0s
     for(i=0; i<number_of_f; i++)
    {
        for(j=0; j<number_of_m; j++)
        {
            mult[i][j] = 0;
        }
    }
     

    //if factor is not 0 create an array of multiples, that are less than the limit
    for(i=0; i<number_of_f; i++)
    {
        temp_f = factors[i];
        if(temp_f != 0)
        {
            for(j = 0; j < number_of_m; j++)
            {
                temp_m = temp_f *(j + 1);
                if(temp_m < limit) mult[i][j] = temp_m;
            }
        }
    }
    

    //combine arrays and remove duplicates
    
    int len = number_of_f * number_of_m;
    unsigned int* mult_combined = malloc(sizeof(unsigned int)*len);
    int k = 0;
    for(i=0; i<number_of_f; i++)
    {
        for(j=0; j<number_of_m; j++)
        {
            temp_m = mult[i][j];
            if(temp_m != 0)
            {
                mult_combined[k] = temp_m;
                k++;
            }
        }
    }

    qsort(mult_combined, k, sizeof(unsigned int), compare);
    for(i=0; i<k; i++)
    {
        if(i == 0 || (mult_combined[i] != mult_combined[i-1]))
        {
            summ += mult_combined[i];
        }
    }
 
    
    for(i=0; i<number_of_f; i++)
    {
        free(mult[i]);
    }
    free(mult);
    free(mult_combined);

    return summ;
    
}