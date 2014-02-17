#include <iostream>
#include "pa.cpp"
#include "pg.cpp"

void printSame(PA *pa_pg) {
	float input = 0.0;

	std::cout << "Escreva os dados para a Progressão:\n";

	std::cout << "Primeiro termo: ";
	std::cin >> input;
	pa_pg->setFirstTerm(input);
	std::cout << '\n';

	std::cout << "Fator: ";
	std::cin >> input;
	pa_pg->setRatio(input);
	std::cout << '\n';

	std::cout << "Número de termos: ";
	std::cin >> input;
	pa_pg->setNumTerms(input);
	std::cout << '\n';

	std::cout << "O " << pa_pg->getNumTerms() << " termo é: " << pa_pg->getNthTerm() << "\n";

	std::cout << "A soma dos termos é " << pa_pg->getSum() << "\n";
}

int main()
{

	PA pa1;
	PG pg1;
	printSame(&pa1);

	printSame(&pg1);

	return 0;
}