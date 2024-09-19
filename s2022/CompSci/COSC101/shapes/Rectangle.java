public class Rectangle
{
  private double width;
  private double height;

  public Rectangle(double rectWidth, double rectHeight)
  {
    width = rectWidth;
    height = rectHeight;
  }

  public double getWidth()
  {
    return width;
  }

  public double getHeight()
  {
    return height;
  }

  public double getArea()
  {
    return width * height;
  }

  public void printInfo()
  {
    String rectInfo = "Rectangle with width " + width + " and height " + height + 
     " and area " + getArea();

    System.out.println(rectInfo);
  }
}