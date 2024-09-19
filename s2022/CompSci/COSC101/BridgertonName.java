import java.util.Scanner;

//ask for the title (lad, lord, "the one and only", "the infamous", "gov'nah")
//middle name

class BridgertonName {
    public static void main(String[] args) {

        String title, middleName, lastDrink, street, yn;
        boolean repeat = false;
        do {
            Scanner s = new Scanner(System.in);
            System.out.println("Birdgerton Name Generator ");

            System.out.print("What is your title ");
            title = s.nextLine();

            System.out.println("what is your middle name? ");
            middleName = s.nextLine();

            System.out.println("What was the last beverage you had? ");
            lastDrink = s.nextLine();

            System.out.println("What was the street name you have lived on? ");
            street = s.nextLine();

            String readMe = String.format("%s %s %ston of %sshire", title, middleName, lastDrink, street);
            System.out.println("Your new name is " + readMe);

            System.out.println("Would you like to create a new name? y or n");
            yn = s.nextLine();

            if (yn.equals("y")) {
                repeat = true;
            } else {
                repeat = false;
            }

        } while (repeat);
        // This is while "repeat" is true, run the loop again.
        /*
         * make sure to change repeat to makke the loop happen! it's defaulted to false
         */
    }
}