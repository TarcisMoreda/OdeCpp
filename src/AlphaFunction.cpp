#include "AlphaFunction.hpp"

namespace ode{
	/*
	 *	Construtor da função alfa.
	 *	@param thau		O valor de tau (obs: ele calcula -1/tau dentro da função).
	 *	@param weight	O peso da função. (Padrão = 0)
	 *	@param state	Estado inicial da função.
	 */
	AlphaFunction::AlphaFunction(const float state, const float thau, const float weight): OdeModel::OdeModel(1){
		this->state.push_back(state);
		this->thau = (-1.0f/thau);
		this->weight = weight;
	}

	/*
	 *	Faz o cálculo diferencial da função alfa.
	 *	v' = tau*v+(I*peso)
	 *	@param input	A corrente de entrada.
	 *	@return			Um std::array contendo v' com chave 'v'.
	 */
	std::vector<float> AlphaFunction::modelDiferentialEquation(const float input){
		std::vector<float> newState = this->state;
		newState[0] = this->thau*this->state[0]+(input*this->weight);
		return newState;
	}

	/*
	 *	Compara a função alfa atual com outra.
	 *	@param other	Ponteiro para a outra função.
	 *	@return			Boolean correspondente.
	 */
	bool AlphaFunction::equals(const AlphaFunction* other){
		if(this==other || (this->numEquations==other->numEquations && this->state==other->state && 
		this->thau==other->thau && this->time==other->time && this->weight==other->weight))
			return true;

		return false;
	}

	float AlphaFunction::getParams(const char param){
		switch(param){
		case 't':
			return this->thau;
			break;

		case 'w':
			return this->weight;
			break;
		
		default:
			return 0;
			break;
		}
	}
}