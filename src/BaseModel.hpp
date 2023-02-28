#pragma once

#include <vector>
#include <sys/types.h>
#include "Observer.hpp"

namespace ode{
	class BaseModel: public ObserverSubject{
	protected:
		char mName;
		std::vector<float> mState;
		float mTime = 0.0f;
	
	public:
		virtual std::vector<float> ModelDiferentialEquation(const float input) = 0;
		virtual const float getParams(const char param) = 0;

		void setState(const std::vector<float> state){
			this->mState = state;
		}
		std::vector<float> getState(){
			return this->mState;
		}
		void setTime(const float time){
			this->mTime = time;
		}
		const float getTime(){
			return this->mTime;
		}
		void addTime(const float interval){
			this->mTime += interval;
		}
		const ulong getNumEquations(){
			return this->mState.size();
		}
		const char getName(){
			return this->mName;
		}
	};
} // mNamespace ode