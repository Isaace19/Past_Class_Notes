import java.util.Scanner;

class ScannerErrorChecking {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int i;

        System.out.println("Give me an integer 1 - 10: ");

        i = s.nextInt();

        if (i < 1 || i > 10) {
            System.out.println("Not a number between 1 and 10 ");
        }

        System.out.println("You picked " + i);
    }

}