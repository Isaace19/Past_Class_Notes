class RockyTop {
    /* This is a multi line comment */

    public static void main(String[] args) {
        /*
         * Variabeles
         * int numofApples -> lower camelCase
         * data type followed by the variable name
         * By java convention, we use lower camelCase for variable names
         * and upper CamelCase with class names.
         * Other conventions:
         * snake_case
         * num_of_apples
         * SCREAMING_SNAKE_CASE: NUM_OF_APPLES
         */
        int numOfApples; // declared a variable
        numOfApples = 10; // Assigned the variable
        double pi = 3.14; // Declaring and assigning at the same time
        /*
         * Note that all the variables above have the NAME on the LEFT
         * when assigning, and the VALUE on the right.
         */
        System.out.println("Rocky Top");
        System.out.println(numOfApples); // NOTE: No quotes becase I'm just outputting the variable
        System.out.println(pi);

        char letter = 'e';
        String name = ("Isaac");
        System.out.println(name);
        System.out.println("\n\n");

        /*
         * Keyword - Final
         * the final keyword will create an error for vs if we change that variable
         * final double pi = 3.14;
         * pi = 2.25;
         */

        /* More Complex Printing */
        System.out.println("More Complex Priting");
        System.out.println(name + " " + letter);

        // Plus sign is used to "concatenate" a string to print
        int x = 20;
        int y = 40;

        System.out.println(pi + numOfApples);
        System.out.println(x + y);
        System.out.println("x is equal to " + x + " and y is equal to " + y);
        // The plus sign can be used for addition or to
        // concatenate a string to print and Java chooses based on context clues
    }
}