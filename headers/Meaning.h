#include <list>
#include "enums.h"
using namespace std;
class Meaning
{
	private:
	partOfSpeech partofspeech_;
	number number_;
	grammarCase grammarcase_;
	degree degree_;
	gender gender_;
	person person_;
	neagtion negation_;
	verbForm verbform_;
	done done_;
	infinitive infinitive_;
	public:
	Meaning(partOfSpeech, number, grammarCase, degree, gender, person, neagtion, verbForm, done, infinitive);
	partOfSpeech getpartofspeech();
	bool setpartofspeech(partOfSpeech);
	//TODO gettery i settery
};