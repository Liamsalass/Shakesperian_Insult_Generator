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

class InsultGenerator() {

	void initialize();



}




