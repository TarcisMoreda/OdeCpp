#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"
#include "Observer.hpp"

namespace ode{
	class BaseSimulator{
	private:
		BaseSolver* solver;
		std::vector<BaseModel*> mModel;
		std::vector<BaseModel*> mFunction;
		SpikeObserver mObserver;

	public:
		~BaseSimulator();
		BaseSimulator(BaseSolver* solver);
		virtual float NeuronSetStep(const float interval, const std::vector<float> inputs) = 0;
		virtual void InsertModel(BaseModel* model) = 0;
	};
} // namespace ode