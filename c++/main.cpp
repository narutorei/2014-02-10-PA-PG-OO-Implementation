#include <iostream>
#include "pa.cpp"
#include "pg.cpp"

using namespace std;

int main()
{

	PA pa1;
	PG pg1;
	float input = 0.0;

	std::cout << "Escreva os dados para a PA:\n";

	std::cout << "Primeiro termo: ";
	std::cin >> input;
	pa1.setFirstTerm(input);
	std::cout << '\n';

	std::cout << "Fator: ";
	std::cin >> input;
	pa1.setRatio(input);
	std::cout << '\n';

	std::cout << "Número de termos: ";
	std::cin >> input;
	pa1.setNumTerms(input);
	std::cout << '\n';

	std::cout << "O " << pa1.getNumTerms() << " termo é: " << pa1.getNthTerm() << "\n";


	std::cout << "Escreva os dados para a PG:\n";

	std::cout << "Primeiro termo: ";
	std::cin >> input;
	pg1.setFirstTerm(input);
	std::cout << '\n';

	std::cout << "Fator: ";
	std::cin >> input;
	pg1.setRatio(input);
	std::cout << '\n';

	std::cout << "Número de termos: ";
	std::cin >> input;
	pg1.setNumTerms(input);
	std::cout << '\n';

	std::cout << "O " << pg1.getNumTerms() << " termo é: " << pg1.getNthTerm() << "\n";

	return 0;
}