#include <iostream>

class Matrix {
private:
    int mat[100][100];
    int rows;
    int cols;

public:
    // Function to input matrix values
    void input(int r, int c) {
        rows = r;
        cols = c;
        std::cout << "Enter matrix values (" << rows << "x" << cols << "):" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> mat[i][j];
            }
        }
    }

    // Function to display the matrix
    void display() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Overload == operator to check matrix dimensions
    bool operator==(const Matrix& other) const {
        return (rows == other.rows) && (cols == other.cols);
    }

    // Overload + operator for adding matrices
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        if (rows == other.rows && cols == other.cols) { // Check if matrices have equal dimensions
            result.rows = rows;
            result.cols = cols;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.mat[i][j] = mat[i][j] + other.mat[i][j];
                }
            }
        } else {
            std::cout << "Matrices must have equal dimensions for addition." << std::endl;
        }
        return result;
    }

    // Overload - operator for subtracting matrices
    Matrix operator-(const Matrix& other) const {
        Matrix result;
        if (rows == other.rows && cols == other.cols) { // Check if matrices have equal dimensions
            result.rows = rows;
            result.cols = cols;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.mat[i][j] = mat[i][j] - other.mat[i][j];
                }
            }
        } else {
            std::cout << "Matrices must have equal dimensions for subtraction." << std::endl;
        }
        return result;
    }
};

int main() {
    int rows1, cols1;
    int rows2, cols2;

    // Input size of first matrix
    std::cout << "Enter the size of first matrix (rows x cols): ";
    std::cin >> rows1 >> cols1;

    // Create first matrix
    Matrix mat1;

    // Input first matrix
    std::cout << "Enter values for first matrix:" << std::endl;
    mat1.input(rows1, cols1);

    // Input size of second matrix
    std::cout << "Enter the size of second matrix (rows x cols): ";
    std::cin >> rows2 >> cols2;

    // Create second matrix
    Matrix mat2;

    // Input second matrix
    std::cout << "Enter values for second matrix:" << std::endl;
    mat2.input(rows2, cols2);

    // Check if matrices have equal dimensions
    if (mat1 == mat2) {
        // Add matrices
        Matrix sum = mat1 + mat2;
        std::cout << "Sum of matrices:" << std::endl;
        sum.display();

        // Subtract matrices
        Matrix diff = mat1 - mat2;
        std::cout << "Difference of matrices:" << std::endl;
        diff.display();
    } else {
        std::cout << "Matrices must have equal dimensions for addition and subtraction." << std::endl;
    }

    return 0;
}
