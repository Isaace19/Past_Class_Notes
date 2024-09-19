/* Budget Class based 2022 Tax Rates, Single Person with 0 Dependents
 * 
 * The following data is used for tax rates:
 * Social Security tax = 6.2% of gross wages (FICA)
 * Medicare tax = 1.45% of gross wages (FICA)
 * to learn more: https://www.ssa.gov/thirdparty/materials/pdfs/educators/What-is-FICA-Infographic-EN-05-10297.pdf
 * 
 * Tax Rates 2022 for filing single
 * 10%               Up to $10,275
 * 12%               $10,276-$41,775
 * 22%               $41,776-$89,075
 * 24%               $89,076-$170,050
 * 32%               $170,051-$215,950
 * 35%               $215,951-$539,900
 * 37%               $539,901 and over

*/
class Budget {
    private int salary;
    private double incomeTax;
    private double yearlyTakeHomePay;
    private double monthlyTakeHomePay;
    private double ssTax;
    private double medicareTax;

    /* Constructor */
    public Budget(int newSalary) {
        salary = newSalary;
    }

    /* Calculate Social Security Tax */
    private void calculateSSTax() {
        ssTax = salary * 0.062;
    }

    /* Calculate Medicare Tax */
    private void calculateMedicareTax() {
        medicareTax = salary * 0.0145;
    }

    /*
     * Calculate Income Tax on Yearly Salary
     * Based on 2022 rates for filing single
     * (You should not understand the if statements, just that we output income tax
     * from this method)
     */
    private void calculateIncomeTax() {
        int leftoverSal = salary;
        incomeTax = 0;
        if (leftoverSal >= 539901) { // Top bracket
            incomeTax += (leftoverSal - 539901) * 0.37;
            leftoverSal = 539900;
        }
        if (leftoverSal >= 215951) {
            incomeTax += (leftoverSal - 215951) * 0.35;
            leftoverSal = 215950;
        }
        if (leftoverSal >= 170051) {
            incomeTax += (leftoverSal - 170051) * 0.32;
            leftoverSal = 170050;
        }
        if (leftoverSal >= 89076) {
            incomeTax += (leftoverSal - 89076) * 0.24;
            leftoverSal = 89075;
        }
        if (leftoverSal >= 41776) {
            incomeTax += (leftoverSal - 41776) * 0.22;
            leftoverSal = 41775;
        }
        if (leftoverSal >= 10276) {
            incomeTax += (leftoverSal - 10276) * 0.12;
            leftoverSal = 10275;
        }
        incomeTax += leftoverSal * 0.1;
    }

    /* Calculate Take Home Pay */
    public void calculateTHP() {
        calculateIncomeTax();
        calculateMedicareTax();
        calculateSSTax();

        yearlyTakeHomePay = salary - ssTax - medicareTax - incomeTax;
        monthlyTakeHomePay = yearlyTakeHomePay / 12;
    }

    /*
     * Calculate how much to allocate to a monthly budget category given a
     * percentage of take-home pay
     */
    public double calculateBudgetCategory(double percent) {
        double categoryAmount = (percent / 100) * monthlyTakeHomePay;
        return categoryAmount;
    }

    public double getMonthlyTakeHomePay() {
        return monthlyTakeHomePay;
    }
}