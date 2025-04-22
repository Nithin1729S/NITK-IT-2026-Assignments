#include <stdio.h>


struct Complex {
    float real;
    float imag;
};


struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    
    struct Complex complex1, complex2, result;

    
    printf("Enter real part of the first complex number: ");
    scanf("%f", &complex1.real);

    printf("Enter imaginary part of the first complex number: ");
    scanf("%f", &complex1.imag);

    
    printf("Enter real part of the second complex number: ");
    scanf("%f", &complex2.real);

    printf("Enter imaginary part of the second complex number: ");
    scanf("%f", &complex2.imag);

    
    result = addComplex(complex1, complex2);

    
    printf("\nSum of the two complex numbers: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
