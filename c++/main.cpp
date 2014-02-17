#include <iostream>
#include "pa.cpp"
#include "pg.cpp"

void printSame(PA *pa_pg) {
	float input = 0.0;
	std::string tipo;

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

	switch(pa_pg->getType()) {
		case PA::TYPE_CRESCENT:
			tipo = "crescente";
			break;
		case PA::TYPE_DECRESCENT:
			tipo = "decrescente";
			break;
		case PA::TYPE_CONSTANT:
			tipo = "constante";
			break;
		default:
			tipo = "indefinido";
			break;
	}

	std::cout << "O tipo da Progressão é: " << tipo << '\n';
}

int main()
{

	PA pa1;
	PG pg1;

	try {
		printSame(&pa1);

		printSame(&pg1);
	} catch (int e) {
		if(e == PA::EXCEPTION_INVALID_NUM_TERMS) {
			std::cout << "Número de termos inválido. Abortando\n";
			exit(1);
		} else if(e == PA::EXCEPTION_INVALID_TYPE) {
			std::cout << "Tipo inválido, contate o suporte ;)";
			exit(1);
		} else throw e;
	}

	return 0;
}