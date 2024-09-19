







/*
 * Program Name: Loops.java
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * This program takes the input from the user and uses the
 * Math.pow(Math.E, double) function to return a value
 */

import java.util.Scanner;

class Loops {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double exponent;
        double result;
        String output;

        do {
            /*
             * If the user enters a number, it will be stored as exponent
             * If the user enters quit, then the program will exit.
             * If the user something not a number, then the program will ask
             * the user to enter an exponent again.
             */
            System.out.print("Enter exponent: ");
            if (s.hasNextDouble()) {
                exponent = s.nextDouble();
            } else if (s.next().equals("quit")) {
                break;
            } else {
                System.out.println("Invalid Input");
                continue;
            }
            /* Uses the math class to take natural log e to user input exponent */
            result = Math.pow(Math.E, exponent);
            output = String.format("Result = %.4f ", result);
            System.out.println(output);
        } while (true);
        s.close();
    }
}