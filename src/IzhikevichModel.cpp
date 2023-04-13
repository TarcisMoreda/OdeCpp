#include "IzhikevichModel.hpp"

namespace ode{
	IzhikevichModel::IzhikevichModel(const float a, const float b, const float c, const float d){
		this->mName = 'i';
		
		this->mState.push_back(c);
		this->mState.push_back(-d);
	
		this->mA = a;
		this->mB = b;
		this->mC = c;
		this->mD = d;
	}

	IzhikevichModel::IzhikevichModel(const float* params){
		this->mName = 'i';
		
		this->mState.push_back(params[2]);
		this->mState.push_back(-params[3]);
	
		this->mA = params[0];
		this->mB = params[1];
		this->mC = params[2];
		this->mD = params[3];
	}

	std::vector<float> IzhikevichModel::ModelDiferentialEquation(const float input){
		std::vector<float> newState = this->mState;
	
		newState[0] = (0.04f*(this->mState[0]*this->mState[0]))+(5.0f*this->mState[0])+140.0f-this->mState[1]+input;
		newState[1] = this->mA*((this->mB*this->mState[0])-this->mState[1]);
	
		return newState;
	}
	
	const float IzhikevichModel::getParams(const char param){
		switch (param){
		case 'a':
		case 'A':
			return this->mA;
			break;
		
		case 'b':
		case 'B':
			return this->mB;
			break;

		case 'c':
		case 'C':
			return this->mC;
			break;

		case 'd':
		case 'D':
			return this->mD;
			break;

		default:
			return 0;
			break;
		}
	}

	void IzhikevichModel::NotifyObservers(){
		for(auto observer: this->mObserversList)
			observer->Notification(this->mTime);
	}

	bool IzhikevichModel::operator==(const IzhikevichModel& other){
		if(this->mState==other.mState && this->mA==other.mA && this->mB==other.mB && this->mC==other.mC 
		&& this->mD==other.mD && this->mName==other.mName && this->mTime==other.mTime)
		 	return true;
		
		return false;
	}
}
