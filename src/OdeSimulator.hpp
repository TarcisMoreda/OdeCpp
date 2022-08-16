#pragma once

#include <unordered_map>
#include <memory>
#include "OdeSolver.hpp"
#include "OdeModel.hpp"

namespace ode{
	template<typename SolverType>
	class OdeSimulator{
	protected:
		SolverType solver;
		std::unordered_map<const int, std::vector<OdeModel>> models;

	public:
		float neuronSetStep(const float interval, const std::vector<int> inputs);
		void addModel(OdeModel& model, const int identifier);
	};
} // namespace ode