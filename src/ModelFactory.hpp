#pragma once

#include "BaseModel.hpp"
#include "IzhikevichModel.hpp"
#include "AlphaFunction.hpp"
#include "Constants.hpp"

namespace ode{
    class ModelFactory{
        public:
        BaseModel* CreateNewModel(ModelType type, const float params[]){
            switch(type){
            case IZHIKEVICH:
                return new IzhikevichModel(params[0], params[1], params[2], params[3]);
            case ALPHA:
                return new AlphaFunction(params[0], params[1], params[2]);
            default:
                return nullptr;
            }
        }
    };
}