#include <list>
#include "Meaning.h"
using namespace std;


Meaning::Meaning()
{

};

string Meaning::getAll()
{
    return Meaning::all_;
}
bool Meaning::setAll(string all)
{
    Meaning::all_=all;
    return 1;
}

string Meaning::getBasicForm()
{
    return Meaning::basicForm_;
}
bool Meaning::setBasicForm(string basicForm)
{
    Meaning::basicForm_=basicForm;
    return 1;
}

string Meaning::getPartOfSpeech()
{
    return Meaning::partofspeech_;
}
bool Meaning::setPartOfSpeech(string partOfSpeech)
{
    Meaning::partofspeech_=partOfSpeech;
    return 1;
}

string Meaning::getNumber()
{
    return Meaning::number_;
}
bool Meaning::setNumber(string number)
{
    Meaning::number_=number;
    return 1;
}

string Meaning::getGrammarCase()
{
    return Meaning::grammarcase_;
}
bool Meaning::setGrammarCase(string grammarCase)
{
    Meaning::grammarcase_=grammarCase;
    return 1;
}

string Meaning::getDegree()
{
    return Meaning::degree_;
}
bool Meaning::setDegree(string degree)
{
    Meaning::degree_=degree;
    return 1;
}

string Meaning::getGender()
{
    return Meaning::gender_;
}
bool Meaning::setGender(string gender)
{
    Meaning::gender_=gender;
    return 1;
}

string Meaning::getPerson()
{
    return Meaning::person_;
}
bool Meaning::setPerson(string person)
{
    Meaning::person_=person;
    return 1;
}

string Meaning::getNegation()
{
    return Meaning::negation_;
}
bool Meaning::setNegation(string negation)
{
    Meaning::negation_=negation;
    return 1;
}

string Meaning::getVerbForm()
{
    return Meaning::verbform_;
}
bool Meaning::setVerbForm(string verbForm)
{
    Meaning::verbform_=verbForm;
    return 1;
}

string Meaning::getDone()
{
    return Meaning::done_;
}
bool Meaning::setDone(string done)
{
    Meaning::done_=done;
    return 1;
}

string Meaning::getInfinitive()
{
    return Meaning::infinitive_;
}
bool Meaning::setInfinitive(string infinitive)
{
    Meaning::infinitive_=infinitive;
    return 1;
}

string Meaning::getFuture()
{
    return Meaning::future_;
}
bool Meaning::setFuture(string future)
{
    Meaning::future_=future;
    return 1;
}


