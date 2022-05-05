#include "../include/OdeModel.hpp"


/*
 *	Construtor da classe abstrata herdada pelas funções.
 *	@param numEquations		Número de equações que a função contém.
 */
ode::OdeModel::OdeModel(const int numEquations){
	this->numEquations = numEquations;
	
	float state[numEquations];
	this->state = state;
}