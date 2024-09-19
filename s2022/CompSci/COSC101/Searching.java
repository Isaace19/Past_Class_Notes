import java.util.ArrayList;

class Searching {
    // x is an index into list as well as y
    public void swap(Integer x, Integer y, listArrayList<Integer> list) {
        // Integer temp = x;
        // x = 5;
        // y = temp;

        // set the elemeent at index x in the list to the element at index y and vice
        // versa

        int a = list.get(x);
        int b = list.get(y);
        int temp = a;
        list.set(x, b)
        list.set(y, a);


    }

    public void bubbleSort(ArrayList<Integer> sortList) {
        swap();
    }

    public boolean linearSerach(int x, ArrayList<Integer> searchList) {
        for (int i = 0; i < searchList.size(); i++) {
            if (x == serachList.get(i)) {
                return true;
            }

        }
    }

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<Integer>();

        list.add(15);
        list.add(61);
        list.add(2);
        list.add(13);
        list.add(27);

        for (int it = 0; it < list.size(); it++) {
            System.out.print(list.get(it) + " ");
        }
        int x = 31;
        boolean found = false;
        for (int it = 0; it < list.size(); it++) {
            if (x == list.get(it)) {
                found = true;
                System.out.println("X has been found " + x + " is in the list ");
            }
        }
        if (!found) {
            System.out.println("X was not in the list");
        }
    }
}

/*
 * linear search, binary search, and bubble sort is to be reviewed for the array
 * and arraylist concepts
 */