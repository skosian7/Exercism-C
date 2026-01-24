 #include "allergies.h"

allergen_list_t get_allergens(int score)
{    
    allergen_list_t a_list = {0};
    int x_score = score%256;

    if(x_score == 0)
    {
        return a_list;
    }

    for(int i = 7; i >=0; i--)
    {    
        if(x_score >= (1 << i) )
        {
            a_list.allergens[i] = true;
            a_list.count ++;
            x_score -= 1 << i;            
        }      
    }
     
    return a_list;
}

bool is_allergic_to(allergen_t allergen, int score)
{
    allergen_list_t a_list = get_allergens(score);    
    return a_list.allergens[allergen];
}

 