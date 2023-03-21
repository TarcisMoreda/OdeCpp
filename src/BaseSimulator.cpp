#include "BaseSolver.hpp"
#include "BaseSimulator.hpp"

namespace ode{
	BaseSimulator::BaseSimulator(BaseSolver* solver){
		this->solver = solver;
	}

	float BaseSimulator::NeuronSetStep(const float interval, const std::vector<float> inputs){
		float result = 0.0f;

		for(size_t i=0; i<this->mModel.size(); ++i){
			solver->Step(this->mModel[i], interval, inputs[i]);
			solver->Step(this->mFunction[i], interval, this->mObserver.HasSpiked());
			result += this->mFunction[i]->getState()[0];
		}

		return result;
	}
} // namespace ode
