class NestForLoops {
    public static void main(String[] args) {
        System.out.println("Printing a grid: ");

        for (int row = 1; row <= 2; row++) {
            for (int col = 1; col <= 5; col++) {
                System.out.print(" * ");
            }
        }
        System.out.print("\n");
    }
}