public class Power {
    private String name;
    private int strength;

    public Power(String theName, int theStrength) {
        name = theName;
        strength = theStrength;
    }

    public String getName() {
        return name;
    }

    public int getStrength() {
        return strength;
    }

    public void setName(String newName) {
        name = newName;
    }

    public void setStrength(int newStrength) {
        if (newStrength < 0) {
            System.out.println("Strength cannot be less than 0. ");
        } else {
            strength = newStrength;
        }
    }
}
