/*
 *
 *      Liam Salass
 *      20229595
 *
 */




#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "math.h"



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


class InsultGenerator{
    public:
        string prefix[49];
        string root[49];
        string suffix[49];
        void initialize(){
            int row = 0;
            ifstream insults("InsultsSource.txt");
            string line;

            while (getline(insults, line)) {
                istringstream iss(line);

                getline(iss, prefix[row], '\t');
                getline(iss, root[row], '\t');
                getline(iss, suffix[row]);
                cout << prefix[row] << " " << root[row] << " " << suffix[row] << endl;
                row++;
            }
        };
        string talkToMe(){
            int iPrefix = rand() % 49;
            int iRoot = rand() % 49;
            int iSuffix = rand() % 49;
            return "Thou " + prefix[iPrefix] + " " + root[iRoot] + " " + suffix[iSuffix] + "!";
        };
        vector<string> generate(int n) {
            if (n <= 0 || n > 10000) {
                throw NumInsultsOutOfBounds();
            } else {
                for (int i = 0; i < n; i++) {

                }
            }
        };
};



