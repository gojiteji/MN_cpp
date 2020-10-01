#include <stdio.h>

typedef struct {
 double real;
 double imaginary;
} Complex;

Complex enshu_4_2(Complex num1, Complex num2){
    double x=num1.real*num2.real-num1.imaginary*num2.imaginary;
    double y=num1.real*num2.imaginary+num2.real*num1.imaginary;
    Complex c;
    c.real=x;
    c.imaginary=y;
    return c;
}


int main() {
    
	return 0;
}
