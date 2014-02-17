#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define ZERO 0.0
#define ONE 1.0
#define TWO 2.0

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
		float resultNth = ZERO;

		/**
		 * Resultado da soma
		 */
		float resultSum = ZERO;

		/**
		 * Guarda o estado do objeto
		 */
		bool updated;

	public:

		/**
		 * Tipo de PA, crescente
		 */
		const unsigned TYPE_CRESCENT = 1;

		/**
		 * Tipo de PA, decrescente
		 */
		const unsigned TYPE_DECRESCENT = 2;

		/**
		 * Tipo de PA, constante
		 */
		const unsigned TYPE_CONSTANT = 3;

		/**
		 * Constante para a exceção de número de termos inválido
		 */
		const unsigned EXCEPTION_INVALID_NUM_TERMS = 1;

		/**
		 * Constante para a exceção para tipo inválido
		 */
		const unsigned EXCEPTION_INVALID_TYPE = 2;

		/**
		 * Construtor sem inicialização
		 */
		PA() {}

		/**
		 * Construtor para inicializar todas as variáveis de uma vez
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

			if(this->updated || this->resultNth == ZERO)
				this->resultNth = this->calculateNthTerm();

			return this->resultNth;

		}

		float calculateNthTerm() {
			return this->firstTerm + (this->nTerms - ONE) * this->ratio;
		}

		float getSum() {

			if(this->updated || this->resultSum == ZERO)
				this->resultSum = this->calculateSum();

			return this->resultSum;

		}

		float calculateSum() {
			return (this->nTerms * (this->firstTerm * getNthTerm())) / TWO;
		}

		/**
		 * Verifica o tipo de PA
		 * @return unsigned int, o tipo de PA
		 * @throws 2, Tipo inválido de PA
		 */
		unsigned getType() {
			if(this->ratio > ZERO)
				return PA::TYPE_CRESCENT;
			else if(this->ratio < ZERO)
				return PA::TYPE_DECRESCENT;
			else if(this->ratio == ZERO)
				return PA::TYPE_CONSTANT;
			else
				throw 2;
		}

};