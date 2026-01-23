#include "allergies.h"
/* Helper functions*/
int allergen_value(int indexx)
{
    int value = 2;
    int power = indexx;
    
    if(power == 0) return 1;
    if(power == 1) return 2;

    for(int i = 1; i < power; i++)
    {
        value *= 2;
    }

    return value;
}

allergen_list_t score_255_list(void)
{
    allergen_list_t a_list;
    
    a_list.count = ALLERGEN_COUNT;
    for(int i = 0; i <=7; i++)
    {
        a_list.allergens[i] = true;
    }
    return a_list;
}

allergen_list_t score_0_list(void)
{
    allergen_list_t a_list;
    a_list.count = 0;
    for(int i = 0; i <=7; i++)
    {
        a_list.allergens[i] = false;
    }
    return a_list;
}

int normalized_score(int x_score)
{
    int normal_score = x_score;
    if((normal_score - 256) < 255) return normal_score - 256;
    while((normal_score - 256) > 255)
        {
            normal_score -= 256;
        }
    return normal_score;
}

/*The functions*/

allergen_list_t get_allergens(int score)
{
    if(score == 255)
    {
        allergen_list_t a_list = score_255_list();
        return a_list;
    }
    
    allergen_list_t a_list = score_0_list();
    if(score == 0 || score == 256)
    {
        return a_list;
    }
    
    int value_of_allergen, difference, x_score;

    if(score > 256)
    {
        x_score = normalized_score(score);
    }else {
        x_score = score;
    }

    for(int i = 7; i >=0; i--)
    {
        value_of_allergen = allergen_value(i);
        difference = x_score - value_of_allergen;
        
        if(difference < 0)
        {
            a_list.allergens[i] = false;
        } else if(difference == 0)
        {
            a_list.allergens[i] = true;
            a_list.count ++;
            i = -97;
        }
        else{
            a_list.allergens[i] = true;
            a_list.count ++;
            x_score = difference;
        }
        
    }
     
    return a_list;
}

bool is_allergic_to(allergen_t allergen, int score)
{
    allergen_list_t a_list = get_allergens(score);    
    return a_list.allergens[allergen];
}

 