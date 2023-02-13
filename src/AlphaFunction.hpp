#pragma once

#include "OdeModel.hpp"

namespace ode{
	class AlphaFunction: public OdeModel{
	private:
		float thau;
		float weight;

	public:
		AlphaFunction(const float state, const float thau, const float weight);

		std::vector<float> modelDiferentialEquation(const float input) override;
		bool equals(const AlphaFunction* other);
		float getParams(const char param);
		void notifyObservers() override;
	};
} // namespace ode