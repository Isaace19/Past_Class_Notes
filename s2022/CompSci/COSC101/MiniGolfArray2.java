import java.util.Scanner;

import javax.print.attribute.standard.NumberOfInterveningJobs;

class MiniGolfArray2 {
    public static void calcScores(int playerNum, int totalHoles, Scanner scan) {
        int[] scores = new int[totalHoles];
        int score;
        int totalScore = 0;
        System.out.print("Player" + playerNum + ": ");
        for (int counterHoles = 0; counterHoles < totalHoles; counterHoles++) {
            System.out.print("Player, what is your score for hole " + (counterHoles + 1) + "? ");
            // save that score to scores 1 and add it to teh running total for P1
            score = scan.nextInt();
            scores[counterHoles] = score;
            totalScore += score;
        }
        System.out.println("  Done calculating holes for this player" + playerNum + ".");
        System.out.println("  Their score was " + totalScore);
        System.out.println("  The scores of for each hole were: ");
        for (int it = 0; it < totalHoles; it++) {
            System.out.println("   Hole " + it + ": " + scores[it]);
        }

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        final int numOfHoles = 4;
        System.out.println("Welcome to mini golf!");

        System.out.println("How many players are in the game? ");

        final int totalPlayers = scan.nextInt();
        // here 5 is the number of total players
        for (int it = 0; it < totalPlayers; it++) {
            calcScores((it + 1), numOfHoles, scan);

        }

        scan.close();

    }

}