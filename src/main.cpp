#include "Sentence.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

int main()
{
    system("chcp 1250");
    //tu docelowo wczytywanie czystego zdania i odpalanie morfologika

    //Wczytywanie przetworzonego zdania
    sentenceToBeProcessed->readProcessedFile();

    if (sentenceToBeProcessed->analyze()==-1)
    {
        cout<<"We're so sorry, but something went terribly wrong"<<endl;
        return 0;
    }
    if (sentenceToBeProcessed->analyze()==0)
    {
        cout<<"We're sorry, but it's a single word, not a sentence"<<endl;
        return 0;
    }

    cout<<endl<<sentenceToBeProcessed->getSentence()<<endl;
    cout<<endl<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;
    sentenceToBeProcessed->writeResultToFile();

    cout << endl<<"Thank you for using the service of PKP Intercity." << endl;

    return 0;
}
