#include <stdio.h>

typedef struct {
 double real;
 double imaginary;
} Complex;

Complex enshu_4_1(Complex num1, Complex num2){
    double x=num1.real+num2.real;
    double y=num1.imaginary+num2.imaginary;
    Complex c;
    c.real=x;
    c.imaginary=y;
    return c;
}


int main() {
    
	return 0;
}
