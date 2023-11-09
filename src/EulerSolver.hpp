#pragma once

#include "IModel.hpp"
#include "ISolver.hpp"
#include <cstddef>

namespace ode{
	template<typename m>
	class EulerSolver: public ISolver<m>{
		public:
		void Step(m& model, const float input, const float interval) override{
			float newState[model.getNumEquations()];
			for(size_t i=0; i<model.getNumEquations(); ++i)
				newState[i] = model.getState()[i];
			
			model.ModelDiferentialEquation(input);
			
			float currState[model.getNumEquations()];
			for(size_t i=0; i<model.getNumEquations(); ++i)
				currState[i] = model.getState()[i];

			for(size_t i=0; i<model.getNumEquations(); ++i)
				newState[i] += interval*currState[i];
			
			model.setState(newState);
			model.addTime(interval);
		}
	};
}