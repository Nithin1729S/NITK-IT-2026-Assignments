public class ArraySumAverage {
    public static void main(String[] args) {
        int[] arr = {2, 4, 6, 8, 10};
        int sum = 0;
        double average;

        for (int num : arr) {
            sum += num;
        }

        average = (double) sum / arr.length;

        System.out.println("Sum of array elements: " + sum);
        System.out.println("Average of array elements: " + average);
    }
}
