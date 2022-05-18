#pragma once
#include <vector>
#include "OdeModel.hpp"
#include "Observer.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel, public ObserverSubject{
	private:
		float a, b, c, d;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);	

		std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);
	};

	class Spike: public Observer{
		void notification(const float time) override;
	};
}