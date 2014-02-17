#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

class PG: public PA {

	public:
		float getNthTerm() {
			return this->firstTerm * pow(this->ratio, this->nTerms - 1.0);
		}

		float getSum() {
			return this->firstTerm * ((1.0 - pow(this->ratio, this->nTerms)) / (1.0 - this->ratio));
		}

};