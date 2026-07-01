#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("===== BASIC CALCULATOR =====\n");

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("\nResult = %.2f\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("\nResult = %.2f\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("\nResult = %.2f\n", result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult = %.2f\n", result);
            } else {
                printf("\nError! Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("\nInvalid operator!\n");
    }

    return 0;
}