#include <list>
//#include "enums.h"
#include <string>
using namespace std;


class Meaning
{
	private:
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

	public:
    Meaning();
	//Meaning(string, string, string, string, string, string, string, string, string, string);

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
};


/*class Meaning
{
	private:
	PartOfSpeech partofspeech_;
	Number number_;
	GrammarCase grammarcase_;
	Degree degree_;
	Gender gender_;
	Person person_;
	Negation negation_;
	VerbForm verbform_;
	Done done_;
	Infinitive infinitive_;

	public:
	Meaning(PartOfSpeech, Number, GrammarCase, Degree, Gender, Person, Negation, VerbForm, Done, Infinitive);

	PartOfSpeech getPartOfSpeech();
	bool setPartOfSpeech(PartOfSpeech);

	Number getNumber();
	bool setNumber(Number);

	GrammarCase getGrammarCase();
	bool setGrammarCase(GrammarCase);

	Degree getDegree();
	bool setDegree(Degree);

	Gender getGender();
	bool setGender(Gender);

	Person getPerson();
	bool setPerson(Person);

	Negation getNegation();
	bool setNegation(Negation);

	VerbForm getVerbForm();
	bool setVerbForm(VerbForm);

	Done getDone();
	bool setDone(Done);

	Infinitive getInfinitive();
	bool setInfinitive(Infinitive);
};*/
