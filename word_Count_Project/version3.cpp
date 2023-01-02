#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include<thread>
#include<string>
#include<mutex>
#include<condition_variable>
#include<unistd.h>
#include <fstream>
using namespace std;
#define MAX_THREADS 50


void openFile(ifstream&,string);
thread *threads = new thread[MAX_THREADS];
condition_variable cv[MAX_THREADS];
mutex m1;
int counter=0;
std::ifstream inFile;

int count_words_in_line(string line){
    
    
    bool odd = true;
    auto thread_count_odd = [&counter, &inFile, &odd, &line, &m1]() {
        while (std::getline(inFile, line)) {
            if (odd) {
                std::cout<<"Count odd"<<std::endl;
                m1.lock();
                counter += count_words_in_line(line);
                m1.unlock();
            }
            odd = !odd;
        }
    };

    bool even = false;
    auto thread_count_even = [&counter, &inFile, &even, &line, &m1]() {

        while (std::getline(inFile, line)) {
            if (even) {
                std::cout<<"Count even"<<std::endl;
                m1.lock();
                counter += count_words_in_line(line);
                m1.unlock();
            }
            even = !even;
        }
    };

    std::thread t1(thread_count_odd);
    std::thread t2(thread_count_even);

    t1.join();
    t2.join();
    
        return 1;
}




    void openFile(ifstream& inFile,string fname){ 
    inFile.open(fname);
    if (inFile.is_open()){
        cout << "successfully opened file \n\n";
    }
    else {
        cout << "Failed to open file" <<
        endl;
        exit(-1);
    }
}




    int main()
    {

       ifstream ifile;
    openFile(ifile, "textfile.txt");


        int numberOfWords = 0;
for (std::string line, word; std::getline(ifile, line); )
{
    std::istringstream iss(line);

    while (iss >> word)
    {
        bool alpha = true;

        for (char c : word)
            if (!std::isalpha(c)) alpha = false;

        if (alpha) ++numberOfWords;
    }
    std::cout << "Number of words on this line: " << numberOfWords << std::endl;
    numberOfWords = 0;
}
        return 0;
}
