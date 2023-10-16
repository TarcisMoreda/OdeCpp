#include "AlphaFunction.hpp"

namespace ode{
	AlphaFunction::AlphaFunction(const float state, const float thau, const float weight){
		this->mName = 'a';
		this->mState[0] = state;
		this->mThau = (-1.0f/thau);
		this->mWeight = weight;
	}

	AlphaFunction::AlphaFunction(const float* params){
		this->mName = 'a';
		this->mState[0] = params[0];
		this->mThau = (-1.0f/params[1]);
		this->mWeight = params[2];
	}

	void AlphaFunction::ModelDiferentialEquation(const float input){
		this->mState[0] = (this->mThau*this->mState[0])+(input*this->mWeight);
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
		if(this->mState[0]==other.mState[0] && this->mThau==other.mThau && this->mWeight==other.mWeight 
		&& this->mName==other.mName && this->mTime==other.mTime)
			return true;

		return false;
	}
}
