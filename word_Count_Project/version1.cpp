  #include <iostream>
    #include <fstream>
    #include <cstring>
    #include <sstream>

    using namespace std;
    
    int main(int argc, char *argv[]){
    ifstream f1("textfile.txt"); 
// check if file is successfully opened
if (!f1) cerr << "Can't open input file.";

string line;
int line_count = 0;

string word;
int word_count = 0;

// read file line by line
while (getline(f1, line)) {

    // count line
    ++line_count;

    stringstream ss(line);

    // extract all words from line
    while (ss >> word) {

        // count word
        ++word_count;
    }
}

// print result
cout << "Total Lines: " << line_count <<" Total Words: "<< word_count << endl;

}