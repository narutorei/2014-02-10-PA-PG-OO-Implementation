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

		/**
		 * Calcula o enézimo termo
		 * @return o enézimo termo calculado
		 */
		virtual float calculateNthTerm() {
			return this->firstTerm + (this->nTerms - ONE) * this->ratio;
		}

		/**
		 * Calcula a soma da PA
		 * @return a soma da PA
		 */
		virtual float calculateSum() {
			return (this->nTerms * (this->firstTerm * this->getNthTerm())) / TWO;
		}


	public:

		/**
		 * Tipo de PA, crescente
		 */
		const static unsigned TYPE_CRESCENT = 1;

		/**
		 * Tipo de PA, decrescente
		 */
		const static unsigned TYPE_DECRESCENT = 2;

		/**
		 * Tipo de PA, constante
		 */
		const static unsigned TYPE_CONSTANT = 3;

		/**
		 * Constante para a exceção de número de termos inválido
		 */
		const static unsigned EXCEPTION_INVALID_NUM_TERMS = 1;

		/**
		 * Constante para a exceção para tipo inválido
		 */
		const static unsigned EXCEPTION_INVALID_TYPE = 2;

		/**
		 * Construtor sem inicialização
		 */
		PA() {}

		/**
		 * Construtor para inicializar todas as variáveis de uma vez
		 */
		PA (float ft, float r, float nt) {

			this->setFirstTerm(ft);
			this->setRatio(r);
			this->setNumTerms(nt);

		}

		/**
		 * Getters & Setters
		 */

		/**
		 * Setter para o primeiro termo
		 * @param ft Primeiro termo
		 */
		void setFirstTerm(float ft) {

			this->setUpdated(true);

			this->firstTerm = (float) ft;

		}

		/**
		 * Getter do primeiro termo
		 * @return o primeiro termo
		 */
		float getFirstTerm() {

			return this->firstTerm;

		}

		/**
		 * Setter do da razão
		 * @param r Razão
		 */
		void setRatio(float r) {

			this->setUpdated(true);

			this->ratio = (float) r;

		}

		/**
		 * Getter da razão
		 * @return a Razão
		 */
		float getRatio() {

			return this->ratio;

		}

		/**
		 * Setter do número de termos da PA
		 * @param float o número de termos
		 * @throws lança uma exceção se o número de termos for negativo ou igual à zero
		 */
		void setNumTerms(float nt) {

			// Lança uma exceção se o número de termos for menor ou igual que zero
			if(nt <= 0)
				throw 1;

			this->setUpdated(true);

			this->nTerms = (float) nt;

		}

		/**
		 * Getter do número de termos
		 * @return o número de termos
		 */
		float getNumTerms() {

			return this->nTerms;

		}

		/**
		 * Setter do estado do objeto, para o lazy loading dos cálculos
		 * @param u true|false true para atualizado, false para não atualizado
		 */
		void setUpdated(bool u) {
			this->updated = u;
		}

		/**
		 * Getter de updated
		 * @return se foi atualizado ou não
		 */
		bool getUpdated() {
			return this->updated;
		}


		/**
		 * Métodos de negócio
		 */

		/**
		 * Retorna o N termo, por lazy loading
		 * @return o enézimo termo, definido por nTerms,
		 *           calculado por lazy loading
		 */
		float getNthTerm() {

			if(this->updated || this->resultNth == ZERO)
				this->resultNth = this->calculateNthTerm();

			return this->resultNth;

		}

		/**
		 * Getter da soma da pa, calculada por lazy loading
		 * @return a soma da pa, calculado por lazy loading
		 */
		float getSum() {

			if(this->updated || this->resultSum == ZERO)
				this->resultSum = this->calculateSum();

			return this->resultSum;

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