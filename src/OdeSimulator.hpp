#pragma once

#include <vector>
#include <memory>
#include "Ode1Solver.hpp"
#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
	class OdeSimulator{
	private:
		Ode1Solver* solver;
		std::vector<IzhikevichModel> izhikevich;
		std::vector<AlphaFunction> alpha;

	public:
		OdeSimulator(Ode1Solver* solver);
		float neuronSetStep(const float interval, const std::vector<float> inputs);
		void addIzhikevich(const float a, const float b, const float c, const float d);
		void addAlpha(const float state, const float thau, const float weight);
	};
} // namespace ode
