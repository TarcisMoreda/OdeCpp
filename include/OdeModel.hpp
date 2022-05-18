#pragma once
#include <array>

namespace ode{
	#define MAX_EQUATIONS 8

	class OdeModel{
	protected:
		int numEquations;
		std::array<float, MAX_EQUATIONS> state;
		float time = 0.0f;
	
	public:
		virtual std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input) = 0;
	};
} // namespace ode