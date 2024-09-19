
/* /* Program Name: First Submission
 * Student Name: Isaac Abella
 * Student ID: 000-641-840
 * NetID: iabella
 * Description: This algorithm properly converts the time given by the user
 * in seconds and converts it into hours and minutes 
 */
import java.util.Scanner;

class ElapsedTime {
    public static void main(String[] args) {
        int dataInSeconds, hours, minutes, seconds;

        Scanner s = new Scanner(System.in);

        /*
         * The following line will ask the user to input a time in seconds that will the
         * be converted by the program.
         */
        System.out.print("Enter the elapsed time in seconds: ");
        dataInSeconds = s.nextInt();
        s.close();

        /*
         * This line of code will then take the user inpute then calculate it into
         * hours, minutes, and seconds.
         */
        hours = dataInSeconds / 3600;
        minutes = dataInSeconds / 60;
        seconds = dataInSeconds % 60;

        System.out.format("%d seconds is %d hours, %d minutes, %d seconds.\n ", dataInSeconds, hours, minutes, seconds);
    }
}