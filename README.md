# -Multi-Threaded-word-count-program
Goal: the aim of this project is to iterate through each line in a text file and count
how many words are contained in that line.
Version upgrades:
First version: In this version, I simply retrieved the contents in the text file and
produced the total number of line_count and word_count separately.
Second version: in this version I optimized the way of retrieving the file by throwing an exception in case the said file cannot be retrieved. Then I changed the way of iterating through the lines and words and made it as follows:
initialize Boolean alpha to determine if there are still words left in a line or not=> create a for loop in which I use the function ‘isalpha’ to make alpha perform a recursion on itself => print number of words in that line until the while loop exhausts the number of words and then the for loop exhausts the number of lines=> print after each for loop iteration => end.
Third version: in this version I added multithreading to the second version by using two threads where one will count odd numbered lines and the other will count even numbered lines. Then I compiled using gcc compiler flags to enforce vectorization.


NOTE: To run this program, simply go to command line or terminal and compile the .cpp files one by one using a g++ or any other c++
compiler and run the compiled programs one after the other. You can also run the files using any IDE of your choice, just don't forget to locate
the textfile. 
