#include "../include/IzhikevichModel.hpp"

namespace ode{
	/*
	 *	Construtor do modelo de Izhikevich.
	 *	@param a,b,c,d	Valores do modelo.
	 */
	IzhikevichModel::IzhikevichModel(const float a, const float b, const float c, const float d): OdeModel::OdeModel(1){
		this->state.push_back(c);
		this->state.push_back(-d);
	
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	
	/*
	 *	Faz o cálculo diferencial do neurônio.
	 *	v' = 0.04*(v^2)+5*v+140-u+I
	 *	u' = a*(b*v-u)
	 *	@param input	A corrente de entrada.
	 *	@return			Um std::vector contendo v' e u'.
	 */
	std::vector<float> IzhikevichModel::modelDiferentialEquation(const float input){
		std::vector<float> newState = this->state;
	
		newState[0] = 0.04f*(this->state[0]*this->state[0])+5.0f*this->state[0]+140.0f-this->state[1]+input;
		newState[1] = this->a*(this->b*this->state[0]-this->state[1]);
	
		return newState;
	}
	
	/*
	 *	Compara o modelo de Izhikevich atual com outro.
	 *	@param other	Ponteiro para o outro modelo.
	 *	@return			Boolean correspondente.
	 */
	bool IzhikevichModel::equals(const IzhikevichModel* other){
		if(this==other || (this->numEquations==other->numEquations && this->state==other->state && 
		this->time==other->time && this->a==other->a && this->b==other->b && this->c==other->c && this->d==other->d))
			return true;
	
		return false;
	}
	
	float IzhikevichModel::getParams(const char param){
		switch (param){
		case 'a':
			return this->a;
			break;
		
		case 'b':
			return this->b;
			break;

		case 'c':
			return this->c;
			break;

		case 'd':
			return this->d;
			break;

		default:
			break;
		}
	}
}