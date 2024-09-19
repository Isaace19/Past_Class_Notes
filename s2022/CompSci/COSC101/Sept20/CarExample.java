import java.util.Scanner;
class CarExample {
    public static void main(String[] args) {
        Car carObj1 = new Car(19000, 2012, "Honda", "Accord");   //making an instance of the Car class, verb is "instanciating"
        Car carObj2;
        carObj2 = new Car(2000, 1992, "Acura", "Integra");

        carObj1.printInfo();
        System.out.println(carObj1.getBrand());

        double newPrice = carObj2.changePrice(1000);
        System.out.println(newPrice);

        Car carObj3 = new Car("Ford", "Mustang");
        System.out.println(carObj3.getBrand());
        System.out.println(carObj3.getPrice()); // not initialized with a price, Java will print 0.0
        carObj3.setPrice(11000);
        System.out.println(carObj3.getPrice());

        Car carObj4 = new Car("Ferrari");
        System.out.println(carObj4.getBrand());
        System.out.println(carObj4.getModel()); // not initialized with a model, Java will null

        Car carObj5 = new Car(10000.0, 2001);

        // Ask for make, model info and store as strings, then call a constructor
        Scanner s = new Scanner(System.in);
        String carName;
        System.out.println("What is the make of your car?");
        carName = s.next();

        Car carObj6 = new Car(carName);

        System.out.println("You entered " + carObj6.getBrand());

        
    }

}