#pragma once
#include <array>

namespace ode{
	template <int MAX_EQUATIONS>
	class OdeModel{
	protected:
		int numEquations=MAX_EQUATIONS;
		std::array<float, MAX_EQUATIONS> state;
		float time = 0.0f;
	
	public:
		virtual std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input) = 0;
		std::array<float, MAX_EQUATIONS> getState(){
			return this->state;
		}
		int getNumEquations(){
			return this->numEquations;
		}
	};
} // namespace ode