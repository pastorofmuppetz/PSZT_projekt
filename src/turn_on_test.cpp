#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void){
	system("chcp 1250");
	system("java -jar morfologik-tools-2.1.0/lib/morfologik-tools-2.1.0.jar dict_apply -d polish.dict > out.txt");
	//@up ścieżka, przy założeniu, że morfologik jest w tym samym katalogu co plik odpalający
	return 0;
}