class IfStatementNotes {
    public static void main(String[] args) {
        // If statements syntax
        // Don't always need an else statement with an if statement.
        int x = 10;
        if (x > 0) {
            // code that executes if the if statement is expression is true
            System.out.println("This value is greater than 0");
            System.out.println("This print statement is inside the if statement");
        }
        System.out.println("This will always be executed by java no matter what X is equal to ");

        if (x > 5) {
            System.out.println("This value is greater than 15");
        } else {
            System.out.println("this value is not greater than 15");
        }
    }

}
