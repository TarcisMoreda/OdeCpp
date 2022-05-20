#pragma once

#include "OdeSolver.hpp"

namespace ode{
	class Ode1Solver: OdeSolver{
		public:
			void step(const OdeModel& model, const float interval, const float input) override{
				std::array<float, > dy = model.modelDiferentialEquation(input);

				for(size_t i=0; i<MAX_EQUATIONS; ++i)
					model.state[i] += (interval*dy[i]);

				model.time += interval;
			}
	};
} // namespace ode