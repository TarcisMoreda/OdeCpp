#pragma once
#include <vector>
#include "OdeModel.hpp"
#include "Observer.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel<2>, public ObserverSubject{
	private:
		float a, b, c, d;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);	

		float* modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);
		float getParams();
	};
	
	class SpikeObserver: public IObserver{
		void notification(const float time) override;
	};
}