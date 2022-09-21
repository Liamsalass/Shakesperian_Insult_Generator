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
private:
    std::vector<std::string> prefix;
    std::vector<std::string> root;
    std::vector<std::string> suffix;

public:
    void initialize();
    std::string talkToMe();
    std::vector<std::string> generate(int n);
    void generateAndSave(int n);
};




