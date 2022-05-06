#pragma once
#include <array>

#define MAX_EQUATIONS 8

namespace ode{
	class OdeModel{
	protected:
		int numEquations;
		std::array<float, MAX_EQUATIONS> state;
		float time = 0.0f;
	
	public:
		virtual std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input) = 0;
	};
} // namespace ode