#include "IzhikevichModel.hpp"
#include "iostream"

namespace ode{
	IzhikevichModel::IzhikevichModel(){
		this->mName = 'i';
		
		this->mState[0] = 0.0f;
		this->mState[1] = 0.0f;
	
		this->mA = 0.0f;
		this->mB = 0.0f;
		this->mC = 0.0f;
		this->mD = 0.0f;
	}

	IzhikevichModel::IzhikevichModel(const float a, const float b, const float c, const float d){
		this->mName = 'i';
		
		this->mState[0] = c;
		this->mState[1] = -d;
	
		this->mA = a;
		this->mB = b;
		this->mC = c;
		this->mD = d;
	}

	IzhikevichModel::IzhikevichModel(const float* params){
		this->mName = 'i';
		
		this->mState[0] = params[2];
		this->mState[1] = -params[3];
	
		this->mA = params[0];
		this->mB = params[1];
		this->mC = params[2];
		this->mD = params[3];
	}

	void IzhikevichModel::ModelDiferentialEquation(const float input){
		const float v = this->mState[0];
		const float u = this->mState[1];
		
		this->mState[0] = (0.04f*(v*v))+(5.0f*v)+140.0f-u+input;
		this->mState[1] = this->mA*((this->mB*v)-u);
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
		for(size_t i=0; i<this->mObserverQuant; ++i)
			this->mObserversList[i]->Notification(this->mTime);
	}

	void IzhikevichModel::operator=(const IzhikevichModel& other){
		this->mA = other.mA;
		this->mB = other.mB;
		this->mC = other.mC;
		this->mD = other.mD;
		this->mTime = other.mTime;
		this->mState[0] = other.mState[0];
		this->mState[1] = other.mState[1];
	}

	bool IzhikevichModel::operator==(const IzhikevichModel& other){
		return this->mState[0]==other.mState[0] && this->mState[1]==other.mState[1] && this->mA==other.mA
			&& this->mB==other.mB && this->mC==other.mC && this->mD==other.mD && this->mName==other.mName
			&& this->mTime==other.mTime;
	}
}
