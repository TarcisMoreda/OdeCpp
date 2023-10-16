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
			float* currState = model.getState();
			for(size_t i=0; i<model.getNumEquations(); ++i)
				newState[i] = currState[i];
			
			model.ModelDiferentialEquation(input);
			for(size_t i=0; i<model.getNumEquations(); ++i){
				newState[i] += interval*currState[i];
				currState[i] = newState[i];
			}
		}
	};
}