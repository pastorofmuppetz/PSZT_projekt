#include "Sentence.h"
#include <list>
#include <string>

Word Sentence::getWord(int pos)
{
    std::list<Word>::iterator iter=Sentence::listOfWords_.begin();
    for(int i=0; i<pos; i++)
    {
        iter++;
    }
    return *iter;
}

bool Sentence::addWord(Word& word)
{
    Sentence::listOfWords_.push_back(word);
    return 1;
}

bool Sentence::removeWord(int pos)
{
    std::list<Word>::iterator iter=Sentence::listOfWords_.begin();
    for (int i=0;i<pos;i++)
        iter++;
    Sentence::listOfWords_.erase(iter);
    return 1;
}

bool Sentence::analyze(void)
{
    //TO DO
    return 1;
}

std::string Sentence::getSentence(void)
{
    //MOIM ZDANIEM TRZEBA TO ZROBIÆ INACZEJ
    return "1";
}

std::string Sentence::getSentenceWithMeanings(void)
{
    //MOIM ZDANIEM TRZEBA TO ZROBIÆ INACZEJ
    return "1";
}

