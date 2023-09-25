#include "BaseSolver.hpp"
#include "BaseSimulator.hpp"

#include <assert.h>

namespace ode{
	BaseSimulator::BaseSimulator(BaseSolver* solver){
		this->solver = solver;
	}

	BaseSimulator::~BaseSimulator(){
		delete this->solver;
		for(BaseModel* model: this->mModel)
			delete model;
		for(BaseModel* model: this->mFunction)
			delete model;
	}
} // namespace ode
