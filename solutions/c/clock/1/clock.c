 #include "clock.h"

clock_t clock_create(int hour, int minute)
{
    clock_t my_clock;
    
    int total_minutes = ((hour*60) + minute)%1440;
    if(total_minutes < 0)
    {
        total_minutes += 1440;
    }
    
    int my_minute = total_minutes%60;
    int my_hour =(total_minutes/60)%24;
    
    my_clock.text[1] = (my_hour%10) + 48;
    my_hour/=10;
    my_clock.text[0] = (my_hour%10) + 48;

    my_clock.text[2] = ':';

    my_clock.text[4] = (my_minute%10) + 48;
    my_minute/=10;
    my_clock.text[3] = (my_minute%10) + 48;

    my_clock.text[5] = '\0';
    return my_clock;

}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hours = ((clock.text[0]-48) *10) + (clock.text[1] - 48);
    int minutes = ((clock.text[3]-48) *10) + (clock.text[4] - 48);
    minutes += minute_add;
    
    clock_t my_clock = clock_create(hours, minutes);

    return my_clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int minutes = minute_subtract * -1;
    return clock_add(clock, minutes);
}

bool clock_is_equal(clock_t a, clock_t b)
{
    for(int i = 0; i < 7; i++)
    {
        if(a.text[i] != b.text[i]) return false;
    }
    return true;
}