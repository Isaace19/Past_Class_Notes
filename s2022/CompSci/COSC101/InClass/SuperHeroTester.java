public class SuperHeroTester {
    public static void main(String[] args) {
        Power speed = new Power("Super Speed", 10);

        SuperHero flash = new SuperHero("The Flash", speed);

        SuperHero shazam = new SuperHero("Shazam", speed);

        System.out.println("Shazam's strength is " + shazam.getStrength());
        System.out.println("The Flash's strength is " + flash.getStrength());

        // U[date the Flash's strength to 15

        System.out.println("Updating the Flash's strength to 15");
        flash.setStrength(15);

        System.out.println("Shazam's strength: " + shazam.getStrength());
        System.out.println("The Flash's strength: " + flash.getStrength());

    }
}