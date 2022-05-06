#include "../include/AlphaFunction.hpp"

/*
 *	Construtor da função alfa.
 *	@param state	Estado inicial da função.
 *	@param thau		O valor de tau (obs: ele calcula -1/tau dentro da função).
 *	@param weight	O peso da função.
 */
ode::AlphaFunction::AlphaFunction(const float state, const float thau, const float weight){
	this->state[0] = state;
	this->thau = (-1.0f/thau);
	this->weight = weight;
	this->numEquations = 1;
}

/*
 *	Faz o cálculo diferencial da função alfa.
 *	v' = tau*v+(I*peso)
 *	@param input	A corrente de entrada.
 *	@return			Um std::array contendo v' no index 0.
 */
std::array<float, MAX_EQUATIONS> ode::AlphaFunction::modelDiferentialEquation(const float input){
	std::array<float, MAX_EQUATIONS> newState;
	newState[0] = this->thau*this->state[0]+(input*this->weight);

	return newState;
}

/*
 *	Compara a função alfa atual com outra.
 *	@param other	Ponteiro para a outra função.
 *	@return			Boolean correspondente.
 */
bool ode::AlphaFunction::equals(const AlphaFunction* other){
	if(this==other || (this->numEquations==other->numEquations && this->state==other->state && 
	this->thau==other->thau && this->time==other->time && this->weight==other->weight))
		return true;

	return false;
}