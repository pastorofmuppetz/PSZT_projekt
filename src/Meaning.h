#include <list>
#include <string>
using namespace std;


class Meaning
{
	private:
    string all_;
    string basicForm_;
	string partofspeech_;
	string number_;
	string grammarcase_;
	string degree_;
	string gender_;
	string person_;
	string negation_;
	string verbform_;
	string done_;
	string infinitive_;
	string future_;

	public:
    Meaning();

    string getAll();
    bool setAll(string);

    string getBasicForm();
    bool setBasicForm(string);

	string getPartOfSpeech();
	bool setPartOfSpeech(string);

	string getNumber();
	bool setNumber(string);

	string getGrammarCase();
	bool setGrammarCase(string);

	string getDegree();
	bool setDegree(string);

	string getGender();
	bool setGender(string);

	string getPerson();
	bool setPerson(string);

	string getNegation();
	bool setNegation(string);

	string getVerbForm();
	bool setVerbForm(string);

	string getDone();
	bool setDone(string);

	string getInfinitive();
	bool setInfinitive(string);

	string getFuture();
	bool setFuture(string);
};


