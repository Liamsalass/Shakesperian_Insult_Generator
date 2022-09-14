/*
 *
 *      Liam Salass
 *      20229595
 *
 */

class FileException : public std::exception {
public:
    char* what();
};

class NumInsultsOutOfBounds : public std::exception {
public:
	char* what();
};

class InsultGenerator {


public:
    void initialize();
    std::string talkToMe();
    std::vector<std::string> generate(int i);
};




