#include <list>
#include "enums.h"
using namespace std;
class Meaning
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
	//TODO gettery i settery
};
