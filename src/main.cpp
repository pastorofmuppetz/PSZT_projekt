#include "Sentence.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

int main(int argc, char *argv[])
{
    system("chcp 1250");
    int check;
    //tu docelowo wczytywanie czystego zdania i odpalanie morfologika

    //Wczytywanie przetworzonego zdania
    for(int i=0; i<argc; ++i)
        cout<<argv[i]<<endl;

    if (argc<2)
        check=sentenceToBeProcessed->readProcessedFile((char*)"morfologik-tools-2.1.0/lib/toAnalyze.txt");
    else
        check=sentenceToBeProcessed->readProcessedFile(argv[1]);

    if (check==false)
    {
        cout<<"We're so sorry, but the file does not contain proper Morfologik's output"<<endl;
        return 0;
    }

    int result=sentenceToBeProcessed->analyze();

    if (result==-1)
    {
        cout<<"We're so sorry, but something went terribly wrong"<<endl;
        return 0;
    }
    if (result==0)
    {
        cout<<"We're sorry, but it's a single word, not a sentence"<<endl;
        return 0;
    }
    if (result==-2)
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
