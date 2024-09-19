public class House {
  private double price;
  private int squareFootage;
  private int numBedrooms;
  private int numBathrooms; // 2.5 If we have a half bath, then we will count that as 3 bathrooms

  public House(double p, int size, int beds, int baths) {
    price = p;
    squareFootage = size;
    numBedrooms = beds;
    numBathrooms = baths;
  }

  public House(double p) {
    price = p;
  }

  public double getPrice() {
    return price;
  }

  public double getSquareFootage() {
    return squareFootage;
  }

  public double getNumBedrooms() {
    return numBedrooms;
  }

  public double getNumBathrooms() {
    return numBathrooms;
  }

  public void printInfo() {
    String cirInfo = squareFootage + " sqft house with " + numBedrooms + " bedrooms and "
        + numBathrooms + " bathrooms for $" + ((int) price);
    System.out.println(cirInfo);
  }

  public double changePrice(double changeAmount) {
    price = price + changeAmount;
    return price;
  }

  public int calcDownPayment(int percent) {
    int downPayment = (int) (price * percent / 100);
    return downPayment;
  }
}