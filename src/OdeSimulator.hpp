#pragma once

#include <unordered_map>
#include <memory>
#include "OdeSolver.hpp"
#include "OdeModel.hpp"
#include "Containers.hpp"

namespace ode{
	template<typename SolverType>
	class OdeSimulator{
	protected:
		SolverType solver;
		std::unordered_map<const char*, std::shared_ptr<IModelArray>> models{};

		template<typename ModelType>
		std::shared_ptr<ModelArray<ModelType>> getModelArray(){
			const char* typeName = typeid(ModelType).name();
			if(this->models.count(typeName)==0) return NULL;
			return std::static_pointer_cast<ComponentArray<ModelType>>(this->models[typeName]);
		}

	public:
		virtual float neuronSetStep(const float interval, const std::vector<int> inputs) = 0;
		
		template<typename ModelType>
		void addModel(ModelType& model){
			const char* typeName = typeid(ModelType).name();
			if(this->models.count(typeName)==0){
				std::vector<ModelType&> tempVec;
				this->models.insert({typeName, std::make_shared<ModelArray<ModelType>>()});
			}
			
			getModelArray<ModelType>()->insert(model);
		}
	};
} // namespace ode