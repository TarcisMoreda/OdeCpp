#pragma once
#include <vector>
#include "OdeModel.hpp"
#include "SpikeObserver.hpp"

namespace ode{
	class IzhikevichModel: OdeModel, public SpikeSubject{
	private:
		float a, b, c, d;
		std::vector<SpikeObserver*> observers;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);	

		std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);
		void attachObserver(SpikeObserver& observer) override;
		void detachObserver(SpikeObserver& observer) override;
		void notifyObservers() override;
	};
}