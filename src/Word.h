#include "Meaning.h"
#include <list>
class Word
{
	private:
	std::list <Meaning> meanings_;
	int position_;
	
	public:
	Word(std::list <Meaning> mean, int pos);
	Meaning getMeaning(int pos);
	bool addMeaning(Meaning &m);
	bool removeMeaning(int pos);
	int getPosition();
	bool setPosition(int pos);

};
