
/* A do while loops is used mainly when we want to repeat code an indefinite number of times
* example: while(condition is true){execute the code until that conditions become false}
*/
import java.util.Scanner;

class MiniGolf {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numoOfPlayers = 2;
        int numOfHoles = 3;
        int counter = 0;
        int score;
        int totalScore1 = 0;
        int totalScore2 = 0;

        System.out.println("Welcome to mini-golf scoring!");
        // System.out.println(""); //ask for number of holes in the future

        while (counter < numOfHoles) {
            System.out.print("Player 1, what is your score for the hole? " + (counter + 1) + "? ");
            // save that score and add it to the running total for P1
            score = scan.nextInt();
            totalScore1 += score;
            counter++;
        }
        System.out.println(totalScore1);
        counter = 0;
        while (counter < numOfHoles) {
            System.out.print("Player 2, what is your score for the hole? " + (counter + 1) + "? ");
            // save that score and add it to the running total for P1
            score = scan.nextInt();
            totalScore2 += score;
            counter++;
        }
        System.out.println(totalScore2);
        // compare totalScore 1 to totalScore 2

        if (totalScore1 < totalScore2) {
            System.out.println("Player 1 wins!");
        } else if (totalScore1 == totalScore2) {
            System.out.println("Player 1 and Player 2 tied!");
        } else {
            System.out.println("Player 2 wins!");
        }

        System.out.println("Thank you for playing!");

    }
}