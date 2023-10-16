#pragma once

#include "IModel.hpp"
#include "ISolver.hpp"
#include "Observer.hpp"
#include <cstddef>

namespace ode{
	template<typename model1, typename model2, size_t size>
	class ISimulator{
	protected:
		ISolver<model1>* mModelSolver;
		ISolver<model2>* mFunctionSolver;
		model1 mModel[size];
		model2 mFunction[size];
		size_t mSize=0;
		IObserver* mObserver;

	public:
		ISimulator(ISolver<model1>* s1, ISolver<model2>* s2){
			this->mModelSolver = s1;
			this->mFunctionSolver = s2;
		}
		~ISimulator(){
			for(size_t i=0; i<this->mSize; ++i){
				delete this->mModel[i];
				delete this->mFunction[i];
			}
			delete this->mModel;
			delete this->mFunction;
		}
		virtual float NeuronStep(const float* inputs, const float interval) = 0;
		
		void InsertModel(model1& m1, model2& m2){
			if(size==this->mSize)
				return;
			
			this->mModel[this->mSize] = m1;
			this->mFunction[this->mSize++] = m2;
		};
	};
} // namespace ode