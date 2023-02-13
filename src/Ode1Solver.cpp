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

	void Ode1Solver::setup(IzhikevichModel* model){
		model->attachObserver(&(this->izhikevichObserver));
	}

	void Ode1Solver::step(OdeModel& model, const float interval, const float input, const int id){
		std::vector<float> y = model.getState();
		if(id==0){
			if(y[0]>=30.0f){
				y[0] = model.getParams('c');
				y[1] += model.getParams('d');
				model.setState(y);
				model.notifyObservers();
			}

			this->internalStep(model, interval, input);
			y = model.getState();
			
			if(y[0]>=35.0f){
				y[0] = 35.0f;
				model.setState(y);
			}
		}
		else{
			float spike = this->izhikevichObserver.hasSpiked();
			this->internalStep(model, 0.001f, spike);
		}
	}
} // namespace ode
