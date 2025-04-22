#include <iostream>
#include <vector>

class Matrix;

void multiplyMatrices(const Matrix &mat1, const Matrix &mat2);

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    void inputMatrix() {
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
                std::cin >> data[i][j];
            }
        }
    }

    void displayMatrix() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    friend void multiplyMatrices(const Matrix &mat1, const Matrix &mat2);
};

void multiplyMatrices(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.cols != mat2.rows) {
        std::cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << std::endl;
        return;
    }

    int resultRows = mat1.rows;
    int resultCols = mat2.cols;
    Matrix result(resultRows, resultCols);

    for (int i = 0; i < resultRows; ++i) {
        for (int j = 0; j < resultCols; ++j) {
            int sum = 0;
            for (int k = 0; k < mat1.cols; ++k) {
                sum += mat1.data[i][k] * mat2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    std::cout << "Resultant Matrix after multiplication:" << std::endl;
    result.displayMatrix();
}

int main() {
    int rows1, cols1, rows2, cols2;

    std::cout << "Enter the number of rows for matrix 1: ";
    std::cin >> rows1;
    std::cout << "Enter the number of columns for matrix 1: ";
    std::cin >> cols1;

    std::cout << "Enter the number of rows for matrix 2: ";
    std::cin >> rows2;
    std::cout << "Enter the number of columns for matrix 2: ";
    std::cin >> cols2;

    if (cols1 != rows2) {
        std::cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << std::endl;
        return 1;
    }

    Matrix matrix1(rows1, cols1);
    Matrix matrix2(rows2, cols2);

    std::cout << "For Matrix 1:" << std::endl;
    matrix1.inputMatrix();

    std::cout << "For Matrix 2:" << std::endl;
    matrix2.inputMatrix();

    std::cout << "Entered matrices:" << std::endl;
    matrix1.displayMatrix();
    matrix2.displayMatrix();

    multiplyMatrices(matrix1, matrix2);

    return 0;
}
