#pragma once

#include "IModel.hpp"
#include <functional>

namespace ode{
	template<typename m>
	class ISolver{
		public:
		virtual void Step(m& model, const float input, const float interval) = 0;
	};
} // namespace ode