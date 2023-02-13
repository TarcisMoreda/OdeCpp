#pragma once

#include "OdeModel.hpp"

namespace ode{
	class OdeSolver{
		public:
			virtual ~OdeSolver() = default;
			virtual void step(OdeModel& model, const float interval, const float input, const int id) = 0;
	};
} // namespace ode