
import java.util.Scanner;

class MiniGolfDoWhile {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int numoOfPlayers = 2;
        int numOfHoles = 3;
        int counter = 0;
        int score;
        int totalScore1 = 0;
        int totalScore2 = 0;

        System.out.println("Welcome to mini-golf scoring!");
        do {
            System.out.println("Player 1, what is your score for hole " + (counter + 1) + " ? ");
            score = scan.nextInt();
            totalScore1 += score;
            counter++;
        } while (counter < numOfHoles);
        System.out.println(totalScore1);

        counter = 0;
        do {
            System.out.print("Player 2, what is your score for the hole? " + (counter + 1) + "? ");
            score = scan.nextInt();
            totalScore2 += score;
            counter++;
        } while (counter < numOfHoles);
        System.out.println(totalScore2);

        if (totalScore1 > totalScore2) {
            System.out.println("Player 1 wins!");
        } else if (totalScore1 == totalScore2) {
            System.out.println("Player 1 and Player 2 tied!");
        } else {
            System.out.println("Player 2 wins!");
        }

        System.out.println("Thank you for playing!");

    }
}