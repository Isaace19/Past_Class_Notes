import java.util.Scanner;

class FormattingPractice {
    public static void main(String[] args) {
        // Formatting with doubles used $f
        // ints, strings, alignment
        int a, b;
        String s1, s2;
        Scanner inputReader = new Scanner(System.in);

        System.out.println("Enter a number from 1 - 10: ");
        a = inputReader.nextInt();
        System.out.println("Enter your name: ");
        s1 = inputReader.next();

        System.out.println("Enter a numner from 1 - 10");
        b = inputReader.nextInt();
        System.out.println("Enter your name: ");
        s2 = inputReader.next();

        // The minus sign is for left justification
        // (right is default)
        // Only use the minus sign with setting width, other you
        // Wouldn't have extra space to pay with anyway
        // The 10 was for seting with to 10 (anything beyond teh string size is spaces)
        // Using .X will round a double to X many decimal places

        System.out.format("%-10s%-10d\n", s1, a); // the 10 is the "set width"
        System.out.format("%-10s%-10d\n", s2, b);

        // Specifiers are: %c = Char, %s = String, %d = integer, %f = double
        double myDouble = 25.55555;
        System.out.format("%-10s%-10f\n", s2, myDouble);
    }
}