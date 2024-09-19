/*
 * Program Name: forloops.java
 * Student Name: Isaac Abella
 * Student ID: 000 - 641 - 840
 * NetID: iabella
 * This program will take input from the user to calculate either a running total or running product based off of how many values they input
 */

import java.util.Scanner;

class forloops {
    public static void main(String[] args) {
        String input;
        int n;
        double sum = 0;
        double product = 1;
        Scanner s = new Scanner(System.in);

        while (true) {
            System.out.print("Sum or product (type 'quit' to quit): ");
            input = s.next();
            if (input.equals("quit")) {
                break;
            } else if (!input.equals("sum") && !input.equals("product")) {
                System.out.println("Invalid operation, try again.");
                continue;
            }
            if (input.equals("sum")) {
                System.out.print("How many values? ");
                n = s.nextInt();
                /*
                 * due to encapsulation because of the while loop, we need to reference the
                 * double sum and double product that was made outside of the while loop instead
                 * of just creating another variable object
                 * by calling the sum again and setting it to 0, we can resest the running total
                 * and product for each new iteration
                 */
                sum = 0;
                for (int it = 0; it < n; it++) {
                    System.out.print("Enter value #" + it + ": ");
                    sum += s.nextDouble();
                }
                System.out.format("Sum = %.3f\n", sum);
            } else if (input.equals("product")) {
                System.out.print("How many values? ");
                n = s.nextInt();
                product = 1;
                for (int it = 0; it < n; it++) {
                    System.out.print("Enter value #" + it + ": ");
                    product *= s.nextDouble();

                }
                System.out.format("Product = %.3f\n", product);
            }

        }
        s.close();
    }
}