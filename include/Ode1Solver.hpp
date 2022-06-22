#pragma once

#include "OdeSolver.hpp"

namespace ode{
	class Ode1Solver: OdeSolver{
	
	public:
		void step(OdeModel& model, const float interval, const float input) override{
			bool izhikevich = model.getNumEquations()==2?true:false;
			
			std::vector<float> y = model.getState();
			std::vector<float> dy = model.modelDiferentialEquation(input);

			if(izhikevich && y[0]>=30.0f){
				y[0] = model.getParams('c');
				y[1] += model.getParams('d');
			}

			for(int i=0; i<model.getNumEquations(); ++i)
				y[i] += (interval*dy[i]);

			model.addTime(interval);
			model.setState(y);

			if(izhikevich && y[0]>=35.0f){
				y[0]=35.0f;
				model.setState(y);
			}
		}
	};
} // namespace ode