#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"

namespace ode{
	class EulerSolver: public BaseSolver{
	public:
		/**
		 * @brief Faz um passo no modelo provido utilizando o método de Euler
		 * 
		 * @param model Ponteiro do modelo
		 * @param input Entrada para a equação
		 * @param interval Intervalo em segundos
		 */
		void Step(BaseModel* model, const float input, const float interval) override;
	};
} // namespace ode