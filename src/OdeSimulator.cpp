#include <iostream>
#include "BaseSolver.hpp"
#include "OdeSimulator.hpp"

namespace ode{
	OdeSimulator::OdeSimulator(BaseSolver* solver){
		this->solver = solver;
	}

	float OdeSimulator::NeuronSetStep(const float interval, const std::vector<float> inputs){
		float result = 0.0f;

		//precisa de loop para as entradas antes do loop para os modelos
		for(size_t i=0; i<this->mModel.size(); ++i){
			float spike = this->mObserver.HasSpiked();
			solver->Step(this->mModel[i], interval, inputs[i], spike);
			solver->Step(this->mFunction[i], interval, inputs[i], spike);
			result += this->mFunction[i]->getState()[0];
		}

		return result;
	}

	void OdeSimulator::InsertModel(BaseModel* model){
		switch (model->getName()){
		case 'i':
			model->AttachObserver(&this->mObserver);
			this->mModel.push_back(model);
		case 'a':
			this->mFunction.push_back(model);
		}
	}
} // namespace ode
