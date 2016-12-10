#include "Meaning.h"
class Word
{
	private:
	std::list <Meaning> meanings_;
	int position_;
	
	public:
	Meaning getMeaning(int i);
	bool setMeaning(Meaning &m);
	int getPosition();
	bool setPosition(int i);

};