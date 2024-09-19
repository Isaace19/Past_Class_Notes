
/*Calculate the area of a triangle given the base and height
 * provided by the user in the terminal.
 * LEARNING: Scanner with numeral data, formatting (specfiically rounding)
*/
import java.util.Scanner;

class AreaTriangle {
    public static void main(String[] args) {
        double b, h, area;
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the base of the triangle: ");
        b = s.nextDouble();
        System.out.print("Enter the height of the triangle: ");
        h = s.nextDouble();

        System.out.println("Sanity Check: " + b + " and " + h);

        area = .5 * b * h;

        // Print area rounded to 3 decimal places (floats - 32 bits, double - 64 bits)
        System.out.format("Base: %.3f and Height: %.3f The area of the triangle is %.3f%n", b, h, area);

        // Prompt for base, height
        // Calculate Area of Triangle

        // Print area rounded to 3 decimal places

    }
}