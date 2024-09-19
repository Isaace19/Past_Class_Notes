class SockSize {
    public static void main(String[] args) {
        int shoeSize = 8;

        switch (shoeSize) {
            case 5:
            case 6:
                System.out.println("Size extra small.");
                break;

            case 7:
            case 8:
                System.out.println("Size small");
                break;

            case 9:
            case 10:
                System.out.println("Size medium");
                break;

            case 11:
            case 12:
                System.out.println("Size large");
                break;

        }
    }
}