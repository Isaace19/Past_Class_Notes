import java.util.Scanner;

public class BirthdayBudget {
    public static void main(String[] args) {
        double brunch, tickets, cake;

        Scanner input = new Scanner(System.in);

        System.out.println("How much is brunch?: ");
        brunch = input.nextDouble();
        System.out.println("How much do move tickets cost?: ");
        tickets = input.nextDouble();
        System.out.println("How much does a layered cake cost?: ");
        cake = input.nextDouble();

        double brunchTotal = brunch + (brunch * 2);
        double ticketsTotal = tickets * 2;
        double cakeTotal = cake + (cake / 3);

        double grandTotal = brunchTotal + ticketsTotal + cakeTotal;

        System.out.println("Brunch: " + "$" + brunchTotal);
        System.out.println("Movie Tickets: " + "$" + ticketsTotal);
        System.out.println("Cake and cupcake: " + "$" + cakeTotal);
        System.out.println("Grand Total: " + "$" + grandTotal);

    }
}
