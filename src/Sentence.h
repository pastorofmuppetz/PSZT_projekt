#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <cstdio>
#include "Word.h"


using namespace std;

class Sentence
{
private:
    std::list<Word> listOfWords_;

public:
    Word getWord(int);
    bool addWord(Word&);
    bool removeWord(int);
    int analyze(void);
    std::string getSentence(void);
    std::string getSentenceWithMeanings(void);

    //input-output functions
    bool readProcessedFile(char*);
    bool writeResultToFile(void);
    Meaning* isolateMembers(string atributes, string basicForm);

    //comparing funcions
    int compareMeanings(Meaning&, Meaning&);
    int compareGenders(string, string);
    int compareNumbers(string, string);
    int compareGrammarCases(string, string);

    //rules
    int analyzeTwoWords(int, int, int);
    int verbVSverb(Meaning&,  Meaning&);
    int substVSverb(Meaning&, Meaning&);
    int prepVSall(Meaning&,Meaning&);
    int allVSprep(Meaning&, Meaning&);
    int substVSadj(Meaning&,Meaning&);
    int adjVSall(Meaning&, Meaning&);
    int substVSsubst(Meaning&, Meaning&);
    int verbVSsubstAdj(Meaning&, Meaning&);
    int gerVSall(Meaning&, Meaning&);

    int chosenMeanings[100];
};
