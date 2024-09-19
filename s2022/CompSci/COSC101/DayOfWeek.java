/*Take a month, day and year as inegers
 * and print out what day of the week that is.
 */

class DayOfWeek {
    public static void main(String[] args) {
        String dayString; // Monday, Tuesday, etc..
        int monthInt = 2;
        int dayInt = 19;
        int yearInt = 2004;

        int d0; // 0 = Sunday, 1 = Monday, 2 = Tuesday.... 6 = Saturday

        int y0 = yearInt - (14 - monthInt) / 12;
        int x0 = y0 + y0 / 4 - y0 / 100 + y0 / 400;
        int m0 = monthInt + 12 * ((14 - monthInt) / 12) - 2;
        d0 = (dayInt + x0 + 31 * m0 / 12) % 7;

        if (d0 == 0) {
            dayString = "Sunday";
        } else if (d0 == 1) {
            dayString = "Monday";
        } else if (d0 == 2) {
            dayString = "Tuesday";
        } else if (d0 == 3) {
            dayString = "Wednesday";
        } else if (d0 == 4) {
            dayString = "Thursday";
        } else if (d0 == 5) {
            dayString = "Friday";
        } else if (d0 == 6) {
            dayString = "Saturday";
        } else {
            dayString = "Error";
        }

        System.out.println(monthInt + " " + dayInt + " " + yearInt + " is a " + dayString);
    }
}