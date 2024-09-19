
/*
 * Program Name: ExactChange.java Program
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * Description: This program will take in a user input
 * that asks for change between 1 - 99 cents then
 * it will then scan and give you the least amount
 * of change possible
 */
import java.util.Scanner;

class ExactChange {
    public static void main(String[] args) {
        // creating scanner object to take in user input
        Scanner s = new Scanner(System.in);
        int change;

        // instantiating the change values to break down given input
        boolean check = false;
        int quarter = 25;
        int dime = 10;
        int nickel = 05;
        int penny = 01;

        System.out.println("How much change do you have between 1 - 99 cents: ");

        /*
         * if else chain statement here to check if the user input is correctly inputed
         * if the first check comes to false, then the code will exit with a fail, if
         * not,
         * then the code will pass as true and check the boolean value that was
         * instantiated at the
         * beginning of the code and run the next if statement to break change down only
         * when that
         * value was checked as true.
         */

        change = s.nextInt();
        if (change < 1 || change > 99) {
            System.out.println("Not a valid value, ending code ");
            check = false;
            System.exit(1);
        } else if (change >= 1 || change <= 99) {
            System.out.println("You want " + change + " in exact change");
            check = true;
        }

        /*
         * The %= operator essentially a combination of the arithmetic modulus operator
         * and the logical eqwual operator
         * This combination will assign the results of two operands and assigns that
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
            quarter = change / 25;
            change %= 25;
            if (quarter >= 0) {
                System.out.println("You have: " + quarter + " quarters");
            } else {
                System.out.println("You have: " + quarter + " quarters");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            dime = change / 10;
            change %= 10;
            if (dime >= 0) {
                System.out.println("You have: " + dime + " dimes");
            } else {
                System.out.println("You have " + dime + " dimes");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            nickel = change / 5;
            change %= 5;
            if (nickel >= 0) {
                System.out.println("You have: " + nickel + " nickels");
            } else {
                System.out.println("You have " + nickel + " nickels");
                System.out.println("That's all your change!");
                System.exit(0);
            }
            penny = change / 1;
            change %= 1;
            if (penny >= 0) {
                System.out.println("You have: " + penny + " pennies");
            } else {
                System.out.println("You have " + penny + " pennies");
                System.out.println("That's all your change!");
                System.exit(0);
            }
        }

    }
}