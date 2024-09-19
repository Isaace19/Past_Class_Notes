public class Student
{
  private String firstName;
  private String lastName;
  private String initials;
  int year;

  public Student(String f, String l)
  {
    firstName = f;
    lastName = l;
  }

  public Student(String l)
  {
    lastName = l;
  }

  public String getFirstName()
  {
    return firstName;
  }

  public String getLastName()
  {
    return lastName;
  }

  public double getPrice()
  {
    return price;
  }

  public int getYear()
  {
    return year;
  }

  public String getInitials()
  {
    initials = firstName.substring(0, 1) + lastName.substring(0,1);
    return initials;
  }

  public void changeYear(int newYear) {
    year = newYear;
  }
}