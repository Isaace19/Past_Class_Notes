
/* Program Name: Raise.java / If/Else Statements Program
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * Description: This program will ask the
 * user to rate the employee's performance so 
 * it can calculate how much raise percentage
 * that employee will get based on their rating.
 */
import java.util.Scanner;

class Raise {
    public static void main(String[] args) {
        double currentSalary; // current annual salary
        int rating; // performance rating
        double raise = 0; // dollar amount of the raise
        Scanner scan = new Scanner(System.in);

        /*
         * This section of the code will ask the user to intput a
         * a salary value for the currentSalary variable, the scanner will
         * pick this information up witht he nextInt() function
         */
        System.out.print("Enter the annual salary: $");
        currentSalary = scan.nextDouble();
        System.out.print("Enter the performance rating. 1 = Excellent, 2 = Good, 3 = Poor: ");
        rating = scan.nextInt();
        scan.close();

        if (currentSalary < 20000) {
            System.out.println("Salary is too low. Must be over $20,000.");
            return;
        }

        /*
         * For the code below, we create an if statement that checks for the correct
         * rating
         * in order to multiply the currentSalary by a certain percentage from the
         * prompt
         * if the rating does not satisfy the first boolean expression, it will
         * be passed into the else if statement with another boolean statement and so on
         */

        if (rating == 1) {
            raise = currentSalary * .08;
        } else if (rating == 2) {
            raise = currentSalary * .04;
        } else if (rating == 3) {
            raise = currentSalary * .015;
        }

        System.out.format("Amount of your Raise: $%.2f\n", raise);
        System.out.format("Your new salary $%.2f\n", currentSalary + raise);
    }

}
