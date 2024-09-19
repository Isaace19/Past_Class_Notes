class Dog {
    private int age;
    private double weight;
    private String ownerName;

    Dog(int ageData, double weightData, String ownerNameData) {
        age = ageData;
        weight = weightData;
        ownerName = ownerNameData;
    }

    public void printDogData() {
        System.out.println(
                "The dog's age is " + age + ", it's weight is " + weight + ", and the owner's name is " + ownerName);
    }
}