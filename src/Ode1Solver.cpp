#include "Ode1Solver.hpp"

namespace ode{
	void Ode1Solver::internalStep(OdeModel& model, const float interval, const float input){
		std::vector<float> dy = model.modelDiferentialEquation(input);
		std::vector<float> y = model.getState();
			
		for(long unsigned int i=0; i<y.size(); ++i)
			y[i] += interval*dy[i];

		model.setState(y);
		model.addTime(interval);
	}

	void Ode1Solver::step(OdeModel& model, const float interval, const float input){
		std::vector<float> y = model.getState();

		if(model.getNumEquations()==2){
			if(!model.hasObserver(&this->izhikevichObserver))
				model.attachObserver(&this->izhikevichObserver);

			if(y[0]>=30.0f){
				y[0] = model.getParams('c');
				y[1] += model.getParams('d');
				model.notifyObservers();
			}

			this->internalStep(model, interval, input);
			y = model.getState();
			
			if(y[0]>=35.0f)
				y[0] = 35.0f;
		}
		else{
			this->internalStep(model, 0.001, this->izhikevichObserver.hasSpiked());
		}
	}
} // namespace ode
