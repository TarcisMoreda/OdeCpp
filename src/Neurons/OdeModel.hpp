#pragma once

#include <vector>

namespace ode{
	class OdeModel{
	protected:
		int numEquations;
		std::vector<float> state;
		float time = 0.0f;
	
	public:
		OdeModel(int numEquations){
			this->numEquations = numEquations;
		}

		virtual std::vector<float> modelDiferentialEquation(const float input) = 0;
		virtual float getParams(const char param) = 0;

		void setState(const std::vector<float> state){
			this->state = state;
		}
		std::vector<float> getState(){
			return this->state;
		}
		void setTime(const float time){
			this->time = time;
		}
		float getTime(){
			return this->time;
		}
		void addTime(const float interval){
			this->time += interval;
		}
		int getNumEquations(){
			return this->numEquations;
		}
	};
} // namespace ode