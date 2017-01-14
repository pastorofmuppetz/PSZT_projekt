#include "Word.h"
#include <list>
#include <string>
class Sentence{
	private:
	std::list<Word> listOfWords_;

	public:
	Word getWord(int);
	bool addWord(Word&);
	bool removeWord(int);
	int analyze(void);
	std::string getSentence(void);
	std::string getSentenceWithMeanings(void);

	int compareMeanings(Meaning&, Meaning&);
	int compareGenders(string, string);
	int compareNumbers(string, string);
	int compareGrammarCases(string, string);

	int analyzeTwoWords(int, int, int);
	int verbVSverb(Meaning&,  Meaning&);
	int substVSverb(Meaning&, Meaning&);
	int prepVSall(Meaning&,Meaning&);
	int substVSadj(Meaning&,Meaning&);
	int adjVSall(Meaning&, Meaning&);
	int substVSsubst(Meaning&, Meaning&);
	int verbVSsubst(Meaning&, Meaning&);

	int chosenMeanings[100];
};
