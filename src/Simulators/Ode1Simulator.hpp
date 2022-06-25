#pragma once

#include "OdeSimulator.hpp"
#include "Ode1Solver.hpp"
#include "../Neurons/IzhikevichModel.hpp"
#include "../Neurons/AlphaFunction.hpp"

namespace ode{
	class Ode1Simulator: public OdeSimulator<Ode1Solver>{
	public:
		void insertIzhikevich(IzhikevichModel model){
			this->addModel('I', model);
		}

		void insertAlpha(AlphaFunction model){
			this->addModel('A', model);
		}

		int neuronSetStep(const float interval, const std::vector<int> inputs){
			if(this->models.at('I').size()!=inputs.size())
				return;
			

		}

	private:
		int neuronStep(const int index, const float interval, const int input){
			OdeModel& izhikevich = this->models.at('I')[index];
			this->solver->step(izhikevich, interval, input);
			
			OdeModel& alpha = this->models.at("A")[index];
			this->solver->step(alpha, interval, izhikevich.getState)
		}
	};
} // namespace ode