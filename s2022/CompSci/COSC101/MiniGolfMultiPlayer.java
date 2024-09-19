import java.util.Scanner;

class MiniGolfMultiPlayer {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        final int numOfPlayers = 2;
        final int numOfHoles = 3;
        int counterHoles = 0;
        int counterOfPlayers = 0;
        int score;
        int[] scores1 = new int[numOfHoles];
        int[] scores2 = new int[numOfHoles];
        int totalScore = 0;

        System.out.println("Welcome to mini golf!");

        for (counterOfPlayers = 0; counterOfPlayers < numOfPlayers; counterOfPlayers++) {
            System.out.print("Player " + (counterOfPlayers + 1) + ": ");
            for (counterHoles = 0; counterHoles < numOfHoles; counterHoles++) {
                System.out.println("Player, what is your score for hole " + (counterHoles + 1) + " ? ");
                // Save that score to score1 and add it to the running total for p1
                score = scan.nextInt();
                scores1[counterHoles] = score;
                totalScore += score;
            }
            System.out.println("  Done calculating holes for this player");
            System.out.println("  Their score was " + totalScore);
            System.out.println("  The scores of for each hole were: ");
            for (int it = 0; it < numOfHoles; it++) {
                System.out.println("   Hole " + it + ": " + scores1[it]);
            }

            totalScore = 0;
            counterOfPlayers++;

            for (counterOfPlayers = 0; counterOfPlayers < numOfPlayers; counterOfPlayers++) {
                System.out.print("Player " + (counterOfPlayers + 1) + ": ");
                for (counterHoles = 0; counterHoles < numOfHoles; counterHoles++) {
                    System.out.println("Player, what is your score for hole " + (counterHoles + 1) + " ? ");
                    // Save that score to score1 and add it to the running total for p1
                    score = scan.nextInt();
                    scores2[counterHoles] = score;
                    totalScore += score;
                }
                System.out.println("  Done calculating holes for this player");
                System.out.println("  Their score was " + totalScore);
                System.out.println("  The scores of for each hole were: ");
                for (int it = 0; it < numOfHoles; it++) {
                    System.out.println("   Hole " + it + ": " + scores2[it]);
                }

            }
        }
    }
}