#include "AlphaFunction.hpp"

namespace ode{
	AlphaFunction::AlphaFunction(const float state, const float thau, const float weight){
		this->mName = 'a';
		this->mState.push_back(state);
		this->mThau = (-1.0f/thau);
		this->mWeight = weight;
	}

	std::vector<float> AlphaFunction::ModelDiferentialEquation(const float input){
		std::vector<float> newState = this->mState;
		newState[0] = (this->mThau*newState[0])+(input*this->mWeight);
		return newState;
	}

	const float AlphaFunction::getParams(const char param){
		switch(param){
		case 't':
		case 'T':
			return this->mThau;
			break;

		case 'w':
		case 'W':
			return this->mWeight;
			break;
		
		default:
			return 0.0f;
			break;
		}
	}

	void AlphaFunction::NotifyObservers(){
		return;
	}

	bool AlphaFunction::operator== (const AlphaFunction& other){
		if(this->mState==other.mState && this->mThau==other.mThau && this->mWeight==other.mWeight 
		&& this->mName==other.mName && this->mTime==other.mTime)
			return true;

		return false;
	}
}
