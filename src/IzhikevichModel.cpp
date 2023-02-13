#include "IzhikevichModel.hpp"
#include <iostream>

namespace ode{
	IzhikevichModel::IzhikevichModel(const float a, const float b, const float c, const float d){
		this->numEquations = 2;
		this->name = 'i';
		
		this->state.push_back(c);
		this->state.push_back(-d);
	
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	std::vector<float> IzhikevichModel::modelDiferentialEquation(const float input){
		std::vector<float> newState = this->state;
	
		newState[0] = 0.04f*(this->state[0]*this->state[0])+5.0f*this->state[0]+140.0f-this->state[1]+input;
		newState[1] = this->a*(this->b*this->state[0]-this->state[1]);
	
		return newState;
	}

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
			return 0;
			break;
		}
	}

	void IzhikevichModel::notifyObservers(){
		for(auto observer: this->observers)
			observer->notification(this->time);
	}
}