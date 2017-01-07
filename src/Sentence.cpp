#include "Sentence.h"
#include <iostream>
#include <list>
#include <cstdio>
#include <string>

Word Sentence::getWord(int pos)
{
    std::list<Word>::iterator iter=Sentence::listOfWords_.begin();
    for(int i=0; i<pos; i++)
    {
        if (iter!=Sentence::listOfWords_.end())
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
    Word nextWord;

    if (analyzeTwoWords(0,0,0)==-1)
        return -1;

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
    int whichWord=0;
    std::string sentenceWithMeanings="";
    for(std::list<Word>::iterator iter=Sentence::listOfWords_.begin(); iter != Sentence::listOfWords_.end(); ++iter)
    {
        w=*iter;
        m=w.getMeaning(chosenMeanings[whichWord]);

        sentenceWithMeanings.append(w.getWord());
        sentenceWithMeanings.append(" => ");
        sentenceWithMeanings.append(m.getBasicForm());
        sentenceWithMeanings.append(" ");
        sentenceWithMeanings.append(m.getAll());
        sentenceWithMeanings.append("\n");
        whichWord++;
    }

    return sentenceWithMeanings;
}

int Sentence::compareMeanings(Meaning& m1, Meaning& m2)
{
    int matching=0;
    string atribute1;
    string atribute2;

    if (!(m1.getPartOfSpeech().compare("qub")&&m2.getPartOfSpeech().compare("qub")))
        return 0;

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

int Sentence::analyzeTwoWords(int wPos1, int mPos1, int mPos2)
{
    static int liczba=0;
    liczba++;
    int lengthOfSentence=listOfWords_.size();
    Word w1=getWord(wPos1);
    Word w2=getWord(wPos1+1);
    int numberOfMeanings1=w1.getNumberOfMeanings();
    int numberOfMeanings2=w2.getNumberOfMeanings();
    Meaning m1=w1.getMeaning(mPos1);
    Meaning m2=w2.getMeaning(mPos2);
    //cout<<"Inside analyzing for "<<liczba<<" time."<<endl;
    //cout<<"Word number, Meaning 1, meaning 2: "<<wPos1<<", "<<mPos1<<", "<<mPos2<<endl;

    if (compareMeanings(m1,m2)==3)
    {
        w1.setPositionOfChosenMeaning(mPos1);
        w2.setPositionOfChosenMeaning(mPos2);
        chosenMeanings[wPos1]=mPos1;
        chosenMeanings[wPos1+1]=mPos2;
        //cout<<"Chosen meanings: "<<mPos1<<", "<<mPos2<<endl;

        if (wPos1+2<lengthOfSentence)
            analyzeTwoWords(wPos1+1, mPos2, 0);
        else
            return 1;
    }
    else
    {
        if (mPos2+1<numberOfMeanings2)
            analyzeTwoWords(wPos1,mPos1,mPos2+1);
        else if (mPos1+1<numberOfMeanings1)
            analyzeTwoWords(wPos1,mPos1+1,0);
        else
        {
            return -1;
        }
    }
}

