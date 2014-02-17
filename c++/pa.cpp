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

		/**
		 * Resultado do N termo
		 */
		float resultNth = 0.0;

		/**
		 * Resultado da soma
		 */
		float resultSum = 0.0;

		/**
		 * Guarda o estado do objeto
		 */
		bool updated;

	public:

		/**
		 * Tipo de PA, crescente
		 */
		const int TYPE_CRESCENT = 1;

		/**
		 * Tipo de PA, decrescente
		 */
		const int TYPE_DECRECENT = 2;

		/**
		 * Tipo de PA, constante
		 */
		const int TYPE_CONSTANT = 3;

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

			this->setUpdated(true);

			this->firstTerm = (float) ft;

		}

		float getFirstTerm() {

			return firstTerm;

		}

		void setRatio(float r) {

			this->setUpdated(true);

			this->ratio = (float) r;

		}

		float getRatio() {

			return ratio;

		}

		void setNumTerms(float nt) throw (float) {

			// Lança uma exceção se o número de termos for menor ou igual que zero
			if(nt <= 0)
				throw 1;

			this->setUpdated(true);

			this->nTerms = (float) nt;

		}

		float getNumTerms() {

			return this->nTerms;

		}

		void setUpdated(bool u) {
			this->updated = u;
		}

		bool getUpdated() {
			return this->updated;
		}


		/**
		 * Métodos de negócio
		 */
		float getNthTerm() {

			if(this->updated || this->resultNth == 0.0)
				this->resultNth = this->calculateNthTerm();

			return this->resultNth;

		}

		float calculateNthTerm() {
			return this->firstTerm + (this->nTerms - 1.0) * this->ratio;
		}

		float getSum() {

			if(this->updated || this->resultSum == 0.0)
				this->resultSum = this->calculateSum();

			return this->resultSum;

		}

		float calculateSum() {
			return (this->nTerms * (this->firstTerm * getNthTerm())) / 2.0;
		}

};