/* Stores a databse of all the cars in a car dealership */
import java.util.ArrayList;

public class ArrayListCars {
    public static void main(String[] args) {
        Car car1 = new Car(15000, 2010, "Ford", "Mustang");
        Car car2 = new Car(10000, 2007, "Honda", "CRV");

        ArrayList <Car> database = new ArrayList<Car>();
        ArrayList <String> newOwner = new ArrayList<String>();

        database.add(car1);
        database.add(car2);
        newOwner.add("Peyton Manning");
        newOwner.add("Taylor Swift");

        newOwner.add("Luke Skywalker");

        database.add(new Car(9000, 2009, "Ford", "Fiesta"));
        database.remove(2);
        for (int it = 0; it < database.size(); it++){
            database.get(it).printInfo();
            System.out.println(newOwner.get(it) + " is buying that car.");
        }

        System.out.println("Does the CRV still exist?");
        car2.printInfo();
    }
}