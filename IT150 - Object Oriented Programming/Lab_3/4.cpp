#include <iostream>
#include <vector>

class Matrix;

void addMatrices(const Matrix &mat1, const Matrix &mat2);

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

    friend void addMatrices(const Matrix &mat1, const Matrix &mat2);
};

void addMatrices(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        std::cout << "Matrix addition is not possible. Matrices must have the same dimensions." << std::endl;
        return;
    }

    Matrix result(mat1.rows, mat1.cols);

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat1.cols; ++j) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }

    std::cout << "Resultant Matrix after addition:" << std::endl;
    result.displayMatrix();
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows for matrices: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns for matrices: ";
    std::cin >> cols;

    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);

    std::cout << "For Matrix 1:" << std::endl;
    matrix1.inputMatrix();

    std::cout << "For Matrix 2:" << std::endl;
    matrix2.inputMatrix();

    std::cout << "Entered matrices:" << std::endl;
    matrix1.displayMatrix();
    matrix2.displayMatrix();

    addMatrices(matrix1, matrix2);

    return 0;
}
