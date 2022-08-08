#pragma once

#include "OdeModel.hpp"
#include "Observer.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel, public ObserverSubject<SpikeObserver>{
	private:
		float a, b, c, d;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);

		std::vector<float> modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);
		float getParams(const char param);
		void notifyObservers();
	};
}