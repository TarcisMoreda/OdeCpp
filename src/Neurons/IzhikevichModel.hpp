#pragma once

#include "OdeModel.hpp"
#include "../Observer.hpp"

namespace ode{
	class IzhikevichModel: public OdeModel, public ObserverSubject{
	private:
		float a, b, c, d;
		float prevU, prevV;

	public:
		IzhikevichModel(const float a, const float b, const float c, const float d);	

		std::vector<float> modelDiferentialEquation(const float input);
		bool equals(const IzhikevichModel* other);
		float getParams(const char param);
		std::vector<float> getState();
		void setState(std::vector<float> state);
	};
	
	class SpikeObserver: public IObserver{
		private:
		bool spiked = false;

		public:
		float hasSpiked(){
			if(this->spiked){
				this->spiked = false;
				return 1.0f;
			}
			return 0.0f;
		}

		void resetInternalState(){
			this->spiked = false;
		}

		float notification(const float time) override{
			this->spiked = true;
			return time;
		}
	};
}