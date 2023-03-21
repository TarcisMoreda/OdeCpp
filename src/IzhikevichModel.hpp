#pragma once

#include "BaseModel.hpp"

namespace ode{
	class IzhikevichModel: public BaseModel{
		private:
		float mA, mB, mC, mD;

		public:
		/**
		 * @brief Construtor para um neurônio de Izhikevich
		 * 
		 * @param a Parâmetro A da especificação de Izhikevich
		 * @param b Parâmetro B da especificação de Izhikevich
		 * @param c Parâmetro C da especificação de Izhikevich
		 * @param d Parâmetro D da especificação de Izhikevich
		 */
		IzhikevichModel(const float a, const float b, const float c, const float d);

		/**
		 * @brief Construtor para um neurônio de Izhikevich
		 * 
		 * @param params Parâmetros em ordem igual ao outro construtor
		 */
		IzhikevichModel(const float* params);

		/**
		 * @brief Faz a equação referente ao modelo em questão
		 * 
		 * @param input A entrada da equação
		 * @return std::vector<float> O estado com a equação aplicada
		 */
		std::vector<float> ModelDiferentialEquation(const float input) override;

		/**
		 * @brief Get para os parâmetros do modelo
		 * 
		 * @param param Um char (a, b, c, ou d) que indentifica o parâmetro em questão
		 * @return const float
		 */
		const float getParams(const char param) override;

		/**
		 * @brief Notifica os observadores de um spike no neurônio
		 */
		void NotifyObservers() override;

		/**
		 * @brief Compara dois neurônios
		 * 
		 * @param other O outro neurônio para comparação
		 * @return boolean
		 */
		bool operator==(const IzhikevichModel& other);
	};
}
