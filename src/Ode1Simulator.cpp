#include "Ode1Simulator.hpp"

namespace ode{
	float Ode1Simulator::neuronSetStep(const float interval, const std::vector<int> inputs){
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
} // namespace ode