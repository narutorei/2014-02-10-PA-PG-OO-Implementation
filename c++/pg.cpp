#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ONE 1.0

class PG: public PA {

	private:
		/**
		 * Calcula o enézimo termo da PG, definido por nTerms
		 * @return enézimo termo calculado
		 */
		float calculateNthTerm() {
			return this->firstTerm * pow(this->ratio, this->nTerms - ONE);
		}

		/**
		 * Calcula a soma da PG
		 * @return a soma da PG calculada
		 */
		float calculateSum() {
			return this->firstTerm * ((ONE - pow(this->ratio, this->nTerms)) / (ONE - this->ratio));
		}

};