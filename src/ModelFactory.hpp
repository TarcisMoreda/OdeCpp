#pragma once

#include "BaseModel.hpp"
#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"

namespace ode{
    class ModelFactory{
        public:
        /**
         * @brief Cria um novo modelo
         * 
         * @tparam model Tipo do melo a ser criado
         * @param params Lista de parâmetros para o modelo
         * @return BaseModel* Ponteiro de tipo genêrico para o modelo
         */
        template <typename model>
        BaseModel* CreateNewModel(const float params[]){
            return new model(params);
        }
    };
}