 #include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
   complex_t answer = {0};
   answer.real = a.real + b.real;
   answer.imag = a.imag + b.imag;

   return answer;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t answer = {0};
   answer.real = a.real - b.real;
   answer.imag = a.imag - b.imag;
    return answer;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t answer = {0};
   answer.real = (a.real*b.real)-(a.imag*b.imag);
   answer.imag = (a.real*b.imag) + (b.real*a.imag);

   return answer;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t answer = {0};
   double denominator = (b.real*b.real) + (b.imag*b.imag);
   if(denominator==0) return answer;

   answer.real = ((a.real*b.real) + (a.imag*b.imag))/denominator;
   answer.imag = ((a.imag*b.real)-(b.imag*a.real))/denominator;

   return answer;
}

double c_abs(complex_t x)
{
   return sqrt ((x.real*x.real) + (x.imag*x.imag));
}

complex_t c_conjugate(complex_t x)
{
   complex_t answer;
    answer.real = x.real;
    answer.imag = -1 * x.imag;

    return answer;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t answer = {0};
    double expon_a = exp(x.real);
    answer.real = expon_a * cos(x.imag);
    answer.imag = expon_a * sin(x.imag);

    return answer;
}
