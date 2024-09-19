Unix/Linux

1. What is Vim and Linux Anyways?
   vim is a text editor GNU - Unix is an operating system that we use to code in

2. What are some commands that we use in unix?
   ls - ls shows the current directory contents
   mkdir - creates a new directory inside of your current path
   rm - stands for rm, you would do "remove file.cpp" and you can add rm -r in order to remove an entire directory.
   cp - copy a file, you can do scp for a secure copy file
   ssh - secure shell login, this is what we do to access the hydra and tesla machines
   chmod - stand for change mode; it's the access way to changing the permission iside of files.
   Uses -rwx-wx-wx
   first characters include d or - d stands for a directory and - stands for file

Searching Algorithms (Know the Steps of the algorithm and how to code) 1. Linear Search Algorithm - it's essentially like a loop
A loop is conducted and values are searched for one by one, if a match is found then that value is returned; if not, then the code keeps going until there is a match.

    1. Binary Search - Much more efficient and is faster than Linear Search     Algorithms
        Make sure the list is sorted before starting the algorithm
        Designate a beginning, midpoint, and the ending of the list.

        Then the code will check to see if the value you are searching for is greater than or less than or equal to the midpoint,
            If it's greater than, then it will discard the values less than the midpoint
            If it's less than, then it will discard the values greater than the midpoint
            If the value is the midpoint, then that's the match!
            else, the match is invalid and not in the list
                This is implemented through checking the end(the high in this case), with the being(the low in this case)

    || Will do the pseudocode inside of MidtermReview.cpp

Sorting Algorithms (know the steps of the algorithm and how to code) 1. Bubble Sort - Bubble sorting is when you swap adjacent elements when they are in the wrong order. The sorting alogirthm will compare the first two indexes (0 and 1) and compare their values, if they are not in order, then the code will swap the two and then compare the next indexes and do the same until it can no longer be swapped.

    2. Selection Sort - Stepping through each index look to the right of the index and compare the value with the current value selected and if it's not in order then it should be swapped.

        This would be a comparison between a sorted and unsorted values inside of an index - it's also the way that people usually 
        sort cards.

        Selection sort is also the the only sorting algorithm that we decide the final resting spot of the value
        And unlike a bubble sort - Sort does not have to compare old indexes at any point.

    3. Insertion Sort - Splits a vector into two part and compares the unsorted side of the vector to the sorted side and compares value from unsorted to the sorted, if it happens to be in the wrong order, than the compared value gets moved the sorted side.

    || Will Do the Code inside of MidtermReview.pp - at least in pseudocode ||
