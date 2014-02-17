<?php

namespace UEPG;

class PA {

	/**
	 * Primeiro termo
	 * @var int
	 */
	private $firstTerm;

	/**
	 * Fator
	 * @var int
	 */
	private $ratio;

	/**
	 * Número de termos
	 * @var int
	 */
	private $nTerms;

	/**
	 * Construtor
	 */
	public function __construct ($ft, $r, $nt) {

		$this->setFirstTerm($tf);
		$this->setRatio($r);
		$this->setNumTerms($nt);

	}

	/**
	 * Getters & Setters
	 */
	public function setFirstTerm($ft) {

		if(!is_numeric($ft))
			throw new \InvalidArgumentException('O valor precisa ser numérico');

		$this->firstTerm = (int) $ft;

	}

	public  function getFirstTerm() {

		return $this->firstTerm;

	}

	public setRatio($r) {

		if(!is_numeric($r))
			throw new \InvalidArgumentException('O valor precisa ser numérico');

		$this->ratio = (int) $r;
	}

	public  function getRatio() {

		return $this->ratio;

	}

	public function setNumTerms($nt) {

		/**
		 * Faz a vez de if($nt <= 0)
		 */
		if(empty($nt))
			throw new \InvalidArgumentException('O valor não pode ser vazio');

		if(!is_numeric($nt))
			throw new \InvalidArgumentException('O valor precisa ser numérico');

		$this->nTerms = (int) $nt;

	}

	public function getNumTerms() {

		return $this->nTerms;

	}


	/**
	 * Métodos de negócio
	 */
	public function getNthTerm() {

		return $this->firstTerm + ($this->nTerms - 1) * $this->ratio;

	}

	public function getSum() {

		return ($this->nTerms * ($this->firstTerm * $this->getNthTerm())) / 2;

	}

}
