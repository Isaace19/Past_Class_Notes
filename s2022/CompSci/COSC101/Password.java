
/*Ask the user for a password, the password is cs101.
 * if the user doesn't get the password in 3 attempts,
 * we will exit the program and give a message
 * if they DO get the password correctly, we'll
 * print out some other message.
 */
import java.util.Scanner;

class Password {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String password;
        for (int i = 0; i < 3; i++) {
            System.out.println("What is the password?");
            password = s.next();

            if (password.equals("cs101")) {
                System.out.println("You're in!");
                break;
            } else {
                System.out.println("Wrong password");
            }
        }
        System.out.println("Bye");
    }
}