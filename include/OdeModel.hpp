#pragma once
#include <array>

namespace ode{
	class OdeModel{
	protected:
		int numEquations = 0;
		float* state = nullptr;
		float time = 0.0f;
	
	public:
		OdeModel(const int numEquations);

		virtual float* modelDiferentialEquation(float input) = 0;
	};
} // namespace ode