#pragma once

#include "OdeSolver.hpp"

namespace ode{
	class Ode1Solver: public OdeSolver<2>{
	public:
		void step(OdeModel& model, const float interval, const float input) override{
			std::vector<float> y = model.getState();

			std::vector<float> dy = model.modelDiferentialEquation(input);

			for(int i=0; i<model.getNumEquations(); ++i)
				y[i] += (interval*dy[i]);

			model.addTime(interval);
			model.setState(y);
		}
	};
} // namespace ode