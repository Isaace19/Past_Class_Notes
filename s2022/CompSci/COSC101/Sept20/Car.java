public class Car
{
  private double price;
  private int year;
  private String brand;
  private String model; 

  /* We have 3 constructors. The parameters lists MUST differ by data types, i.e. we can't have two
   * constructors that take 1 String.
   * We can have a constructor that takes a String and an int, or a constructor that takes a String and a double.
   * This is called Constructor Overloading.
   * Constructor Overloading = making more than 1 constructor.
   * The only constraint here is you can't make multiple constructors with the exact same list of data types as parameters.
   */
  public Car(double p, int y, String b, String m)
  {
    price = p;
    year = y;
    brand = b;
    model = m;
  }

  public Car(String b, String m) {
    brand = b;
    model = m;
  }

  public Car(double p, int y) {
    price = p;
    year = y;
  }

  public Car(String b) {
    brand = b;
  }

  public double getPrice()
  {
    return price;
  }

  public void setPrice(int newPrice)
  {
    price = newPrice;
  }

  public int getYear()
  {
    return year;
  }

  public String getBrand()
  {
    return brand;
  }

  public String getModel()
  {
    return model;
  }

  public void printInfo()
  {
    String carInfo = year + " " + brand + " " + model;
    System.out.println(carInfo);
  }

  public double changePrice(double changeAmount) {
    price = price + changeAmount;
    return price;
  }
}