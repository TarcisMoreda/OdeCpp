#pragma once

#include "BaseModel.hpp"

namespace ode{
	class BaseSolver{
		public:
		virtual ~BaseSolver(){};
		virtual void Step(BaseModel* model, const float input, const float interval) = 0;
	};
} // namespace ode