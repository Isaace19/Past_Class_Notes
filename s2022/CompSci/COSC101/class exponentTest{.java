import java.util.Scanner;

class exponentTest {
    public static void main(String[] args) {
        // testing how to convert ints to doubles then putting them into exponents.

        int left, right;
        int result;

        Scanner s = new Scanner(System.in);

        System.out.println("Enter your first number to represent the base");
        left = s.nextInt();
        s.close();
        System.out.println("Enter your second number to represent the exponent");
        right = s.nextInt();
        s.close();

    }
}