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
#include <unordered_set>
#include "insultgenerator_19lhs4.h"



using namespace std;

char* FileException::what() {
    return (char *) "File Error";
}




char* NumInsultsOutOfBounds::what() {
    return (char *) "The number of insults is out of bounds";
}


void InsultGenerator::initialize(){
    ifstream insults("InsultsSource.txt");
    string line;

    while (getline(insults, line)) {
        istringstream iss(line);

        string str1;
        string str2;
        string str3;
        getline(iss, str1, '\t');
        getline(iss, str2, '\t');
        getline(iss, str3);

        prefix.push_back(str1);
        root.push_back(str2);
        suffix.push_back(str3);
    }
    insults.close();
}

string InsultGenerator::talkToMe(){
    int iPrefix = rand() % 49;
    int iRoot = rand() % 49;
    int iSuffix = rand() % 49;
    return "Thou " + prefix[iPrefix] + " " + root[iRoot] + " " + suffix[iSuffix] + "!";
}

vector<string> InsultGenerator::generate(int n) {
    vector<string> insults;
    unordered_set<string> insult_set;
    insult_set.reserve(n);
    if (n <= 0 || n > 10000) {
        throw NumInsultsOutOfBounds();
    } else {
        for (int i = 0; i < n; i++) {
            string insult = talkToMe();
            int previous_count = (int) insult_set.size();
            insult_set.insert(insult);
            if (insult_set.size() <= previous_count) {
                i--;
                continue;
            }
            insults.push_back(insult);
        }
    }
    return insults;
};

void InsultGenerator::generateAndSave(int n) {


};




