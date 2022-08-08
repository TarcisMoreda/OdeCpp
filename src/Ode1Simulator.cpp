#include "Ode1Simulator.hpp"

namespace ode{
	float Ode1Simulator::neuronSetStep(const float interval, const std::vector<int> inputs){
		auto izhikevich = this->getModelArray<IzhikevichModel>();
		auto alpha = this->getModelArray<AlphaFunction>();
		
		if(izhikevich->size()!=alpha->size() || izhikevich->size()!=inputs.size()) 
			return 0.0f;

		float response = 0.0f;
		for(int i=0; i<(int)izhikevich->size(); ++i){
			solver.step<IzhikevichModel>(izhikevich->getModel(i), interval, inputs[i]);
			solver.step<AlphaFunction>(alpha->getModel(i), interval, inputs[i]);

			response += alpha->getModel(i).getState()[0];
		}

		return response;
	}
} // namespace ode