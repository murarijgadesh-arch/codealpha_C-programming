#include <stdio.h>
#define MAX 10
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int C[MAX][MAX];
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nResult of Matrix Addition:\n");
    displayMatrix(C, rows, cols);
}

// Function for matrix multiplication
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2) {
    int C[MAX][MAX];
    int i, j, k;

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    displayMatrix(C, r1, c2);
}

// Function for transpose
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transpose[MAX][MAX];
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of Matrix:\n");
    displayMatrix(transpose, cols, rows);
}

int main() {
    int choice;
    int A[MAX][MAX], B[MAX][MAX];
    int rows, cols, r1, c1, r2, c2;

    do {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &rows, &cols);

                printf("\nMatrix A\n");
                inputMatrix(A, rows, cols);

                printf("\nMatrix B\n");
                inputMatrix(B, rows, cols);

                addMatrices(A, B, rows, cols);
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if(c1 != r2) {
                    printf("\nMatrix multiplication is not possible.\n");
                } else {
                    printf("\nMatrix A\n");
                    inputMatrix(A, r1, c1);

                    printf("\nMatrix B\n");
                    inputMatrix(B, r2, c2);

                    multiplyMatrices(A, B, r1, c1, c2);
                }
                break;

            case 3:
                printf("Enter rows and columns of the matrix: ");
                scanf("%d%d", &rows, &cols);

                inputMatrix(A, rows, cols);

                transposeMatrix(A, rows, cols);
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}