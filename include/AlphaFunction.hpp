#pragma once
#include "OdeModel.hpp"

namespace ode{
	class AlphaFunction: OdeModel{
	private:
		float thau;
		float weight;

	public:
		AlphaFunction(const float state, const float thau, const float weight);

		std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input);
		bool equals(const AlphaFunction* other);
	};
} // namespace ode