#pragma once

#include "BaseModel.hpp"

namespace ode{
	class AlphaFunction: public BaseModel{
		private:
		float mThau;
		float mWeight;

		public:
		AlphaFunction(const float state, const float thau, const float weight);

		std::vector<float> ModelDiferentialEquation(const float input) override;
		const float getParams(const char param) override;
		void NotifyObservers() override;

		bool operator==(const AlphaFunction& other);
	};
} // namespace ode
