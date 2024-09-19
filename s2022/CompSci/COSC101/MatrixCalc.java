import java.util.Scanner;

import javax.naming.spi.DirStateFactory.Result;

class MatrixCalc {
    private final static int VECTOR_SIZE = 3;
    private final static int MATRIX_SIZE = VECTOR_SIZE * VECTOR_SIZE;

    public static void main(String[] args) {
        double[] matrix = new double[MATRIX_SIZE];
        double[] vector = new double[VECTOR_SIZE];
        // creates objects from the private ints

        Scanner s = new Scanner(System.in);
        System.out.format("Enter %d matrix values: ", MATRIX_SIZE);

        for (int it = 0; it < MATRIX_SIZE; it++) {
            matrix[it] = s.nextDouble();
        }

        System.out.format("Enter %d vector values: ", VECTOR_SIZE);
        for (int it = 0; it < VECTOR_SIZE; it++) {
            vector[it] = s.nextDouble();
        }
        s.close();
        // here's the method multiply where we pass our created parameters matrix and
        // vector through
        double[] result = multiply(matrix, vector);

        System.out.print("Result = [");
        printVector(result);
        System.out.println("]");
    }

    // the print vector method formats our answer to 3 decimal places in the
    // terminal

    private static void printVector(double[] arr) {
        for (int it = 0; it < arr.length - 1; it++) {
            System.out.format("%.3f%s", arr[it], " ");
        }
        System.out.format("%.3f", arr[arr.length - 1]);
    }

    // for the matrix calculator, we would create an output of 3 using the vector
    // length
    private static double[] multiply(double[] matrix, double[] vector) {
        double[] result = new double[vector.length];
        int sum = 0;
        for (int j = 0; j < vector.length; j++) {
            for (int i = 0; i < vector.length; i++) {
                result[j] += matrix[sum] * vector[i];
                sum++;
            }
            // we increment by sum every turn because we want to add the previous matrix to
            // the next matrix
        }
        return result;
    }
}