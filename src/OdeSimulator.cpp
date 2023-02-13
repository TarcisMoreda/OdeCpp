#include <iostream>
#include "OdeSimulator.hpp"

namespace ode{
	OdeSimulator::OdeSimulator(Ode1Solver* solver){
		this->solver = solver;
	}

	float OdeSimulator::neuronSetStep(const float interval, const std::vector<float> inputs){
		float result = 0.0f;

		for(size_t i=0; i<this->izhikevich.size(); ++i){
			solver->step(this->izhikevich[i], interval, inputs[i], 0);
			solver->step(this->alpha[i], interval, inputs[i], 1);
			result += this->alpha[i].getState()[0];
		}

		return result;
	}

	void OdeSimulator::addIzhikevich(const float a, const float b, const float c, const float d){
		this->izhikevich.push_back(IzhikevichModel(a, b, c, d));
		this->solver->setup(&(this->izhikevich.back()));
	}

	void OdeSimulator::addAlpha(const float state, const float thau, const float weight){
		this->alpha.push_back(AlphaFunction(state, thau, weight));
	}
} // namespace ode
