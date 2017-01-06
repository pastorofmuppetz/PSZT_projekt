#include <list>
#include "Meaning.h"
using namespace std;

Meaning::Meaning(string partOfSpeech, string number, string grammarCase, string degree, string gender, string person, string negation, string verbForm, string done, string infinitive)
{
    setPartOfSpeech(partOfSpeech);
    setNumber(number);
    setGrammarCase(grammarCase);
    setDegree(degree);
    setGender(gender);
    setPerson(person);
    setNegation(negation);
    setVerbForm(verbForm);
    setDone(done);
    setInfinitive(infinitive);
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




/*Meaning::Meaning(PartOfSpeech partOfSpeech, Number number, GrammarCase grammarCase, Degree degree, Gender gender, Person person, Negation negation, VerbForm verbForm, Done done, Infinitive infinitive)
{
    setPartOfSpeech(partOfSpeech);
    setNumber(number);
    setGrammarCase(grammarCase);
    setDegree(degree);
    setGender(gender);
    setPerson(person);
    setNegation(negation);
    setVerbForm(verbForm);
    setDone(done);
    setInfinitive(infinitive);
}

PartOfSpeech Meaning::getPartOfSpeech()
{
    return Meaning::partofspeech_;
}
bool Meaning::setPartOfSpeech(PartOfSpeech partOfSpeech)
{
    Meaning::partofspeech_=partOfSpeech;
    return 1;
}

Number Meaning::getNumber()
{
    return Meaning::number_;
}
bool Meaning::setNumber(Number number)
{
    Meaning::number_=number;
    return 1;
}

GrammarCase Meaning::getGrammarCase()
{
    return Meaning::grammarcase_;
}
bool Meaning::setGrammarCase(GrammarCase grammarCase)
{
    Meaning::grammarcase_=grammarCase;
    return 1;
}

Degree Meaning::getDegree()
{
    return Meaning::degree_;
}
bool Meaning::setDegree(Degree degree)
{
    Meaning::degree_=degree;
    return 1;
}

Gender Meaning::getGender()
{
    return Meaning::gender_;
}
bool Meaning::setGender(Gender gender)
{
    Meaning::gender_=gender;
    return 1;
}

Person Meaning::getPerson()
{
    return Meaning::person_;
}
bool Meaning::setPerson(Person person)
{
    Meaning::person_=person;
    return 1;
}

Negation Meaning::getNegation()
{
    return Meaning::negation_;
}
bool Meaning::setNegation(Negation negation)
{
    Meaning::negation_=negation;
    return 1;
}

VerbForm Meaning::getVerbForm()
{
    return Meaning::verbform_;
}
bool Meaning::setVerbForm(VerbForm verbForm)
{
    Meaning::verbform_=verbForm;
    return 1;
}

Done Meaning::getDone()
{
    return Meaning::done_;
}
bool Meaning::setDone(Done done)
{
    Meaning::done_=done;
    return 1;
}

Infinitive Meaning::getInfinitive()
{
    return Meaning::infinitive_;
}
bool Meaning::setInfinitive(Infinitive infinitive)
{
    Meaning::infinitive_=infinitive;
    return 1;
}*/

