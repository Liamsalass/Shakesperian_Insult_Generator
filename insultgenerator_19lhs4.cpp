/*
 *
 *      Liam Salass
 *      20229595
 *
 */

#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include "insultgenerator_19lhs4.h"



using namespace std;

char* FileException::what() { //Exception message if failed to read in file.
    return (char *) "File Error";
}




char* NumInsultsOutOfBounds::what() { //Exception message if too many or too few number of insults are to be generated.
    return (char *) "The number of insults is out of bounds";
}


void InsultGenerator::initialize(){ //Function for initializing the insult generator.
    srand(time(NULL)); //Makes sure random numbers are used each time project compiles
    ifstream insults("InsultsSource.txt"); //Reads in text file
    string line; //Used to hold each line from the getLine function.
    if ((insults.fail())) throw FileException();

    while (getline(insults, line)) { //Continues until at the end of text file. Once at the bottom, returns 0
        istringstream iss(line); //Use of a string stream to use getLine function to parsing each line with the tab delimiter.
        //String for holding each individual prefix, root, and suffix.
        string str1;
        string str2;
        string str3;
        //getLine function on the stringstream to parse each line. Tab delimited for the first two.
        getline(iss, str1, '\t');
        getline(iss, str2, '\t');
        getline(iss, str3);
        //Puts values inside of their respective vectors.
        prefix.push_back(str1);
        root.push_back(str2);
        suffix.push_back(str3);
    }
    insults.close(); //Closes text file
}

string InsultGenerator::talkToMe(){ //Function return string with a full insult message.
    //Generates random int variable to select each random value form the vectors.
    int iPrefix = rand() % 49;
    int iRoot = rand() % 49;
    int iSuffix = rand() % 49;
    //Return statement using the random ints to pull random words from the vectors.
    return "Thou " + prefix[iPrefix] + " " + root[iRoot] + " " + suffix[iSuffix] + "!";
}

vector<string> InsultGenerator::generate(int n) { //Function returns a vector of strings, each string being an entire insult.
    vector<string> insults;
    unordered_set<string> insult_set; //Used to check if duplicate insults are generated.
    insult_set.reserve(n);
    if (n < 1 || n > 10000) { //Exception catch
        throw NumInsultsOutOfBounds();
    } else {
        for (int i = 0; i < n; i++) { //For loop to run n times to produce n insults.
            string insult = talkToMe();
            int previous_count = (int) insult_set.size(); //Takes the current size of the unordered_set and saves it so it can be used later.
            insult_set.insert(insult); //Adds new insult to the unordered_set.
            //If the insult wasn't added to the unordered_set (due to it being a duplicate) the size of it should still be the same.
            //If it's the same size, then we decrement i, and restart the loop, causing it to regenerate a new insult again.
            if (insult_set.size() <= previous_count) {
                i--;
                continue;
            }
            insults.push_back(insult); //If the insult was added to the unordered_set, then also add it to the vector insults.
        }
    }
    insult_set.clear(); //Remove the unordered_set from memory.
    return insults;
};



void InsultGenerator::generateAndSave(const string &file_name, int n) {
    //Number of insults exception catch.
    if (n < 1 || n > 10000) throw NumInsultsOutOfBounds();

    vector<string> insults = generate(n); //Create a vector of insults.
    sort(insults.begin(), insults.end()); //Sorts the vector alphabetically
    ofstream outfile(file_name); //Creates file for output.
    for (int i = 0; i <= n; i++){ //Writes an insult to each line of the text file.
        outfile << insults[i] << endl;
    }
};




