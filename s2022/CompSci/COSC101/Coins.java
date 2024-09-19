
/*
 * Program Name: Coins.java Program
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * Description: This program will take in a user input
 * that asks for change between 1 - 99 cents then
 * it will then scan and give you the least amount
 * of change possible
 */

import java.util.Scanner;

class Coins {
    public static void main(String[] args) {
        // creating scanner object to take in user input
        Scanner s = new Scanner(System.in);

        // instantiating the change values to break down given input
        boolean check = false;
        int change;
        System.out.println("How much change do you have between 1 - 99 cents: ");

        if (!s.hasNextInt()) {
            System.out.println("Must enter a whole number. Program exiting... ");
            s.close();
            return;
        }
        change = s.nextInt();
        if (change < 1 || change > 99) {
            System.out.println("Must enter a number between 0 and 99. Program exiting... ");
            check = false;
            System.exit(1);
        } else if (change >= 0 || change <= 99) {
            System.out.println("you want " + change + " in exact change");
            check = true;
        }
        s.close();
        /*
         * The %= operator essentially a combination of the arithmetic modulus operator
         * and the logical eqwual operator
         * This combination will assign the results of two operands and assigns that d
         * result to the left hand side.
         * Example: C %= A is the equivalent of C = C % A
         */

        /*
         * How the code actually works:
         * Essentially this code will take the change value from the user input (granted
         * that the check value is able to start the actual if statement chain)
         * Then it will divide the change by the created integer values for Quarters,
         * Dimes, Nickels, and pennies then store the whole value from that number into
         * the results
         * that will get printed out int he first if statement if there was a whole
         * number avaialble to be printed out (because we can't give .75 of a quarter to
         * someone!)
         * there is also a module equals operator that take the remainder of what
         * couldn't be divided in whole numbers and passes that value on.
         * The value would be like 99 / 25 = 3 quarters with a remainer of 24 cents.
         * The 24 cents would be stored by the change %= 25; then the program would keep
         * going until that new stored value runs out
         * and you can't give anymore change back.
         */

        if (check = true) {
            final int qValue = change / 25;
            change %= 25;
            if (qValue >= 0) {
                System.out.println("You have: " + qValue + " quarters");
            } else {
                System.out.println("You have: " + qValue + " quarters");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            final int dValue = change / 10;
            change %= 10;
            if (dValue >= 0) {
                System.out.println("You have: " + dValue + " dimes");
            } else {
                System.out.println("You have " + dValue + " dimes");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            final int nValue = change / 5;
            change %= 5;
            if (nValue >= 0) {
                System.out.println("You have: " + nValue + " nickels");
            } else {
                System.out.println("You have " + nValue + " nickels");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            final int pValue = change / 1;
            change %= 1;
            if (pValue >= 0) {
                System.out.println("You have: " + pValue + " pennies");
            } else {
                System.out.println("You have " + pValue + " pennies");
                System.out.println("That's all your change!");
                System.exit(0);
            }
        }

    }
}