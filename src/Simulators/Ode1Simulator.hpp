#pragma once

#include "OdeSimulator.hpp"
#include "Ode1Solver.hpp"
#include "../Neurons/IzhikevichModel.hpp"
#include "../Neurons/AlphaFunction.hpp"

namespace ode{
	class Ode1Simulator: public OdeSimulator<Ode1Solver>{
	private:
		std::shared_ptr<SpikeObserver> internalObserver;

		int neuronStep(const int index, const float interval, const int input){
			OdeModel& izhikevich = this->models.at('I')[index];
			this->solver->step(izhikevich, interval, input);
			
			OdeModel& alpha = this->models.at('A')[index];
			this->solver->step(alpha, interval, internalObserver->hasSpiked());
			
			return alpha.getState()[0]; 
		}

	public:
		void insertIzhikevich(IzhikevichModel model){
			model.attachObserver(internalObserver);
			this->addModel('I', model);
		}

		void insertAlpha(AlphaFunction model){
			this->addModel('A', model);
		}

		int neuronSetStep(const float interval, const std::vector<int> inputs){
			if(this->models.at('I').size()!=inputs.size() ||
			   this->models.at('I').size()!=this->models.at('A').size())
				return;
			
			float response = 0.0f;
			
			for (size_t i=0; i<this->models.at('I').size(); ++i){
				response+=this->neuronStep(i, interval, inputs[i]);
			}
			
			return response;
		}
	};
} // namespace ode