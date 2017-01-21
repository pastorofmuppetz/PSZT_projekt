#include "Sentence.h"

//tables with possible Morfologik's tags
string PartOfSpeech[]= { "adj", "adja", "adjc", "adjp", "adv", "burk", "depr", "ger", "conj", "comp", "num", "pact", "pant",
                         "pcon", "ppas", "ppron12", "ppron3", "pred", "prep", "siebie", "subst", "verb", "brev", "interj", "qub"
                       };
string Number[]= {"sg", "pl"};
string GrammarCase[]= {"nom", "gen", "acc", "dat", "inst", "loc", "voc"};
string Degree[]= {"pos", "com", "sup"};
string Gender[]= {"m1", "m2", "m3", "n1", "n2", "p1", "p2", "p3", "f"};
string Person[]= {"pri", "sec", "ter"};
string Negation[]= {"aff", "neg"};
string VerbForm[]= {"refl", "nonrefl", "refl_nonrefl"};
string Done[]= {"perf", "imperf", "imperf_perf"};
string Infinitive[]= {"inf"};

//getting word of given position in the sentence
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

//adding word at the end of the sentence
bool Sentence::addWord(Word& word)
{
    Sentence::listOfWords_.push_back(word);
    return 1;
}

//removing word of given position from the sentence
bool Sentence::removeWord(int pos)
{
    std::list<Word>::iterator iter=Sentence::listOfWords_.begin();
    for (int i=0; i<pos; i++)
        iter++;
    Sentence::listOfWords_.erase(iter);
    return 1;
}

//analyzing sentence in order to chose proper meanings of the words
int Sentence::analyze(void)
{
    //if there's only one word => nothing to analyze, because it's not a sentence
    if (Sentence::listOfWords_.size()==1)
        return 0;

    //if analyzing ended without the conclusion
    if (analyzeTwoWords(0,0,0)==-1)
        return -1;

    return 1;
}

//returns senstence as string
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

//returns sentence with chosen meanings as string (each word with meaning in new line)
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

//comparing meanings of two neighbouring words
int Sentence::compareMeanings(Meaning& m1, Meaning& m2)
{
    int matching=0;
    string atribute1;
    string atribute2;
    string partOfSpeech1=m1.getPartOfSpeech();
    string partOfSpeech2=m2.getPartOfSpeech();

    //checking which rule should be applied to given pair of meanings
    if (!(partOfSpeech1.compare("qub")&&partOfSpeech2.compare("qub")))
        return 0;

    if (!(partOfSpeech1.compare("verb")||partOfSpeech2.compare("verb")))
        return verbVSverb(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("verb")))
        return substVSverb(m1, m2);

    if (!partOfSpeech1.compare("brev")||!partOfSpeech2.compare("brev"))
        return 0;

    if (!partOfSpeech1.compare("interj")||!partOfSpeech2.compare("interj"))
        return 0;

    if (!partOfSpeech1.compare("adja")||!partOfSpeech2.compare("adja"))
        return 0;

    if (!partOfSpeech1.compare("prep"))
        return prepVSall(m1, m2);

    if (!partOfSpeech2.compare("prep"))
        return allVSprep(m1, m2);

    if (!partOfSpeech1.compare("ger"))
        return gerVSall(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("adj")))
        return substVSadj(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("ppas")))
        return substVSadj(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("pact")))
        return substVSadj(m1, m2);

    if (!(partOfSpeech1.compare("subst")||partOfSpeech2.compare("subst")))
        return substVSsubst(m1, m2);

    if (!(partOfSpeech1.compare("verb")||partOfSpeech2.compare("subst")))
        return verbVSsubst(m1, m2);

    if (!partOfSpeech1.compare("adj")||!partOfSpeech1.compare("ppas")||!partOfSpeech1.compare("pact"))
        return adjVSall(m1, m2);

    //if no rule matches, checking the gender, number and grammar case of the meanings
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

//recursive function for analyzing two neighbouring words with their meanings
//input: first word position, first word meaning to be analyzed position, second word meaning to be analyzed position
int Sentence::analyzeTwoWords(int wPos1, int mPos1, int mPos2)
{
    static int liczba=1;
    liczba++;
    int lengthOfSentence=listOfWords_.size();
    Word w1=getWord(wPos1);
    Word w2=getWord(wPos1+1);
    int numberOfMeanings1=w1.getNumberOfMeanings();
    int numberOfMeanings2=w2.getNumberOfMeanings();
    Meaning m1=w1.getMeaning(mPos1);
    Meaning m2=w2.getMeaning(mPos2);
    if (compareMeanings(m1,m2)==3)
    {
        chosenMeanings[wPos1]=mPos1;
        chosenMeanings[wPos1+1]=mPos2;

        if (wPos1+2<lengthOfSentence)
        {
            if (analyzeTwoWords(wPos1+1, mPos2, 0)==-1)
                return -1;
        }
        else
            return 1;
    }
    else
    {
        if (mPos2+1<numberOfMeanings2)
        {
            if (analyzeTwoWords(wPos1,mPos1,mPos2+1)==-1)
                return -1;
        }
        else if (wPos1-1>=0)
        {
            if (mPos1+1<numberOfMeanings1)
            {
                if (analyzeTwoWords(wPos1-1,chosenMeanings[wPos1-1],mPos1+1)==-1)
                    return -1;
            }
            else
                return -1;

        }
        else if (mPos1+1<numberOfMeanings1)
        {
            if (analyzeTwoWords(wPos1,mPos1+1,0)==-1)
                return -1;
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

//rule for verb following another verb
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::verbVSverb(Meaning& m1,  Meaning& m2)
{
    //one verb can follow another only in complex future tense
    if (!m1.getFuture().compare("bedzie"))
        return 3;
    else
        return 0;
}

//rule for verb following substantive
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::substVSverb(Meaning& m1, Meaning& m2)
{
    int matching=0;
    matching+=compareGenders(m1.getGender(),m2.getGender());
    matching+=compareNumbers(m1.getNumber(),m2.getNumber());
    matching+=compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase());

    return matching;
}

//rule for preposition before another words
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::prepVSall(Meaning& m1,Meaning& m2)
{
    //grammar case of preposition is pointing the grammar case of the word that's following it
    if (!m2.getPartOfSpeech().compare("verb"))
        return 0;
    if (compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase())==1)
        return 3;
    return 0;
}

//rule for preposition following another word
//return 3 - it's always matching
int Sentence::allVSprep(Meaning& m1, Meaning& m2)
{
    return 3;
}

//rule for adjective following substantive
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::substVSadj(Meaning& m1,Meaning& m2)
{
    int matching=2;

    if(compareGrammarCases(m2.getGrammarCase(),"gen"))
        matching++;
    else if(compareGrammarCases(m1.getGrammarCase(),"acc")&&compareGrammarCases(m2.getGrammarCase(),"dat"))
        matching++;
    else if(compareGrammarCases(m1.getGrammarCase(),"dat")&&compareGrammarCases(m2.getGrammarCase(),"acc"))
        matching++;
    return matching;
}

//rule for adjective following another word
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::adjVSall(Meaning& m1, Meaning& m2)
{
    int matching=0;
    if(!m2.getPartOfSpeech().compare("verb"))
        return 0;
    else if (!m2.getPartOfSpeech().compare("subst")||!m2.getPartOfSpeech().compare("adj")||!m2.getPartOfSpeech().compare("ppas")||!m2.getPartOfSpeech().compare("pact"))
    {
        matching+=compareGenders(m1.getGender(),m2.getGender());
        matching+=compareNumbers(m1.getNumber(),m2.getNumber());
        matching+=compareGrammarCases(m1.getGrammarCase(),m2.getGrammarCase());
    }
    return matching;
}

//rule for substantive following another substantive
//return 3 - meanings are matching; return less than 3 - not matching;
int Sentence::substVSsubst(Meaning& m1, Meaning& m2)
{
    int matching=2;

    //rules for grammar cases consistency
    if(compareGrammarCases(m2.getGrammarCase(),"gen"))
        matching++;
    else if(compareGrammarCases(m1.getGrammarCase(),"acc")&&compareGrammarCases(m2.getGrammarCase(),"dat"))
        matching++;
    else if(compareGrammarCases(m1.getGrammarCase(),"dat")&&compareGrammarCases(m2.getGrammarCase(),"acc"))
        matching++;

    return matching;
}


//rule for substantive following verb
//return 3 - meanings are matching; return less than 3 - not matching;
int Sentence::verbVSsubst(Meaning& m1, Meaning& m2)
{
    int matching=2;
    if(!m1.getBasicForm().compare("być"))
    {
        if(compareGrammarCases(m2.getGrammarCase(),"nom")|| compareGrammarCases(m2.getGrammarCase(),"inst"))
            matching++;
    }
    else
    {
        if(compareGrammarCases(m2.getGrammarCase(),"nom"))
            return 0;
        if(compareGrammarCases(m2.getGrammarCase(),"voc"))
            return 0;
        matching++;
    }

    return matching;
}

//rule for gerand before another word
//return 3 - meanings are matching; return 0 - not matching;
int Sentence::gerVSall(Meaning& m1, Meaning& m2)
{
    if (compareGrammarCases(m2.getGrammarCase(),"nom")||compareGrammarCases(m2.getGrammarCase(),"loc"))
    {
        return 0;
    }
    else
        return 3;
}

//comparing two genders given as strings
//they can be given as "m1.m2.m3" so we must extract the parts between dots
int Sentence::compareGenders(string s1, string s2)
{
    int k=0;
    if (s1.empty() || s2.empty())
        return 1;
    else
    {
        k=s1.find(".");
        if (k>=0)
        {
            while (k>=0)
            {
                if(s2.find(s1.substr(0,k))!=-1)
                    return 1;
                s1=s1.substr(k+1);
                k=s1.find(".");
            }
        }
        else
        {
            if (s2.find(s1)!=-1)
                return 1;
        }
    }
    return 0;
}

//comparing two numbers given as strings
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

//comparing two grammar cases given as strings
//they can be given as "nom.voc" so we must extract the parts between dots
int Sentence::compareGrammarCases(string s1, string s2)
{
    int k=0;
    if (s1.empty() || s2.empty())
        return 1;
    else
    {
        k=s1.find(".");
        if (k>=0)
        {
            while (k>=0)
            {
                if(s2.find(s1.substr(0,k))!=-1)
                    return 1;
                s1=s1.substr(k+1);
                k=s1.find(".");
            }
        }
        else
        {
            if (s2.find(s1)!=-1)
                return 1;
        }
    }
    return 0;
}

//reading the sentence from the file
bool Sentence::readProcessedFile(char* arg)
{
    Word* w=new Word();
    Meaning m;
    string previousWord="";
    string currentWord;
    string line;
    string basicForm;

    int position=0;
    static int init=1;

    //opening file to read from
    ifstream processedSentenceFile;
    processedSentenceFile.exceptions(ifstream::failbit);

    try
    {
        processedSentenceFile.open(arg);
    }
    catch(exception& e)
    {
        cerr<<"File does not exist.\nException caught: "<<e.what()<<endl;
    }
    processedSentenceFile.exceptions(ifstream::failbit & ifstream::badbit);

    if (processedSentenceFile.peek() == std::ifstream::traits_type::eof())
        return false;

    //analyzing file line after line
    while (!processedSentenceFile.eof())
    {
        getline(processedSentenceFile,line);
        if (!(line.find("[not found]")==-1))
            return false;

        //isolating word
        int i=line.find(" ");
        currentWord=line.substr(0,i);
        if (init)
        {
            w->setWord(currentWord);
            w->setPosition(position);
            position++;
        }

        //checking whether it's a new one or only another meaning (creating word or not)
        if (currentWord.compare(previousWord))
        {
            if (!init)
            {
                this->addWord(*w);
                w=new Word();
                w->setWord(currentWord);
                w->setPosition(position);
                position++;
            }
            else
                init=0;
        }

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
            return true;

        //isolating meanings & adding it to list of meanings in the word
        while (i>=0)
        {
            i=line.find("+");
            if (i>=0)
            {
                w->addMeaning(*isolateMembers(line.substr(0,i), basicForm));
                line=line.substr(i+1);
            }
            else
                w->addMeaning(*isolateMembers(line, basicForm));
        }
        previousWord=currentWord;

    }
    this->addWord(*w);

    //closing  file
    processedSentenceFile.close();

    return true;
}


//writing results of analyzing to file
bool Sentence::writeResultToFile()
{
    ofstream resultFile;
    resultFile.open("results.txt");
    resultFile<<this->getSentence()<<endl<<endl;
    resultFile<<this->getSentenceWithMeanings();

    resultFile.close();
    return 1;
}

//isolating valuable information from line
Meaning* Sentence::isolateMembers(string atributes, string basicForm)
{
    Meaning* m = new Meaning();
    int i=0;
    int k=0;

    m->setAll(atributes);

    //isolating members of vital part of the line
    do
    {
        i=atributes.find(":");

        for (int j=0; j<sizeof(PartOfSpeech)/sizeof(*PartOfSpeech); j++)
        {
            if (!atributes.substr(0,i).compare(PartOfSpeech[j]))
            {
                m->setPartOfSpeech(PartOfSpeech[j]);
            }
        }

        for (int j=0; j<sizeof(Number)/sizeof(*Number); j++)
        {
            if (!atributes.substr(0,i).compare(Number[j]))
            {
                m->setNumber(Number[j]);
            }

        }

        int p=1;
        for (int j=0; j<sizeof(GrammarCase)/sizeof(*GrammarCase); j++)
        {
            if (atributes.substr(0,i).find(GrammarCase[j])!=-1 &&p)
            {
                m->setGrammarCase(atributes.substr(0,i));
                p=0;
            }
        }

        p = 1;
        for (int j=0; j<sizeof(Gender)/sizeof(*Gender); j++)
        {
            if ((atributes.substr(0,i).find(Gender[j])!=-1) && p)
            {
                string temp=atributes.substr(0,i);
                if (temp.find("aff")!=-1 || temp.find("refl")!=-1 || temp.find("perf")!=-1 || temp.find("inf")!=-1 || temp.find("fin")!=-1)
                {
                }
                else
                {
                    m->setGender(atributes.substr(0,i));
                    p = 0;
                }
            }
        }

        if (!atributes.substr(0,i).compare("bedzie"))
        {
            m->setFuture("bedzie");
        }

        atributes=atributes.substr(i+1);
    }
    while (i>=0);

    m->setBasicForm(basicForm);

    return m;
}

