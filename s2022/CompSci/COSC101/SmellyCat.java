/* Program: Mad Libs version of Smelly Cat
 * Learning Objective: Using the Scanner to read input
 */
import java.util.Scanner;
class SmellyCat {
    public static void main(String[] args) {
        String animal, INGverb, noun1, noun2, noun3, noun4;
        Scanner myScanner = new Scanner(System.in);

        /* Use the Scanner to capture the answers to the prompts.
           .next() will capture a string up until ANY whitespace 
         * and .nextLine() will capture a string until ENTER (will capture spaces)
        */
        System.out.print("Type an animal: ");               // Prompt the user
        animal = myScanner.nextLine();                         // Store what they typed in a variable
        System.out.print("Type an verb ending in -ing: ");  // repeat
        INGverb = myScanner.nextLine();

        System.out.print("Type a noun: ");
        noun1 = myScanner.nextLine();
        System.out.print("Type a noun that rhymes with the noun above: ");
        noun2 = myScanner.nextLine();

        System.out.print("Type a noun: ");
        noun3 = myScanner.nextLine();
        System.out.print("Type a noun that rhymes with the noun above: ");
        noun4 = myScanner.nextLine();

        myScanner.close();  // close the Scanner when you are done using it

        /* Print out the finished Mad Libs
         * given the input collected from the user.
         */
        System.out.println("\n"); // visual separator between the prompts and the Mad Libs

        System.out.println("Smelly " + animal + ", smelly " + animal); 
        System.out.println("What are they " + INGverb + " you?");      
        System.out.println("Smelly " + animal + ", smelly " + animal);
        System.out.println("It's not your fault\n"); // Use the '\n' here to create an empty line

        System.out.println("They won't take you to the " + noun1);
        System.out.println("You've obviously not their favorite " + noun2);
        System.out.println("You may not be a bed of " + noun3);
        System.out.println("You're no friend to those with " + noun4 + "\n"); // \n to separate verse

        System.out.println("Smelly " + animal + ", smelly " + animal); 
        System.out.println("What are they " + INGverb + " you?");      
        System.out.println("Smelly " + animal + ", smelly " + animal);
        System.out.println("It's not your fault"); // Did not use the '\n' - do NOT want extra line at end of program
        
    }
 }