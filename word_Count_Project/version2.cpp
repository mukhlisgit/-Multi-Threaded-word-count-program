#include <iostream>
    #include <fstream>
    #include <cstring>
    #include <sstream>
    
    using namespace std;
    void openFile(ifstream&,string);

    void openFile(ifstream& inFile,string fname){
    
    
    inFile.open(fname);
    if (inFile.is_open()){
        cout << "successfully opened file";
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