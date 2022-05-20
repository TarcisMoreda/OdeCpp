#pragma once

#include "OdeModel.hpp"

namespace ode{
	class OdeSolver{
		public:
			virtual void step(const OdeModel& model, const float interval, const float input) = 0;
	};
} // namespace ode