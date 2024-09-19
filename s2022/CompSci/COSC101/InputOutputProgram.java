
/* Put your header here! Refer to the First Submission header. */
/* In this program, we will put comments in your code too. */
import java.util.Scanner;

class Equation {
    public static void main(String[] args) {
        double a;
        double b;
        double c;

        /*
         * This Section of code is the initialization of the Scanner as well as
         * the function in order for scanner to get the user input required for
         * a, b, and c
         */

        Scanner s = new Scanner(System.in);
        System.out.print("Enter three doubles (a / b - c): ");
        a = s.nextDouble();
        b = s.nextDouble();
        c = s.nextDouble();
        // This section contains all three of the scanner commands to pull 3 inputs
        s.close();

        /*
         * The code output below is the calculation of the doubles that we
         * asked from the userinput. These values are taken from the scanner
         */

        double result = a / b - c;
        System.out.format("The result of your input is ", result);
    }
}