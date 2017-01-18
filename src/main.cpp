#include "Sentence.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

int main(int argc, char *argv[])
{
    system("chcp 1250");
    int check;

    //Wczytywanie przetworzonego zdania

    if (argc<2)
        check=sentenceToBeProcessed->readProcessedFile((char*)"morfologik-tools-2.1.0/lib/toAnalyze.txt");
    else
        check=sentenceToBeProcessed->readProcessedFile(argv[1]);

    if (check==false)
    {
        cout<<endl<<"We're so sorry, but the file does not contain proper Morfologik's output"<<endl;
        return 0;
    }

    int result=sentenceToBeProcessed->analyze();

    if (result==-1)
    {
        cout<<endl<<"We're so sorry, but something went terribly wrong"<<endl;
        return 0;
    }
    if (result==0)
    {
        cout<<endl<<"We're sorry, but it's a single word, not a sentence"<<endl;
        return 0;
    }

    cout<<endl<<"Your sentence is: "<<sentenceToBeProcessed->getSentence()<<endl;
    cout<<endl<<"Chosen meanings are given below: "<<endl;
    cout<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;
    sentenceToBeProcessed->writeResultToFile();
    cout<<endl<<"You can also check them in file 'results.txt' if you wish."<<endl;

    cout<<endl<<endl<<"Thank you for using our program. See you soon!."<<endl;

    return 0;
}
