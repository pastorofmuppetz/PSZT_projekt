#include "Sentence.h"
#include <iostream>
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
    Word w;
    std::string sentence="";
    for(std::list<Word>::iterator iter=Sentence::listOfWords_.begin(); iter != Sentence::listOfWords_.end(); ++iter)
    {
        w=*iter;
        sentence.append(w.getWord());
        sentence.append(" ");
    }

    return sentence;

}

std::string Sentence::getSentenceWithMeanings(void)
{
    return "1";
}

