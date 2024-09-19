
/* Program Name: First Submission
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * Description: This program simply
 * takes the inputted salaries and
 * calculates the two after taxes
 * as well as budgeting them out.
 */
import java.util.Scanner;

class SalaryComparison {
    public static void main(String[] args) {
        int salaryInput1, salaryInput2;
        Scanner s = new Scanner(System.in);

        // The system.out lines will ask the user to input a salary twice for the code
        // to work.
        System.out.print("Enter the salary for the first job (no commas): $");
        salaryInput1 = s.nextInt();
        System.out.print("Enter the salary for the second job (no commas): $");
        salaryInput2 = s.nextInt();
        s.close();

        // This section of the code is where we create the job1 method from the class
        // budget using salaryInput1 or 2 as the instiator
        Budget job1 = new Budget(salaryInput1);
        Budget job2 = new Budget(salaryInput2);

        job1.calculateTHP();
        job2.calculateTHP();

        // This section of code will store values into job1 into needs, wants, and
        // savings.
        double needs, wants, savings;
        needs = job1.calculateBudgetCategory(50);
        wants = job1.calculateBudgetCategory(30);
        savings = job1.calculateBudgetCategory(20);
        System.out.format("Monthly Take Home Salary for Job 1: $%.2f\n", job1.getMonthlyTakeHomePay());
        System.out.format("By the 50/30/20 Budget, spend up to $%.2f on needs (Food, shelter, etc)\n", needs);
        System.out.format("                        spend up to $%.2f on wants (Hobbies, travel, etc)\n", wants);
        System.out.format("                        and up to   $%.2f on savings (retirement, emergency fund)\n",
                savings);

        // This section of code will call the budget class to store values of job2 into
        // needs, wants, and savings
        needs = job2.calculateBudgetCategory(50);
        wants = job2.calculateBudgetCategory(30);
        savings = job2.calculateBudgetCategory(20);
        System.out.format("Monthly Take Home Salary for Job 2: $%.2f\n", job2.getMonthlyTakeHomePay());
        System.out.format("By the 50/30/20 Budget, spend up to $%.2f on needs (Food, shelter, etc)\n", needs);
        System.out.format("                        spend up to $%.2f on wants (Hobbies, travel, etc)\n", wants);
        System.out.format("                        and up to   $%.2f on savings (retirement, emergency fund)\n",
                savings);
    }
}