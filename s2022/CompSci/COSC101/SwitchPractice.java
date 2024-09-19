class SwitchPractice {

    public static void main(String[] args) {
        char letter = 'A';
        String Letter = "A+";

        switch (letter) {
            case 'A':
                System.out.println("the case for A");
                break;
            case 'B':
                System.out.Println("the case for B");
                System.out.println("inside case B");
                break;
            default:
                System.out.println("neither A nor B");
                break;
        }
        switch (LetterString) {
            case "A+":
                System.out.println("the case for A");
                break;
            case "B+":
                System.out.Println("the case for B");
                System.out.println("inside case B");
                break;
            default:
                System.out.println("neither A+ nor B+");
                break;

        }
    }
}