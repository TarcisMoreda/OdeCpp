#pragma once
#include <vector>
#include "OdeModel.hpp"
#include "Observer.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel, public ObserverSubject<float>{
	private:
		float a, b, c, d;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);	

		std::array<float, MAX_EQUATIONS> modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);


		void attachObserver(Observer<float>& observer) override;
		void detachObserver(Observer<float>& observer) override;
		void notifyObservers() override;
	};
}