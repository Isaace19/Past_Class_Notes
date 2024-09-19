public class SuperHero {
    private String name;
    private Power superPower;

    public SuperHero(String heroName, Power heroPower) {
        name = heroName;

        superPower = new Power(heroPower.getName(), heroPower.getStrength());

    }

    public int getStrength() {
        return superPower.getStrength();
    }

    public void getStrength(int newStrength) {
        superPower.setStrength(newStrength);
    }

}