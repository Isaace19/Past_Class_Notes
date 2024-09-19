class Cat {
    private int age;
    private double weight;
    private String ownerName; // if this was not private, you can change name in other programs

    // Constructor

    Cat(int ageData, double weightData, String ownerNameData) {
        age = ageData;
        weight = weightData;
        ownerName = ownerNameData;
    }

    // Method
    public void printCatData() {
        System.out.println(
                "the cat's age is " + age + ", it's weight is " + weight + ", and the owner's name is " + ownerName);
    }
}