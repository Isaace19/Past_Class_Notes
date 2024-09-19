/*Program name: Equation
 * Student Name; Isaac Abella
 * Student iD; 000-641-840
 * netID: iabella
 * Description: This program takes in 3 inputs from the user
 * then it will calculate those 3 numbers into a formula
 * then prints out an answer.
 */

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
        System.out.format("%s, / %s, - %s is: %.2f\n", a, b, c, result);
    }
}