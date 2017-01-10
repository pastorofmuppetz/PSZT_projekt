#define BOOST_TEST_MODULE boost_test_macro1
#include <boost/test/included/unit_test.hpp>
#include <string>
#include <iostream>
#include "Sentence.h"

BOOST_AUTO_TEST_CASE( test_proper_meanings )
{
	Sentence* sentenceToBeProcessed=new Sentence();
	system("chcp 1250");
	sentenceToBeProcessed->readProcessedFile();
	BOOST_TEST_REQUIRE(sentenceToBeProcessed->analyze()!=-1);
	BOOST_TEST_REQUIRE(sentenceToBeProcessed->analyze()!=0);
	std::string tmp="Kinga jest fajna ";
	 cout<<sentenceToBeProcessed->getSentence()<<endl;
	  cout<<sentenceToBeProcessed->getSentenceWithMeanings()<<endl;
	BOOST_TEST_CHECK(tmp==sentenceToBeProcessed->getSentence());
	//BOOST_TEST_CHECK(sentenceToBeProcessed->ge)
}