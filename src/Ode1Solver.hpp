#pragma once

#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
	class Ode1Solver{
	private:
		SpikeObserver izhikevichObserver;

		template<typename ModelType>
		void internalStep(ModelType& model, const float interval, const float input){
			std::vector<float> dy = model.modelDiferentialEquation(input);
			std::vector<float> y = model.getState();
			
			for(size_t i=0; i<y.size(); ++i)
				y[i] += interval*dy[i];

			model.setState(y);
			model.addTime(interval);
		}

	public:
		SpikeObserver& getSpike(){
			return izhikevichObserver;
		}

		template<typename ModelType>
		float step(ModelType& model, const float interval, const float input){
			const char* typeName = typeid(ModelType).name();
			std::vector<float> y = model.getState();

			if(typeName == typeid(IzhikevichModel).name()){
				if(y[0]>=30.0f){
					y[0] = model.getParams('c');
					y[1] += model.getParams('d');
					model.notifyObservers();
				}

				this->internalStep<ModelType>(model, interval, input);
				y = model.getState();
				
				if(y[0]>=35.0f)
					y[0] = 35.0f
			}
			else
				this->internalStep(model, interval, this->izhikevichObserver.hasSpiked());
		}
	};
} // namespace ode