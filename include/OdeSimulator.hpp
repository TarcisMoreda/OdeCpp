#pragma once

#include <unordered_map>
#include "OdeSolver.hpp"
#include "OdeModel.hpp"

namespace ode{
	template<OdeSolver& Solver>
	class OdeSimulator{
	private:
		OdeSolver& solver = Solver;
		std::unordered_map<const char*, std::vector<OdeModel&>> models;
	
	public:
		void addModel(const char* name, const OdeModel& model){
			if(this->models.count(name)==0)
				this->models.insert({name, std::vector<OdeModel&>});
			this->models.at(name).insert(model);
		}
	};
} // namespace ode