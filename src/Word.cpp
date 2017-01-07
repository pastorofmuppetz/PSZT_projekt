#include "Word.h"

Word::Word()
{

};
Word::Word(std::list <Meaning> mean, int pos){
	position_ = pos;
	meanings_ = mean;
}

string Word::getWord()
{
    return Word::word_;
}
bool Word::setWord(string word)
{
    Word::word_=word;
    return 1;
}

Meaning Word::getMeaning(int pos){
	std::list<Meaning>::iterator iter=meanings_.begin();
	for(int i = 0; i < pos; i++)
		iter++;
	return *iter;
}

bool Word::addMeaning(Meaning &m){
	meanings_.push_back(m);
	return true;
}

bool Word::removeMeaning(int pos){
	std::list<Meaning>::iterator iter=meanings_.begin();
	for(int i = 0; i < pos; i++)
		iter++;
	meanings_.erase(iter);
	return true;
}

int Word::getPosition(){
	return position_;
}

bool Word::setPosition(int pos){
	position_ = pos;
	return true;
}

int Word::getPositionOfChosenMeaning()
{
    return Word::positionOfChosenMeaning_;
}
bool Word::setPositionOfChosenMeaning(int pos)
{
    Word::positionOfChosenMeaning_=pos;
    return 1;
}

int Word::getNumberOfMeanings()
{
    return Word::meanings_.size();
}
