#include "Word.h"

class Sentence{
	private:
	std::list<Word> listOfWords_;
	public:
	Word getWord(int);
	bool addWord(Word&);
	bool removeWord(int);
	bool analyze(void);
	std::string getSentence(void);
	std::string getSentenceWithMeanings(void);
};
