 
#include "all_your_base.h"

/*Helper functions*/

int16_t my_power(int16_t input_base, size_t i) {
    int16_t temp_power = input_base;
    if (i == 0)
    {
        return 1;
    }else if (i == 1)
    {
        return input_base;
    }
    else {
        for (size_t k = 2; k <= i; k++) {
            temp_power *= (int16_t) input_base;
        }
    }
    return temp_power;
}

/*The function*/

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length) {
    size_t count = 0, i, j;
    j = input_length - 1;
    int16_t temp, temp_sum = 0, temp_power = input_base;
    size_t zero_count = 0;


    //check for invalid values in digits or bases
    for (i = 0; i < input_length; i++) {
        temp = digits[i];
        if (temp == 0) {zero_count++;}
        if (temp < 0 || temp >= input_base) return 0;
    }

    if (input_length == 0) {
        return 0;
    } else if (input_base <= 1 || output_base <= 1) {
        return 0;
    }else if (zero_count == input_length) {
        return 1;
    }

    //temp_sum variable is set to the value of a number in base 10

    for (i = 0; i < input_length; i++, j--)
    {
        //set the temp power
        temp_power = my_power(input_base, i);

        //set the temp_sum
        temp = digits[j];
        temp_sum += temp * temp_power;

         
    }



    //find the length in new base
    temp = temp_sum;
    while (temp != 0) {
        count++;
        temp /= output_base;
         

    }

    temp = temp_sum;
    temp_power = 0;

    for (i = 0, j = count - 1; i < count; i++, j--) {

        //set the temp_power
        temp_power = my_power(output_base, i);

        digits[j] = temp % output_base;
        temp /= output_base;
    }

 

    return count;

}