import java.util.Scanner;

//ask for the title (lad, lord, "the one and only", "the infamous", "gov'nah")
//middle name

class BridgertonName {
    public static void main(String[] args) {
        String title, middleName, lastDrink, street;

        Scanner s = new Scanner(System.in);
        System.out.println("Birdgerton Name Generator");

        System.out.print("What is your title ");
        title = s.nextLine();

        System.out.println("what is your middle name? ");
        middleName = s.nextLine();

        System.out.println("What was the last beverage you had? ");
        lastDrink = s.nextLine();

        System.out.println("What is your street name you have lived on? ");
        street = s.nextLine();

    }
}