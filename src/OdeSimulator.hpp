#pragma once

#include <unordered_map>
#include <memory>
#include "OdeSolver.hpp"
#include "OdeModel.hpp"

namespace ode{
	template<typename SolverType>
	class OdeSimulator{
	protected:
		std::shared_ptr<SolverType> solver;
		std::unordered_map<const char, std::vector<OdeModel&>> models;

		void addModel(const char type, OdeModel& model){
			if(this->models.count(type)==0){
				std::vector<OdeModel&> tempVec;
				this->models.insert({type, tempVec});
			}
			this->models.at(type).push_back(model);
		}

	public:
		virtual int neuronSetStep(const float interval, const std::vector<int> inputs) = 0;
	};
} // namespace ode