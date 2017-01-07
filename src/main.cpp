#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Sentence.h"
#include "strings.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

bool readProcessedFile();
Meaning* isolateMembers(string atributes, string basicForm);

int main()
{
    system("chcp 1250");
    //tu docelowo wczytywanie czystego zdania i odpalanie morfologika
    //Wczytywanie przetworzonego zdania
    readProcessedFile();

    cout<<endl<<sentenceToBeProcessed->getSentence()<<endl;
    cout<<endl<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;

    cout << endl<<"Thank you for using the service of PKP Intercity." << endl;

    return 0;
}

bool readProcessedFile()
{
    Word* w=new Word();
    Meaning m;
    string previousWord="";
    string currentWord;
    string line;
    string basicForm;

    int counter=0;
    static int init=1;

    //open file to read from
    ifstream processedSentenceFile;
    processedSentenceFile.open("sentences_test/2.txt");

    //analyzing file line after line
    while (!processedSentenceFile.eof())
    {
        getline(processedSentenceFile,line);

        //isolating word
        int i=line.find(" ");
        currentWord=line.substr(0,i);
        if (init)
            w->setWord(currentWord);

        //checking whether it's a new one or only another meaning (creating word or not)
        if (currentWord.compare(previousWord))
        {
            if (!init)
            {
                sentenceToBeProcessed->addWord(*w);
                w=new Word();
                w->setWord(currentWord);
                w->setPositionOfChosenMeaning(0);   //DO USUNIÊCIA PO OGARNIÊCIU FUNKCJI Sentence::analyze();
                counter=0;
            }
            else
                init=0;
        }
        else
            counter++;

        //isolating the valuable part of line
        if (i>=0)
        {
            line=line.substr(i+1);
            i=line.find(" ");
            if (i>=0)
            {
                line=line.substr(i+1);
                i=line.find(" ");
                if (i>=0)
                {
                    basicForm=line.substr(0,i);
                    line=line.substr(i+1);
                }
            }
        }

        //checking if everything went fine
        i=0;
        if (currentWord.empty()||line.empty())
            return 0;

        //isolating meanings & adding it to list of meanings in the word
        while (i>=0)
        {
            i=line.find("+");
            if (i>=0)
            {
                w->addMeaning(*isolateMembers(line.substr(0,i), basicForm));
                line=line.substr(i+1);
                counter++;
            }
            else
                w->addMeaning(*isolateMembers(line, basicForm));
        }

        cout<<"current word: "<<currentWord<<endl;
        m=w->getMeaning(counter);
        cout<<"part of speech: "<<m.getPartOfSpeech()<<endl;
        cout<<line<<endl<<endl;
        previousWord=currentWord;

    }
    sentenceToBeProcessed->addWord(*w);

    //close file
    processedSentenceFile.close();
}

Meaning* isolateMembers(string atributes, string basicForm)
{
    Meaning* m = new Meaning();
    int i=0;
    int k=0;

    m->setAll(atributes);

    //isolating members of vital part of the line
    do
    {
        i=atributes.find(":");
        k=atributes.find(".");

        //if . occures, ignoring the info right after it, before :
        if (k<i && k>=0)
            i=k;

        for (int j=0; j<sizeof(PartOfSpeech)/sizeof(*PartOfSpeech);j++)
        {
            if (!atributes.substr(0,i).compare(PartOfSpeech[j]))
            {
                //cout<<"Yay, to sie zgadza: "<<PartOfSpeech[j]<<endl;
                m->setPartOfSpeech(PartOfSpeech[j]);
            }

        }
        for (int j=0; j<sizeof(Number)/sizeof(*Number);j++)
        {
            if (!atributes.substr(0,i).compare(Number[j]))
            {
                //cout<<"Yay, to sie zgadza: "<<Number[j]<<endl;
                m->setNumber(Number[j]);
            }

        }
        for (int j=0; j<sizeof(GrammarCase)/sizeof(*GrammarCase);j++)
        {
            if (!atributes.substr(0,i).compare(GrammarCase[j]))
            {
                //cout<<"Yay, to sie zgadza: "<<GrammarCase[j]<<endl;
                m->setGrammarCase(GrammarCase[j]);
            }

        }
        for (int j=0; j<sizeof(Gender)/sizeof(*Gender);j++)
        {
            if (!atributes.substr(0,i).compare(Gender[j]))
            {
                //cout<<"Yay, to sie zgadza: "<<Gender[j]<<endl;
                m->setGender(Gender[j]);
            }
        }

        if (k==i)
            i=atributes.find(":");


        atributes=atributes.substr(i+1);
    }
    while (i>=0);

    m->setBasicForm(basicForm);

    return m;
}
