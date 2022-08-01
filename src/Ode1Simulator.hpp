#pragma once

#include "OdeSimulator.hpp"
#include "Ode1Solver.hpp"

namespace ode{
	class Ode1Simulator: public OdeSimulator<Ode1Solver>{
	public:
		float neuronSetStep(const float interval, const std::vector<int> inputs) override{
			std::shared_ptr<ModelArray<IzhikevichModel>> izhikevich = this->getModelArray<IzhikevichModel>();
			std::shared_ptr<ModelArray<AlphaFunction>> alpha = this->getModelArray<AlphaFunction>();
			
			if(izhikevich->size()!=alpha->size() || izhikevich->size()!= inputs.size()) 
				return 0.0f;

			float response = 0.0f;

			for(size_t i=0; i<izhikevich->size(); ++i){
				solver.step<IzhikevichModel>(izhikevich->get(i), interval, inputs[i]);
				solver.step<AlphaFunction>(alpha->get(i), interval, inputs[i]);

				response += alpha->get(i).getState()[0];
			}

			return response;
		}
	};
} // namespace ode
