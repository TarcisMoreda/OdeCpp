#pragma once

#include <vector>
#include "Observer.hpp"

namespace ode{
	class OdeModel: public ObserverSubject{
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

		void setState(const std::vector<float> state);
		std::vector<float> getState();
		void setTime(const float time);
		float getTime();
		void addTime(const float interval);
		int getNumEquations();
	};
} // namespace ode