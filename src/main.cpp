#include "Sentence.h"

using namespace std;

Sentence* sentenceToBeProcessed=new Sentence();

int main(int argc, char *argv[])
{
    //initializing polish characters in console
    system("chcp 1250");
    int check;

    //chcecking wether we're given a file name or not and reading the file
    if (argc<2)
        check=sentenceToBeProcessed->readProcessedFile((char*)"morfologik-tools-2.1.0/lib/toAnalyze.txt");
    else
        check=sentenceToBeProcessed->readProcessedFile(argv[1]);

    //if there's wrong content in the file
    if (check==false)
    {
        cout<<endl<<"We're so sorry, but the file does not contain proper Morfologik's output"<<endl;
        return 0;
    }

    //analyzing the sentence
    int result=sentenceToBeProcessed->analyze();

    //analyzing ended without the conclusion
    if (result==-1)
    {
        cout<<endl<<"We're so sorry, but something went terribly wrong"<<endl;
        cout<<"There are two possible explanations:"<<endl;
        cout<<"1. The sentence is not grammatically correct"<<endl;
        cout<<"2. This program is not as good as its makers thought it was"<<endl;
        return 0;
    }

    //there was no sentence in the file, but a single word
    if (result==0)
    {
        cout<<endl<<"We're sorry, but it's a single word, not a sentence"<<endl;
        return 0;
    }

    //everything went fine and we have the results
    cout<<endl<<"Your sentence is: "<<sentenceToBeProcessed->getSentence()<<endl;
    cout<<endl<<"Chosen meanings are given below: "<<endl;
    cout<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;
    sentenceToBeProcessed->writeResultToFile();
    cout<<endl<<"You can also check them in file 'results.txt' if you wish."<<endl;

    cout<<endl<<endl<<"Thank you for using our program. See you soon!"<<endl;

    return 0;
}
