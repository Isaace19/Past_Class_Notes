echo "Compiling."
g++ -o hello hello.cpp
echo "Running hello executable with redirect
echo "Difftool Output: ""
./hello > input3.txt
diff input1.txt input3.txt
echo "ENDING SCRIPT"

