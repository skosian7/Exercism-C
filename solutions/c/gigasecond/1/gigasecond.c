  #include "gigasecond.h"


void magic_time(char * c, int value, int indexx)
{
    c[indexx] = value%10 + '0';
    value /= 10;
    c[indexx - 1] = value%10 + '0';
}

void gigasecond(time_t input, char *output, size_t size)
{
    //I need to add 10^9 seconds to input
    time_t g_input = input + 1000000000;

    //I need to convert time_t to struct tm
    struct tm *g_time = gmtime(&g_input);

    //I need to use information from struct tm *g_time to write into a string
    char giga_time[size];

    //Year
    int giga_year = g_time->tm_year + 1900;
    for(int i = 3; i >= 0; i--)
    {
        char temp = giga_year%10 + '0';
        giga_time[i] = temp;
        giga_year /= 10;
    }
    giga_time[4] = '-';

    //Month
    int giga_month = g_time->tm_mon + 1;
    magic_time(giga_time, giga_month, 6);
    giga_time[7] = '-';
    
    //Day
    int giga_day = g_time->tm_mday;
    magic_time(giga_time, giga_day, 9);
    giga_time[10] = 32;

    //Hour
    int giga_hour = g_time->tm_hour;
    magic_time(giga_time,giga_hour, 12);
    giga_time[13] = ':';

    //Min
    int giga_min = g_time->tm_min;
    magic_time(giga_time, giga_min, 15);
    giga_time[16] = ':';

    //Sec
    int giga_sec = g_time->tm_sec;
    magic_time(giga_time, giga_sec, 18);

    for(int i = 0; i < 19; i++)
    {
        output[i] = giga_time[i];
    }

}