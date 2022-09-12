#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "math.h"

using namespace std;





class InsultGenerator() {
public:
	char prefix[49][50];
	char root[49][50];
	char suffix[49][50];

	void initialize() {
		int row = 0;
		ifstream insults("InsultsSource.txt")
		string line;

		while (getline(insults, line)) {
			istringstream iss(line);
			
			getline(iss, prefix[row][0], '\t');
			getline(iss, root[row][0], '\t');
			getline(iss, sufffix[row][0]);

			row++;
		}

	}

}

