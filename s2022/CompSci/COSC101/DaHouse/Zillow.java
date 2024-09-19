class Zillow {
    public static void main(String[] args) {
        House home1 = new House(350000, 2000, 3, 2);

        home1.printInfo();
        /*
         * if we want to change that, we change the return value type in the signature
         * of changePrice
         * and we add a reutrn statement. The value it returns must be the data type as
         * the return type in the signature.
         * ChangePrice has a parameter - changeAmount;
         * changeAmount is a double, so we must provide a double in order for it to run.
         */
        double a = home1.changePrice(1000); // changePrice is a void function, it does not give us any value in return
        double newPrice = home1.getPrice();

        int home1Dpay3 = home1.calcDownPayment(3);
        int homeDPay5 = home1.calcDownPayment(5);

        System.out.println(a);
        System.out.println(newPrice);

        System.out.println("3% down payment is $" + home1Dpay3);
        System.out.println("5% down payment is $" + homeDPay5);

        House home2 = new House(100000, 800, 1, 1);

    }
}