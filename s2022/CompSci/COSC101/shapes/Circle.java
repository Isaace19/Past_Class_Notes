public class Circle
{
  private double radius;

  public Circle(double cirRadius)
  {
    radius = cirRadius;
  }

  public double getRadius()
  {
    return radius;
  }

  public double getArea()
  {
    return 3.1416 * radius * radius;
  }

  public void printInfo()
  {
    String cirInfo = "Circle with radius " + radius + " and area " + getArea();
    System.out.println(cirInfo);
  }
}