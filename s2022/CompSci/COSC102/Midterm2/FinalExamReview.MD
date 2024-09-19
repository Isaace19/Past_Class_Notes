* Final Exam Review * 
This was in class with Prof. Crumpton


1: Convert 0xDAD to Binary - 1101_1010_1101
    D - 1101
    A - 1010
    D - 1101

2: Give this result in hexadecimal 
    0xD7 (1<<3) = D = 13, and then we have a7

    1101_0111
    0000_0111 
    now shift 3 = 0001_0101

    Now that is 1101_1111 which is F in hexadecimal
3: Shifting Bits
    0b1101_0011 >> 2 = 0b0011_0011 because this is a right shift
    0b1101_0011 << 2 = 0b0100_1100

    >> is a right shift indicator
    << is a left shift indicator

4: Convert 0x23 to decimal
    0x23 converted to binary would be 0010_0011 in 8 bits with the 1,2 and 32 place turned on because 0010 is 2 and 0011 is 3
    converted this to decimal is 35
    in 8 bits the 0010 has the 32 turned on and the 0011 is 3 turned on, so in total you have 35

5: Binary true or false
    True or False: 1<< 0 = 1
    Answer is A: which was 0x1C, 0x31, 0xAB, 0xC1
    you can tell by looking at the placement of the first value of each digit and see if those are in order
    1 is 16, 3 would b 16*3, A is 10*16, and C is 12*16, which are all in order

    0x9F - 9 * 16 and F is 15, so you would have A0

6: Chmod commands
    current commands
    -rw-r--r--

    Permissions that we want to give

    user: read only
    group : read and write
    world: same

    How would we convert this file to give those permissions? The file name myfile.txt

    rwx 
    421

    it would look something like -r- -rw -r-
    chmod 464 myfile.txt 

7: Sorting Algorthms
    Bubble Sort
    [5,2,7,9,1,3] what is the order of the array after 2 steps of bubble sort?

    [2,5,7,9,1,3]
    [2,5,7,9,1,3] would be the answer after 2 steps because 5 and 7 do not swap
    [2,5,7,9,1,3]
    [2,5,7,1,9,3] would be the answer after 4 steps because 9 and 1 will swap
