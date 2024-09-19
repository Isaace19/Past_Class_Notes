/*A program that asks for a numerical exam grade,
 * and prints a letter grade and a message.
 */

import java.util.Scanner;

class letterGrades {
    public static void main(String[] args) {
        int score;
        char letterGrade;

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter your test score ");
        score = scan.nextInt();

        scan.close();

        /*
         * Set letterGrade based on the score where
         * 90 and above -A, 80 and above = 80, etc
         */
        if (score >= 90) {
            letterGrade = 'A';
            System.out.println("Excellent");
        } else if (score >= 80) {
            letterGrade = 'B';
            System.out.println("Good");
        } else if (score >= 70) {
            letterGrade = 'c';
            System.out.println("Fair");
        } else if (score >= 60) {
            letterGrade = 'D';
            System.out.println("Not Good");
        } else {
            letterGrade = 'F';
            System.out.println("Failed");

        }
        System.out.println("Your letter grade is " + letterGrade);
    }
}