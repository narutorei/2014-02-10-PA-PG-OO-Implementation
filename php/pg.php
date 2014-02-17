<?php

namespace UEPG;

class PG extends PA {

	public function getNthTerm() {

		return $this->firstTerm * ($this->ratio ^ ($this->nTerms - 1));

	}

	public function getSum() {

		return $this->firstTerm * ((1 - ($this->ratio ^ $this->nTerms)) / (1 - $this->ratio));

	}

}