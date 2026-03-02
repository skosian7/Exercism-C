 #include "rational_numbers.h"

//Helper functions
int gcd(int a, int b) {

    int numerator = a, denominator = b, temp = 0;
    while(denominator) {
        temp = numerator % denominator;
        numerator = denominator;
        denominator = temp;
    }

    return numerator;
}

int power(int number, int power) {

    if (power == 0) {
        return 1;
    }else if (power == 1) {
        return number;
    }else if (number == 0) {
        return 0;
    }

    int answer = 1;
    for (int i = 0; i < power; i++) {
        answer *= number;
    }

    return answer;
}

int root (int number, int root) {
    
    if (number == 0 || number == 1) return number;

    int answer = 0, low = 0, high = number, mid = 0, mid_power = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;
        mid_power = 1;

        for (int i = 0; i < root; i++) {
            if (mid_power > number / mid){
                mid_power = number + 1;
                break;// to avoid overflow
                }
            mid_power *= mid;
        }
        

        if (mid_power == number) {
            
            return mid;
        }else if (mid_power < number) {
            low = mid + 1;
            answer = mid;
        }else {
            high = mid - 1;
        }



    }
    return answer;

}

rational_t reduce(rational_t r) {
    rational_t reduced = r;
    int greatest = gcd(reduced.numerator, reduced.denominator);
    reduced.numerator = reduced.numerator / greatest;
    reduced.denominator = reduced.denominator / greatest;

    if (reduced.denominator < 0) {
        reduced.denominator = -reduced.denominator;
        reduced.numerator = -reduced.numerator;
    }

    return reduced;
}

rational_t add(rational_t r1, rational_t r2) {
    rational_t sum = {0,0};

    //check for denominator 0
    if (!r1.denominator || !r2.denominator) {return sum;}

    if (r1.denominator == r2.denominator) {
        sum.numerator = r1.numerator + r2.numerator;
        sum.denominator = r1.denominator;

    }else {
        sum. denominator = r1.denominator * r2.denominator;
        sum.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
    }



    return reduce(sum);
}
rational_t subtract(rational_t r1, rational_t r2) {
    rational_t difference = {0,0};

    //check for denominator 0
    if (!r1.denominator || !r2.denominator) {return difference;}

    if (r1.denominator == r2.denominator) {
        difference.numerator = r1.numerator - r2.numerator;
        difference.denominator = r1.denominator;
    }else {
        difference. denominator = r1.denominator * r2.denominator;
        difference.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
    }

    return reduce(difference);
}

rational_t multiply(rational_t r1, rational_t r2) {
    rational_t product = {0,0};
    if (!r1.denominator || !r2.denominator) {return product;}

    product.numerator = r1.numerator * r2.numerator;
    product.denominator = r1.denominator * r2.denominator;

    return reduce(product);
}

rational_t divide(rational_t r1, rational_t r2) {
    rational_t quotient = {0,0};
    if (!r1.denominator || !r2.denominator) {return quotient;}

    quotient.numerator = r1.numerator * r2.denominator;
    quotient.denominator = r1.denominator * r2.numerator;

    return reduce(quotient);
}

rational_t absolute(rational_t r) {
    rational_t absolute = {0,0};
    if (r.numerator < 0) {
        absolute.numerator = -r.numerator;
    }else {
        absolute.numerator = r.numerator;
    }
    if (r.denominator < 0) {
        absolute.denominator = -r.denominator;
    }else {
        absolute.denominator = r.denominator;
    }

    return reduce(absolute);
}

rational_t exp_rational(rational_t r, int exp) {
    rational_t answer = {0,0};
    //if (!r.numerator || !r.denominator) {return answer;}

    if (exp >= 0) {
        answer.numerator = power(r.numerator, exp);
        answer.denominator = power(r.denominator, exp);
    }else {
        answer.numerator = power(r.denominator, -exp);
        answer.denominator = power(r.numerator, -exp);
    }

    return reduce(answer);
}

 float exp_real(int number, rational_t exp) {
    int number_numerator_power = 0, number_denominator_root = 0;
    if (exp.numerator >= 0) {
        number_numerator_power = power(number, exp.numerator);
        number_denominator_root = root(number_numerator_power, exp.denominator);
        return (float)number_denominator_root;
    }else {
        number_numerator_power = power(number, -exp.numerator);
        number_denominator_root = root(number_numerator_power, exp.denominator);
        return 1.0 / number_denominator_root;
    }
 }