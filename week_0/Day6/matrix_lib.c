#include <stdio.h>
#include <stdlib.h>

// Matrix structure
typedef struct {
    int rows, cols;
    double **data;
} Matrix;

/*
m.data (double**)
    ↓
[ptr to row 0][ptr to row 1][ptr to row 2]  ← Array of double* pointers
    ↓             ↓             ↓
[1.0][2.0][3.0] [4.0][5.0][6.0] [7.0][8.0][9.0]  ← Arrays of actual doubles*/


// Create matrix with dynamic allocation 
Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double **)malloc(rows * sizeof(double *));  // allocating for (double *) pointer is important
    for (int i = 0; i < rows; i++) {
        m.data[i] = (double *)malloc(cols * sizeof(double)); // since 
    }
    return m; 
}

// Free matrix 
void free_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

// Matrix addition 
Matrix matrix_add(Matrix a, Matrix b) {
    if (a.rows !=  b.rows && a.cols != b.cols) {
        printf("Error: Matrices must have equal dimension for addition\n");
        exit(1);
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication 
Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a.cols !=  b.rows) {
        printf("Error: Matrix A cols must be equal to Matrix B rows.\n");
        exit(1);
    }
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// print matrix
void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.1f ", m.data[i][j]);
        }
        printf("\n");
    } 
}

int main() {
    // Example 3x3 matrix 
    Matrix a = create_matrix(3, 3);
    Matrix b = create_matrix(3, 3);
    
    double values_a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double values_b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            a.data[i][j] = values_a[i][j];
            b.data[i][j] = values_b[i][j];
        }
    }

    // Addition 
    printf("Matrix A:\n");
    print_matrix(a);
    printf("Matrix B:\n");
    print_matrix(b);
    printf("\nMatrix A + B\n");
    Matrix sum = matrix_add(a, b);
    print_matrix(sum);

    // Multiplication 
    printf("\nA * B\n");
    Matrix product = matrix_multiply(a, b);
    print_matrix(product);

    // Free memory
    free_matrix(b);
    free_matrix(a);
    free_matrix(sum);
    free_matrix(product);

    return 0;
    
}