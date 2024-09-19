import java.util.Scanner;

class VetOffice {
    public static void main(String[] args) {
        Cat esso = new Cat(3, 10, "Emily");
        esso.printCatData();

        Dog silvie = new Dog(1, 5, "Angela");
        silvie.printDogData();

        int a, b;
        a = 7;
        b = 8;

        System.out.println(a + " " + b + " " + a * b);
        char excl = '!';
        System.out.format("%s %s%c%n", greeting, "World", excl);

    }
}