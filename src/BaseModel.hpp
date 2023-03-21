#pragma once

#include <vector>
#include "Observer.hpp"

namespace ode{
	class BaseModel: public ObserverSubject{
	protected:
		char mName;
		std::vector<float> mState;
		float mTime = 0.0f;
	
	public:
		virtual ~BaseModel(){};
		virtual std::vector<float> ModelDiferentialEquation(const float input) = 0;
		virtual const float getParams(const char param) = 0;

		/**
		 * @brief Set para o estado do modelo
		 * 
		 * @param state
		 */
		void setState(const std::vector<float> state){
			this->mState = state;
		}

		/**
		 * @brief Get para o estado do modelo
		 * 
		 * @return std::vector<float>
		 */
		std::vector<float> getState(){
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
			return this->mState.size();
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
} // mNamespace ode