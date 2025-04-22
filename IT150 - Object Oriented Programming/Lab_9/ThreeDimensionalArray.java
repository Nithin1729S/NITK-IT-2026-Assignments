public class ThreeDimensionalArray {
    public static void main(String[] args) {
        int[][][] cube = new int[4][5][6];

        // Initialize elements
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 6; k++) {
                    cube[i][j][k] = i * 100 + j * 10 + k;
                }
            }
        }

        // Access and print elements
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 6; k++) {
                    System.out.println("cube[" + i + "][" + j + "][" + k + "] = " + cube[i][j][k]);
                }
            }
        }
    }
}
