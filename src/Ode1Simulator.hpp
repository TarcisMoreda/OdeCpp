#pragma once

#include "OdeSimulator.hpp"
#include "Ode1Solver.hpp"

namespace ode{
	class Ode1Simulator: public OdeSimulator<Ode1Solver>{
	public:
		float neuronSetStep(const float interval, const std::vector<int> inputs);
	};
} // namespace ode