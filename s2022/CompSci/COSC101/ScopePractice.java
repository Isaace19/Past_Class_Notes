/* Scope practice */

import java.util.Scanner;

class ScopePractice {
    public static void main(String[] args) {
        int a, b;

        a = 10;
        b = 22;
        System.out.println(a);
        {
            int c = 55;
            a = 10;
            System.out.println(c);
            {
                // Scope #2
                System.out.println(c);
            }
        }
        System.out.println(a);
    }
}