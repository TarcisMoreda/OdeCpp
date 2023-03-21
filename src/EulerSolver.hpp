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
		 * @param interval Intervalo em segundos
		 * @param input Entrada para a equação
		 */
		void Step(BaseModel* model, const float interval, const float input) override;
	};
} // namespace ode