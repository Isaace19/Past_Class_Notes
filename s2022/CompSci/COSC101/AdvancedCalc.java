/*
 * Program Name: AdvancedCalc.java Program
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * This program takes the input from user and puts it into a switch statement
 * to deciede which operator to use. Then it will print out the output
 */

import java.util.Scanner;

class AdvancedCalc {
    public static void main(String[] args) {
        int left, right;
        int result;
        String operator;
        Scanner s = new Scanner(System.in);

        System.out.print("Enter <left> <op> <right>: ");

        if (!s.hasNextInt()) {
            System.out.println("Please enter an integer");
            s.close();
            return;
        }
        left = s.nextInt();

        if (!s.hasNext()) {
            System.out.println("Please enter a proper operator");
            s.close();
            return;
        }
        operator = s.next();
        if (!s.hasNextInt()) {
            System.out.println("Please enter an integer");
            s.close();
            return;
        }
        right = s.nextInt();

        switch (operator) {
            case "+":
                result = left + right;
                break;
            case "-":
                result = left - right;
                break;
            case "*":
                result = left * right;
                break;
            case "/":
                result = left / right;
                break;
            case "%":
                result = left % right;
                break;
            case "^":
                if (operator.equals("^")) {
                    double result1 = Math.pow(left, right);
                    String output1 = String.format("%d %s %d = %f", left, operator, right, result1);
                    System.out.println(output1);
                    System.exit(0);
                }
            default:
                System.out.println("Invalid Operator!");
                s.close();
                return;
        }
        String output = String.format("%d %s %d = %d", left, operator, right, result);
        System.out.println(output);

    }
}
