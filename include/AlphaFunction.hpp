#pragma once
#include "OdeModel.hpp"

namespace ode{
	class AlphaFunction: public OdeModel{
	private:
		float thau;
		float weight;

	public:
		AlphaFunction(const float thau, const float weight, const float state=0);

		std::vector<float> modelDiferentialEquation(const float input);
		bool equals(const AlphaFunction* other);
	};
} // namespace ode