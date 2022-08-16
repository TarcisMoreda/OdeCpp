#include "OdeSimulator.hpp"

namespace ode{
	template<typename SolverType>
	float OdeSimulator<SolverType>::neuronSetStep(const float interval, const std::vector<int> inputs){
		float result = 0.0f;
		
		for(int i=0; i<this->models[0].size(); ++i){
			solver.step(models[0][i], interval, inputs[i]);
			solver.step(models[1][i], interval, inputs[i]);
			result += models[1][i].getState()[0];
		}

		return result;
	}

	template<typename SolverType>
	void OdeSimulator<SolverType>::addModel(OdeModel& model, const int identifier){
		if(this->models.find(identifier)==(++this->models.end())){
			std::vector<OdeModel> tempVec{};
			this->models.insert({identifier, tempVec});
		}

		this->models.at(identifier).push_back(model);
	}
} // namespace ode