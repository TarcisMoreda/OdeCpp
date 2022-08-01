#pragma once

#include "OdeModel.hpp"

namespace ode{
	class IModelArray{
	public:
		virtual ~IModelArray() = default;
	};

	template<typename ModelType>
	class ModelArray{
	private:
		std::vector<ModelType&> modelArray;

	public:
		void append(ModelType& model){
			this->modelArray.insert(model);
		}
		void remove(const int index){
			auto iterator = this->modelArray.begin()+(index+1);
			this->modelArray.erase(iterator);
			this->modelArray.shrink_to_fit();
		}

		ModelType& get(const int index){
			if(index>=this->modelArray.size()) return NULL;
			return this->modelArray.at(index);
		}

		int size(){
			return this->modelArray.size();
		}
	};
} // namespace ode