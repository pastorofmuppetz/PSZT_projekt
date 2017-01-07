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
    Word currentWord;
    Word previousWord;
    Word nextWord;
    int pos;
    int chosenPos;
    std::list<Word>::iterator tempIter;
    for(std::list<Word>::iterator iter=Sentence::listOfWords_.begin(); iter != Sentence::listOfWords_.end(); ++iter)
    {
        currentWord=*iter;
        pos=currentWord.getPosition();
        tempIter=iter;
        tempIter++;
        //nextWord=*tempIter;
        /*if (pos>0)
        {
            tempIter--;
            tempIter--;
            previousWord=*tempIter;
        }
        else
        {

        }*/

    }


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
    Word w;
    Meaning m;
    int countTill;
    std::string sentenceWithMeanings="";
    for(std::list<Word>::iterator iter=Sentence::listOfWords_.begin(); iter != Sentence::listOfWords_.end(); ++iter)
    {
        w=*iter;
        if (w.getPositionOfChosenMeaning()>=0)
            m=w.getMeaning(w.getPositionOfChosenMeaning());

        sentenceWithMeanings.append(w.getWord());
        sentenceWithMeanings.append(" => ");
        sentenceWithMeanings.append(m.getBasicForm());
        sentenceWithMeanings.append(" ");
        sentenceWithMeanings.append(m.getAll());
        sentenceWithMeanings.append("\n");
    }

    return sentenceWithMeanings;
}

int Sentence::compareMeanings(Meaning& m1, Meaning& m2)
{
    int matching=0;
    string atribute1;
    string atribute2;

    atribute1=m1.getGender();
    atribute2=m2.getGender();
    if (atribute1.empty() || atribute2.empty())
        matching++;
    else
    {
        if (!atribute1.compare(atribute2))
            matching++;
    }

    atribute1=m1.getNumber();
    atribute2=m2.getNumber();
    if (atribute1.empty() || atribute2.empty())
        matching++;
    else
    {
        if (!atribute1.compare(atribute2))
            matching++;
    }

    atribute1=m1.getGrammarCase();
    atribute2=m2.getGrammarCase();
    if (atribute1.empty() || atribute2.empty())
        matching++;
    else
    {
        if (!atribute1.compare(atribute2))
            matching++;
    }

    return matching;
}

