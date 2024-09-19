import java.util.Scanner;

class ShapesPractice {
    public static void main(String[] args) {
        Rectangle mySquare = new Rectangle(4, 4);
        Rectangle myRectangle = new Rectangle(5, 10);
        Triangle myTriangle = new Triangle(3, 7);
        Circle myCircle = new Circle(2);

        mySquare.printInfo(); // void method the method is printInfo on a rectangle object
        myRectangle.printInfo(); // a void method gives user nothing in return
        myTriangle.printInfo();

        double a = mySquare.getArea(); // RETURNS to me a double (4*4 = 16)
        double b = myRectangle.getArea(); // Returns ot me a double and we know that from the method's signature
                                          // Signature: public double getArea()
                                          // The reutrn value of a method is placed NBEFORE the method name i the
                                          // signature
                                          // If the method reutnrs nothing, we will see void before the method name

        System.out.println("The area of the square is " + a);
        double c = a + b;
        double d = myTriangle.getBase();

        System.out.println("The areas added together area " + c);
        System.out.println("The triangle's base is " + d);

        myCircle.printInfo();
    }
}