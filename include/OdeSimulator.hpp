#pragma once

#include "OdeSolver.hpp"
#include "OdeModel.hpp"

namespace ode{
	template<OdeSolver& Solver>
	class OdeSimulator{
	private:
		OdeSolver& solver = Solver;
		std::vector<OdeModel> models;
	
	public:
		void addModel(const OdeModel& model){
			this->models.push_back(model);
		}
	};
} // namespace ode
