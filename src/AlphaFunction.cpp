#include "AlphaFunction.hpp"

namespace ode{
	AlphaFunction::AlphaFunction(const float state, const float thau, const float weight): OdeModel::OdeModel(1){
		this->state.push_back(state);
		this->thau = (-1.0f/thau);
		this->weight = weight;
	}

	std::vector<float> AlphaFunction::modelDiferentialEquation(const float input){
		std::vector<float> newState = this->state;
		newState[0] = this->thau*this->state[0]+(input*this->weight);
		return newState;
	}

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