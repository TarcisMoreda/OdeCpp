#pragma once

#include "OdeSolver.hpp"

namespace ode{
	class Ode1Solver: OdeSolver<2>{
	
	public:
		void step(OdeModel<2>& model, const float interval, const float input) override{
			std::array<float, 2> y = model.getState();
			std::array<float, 2> dy = model.modelDiferentialEquation(input);

			for(size_t i=0; i<model.getNumEquations(); ++i)
				y[i] += (interval*dy[i]);

			model.addTime(interval);
			model.setState(y);
		}
	};
} // namespace ode