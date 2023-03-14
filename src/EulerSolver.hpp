#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"

namespace ode{
	class EulerSolver: public BaseSolver{
	private:
		void InternalStep(BaseModel* model, const float interval, const float input);

	public:
		void Step(BaseModel* model, const float interval, const float input) override;
	};
} // namespace ode