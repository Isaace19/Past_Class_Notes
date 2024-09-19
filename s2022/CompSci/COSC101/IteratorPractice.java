/*iterator practice*/

class IteratorPractice {
    public static void main(String[] args) {
        int i, j; // i is for iterator
        i = 5;
        j = 5;
        /* System.out.print(i++), this is equal to i = 5 + 1 = 6 */
        /* System.out.println(i+1) this is equal to i = i + 1 */

        System.out.println(i++);
        System.out.println(++j);

        System.out.println(i);
        System.out.println(j);

        System.out.format("My number is %d or %d\n", 5 + 9, i + 2);

    }
}