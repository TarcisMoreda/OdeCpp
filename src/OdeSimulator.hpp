#pragma once

#include <unordered_map>
#include <memory>
#include "OdeSolver.hpp"
#include "OdeModel.hpp"

namespace ode{
	class IModelArray{
	public:
		virtual ~IModelArray() = default;
	};

	template<typename ModelType>
	class ModelArray: public IModelArray{
	private:
		std::vector<ModelType&> modelArray;
	public:
		void push_back(ModelType& model){
			this->modelArray.push_back(model);
		}

		int size(){
			return this->modelArray.size();
		}

		ModelType& getModel(const int index){
			return this->modelArray.at(index);
		}
	};

	template<typename SolverType>
	class OdeSimulator{
	protected:
		SolverType solver;
		std::unordered_map<const char*, std::shared_ptr<IModelArray>> models;

		template<typename ModelType>
		std::shared_ptr<ModelArray<ModelType>> getModelArray(){
			const char* typeName = typeid(ModelType).name();
			return std::static_pointer_cast<ModelArray<ModelType>>(this->models[typeName]);
		}

	public:
		virtual float neuronSetStep(const float interval, const std::vector<int> inputs) = 0;
		
		template<typename ModelType>
		void addModel(ModelType& model){
			const char* typeName = typeid(ModelType).name();
			if(this->models.count(typeName)==0){
				this->models.insert({typeName, std::make_shared<ModelArray<ModelType>>});
			}
			
			this->getModelArray<ModelType>()->modelArray.push_back(model);
		}
	};
} // namespace ode