echo "What is your name?? "
read USER_NAME
echo "Hello $USER_NAME"
echo "I will create a file called ${USER_NAME}_file"
touch "${USER_NAME}_file"

./hello 1 2 
./ hello abc 123
./ hello 123 abc
./ hello 

