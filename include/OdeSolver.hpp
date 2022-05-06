#pragma once

namespace ode{
	class OdeSolver{
		public:
			virtual void step(const float interval) = 0;
	};
} // namespace ode