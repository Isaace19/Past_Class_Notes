import javax.xml.namespace.QName;

class ArrayPractice {
    public static void main(String[] args) {
        int[] myArray; // declearing an integer array ~ it's totally empty and has a size of zero
        double[] myArray2 = new double[5];
        /*
         * this is an array of doubles - it has a length of 5, but we didn't specify
         * what values are inside the array
         */
        // myArray2 will then be set to have all default values -0.0
        // double 0.0 is default, int is 0, boolean is false, any object is "null"

        // myArray3 is an int array that we will set the initial values for
        int[] myArray3 = { 10, 20, 30, 40, 50 }; // byte - 8 bits, and a bit is either a 0 or 1
        myArray3[0] = 13;
        myArray3[4] = 23;
        // now myArray3 is no 13, 20, 30, 40, 50 because i set the first number to 13

        for (int it = 0; it < myArray3.length; it++) {
            System.out.println(myArray3[it]);
        }

    }
}