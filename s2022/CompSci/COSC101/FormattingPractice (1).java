import java.util.Scanner;

class FormattingPractice {
    public static void main(String[] args) {
        // Formatting with doubles used %f
        // Ints, strings, alignment

        double a, b;
        int c;
        String s1, s2, s3;
        Scanner inputReader = new Scanner(System.in);

        System.out.print("Enter a number from 1 to 10: ");
        a = inputReader.nextDouble();
        System.out.print("Enter your name: ");
        s1 = inputReader.next();

        System.out.print("Enter a number from 1 to 10: ");
        b = inputReader.nextDouble();
        System.out.print("Enter your last name: ");
        s2 = inputReader.next();

        System.out.print("Enter a integer from 1 to 10: ");
        c = inputReader.nextInt();
        System.out.print("Enter your nickname: ");
        s3 = inputReader.next();
        inputReader.close();

        // %-10s specifies a string that is left justified and 10 characters wide; corresponds with s1
        // If string is longer than 10 characters, the string prints anyway without left-justification
        // %-10.2f specifies a double that is left-justified, 10 characters long, and rounded to 2 decimal places; corresponds with a
        System.out.format("%-10s%-10.2f\n", s1, a);
        System.out.format("%-10s%-10.2f\n", s2, b);

        //%-10d specifies an integer that is left-justified and 10 characters long
        System.out.format("%-10s%-10d\n", s3, c);
    }
}