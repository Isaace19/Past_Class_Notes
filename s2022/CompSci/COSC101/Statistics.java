import java.util.Scanner;
import java.util.Set;

class Statistics {
    public static void main(String[] args) {
        boolean isrunning = true;
        Statistics myClass = new Statistics();
        Scanner s = new Scanner(System.in);
        int num1;
        do {
            do {
                System.out.print("Enter an integer (\"quit\" to quit): ");
                if (!s.hasNextInt()) {
                    if (s.next().equals("quit")) {
                        isrunning = false;
                        break;
                    }
                    System.out.println("You did not enter an integer, try again.");
                } else {
                    num1 = s.nextInt();
                    myClass.addValue(num1);
                    break;
                }
            } while (true);
        } while (isrunning);
        s.close();
        /*
         * for this part of the code we just use the myClass functions to use the
         * methods below in the code
         */

        System.out.format("Number of values entered = %d%n", myClass.getNumValues());
        System.out.format("Sum of all values        = %d%n", myClass.getSum());
        System.out.format("Product of all values    = %d%n", myClass.getProduct());
        System.out.format("Biggest value            = %d%n", myClass.getMax());
        System.out.format("Smallest value           = %d%n", myClass.getMin());
        System.out.format("Average of all values    = %.2f%n", myClass.getAverage());
    }

    public void addValue(int val) {
        // using arithmetic operaters to assign the sum and product values to the val
        // input
        mNumValues++;
        mSumOfValues += val;
        mProductOfValues *= val;

        if (mNumValues == 1) {
            mMaximumValue = val;
            mMinimumValue = val;
        } else if (val > mMaximumValue) {
            mMaximumValue = val;
        } else if (val < mMinimumValue) {
            mMinimumValue = val;
        }
    }

    public double getAverage() {
        return (double) mSumOfValues / mNumValues;
    }

    public Statistics() {
        // creating instances of the num values from the attributes below
        int numValue = mNumValues;
        int sumValue = mSumOfValues;
        int productValue = mProductOfValues;
        int maximumValue = mMaximumValue;
        int minimumValue = mMinimumValue;
    }

    private int mNumValues = 0;
    private int mSumOfValues = 0;
    private int mProductOfValues = 1;
    private int mMaximumValue = 0;
    private int mMinimumValue = 0;

    public int getSum() {
        return mSumOfValues;
    }

    public int getNumValues() {
        return mNumValues;
    }

    public int getProduct() {
        return mProductOfValues;
    }

    public int getMin() {
        return mMinimumValue;
    }

    public int getMax() {
        return mMaximumValue;
    }
}