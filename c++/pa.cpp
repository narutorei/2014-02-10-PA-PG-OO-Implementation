#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class PA {

	protected:
		/**
		 * Primeiro termo
		 * @var float
		 */
		float firstTerm;

		/**
		 * Fator
		 * @var float
		 */
		float ratio;

		/**
		 * Número de termos
		 * @var float
		 */
		float nTerms;

	public:

		PA() {}

		/**
		 * Construtor
		 */
		PA (float ft, float r, float nt) {

			setFirstTerm(ft);
			setRatio(r);
			setNumTerms(nt);

		}

		/**
		 * Getters & Setters
		 */
		void setFirstTerm(float ft) {

			this->firstTerm = (float) ft;

		}

		float getFirstTerm() {

			return firstTerm;

		}

		void setRatio(float r) {

			this->ratio = (float) r;

		}

		float getRatio() {

			return ratio;

		}

		void setNumTerms(float nt) throw (float) {

			// Lança uma exceção se o número de termos for menor ou igual que zero
			if(nt <= 0)
				throw 1;

			this->nTerms = (float) nt;

		}

		float getNumTerms() {

			return this->nTerms;

		}


		/**
		 * Métodos de negócio
		 */
		float getNthTerm() {

			return this->firstTerm + (this->nTerms - 1.0) * this->ratio;

		}

		float getSum() {

			return (this->nTerms * (this->firstTerm * getNthTerm())) / 2.0;

		}

};