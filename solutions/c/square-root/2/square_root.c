 #include "square_root.h"

int square_root(int a)
{
    int sq_root = 0;
    int bit = 1 << 30;

    while(bit > a)
    {
        bit >>= 2;
    }

    while(bit != 0)
    {
        int temp = sq_root + bit;
        if(a >= temp)
        {
            a -= temp;
            sq_root = (sq_root >> 1) + bit;
        }else{
            sq_root >>= 1;
        }
        bit >>= 2;
    }

    return sq_root;

}