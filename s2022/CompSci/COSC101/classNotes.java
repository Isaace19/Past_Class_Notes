class classNotes {
    public static void main(String[] args) {
        /*
         * Boolean Expressions
         * Expressions that evaluate to True or false
         * Today is about compound boolean expressions
         * ex. calculaute a discount for a theme park: children discount
         * a senior discount is the same.
         * child: under 18
         * Senior: 65 and over} person is an int that over age
         * 
         * pesudocode:
         * if(person <18 or person >=65){
         * //cacluate discount would go here in this if statement
         * }
         * 
         * -symbols:
         * ! - NOT
         * && - AND - have to use ampreand twice or it would be an operator type
         * || - OR
         * 
         * pseudocode:
         * int person =17;
         * if(person < 18 || person >=65){
         * //calculate the discount
         * 
         * Java would evaluate the expression inside the if statement and determine if
         * it is true or false given the integer
         * variable above, if one evaluates to true or false, it would not evaluate the
         * other condition
         * this is known as short-circuit evaluation. (This happens when we don't have
         * to evaluate the entire expression)
         * }
         */
        System.out.print(!(3 > 2) && (0 < 1));
    }
}