#pragma once

#include <unordered_map>
#include <memory>
#include "OdeSolver.hpp"
#include "../Neurons/OdeModel.hpp"

namespace ode{
	template<typename SolverType>
	class OdeSimulator{
	protected:
		std::shared_ptr<SolverType> solver;
		std::unordered_map<const char, std::vector<OdeModel&>> models;

		void addModel(const char type, OdeModel& model){
			if(this->models.count(type)==0)
				this->models.insert({type, model});
			this->models.at(type).insert(model);
		}

	public:
		virtual int neuronSetStep(const float interval, const std::vector<int> inputs) = 0;
	};
} // namespace ode