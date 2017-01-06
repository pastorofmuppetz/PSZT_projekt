#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Sentence.h"
#include "strings.h"

using namespace std;

Sentence sentenceToBeProcessed;

bool readProcessedFile();
bool isolateMembers(string atributes);

int main()
{
    system("chcp 1250");
    //tu docelowo wczytywanie czystego zdania i odpalanie morfologika
    //Wczytywanie przetworzonego zdania
    readProcessedFile();

    cout << endl<<"Hello world!" << endl;

    return 0;
}

bool readProcessedFile()
{
    string previousWord;
    string currentWord;
    string info;
    string line;

    int numberOfPluses=0;
    int pos=0;

    ifstream processedSentenceFile;
    processedSentenceFile.open("2.txt");

    while (!processedSentenceFile.eof())
    {
        getline(processedSentenceFile,line);
        int i=line.find(" ");
        currentWord=line.substr(0,i);

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
                    line=line.substr(i+1);
                }
            }
        }
        i=0;
        if (currentWord.empty()||line.empty())
            return 0;

        /* //zliczanie plusów dzia³ajace
        while (i>=0 && line.length()>pos)
        {

            i=line.find("+",pos);
            if (i>=0)
                numberOfPluses++;
            pos=i+1;
        }
        */

        while (i>=0)
        {
            i=line.find("+");
            if (i>=0)
            {
                isolateMembers(line.substr(0,i));
                line=line.substr(i+1);
                cout<<endl;
            }
            else
                isolateMembers(line);
        }
        cout<<"current word: "<<currentWord<<endl;
        cout<<line<<endl<<endl;
        previousWord=currentWord;
        numberOfPluses=0;
    }

    processedSentenceFile.close();
}

bool isolateMembers(string atributes)
{
    int i=0;
    int k=0;
    do
    {
        i=atributes.find(":");
        k=atributes.find(".");
        if (k<i && k>=0)
            i=k;
        for (int j=0; j<sizeof(PartOfSpeech)/sizeof(*PartOfSpeech);j++)
        {
            if (!atributes.substr(0,i).compare(PartOfSpeech[j]))
            cout<<"Yay, to sie zgadza: "<<PartOfSpeech[j]<<endl;
        }
        for (int j=0; j<sizeof(Number)/sizeof(*Number);j++)
        {
            if (!atributes.substr(0,i).compare(Number[j]))
            cout<<"Yay, to sie zgadza: "<<Number[j]<<endl;
        }
        for (int j=0; j<sizeof(GrammarCase)/sizeof(*GrammarCase);j++)
        {
            if (!atributes.substr(0,i).compare(GrammarCase[j]))
            cout<<"Yay, to sie zgadza: "<<GrammarCase[j]<<endl;
        }
        for (int j=0; j<sizeof(Gender)/sizeof(*Gender);j++)
        {
            if (!atributes.substr(0,i).compare(Gender[j]))
            cout<<"Yay, to sie zgadza: "<<Gender[j]<<endl;
        }

        atributes=atributes.substr(i+1);
    }
    while (i>=0);

}
