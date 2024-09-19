class StudentExample {
    public static void main(String[] args) {
        Student stuObj1 = new Student("Dylan", "Allen");
        Student stuObj2 = new Student("Bob", "Dylan");

        // initials = firstName.substring(0, 1) + lastName.substring(0, 1); 
        //            A                         + A
        //            size of ss = endIndex - beginIndex
        //                       = 1        - 0         = 1
        System.out.println(stuObj1.getInitials());
        System.out.println(stuObj2.getInitials());

        String s1 = stuObj1.getFirstName();
        String s2 = stuObj2.getLastName();

        boolean areStringsEqual = s2.equals(s1);
        System.out.println(areStringsEqual);

        String hw = "Hello World";
        String sshw = hw.substring(0, 8); //End index at r, EndIndex - 1
        System.out.println(sshw);
    }
} 