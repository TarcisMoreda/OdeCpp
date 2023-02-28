#pragma once

#include "BaseModel.hpp"

namespace ode{
	class BaseSolver{
		public:
			virtual ~BaseSolver() = 0;
			virtual void Step(BaseModel* model, const float interval, const float input, const float spike) = 0;
	};
} // namespace ode