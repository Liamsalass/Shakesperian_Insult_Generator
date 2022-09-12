#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "math.h"

using namespace std;


class InsultGenerator()

{
public:
string prefix[49];
string root[49];
string suffix[49];


void initialize() {
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

}

