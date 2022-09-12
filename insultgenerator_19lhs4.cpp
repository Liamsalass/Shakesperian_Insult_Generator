#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "math.h"
#include "insultgenerator_19lhs4.h"


using namespace std;

class FileException : public std::exception {
public:
    char* what() {
        return "File Error";
    }
};


class NumInsultsOutOfBounds : public std::exception {
public:
    char* what() {
        return "The number of insults is out of bounds";
    }
};


class InsultGenerator(){
    public:
        string prefix[49];
        string root[49];
        string suffix[49];
        void initialize();
        string talkToMe();
};
void InsultGenerator::initialize() {
    int row = 0;
    ifstream insults("InsultsSource.txt");
    string line;

    while (getline(insults, line)) {
        istringstream iss(line);

        getline(iss, prefix[row], '\t');
        getline(iss, root[row], '\t');
        getline(iss, sufffix[row]);
        cout << prefix[row] << " " << root[row] << " " << suffix[row] << endl;
        row++;
    }
}


std::string InsultGenerator::talkToMe() {
    int iPrefix = rand() % 49;
    int iRoot = rand() % 49;
    int iSuffix = rand() % 49;
    return prefix[iPrefix] + " " + root[iRoot] + " " + suffix[iSuffix];
}

std::vector<string> InsultGenerator::generate(int i) {
    return nullptr;
}

void InsultGenerator::generateAndSave(const char *string, int i) {

}
