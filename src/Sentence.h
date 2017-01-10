<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <cstdio>
#include "Word.h"
//#include "strings.h"
//#include <string>

using namespace std;




=======
#include "Word.h"
>>>>>>> 9f8b8cc174b7d9c43ac67e8609bf2251973878ba
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

	bool readProcessedFile(void);
	bool writeResultToFile(void);
	Meaning* isolateMembers(string atributes, string basicForm);

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
