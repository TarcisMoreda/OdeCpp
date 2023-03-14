#include "EulerSolver.hpp"

namespace ode{
	void EulerSolver::InternalStep(BaseModel* model, const float interval, const float input){
		std::vector<float> dy = model->ModelDiferentialEquation(input);
		std::vector<float> y = model->getState();
			
		for(long unsigned int i=0; i<y.size(); ++i)
			y[i] += interval*dy[i];

		model->setState(y);
		model->addTime(interval);
	}

	void EulerSolver::Step(BaseModel* model, const float interval, const float input){
		std::vector<float> y = model->getState();
		if(model->getName()=='i'){
			if(y[0]>=30.0f){
				y[0] = model->getParams('c');
				y[1] += model->getParams('d');
				model->setState(y);
				model->NotifyObservers();
			}

			this->InternalStep(model, interval, input);
			y = model->getState();
			
			if(y[0]>=35.0f){
				y[0] = 35.0f;
				model->setState(y);
			}
		}
		else
			this->InternalStep(model, interval, input);
	}
} // namespace ode
