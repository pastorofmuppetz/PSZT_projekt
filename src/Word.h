#include "Meaning.h"
class Word
{
	private:
    string word_;
	std::list <Meaning> meanings_;
	int positionOfChosenMeaning_;
	int position_;

	public:
    Word();
	Word(std::list <Meaning>, int);
	string getWord();
	bool setWord(string);
	Meaning getMeaning(int );
	bool addMeaning(Meaning&);
	bool removeMeaning(int);
	int getPosition();
	bool setPosition(int);
	int getPositionOfChosenMeaning();
	bool setPositionOfChosenMeaning(int);
	int getNumberOfMeanings();

};
