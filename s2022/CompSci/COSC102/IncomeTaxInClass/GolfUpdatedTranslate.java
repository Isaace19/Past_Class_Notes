/* Updated Golf Program using ArrayLists */
/* Have 2 players and ask for their scores
   and store scores in an ArrayList
   which can use to print scores for each hole
   and change scores. */

import java.util.ArrayList;
import java.util.Scanner;

class GolfUpdatedTranslate {
    public static void main(String[] args) {
        /* Variables - everything except the ArrayList */
        String player1, player2; // store names of each player
        int score1 = 0;
        int score2 = 0;
        int strokes; // reuse this for input with each player's score for each hole
        int playerNum; // 1 or 2 or 0 - use this to catch which player has incorrect data

        /* ArrayList */
        ArrayList<Integer> player1holes; // Declaration for an AL - the scores for player1 for each hole
        ArrayList<Integer> player2holes;
        final int SHORT_GAME = 2; // just to make typing in input faster, we will have a shorter game
        final int TOTAL_HOLES_NORMAL_GAME = 18;

        /* Initialize the AL / Allocate space */
        player1holes = new ArrayList<>(SHORT_GAME);
        player2holes = new ArrayList<>(SHORT_GAME); // Java doesn't actually need the SHORT_GAME part, could leave it
                                                    // like ();

        Scanner scan = new Scanner(System.in);

        /* Gather the names of the players and welcome them to the game. */
        System.out.println("Welcome to golf scoring!");
        System.out.print("Player 1, what is your name? ");
        player1 = scan.nextLine();
        System.out.print("Player 2, what is your name? ");
        player2 = scan.nextLine();

        /*
         * Collect the scores for each hole (for each player) and save in the ArrayList
         */
        /* .add() METHOD HERE */
        for (int i = 0; i < SHORT_GAME; i++) {
            System.out.print("What was " + player1 + "'s score for hole " + (i + 1) + "? ");
            strokes = scan.nextInt();
            player1holes.add(strokes);

            /* Same thing for player 2 down here */
            System.out.print("What was " + player2 + "'s score for hole " + (i + 1) + "? ");
            strokes = scan.nextInt(); // reusing strokes twice in one iteration of for loop
            player2holes.add(strokes);

        }

        /*
         * See if scores are correct by looping through the players' respective
         * ArrayLists
         */
        /*
         * We can use the .size() METHOD HERE with an ArrayList - as a reminder,
         * remember arrays use .length, not .size()
         * and we can use the .get() METHOD HERE to retrieve elements from the ArrayList
         * .get() will take an index as a parameter, and give us what is stored at that
         * index back.
         * REMEMBER 0-indexing!
         */
        System.out.println(player1 + "'s Game: ");
        for (int i = 0; i < player1holes.size(); i++) {
            System.out.println("  Hole " + (i + 1) + ": " + player1holes.get(i));
        }
        /* Do the same thing for Player 2 */
        System.out.println(player2 + "'s Game: ");
        for (int i = 0; i < player2holes.size(); i++) {
            System.out.println("  Hole " + (i + 1) + ": " + player2holes.get(i));
        }

        /* Check for incorrect scores */
        System.out.println("Was there an incorrect score for player 1 or player 2?");
        System.out.println(" If so, type 1 or 2 respectively, or 0 if all are correct.");
        playerNum = scan.nextInt();

        /*
         * Use a conditional statement to check either player 1's or player 2's
         * AL to change
         */
        int incorrectHole;
        int newScore;
        if (playerNum == 1) {
            System.out.print("Which hole was incorrect? ");
            incorrectHole = scan.nextInt();
            System.out.print("What is the correct score? ");
            newScore = scan.nextInt();
            player1holes.set(incorrectHole - 1, newScore);
            System.out.println("Player 1's Corrected Game: ");
            for (int i = 0; i < player1holes.size(); i++) {
                System.out.println("  Hole " + (i + 1) + ": " + player1holes.get(i));
            }
        } else if (playerNum == 2) {
            System.out.print("Which hole was incorrect? ");
            incorrectHole = scan.nextInt();
            System.out.print("What is the correct score? ");
            newScore = scan.nextInt();
            player2holes.set(incorrectHole - 1, newScore);
            System.out.println("Player 2's Corrected Game: ");
            for (int i = 0; i < player2holes.size(); i++) {
                System.out.println("  Hole " + (i + 1) + ": " + player2holes.get(i));
            }
        }

        /*
         * Change the code to have more helper functions
         * Do this anywhere where have repetition (i.e. "do the same thing
         * but for player 2") -- printing scores for loop is something
         * we did a LOT
         */
        /* Error check - user typing in incorrect holes, etc */
        /* We could change the code for player 1's AND 2's scores are incorrect. */

        /*
         * BLUEPRINT FOR CHANGING SCORES ABOVE
         * if ( USER ENTERS ONE)
         * change a score in the AL but we don't know what hole # was incorrect yet
         * so we need to ask
         * 
         * once we get that info,
         * .set() method to change the score at the hole #. We can use the hole # to
         * index into our arraylist. If they type that hole 1 is incorrect, we will
         * use the .set() with index 0
         * if ( USER ENTERS TWO)
         * we will do the same thing, except with player 2's AL
         * ELSE (NEITHER 1 NOR 2 is ENTERED ... HOPEFULLY 0)
         * do nothing
         */

        /* Sanity check for entering scores into AL - use .get() */
        // System.out.println("Sanity check");
        // for (int i = 0; i < SHORT_GAME; i++) {
        // System.out.println("You entered: " + player2holes.get(i));
        // }
    }
}
