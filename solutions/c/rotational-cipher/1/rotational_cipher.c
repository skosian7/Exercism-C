 #include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
    //what is the length of the given text?
    int i = 0;
    char temp = text[i];
    while(temp != '\0')
    {
        i++;
        temp = text[i];
    }
    int text_length = i + 1;

    //create a new "string"
    char *rotated_text = malloc(sizeof(char) * text_length);

    //make rotated text the same as given text for now
    for(i = 0; i < text_length; i++)
    {
        rotated_text[i] = text[i];
    }

    //let's rotate the text
    int shifted_temp = 0;    
    for(i = 0; i < text_length; i ++)
    {
        temp = text[i];
        shifted_temp = temp + shift_key;

        if((temp>=65 && temp<=90) && (shifted_temp <= 90))
        {
            rotated_text[i] = shifted_temp;
        }else if((temp>=65 && temp<=90) && (shifted_temp > 90))
        {
            int a = 90 - temp;
            int b = shift_key - a;
            shifted_temp = 64 + b;
            rotated_text[i] = shifted_temp;
        }else if((temp>=97 && temp<=122) && (shifted_temp <= 122))
        {
            rotated_text[i] = shifted_temp;
        }else if((temp>=97 && temp<=122) && (shifted_temp > 122))
        {
            int a = 122 - temp;
            int b = shift_key - a;
            shifted_temp = 96 + b;
            rotated_text[i] = shifted_temp;
        }

    }

    return rotated_text;
}