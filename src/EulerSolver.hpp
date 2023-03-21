#pragma once

#include "BaseModel.hpp"
#include "BaseSolver.hpp"

namespace ode{
	class EulerSolver: public BaseSolver{
	public:
		void Step(BaseModel* model, const float interval, const float input) override;
	};
} // namespace ode