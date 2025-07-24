#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
int is_valid_number(const char *str);
void print_instruction(void);

int main(int argc, char* argv[]) {
    if(argc != 4) {
        print_instruction();
        return 1;
    }

    if(!is_valid_number(argv[2]) || !is_valid_number(argv[3])) {
        printf("Error: Invalid input type.\n");
        print_instruction();
        return 1;
    }

    // convert strings to double
    double num1 = atof(argv[2]);
    double num2 = atof(argv[3]);

    // Check for operation
    if (strcmp(argv[1], "add") == 0) {
        printf("%.2f", add(num1, num2));
    } else if (strcmp(argv[1], "subtract") == 0) {
        printf("%.2f", subtract(num1, num2));
    } else if (strcmp(argv[1], "multiply") == 0) {
        printf("%.2g", multiply(num1, num2));
    } else if (strcmp(argv[1], "divide") == 0) {
        if (num2 == 0) {
            printf("Error: Divide by zero");
            return 1;
        }
        printf("%.2f", divide(num1, num2));
    } else {
        printf("Error: Invalid operation '%s'\n", argv[1]);
        print_instruction();
        return 1;
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int is_valid_number(const char* str) {
    // Check for empty
    if (str == NULL || *str == '\0') return 0;

    // Check for at least one digit
    int has_digit = 0;
    int has_decimal = 0;

    while (*str) {
        if(isdigit(*str)) {
            has_digit = 1;
        } else if (*str == '.' && !has_decimal) {
            has_decimal = 1;
        } else {
            return 0; // Invalid character
        }
        str++;
    }

    return has_digit;  // Must have at least one digit
}


void print_instruction(void) {
    printf("Usage: ./calc <operation> <num1> <num2>\n");
    printf("Operations: add, subtract, multiply, divide\n");
    printf("Example: ./calc add 5 4\n");
}