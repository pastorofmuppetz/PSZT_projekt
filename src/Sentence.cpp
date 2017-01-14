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
    for (int i=0; i<pos; i++)
        iter++;
    Sentence::listOfWords_.erase(iter);
    return 1;
}

int Sentence::analyze(void)
{
    if (Sentence::listOfWords_.size()<2)
        return 0;

    if (analyzeTwoWords(0,0,0)==-1)
        return -1;

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
    //char lol[10];
    std::string sentenceWithMeanings="";
    for(std::list<Word>::iterator iter=Sentence::listOfWords_.begin(); iter != Sentence::listOfWords_.end(); ++iter)
    {
        w=*iter;
        m=w.getMeaning(chosenMeanings[whichWord]);
        cout<<chosenMeanings[whichWord]<<" "; //do wyrzucenia
        sentenceWithMeanings.append(w.getWord());
        sentenceWithMeanings.append(" => ");
        sentenceWithMeanings.append(m.getBasicForm());
        sentenceWithMeanings.append(" ");
        sentenceWithMeanings.append(m.getAll());
        sentenceWithMeanings.append(" ");
        sentenceWithMeanings.append(m.getGender());
        //sentenceWithMeanings.append("     Chosen meaning: ");
        //sprintf(lol, "%d", chosenMeanings[whichWord]);
        //sentenceWithMeanings.append(lol);
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
    string partOfSpeech1=m1.getPartOfSpeech();
    string partOfSpeech2=m2.getPartOfSpeech();

    if (!(partOfSpeech1.compare("qub")&&partOfSpeech2.compare("qub")))
        return 0;

    if (!(partOfSpeech1.compare("verb")||partOfSpeech2.compare("verb")))
        return verbVSverb(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("verb")))
        return substVSverb(m1, m2);

    if (!partOfSpeech2.compare("brev"))
        return 0;

    if (!partOfSpeech2.compare("interj"))
        return 0;

    if (!partOfSpeech1.compare("prep"))
        return prepVSall(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("adj")))
        return substVSadj(m1, m2);
    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("subst")))
        return substVSsubst(m1, m2);

    if (!partOfSpeech1.compare("adj"))
    {
        int a=adjVSall(m1, m2);
        cout<<"A="<<a<<endl;
        return a;
    }



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
    cout<<"Word number: "<<wPos1<<" Meaning of word: "<<mPos1<<" Meaning of next word: "<<mPos2<<endl;

    if (compareMeanings(m1,m2)==3)
    {
        w1.setPositionOfChosenMeaning(mPos1);
        w2.setPositionOfChosenMeaning(mPos2);
        chosenMeanings[wPos1]=mPos1;
        chosenMeanings[wPos1+1]=mPos2;
        cout<<"Chosen meanings: "<<mPos1<<", "<<mPos2<<endl;

        if (wPos1+2<lengthOfSentence)
            analyzeTwoWords(wPos1+1, mPos2, 0);
        else
            return 1;
    }
    else
    {
        if (mPos2+1<numberOfMeanings2)
            analyzeTwoWords(wPos1,mPos1,mPos2+1);
        else if (wPos1-1>=0)
        {
            if (mPos1+1<numberOfMeanings1)
               {
                   analyzeTwoWords(wPos1-1,chosenMeanings[wPos1-1],mPos1+1);
               }
            else
                return -1;

        }
        else if (mPos1+1<numberOfMeanings1)
            analyzeTwoWords(wPos1,mPos1+1,0);
        else
        {
            return -1;
        }
    }
    return 1;
}

int Sentence::verbVSverb(Meaning& m1,  Meaning& m2)
{
    if (!m1.getFuture().compare("bedzie"))
        return 3;
    else
        return 0;
}

int Sentence::substVSverb(Meaning& m1, Meaning& m2)
{
    int matching=0;
    if (!(m2.getBasicForm().compare("byæ") || m1.getGrammarCase().compare("nom")))
        return 3;
    else
    {
        matching+=compareGenders(m1.getGender(),m2.getGender());
        matching+=compareNumbers(m1.getNumber(),m2.getNumber());
        matching+=compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase());
    }

    return matching;
}

int Sentence::prepVSall(Meaning& m1,Meaning& m2)
{
    if (compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase())==1)
        return 3;
    else
        return 0;
}

int Sentence::substVSadj(Meaning& m1,Meaning& m2)
{
    if (!(m1.getGrammarCase().compare("loc") || m2.getGrammarCase().compare("gen")))
        return 3;
    else
        return 0;
}

int Sentence::adjVSall(Meaning& m1, Meaning& m2)
{
    int matching=0;
    if(!m2.getPartOfSpeech().compare("verb"))
        return 0;
    else if (!m2.getPartOfSpeech().compare("subst")||!m2.getPartOfSpeech().compare("adj"))
    {
        matching+=compareGenders(m1.getGender(),m2.getGender());
        matching+=compareNumbers(m1.getNumber(),m2.getNumber());
        matching+=compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase());
    }
    return matching;
}

int Sentence::substVSsubst(Meaning& m1, Meaning& m2)
{
    int matching=0;
    if(!m2.getGrammarCase().compare("gen"))
        matching++;
    else if(!(m1.getGrammarCase().compare("acc")||m2.getGrammarCase().compare("dat")))
        matching++;
    else if(!(m1.getGrammarCase().compare("nom")||m2.getGrammarCase().compare("dat")))
        matching++;
    else if(!(m1.getGrammarCase().compare("dat")||m2.getGrammarCase().compare("acc")))
        matching++;

    matching+=compareNumbers(m1.getNumber(),m2.getNumber());
    matching+=compareGenders(m1.getGender(),m2.getGender());

    return matching;

}

int Sentence::compareGenders(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return 1;
    else
    {
        if (!s1.compare(s2))
            return 1;
    }
    return 0;
}

int Sentence::compareNumbers(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return 1;
    else
    {
        if (!s1.compare(s2))
            return 1;
    }
    return 0;
}

int Sentence::compareGrammarCases(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return 1;
    else
    {
        if (!s1.compare(s2))
            return 1;
    }
    return 0;
}


