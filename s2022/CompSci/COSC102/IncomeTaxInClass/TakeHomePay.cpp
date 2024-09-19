/*
name: Isaac Abella
netid: iabella
Studentid: 000641840
Program Name: TakeHomePay.cpp
Description: Calculates take home pay for income
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Get userinput for salary
    int tax = 0;
    double gsalary, salary, incomeTax, takeHomeSalary;

    cout << "Enter a salary: ";
    cin >> salary;
    gsalary = salary;

    // Calculate the Medicare and Social Security with doubles
    double socialSecurirtyTax = (.062 * salary);
    double medicareTax = (.0145 * salary);

    // Income Tax Calculations Using Compound If Statements to calculate certain brackets
    // You need to create a new salary value for the tax bracket that you're calculating for

    if (salary < 15080)
    {
        cout << "This is less than minimum wage for a yearly." << endl;
        return 1;
    }
    if (salary >= 539901)
    {
        incomeTax += (salary - 539900) * .37;
        salary = 539900;
    }
    if (salary >= 215951)
    {
        incomeTax += (salary - 215950) * .35;
        salary = 215950;
    }
    if (salary >= 170050)
    {
        incomeTax += (salary - 170050) * .32;
        salary = 170051;
    }
    if (salary >= 89076)
    {
        incomeTax += (salary - 89075) * .24;
        salary = 89075;
    }
    if (salary >= 41776)
    {
        incomeTax += (salary - 41775) * .22;
        salary = 41775;
    }
    if (salary >= 10276)
    {
        incomeTax += (salary - 10275) * .12;
        salary = 10275;
    }
    if (salary >= 10275)
    {
        incomeTax += (salary)*.10;
    }

    // Calculate the Take Home Pay after deducting all the taxes

    takeHomeSalary = gsalary - (incomeTax + socialSecurirtyTax + medicareTax);

    // formated print states to the 2nd decimal of our calculations with proper lines and spacing.
    printf("-----------------------------------\n");
    printf("%-25s$%9.2f\n", "Yearly Salary", salary);
    printf("%-25s$%9.2f\n", "Social Security Tax:", socialSecurirtyTax);
    printf("%-25s$%9.2f\n", "Medicare Tax:", medicareTax);
    printf("%-25s$%9.2f\n", "Income Tax:", incomeTax);
    printf("-----------------------------------\n");
    printf("%-25s$%9.2f\n", "Take Home Salary: ", takeHomeSalary);
    printf("%-25s$%9.2f\n", "Monthly Take Home Pay:", takeHomeSalary / 12);

    return 0;
}
