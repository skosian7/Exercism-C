#include "beer_song.h"

int find_len(char *s)
{
    int len = 0;
    char temp = s[len];
    while(temp != '\0')
    {
        len++;
        temp = s[len];
    }
    return len;
}

void lines_zero(int line_number, char **song)
{
     //lines for 0 bottles
    char zero_0[] = "No more bottles of beer on the wall, no more bottles of beer.";
    char zero_1[] = "Go to the store and buy some more, 99 bottles of beer on the wall.";    
    int len_zero_0 = find_len(zero_0);
    int len_zero_1 = find_len(zero_1);
        
    //first line
    int i = line_number;
    for(int j = 0; j <  len_zero_0; j++) 
    {song[i][j] = zero_0[j];}
    
    i++;
        
    //second line
    for(int j = 0; j <  len_zero_1; j++) 
    {song[i][j] = zero_1[j];}
    
}
void lines_one(int line_number, char **song)
{
     //lines for 1 bottle
    char one_0[] = "1 bottle of beer on the wall, 1 bottle of beer.";
    char one_1[] = "Take it down and pass it around, no more bottles of beer on the wall.";        
    int len_one_0 = find_len(one_0);
    int len_one_1 = find_len(one_1);

    //first line
    int i = line_number;
    for(int j = 0; j <  len_one_0; j++) 
    {
        song[i][j] = one_0[j];
    }
     
    i++;

    //second line
    for(int j = 0; j <  len_one_1; j++) 
    {song[i][j] = one_1[j];}
}

void lines_many_dd(int bottles, int line_number, char **song)
{
    //case when many bottles
    char many_1[] = " bottles of beer on the wall, ";
    char many_2[] = " bottles of beer.";
    char many_3[] = "Take one down and pass it around, ";
    char many_4[] = " bottles of beer on the wall.";
    char many_5[] = "1 bottle of beer on the wall.";
    
    int len_many_1 = find_len(many_1);
    int len_many_2 = find_len(many_2);
    int len_many_3 = find_len(many_3);
    int len_many_4 = find_len(many_4);
    int len_many_5 = find_len(many_5);

    int i, j;

    //make decisions about bottles
    int bottles_first_line = bottles;
    int bottles_first_line_d = bottles_first_line < 10;

    int bottles_second_line = bottles - 1;
    int bottles_second_line_d = bottles_second_line < 10;

    char first_line, first_line_10, first_line_01;
    char second_line, second_line_01, second_line_10;
    
    /*WRITING THE FIRST LINE*/

    if(bottles_first_line_d)
    {
        first_line = bottles_first_line + 48;
        song[line_number][0] = first_line;
        j = 1;
    }else{
        first_line_01 = bottles_first_line%10 + 48;
        first_line_10 = (bottles_first_line/10)%10 + 48;
        song[line_number][0] = first_line_10;
        song[line_number][1] = first_line_01;
        j = 2;
    }

    for(i = 0; i < len_many_1; i++, j++)
    {
        song[line_number][j] = many_1[i];
    }
        
    if(bottles_first_line_d)
    {
        song[line_number][j] = first_line;
        j++;
    }else{
        song[line_number][j] = first_line_10;
        j++;
        song[line_number][j] = first_line_01;
        j++;
    }
        
    for(int i = 0; i < len_many_2; i++, j++ )
    {
        song[line_number][j] = many_2[i];
    }
    
    line_number ++;

    /*WRITING THE SECOND LINE*/
    for(int i = 0; i < len_many_3; i++)
    {
        song[line_number][i] = many_3[i];
    }
        
    j = len_many_3;

    if(bottles_first_line == 2)
    {
        for(i = 0; i < len_many_5; i++, j++)
        {
            song[line_number][j] = many_5[i];                
        }
        return;
    }else if(bottles_second_line_d)
    {
        second_line = bottles_second_line + 48;
        song[line_number][j] = second_line;
        j++; 
    }else{
        second_line_10 = (bottles_second_line/10)%10 + 48;
        song[line_number][j] = second_line_10;
        j++;
        second_line_01 = bottles_second_line%10 + 48;
        song[line_number][j] = second_line_01;
        j++;
    }    
    
    for(i = 0; i < len_many_4; i++, j++)
    {
        song[line_number][j] = many_4[i];
    }
         
}


void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{   
    int actual_bottles = start_bottles;
    int flag = take_down;
    int line_number = 0;

    while(flag > 0)
    {
        if(actual_bottles == 0)
        {
            
            lines_zero(line_number, song);

        }else if(actual_bottles == 1)
        {
             
            lines_one(line_number, song);

        }else{
            
            lines_many_dd(actual_bottles, line_number, song);
        }
        line_number += 2;
        actual_bottles --;

        if(flag > 1)
        {
            song[line_number][0] = '\0';
            line_number++;
        }
        
        flag --; 
    }

}
