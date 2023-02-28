#pragma once

#include "BaseModel.hpp"

namespace ode{
	class IzhikevichModel: public BaseModel{
		private:
		float mA, mB, mC, mD;

		public:
		IzhikevichModel(const float a, const float b, const float c, const float d);

		std::vector<float> ModelDiferentialEquation(const float input) override;
		const float getParams(const char param) override;
		void NotifyObservers() override;

		bool operator==(const IzhikevichModel& other);
	};
}
