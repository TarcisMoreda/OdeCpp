#pragma once

#include "IModel.hpp"

namespace ode{
	class ModelFactory{
		public:
		/**
		 * @brief Cria um novo modelo
		 * 
		 * @tparam model Tipo do modelo a ser criado
		 * @param params Lista de parâmetros para o modelo
		 * @return model* Ponteiro de tipo do modelo
		 */
		template<typename m>
		m CreateNewModel(const float params[]){
			return m(params);
		}
	};
}