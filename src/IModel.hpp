#pragma once

#include "Observer.hpp"
#include <cstddef>

namespace ode{
	template<size_t size>
	class IModel: public ObserverSubject{
	protected:
		char mName;
		float mState[size];
		float mTime = 0.0f;
		const size_t mSize = size;
	
	public:
		virtual ~IModel(){};
		virtual void ModelDiferentialEquation(const float input) = 0;
		virtual const float getParams(const char param) = 0;

		/**
		 * @brief Set para o estado do modelo
		 * 
		 * @param state
		 */
		void setState(const float* state){
			for(size_t i=0; i<this->mSize; ++i)
				this->mState[i] = state[i];
		}

		/**
		 * @brief Get para o estado do modelo
		 * 
		 * @return float*
		 */
		float* getState(){
			return this->mState;
		}

		/**
		 * @brief Set para o tempo interno do modelo
		 * 
		 * @param time 
		 */
		void setTime(const float time){
			this->mTime = time;
		}

		/**
		 * @brief Get para o tempo interno do modelo
		 * 
		 * @return const float 
		 */
		const float getTime(){
			return this->mTime;
		}

		/**
		 * @brief Adiciona um intervalo de tempo ao tempo interno do modelo
		 * 
		 * @param interval 
		 */
		void addTime(const float interval){
			this->mTime += interval;
		}

		/**
		 * @brief Get para a quantidade de estados
		 * 
		 * @return const unsigned long 
		 */
		const unsigned long getNumEquations(){
			return this->mSize;
		}

		/**
		 * @brief Get para o nome interno do modelo
		 * 
		 * @return const char 
		 */
		const char getName(){
			return this->mName;
		}
	};
}; // mNamespace ode
