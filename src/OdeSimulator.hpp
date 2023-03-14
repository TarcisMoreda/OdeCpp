#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"
#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"
#include "Observer.hpp"

namespace ode{
	class OdeSimulator{
	private:
		BaseSolver* solver;
		BaseSolver* solver;
		std::vector<BaseModel*> mModel;
		std::vector<BaseModel*> mFunction;
		SpikeObserver mObserver;

	public:
		~OdeSimulator(){
			delete this->solver;
			for(BaseModel* model: this->mModel)
				delete model;
			for(BaseModel* model: this->mFunction)
				delete model;
		}
		
		OdeSimulator(BaseSolver* solver);
		float NeuronSetStep(const float interval, const std::vector<float> inputs);
		void InsertModel(BaseModel* model);
	};
} // namespace ode
