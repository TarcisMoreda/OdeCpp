#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"
#include "Observer.hpp"

namespace ode{
	class BaseSimulator{
	protected:
		BaseSolver* solver;
		std::vector<BaseModel*> mModel;
		std::vector<BaseModel*> mFunction;
		SpikeObserver mObserver;

	public:
		/**
		 * @brief Construtor para um simulador
		 * 
		 * @param solver Utilize "new TipoSolver" para a criação, o desconstrutor irá liberar a memória do ponteiro.
		 */
		BaseSimulator(BaseSolver* solver);
		~BaseSimulator();
		virtual float NeuronStep(const float interval, const std::vector<float> inputs) = 0;
		virtual void InsertModel(BaseModel* model) = 0;
	};
} // namespace ode