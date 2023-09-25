#pragma once

#include "BaseModel.hpp"

namespace ode{
	class AlphaFunction: public BaseModel{
		private:
		float mThau;
		float mWeight;

		public:
		/**
		 * @brief Construtor para uma função de ativação alfa
		 * 
		 * @param state O estado interno da função
		 * @param thau O valor de thau, será utilizado para calcular -1/thau
		 * @param weight O peso do neurônio
		 */
		AlphaFunction(const float state, const float thau, const float weight);
		
		/**
		 * @brief Construtor para uma função de ativação alfa
		 * 
		 * @param params Parâmetros em ordem igual ao outro construtor
		 */
		AlphaFunction(const float* params);

		/**
		 * @brief Faz a equação referente ao modelo em questão
		 * 
		 * @param input A entrada da equação
		 */
		void ModelDiferentialEquation(const float input) override;
		
		/**
		 * @brief Get para os parâmetros do modelo
		 * 
		 * @param param Um char (t ou w) que indentifica o parâmetro em questão
		 * @return const float
		 */
		const float getParams(const char param) override;

		/**
		 * @brief Não utilizado para a função alfa
		 */
		void NotifyObservers() override;

		/**
		 * @brief Compara duas funções alfas
		 * 
		 * @param other A outra função para comparação
		 * @return boolean
		 */
		bool operator==(const AlphaFunction& other);
	};
} // namespace ode
