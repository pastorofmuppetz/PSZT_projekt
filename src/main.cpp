#include "Sentence.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

int main(int argc, char *argv[])
{
    system("chcp 1250");
    //tu docelowo wczytywanie czystego zdania i odpalanie morfologika

    //Wczytywanie przetworzonego zdania
    for(int i=0; i<argc; ++i)
        cout<<argv[i]<<endl;

    sentenceToBeProcessed->readProcessedFile(argv[1]);
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
    if (sentenceToBeProcessed->analyze()==-2)
    {
        cout<<"We're sorry, but none word in file"<<endl;
        return 0;
    }

    cout<<endl<<sentenceToBeProcessed->getSentence()<<endl;
    cout<<endl<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;
    sentenceToBeProcessed->writeResultToFile();

    cout << endl<<"Thank you for using the service of PKP Intercity." << endl;

    return 0;
}
