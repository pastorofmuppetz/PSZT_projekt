#include "Meaning.h"
class Word
{
	private:
	std::list <Meaning> meanings_;
	int position_;
	
	public:
	Meaning getMeaning(int i);
	bool addMeaning(Meaning &m);
	bool removeMeaning(int i);
	int getPosition();
	bool setPosition(int i);

};
