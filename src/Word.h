#include "Meaning.h"
#include <list>
class Word
{
	private:
    string word_;
	std::list <Meaning> meanings_;
	int position_;

	public:
    Word();
	Word(std::list <Meaning> mean, int pos);
	string getWord();
	bool setWord(string);
	Meaning getMeaning(int pos);
	bool addMeaning(Meaning &m);
	bool removeMeaning(int pos);
	int getPosition();
	bool setPosition(int pos);

};
