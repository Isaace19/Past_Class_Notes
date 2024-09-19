public class Triangle
{
  private double base;
  private double height;

  public Triangle(double triBase, double triHeight)
  {
    base = triBase;
    height = triHeight;
  }

  public double getBase()
  {
    return base;
  }

  public double getHeight()
  {
    return height;
  }

  public double getArea()
  {
    return base * height * 0.5;
  }

  public void printInfo()
  {
    String triInfo = "Triangle with base " + base + " and height " + height + 
     " and area " + getArea();

    System.out.println(triInfo);
  }
}