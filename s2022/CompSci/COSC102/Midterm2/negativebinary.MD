** Negative Binary and Some Exam Review **

    8 Bit Examples
    0000 0001 -> 1 this doesn't work
    we have to do another method to get negative numbers in binary

Some Addition of Binary
    0000 0001 (1)
    1000 0001 (-1)
+ ------------
    1000 0010 (-2)    However, this notation does not work in getting negative numbers.

Using 2's Complement
    28 in binary -> 0001_1100 (28) Good practice for exams

    step 1: Invert all of the digits
        1110_0011
    stpe 2: Then add 1 
        1110_0011 
        0000_0001 (1) Inverted
    + ------------
        1110_0100 (-28) This is negative

        0000_0001 (1)
        1111_1110 (1) Inverted
    + ------------
        1111_1111 (-1) This is now negative 1 in binary

    Here there are 8 bits, while 1111_1111 can be a large number, for our case given the 8 bits,
    this number is -1 and above it has the largest magnitude then any other negative integer, hence the all 1s

    0000_0001 (1)
    1111_1111 (-1) with two's complement
+ ---------S----
    0000_0000 This will equal 0

    What would happen when you carry a 1 into another column with two 1s already being added.

        0001_1101 (27)
        0001_1111 (30)   
    + ----------------
        0011_1010   (58)

Remember: Leading 1 in an 8 bit byte is an indicator that it's a negative, if you wanted this to be positive
you would beed to have a 12 bit byte that holds 4 0s in front of the leading 1 to indicate a positive.

        1110_0100 (-28)
        0001_0011 (19)
    +-------------------
        1111_0111 (-9)S

Summary - WILL BE ON THE FINAL EXAM
    * Take a positive number and write the negative veresion of it in binary using 2's complement
    * Adding 2 bSinary numbers together (positive numbers only)


    