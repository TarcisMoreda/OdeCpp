#pragma once

#include "BaseModel.hpp"

namespace ode{
	class BaseSolver{
		public:
		virtual ~BaseSolver(){};
		virtual void Step(BaseModel* model, const float interval, const float input, const float spike) = 0;
	};
} // namespace ode