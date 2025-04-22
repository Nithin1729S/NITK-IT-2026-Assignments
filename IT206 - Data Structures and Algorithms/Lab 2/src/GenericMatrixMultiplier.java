public class GenericMatrixMultiplier {

    public static <T extends Number> Double[][] multiplyMat(T[][] matrix1, T[][] matrix2) {
        int rows1 = matrix1.length;
        int rows2 = matrix2.length;
        int cols1 = matrix1[0].length;
        int cols2 = matrix2[0].length;

        Double[][] result = new Double[rows1][cols2];

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                double sum = 0.0;

                for (int k = 0; k < cols1; k++) {
                    sum += matrix1[i][k].doubleValue() * matrix2[k][j].doubleValue();
                }

                result[i][j] = sum;
            }
        }
        return result;
    }

    public static <T> void printMat(T[][] matrix) {
        for (T[] row : matrix) {
            for (T num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Integer Matrices
        Integer[][] matrix1 = {{1, 2, 3}, {4, 5, 6}, {3, 4, 5}};
        Integer[][] matrix2 = {{10, 3, 5}, {45, 6, 9}, {3, 4, 9}};
        Double[][] result1 = multiplyMat(matrix1, matrix2);
        System.out.println("Integer Result:");
        printMat(result1);

        // Double Type Matrices
        Double[][] matrixA = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {3.0, 4.0, 5.0}};
        Double[][] matrixB = {{10.0, 3.0, 5.0}, {45.0, 6.0, 9.0}, {3.0, 4.0, 9.0}};
        Double[][] result2 = multiplyMat(matrixA, matrixB);
        System.out.println("Double Result:");
        printMat(result2);
    }
}
