#pragma once
#include <array>

namespace ode{
	template<std::size_t N>
	class OdeModel{
	protected:
		int numEquations;
		std::array<float, N> state;
		float time = 0.0f;
	
	public:
		OdeModel();
		virtual std::array<float, N> modelDiferentialEquation(const float input) = 0;
		virtual float getParams() = 0;

		void setState(const std::array<float, 2> state){
			for(int i=0; i<this->numEquations; ++i)
				this->state[i] = state[i];
		}
		std::array<float, N> getState(){
			return this->state;
		}
		void setTime(const float time){
			this->time = time;
		}
		float getTime(){
			return this->time;
		}
		void addTime(const float interval){
			this->time += interval;
		}
		int getNumEquations(){
			return this->numEquations;
		}
	};
} // namespace ode