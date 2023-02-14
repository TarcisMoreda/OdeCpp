#pragma once

#include "OdeModel.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel{
	private:
		float a, b, c, d;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);

		std::vector<float> modelDiferentialEquation(const float input) override;
		bool equals(const IzhikevichModel* other);
		float getParams(const char param) override;
		void notifyObservers() override;
	};
}
