#ifndef _APP_RTGI_WITH_RRF_MODEL_H_
#define _APP_RTGI_WITH_RRF_MODEL_H_

#include <CppUtil/Basic/HeapObj.h>

#include <vector>
#include <string>

namespace App {
	class Layer;

	class Model : public CppUtil::Basic::HeapObj {
		HEAP_OBJ_SETUP(Model)
	public:
		explicit Model(const std::string & name = "")
			: name(name) { }

	public:
		const std::string GetFuncName() const { return name; }
		const std::vector<CppUtil::Basic::CPtr<Layer>> & GetLayers() const { return layers; }
		int GetInputDim() const;
		int GetOutputDim() const;
		int GetIDof(CppUtil::Basic::CPtr<Layer> layer) const;

	public:
		bool AddLayer(CppUtil::Basic::CPtr<Layer> layer) const;
		const std::string GenFunc(bool genLayers = true) const;

	private:
		mutable std::vector<CppUtil::Basic::CPtr<Layer>> layers;
		std::string name;
	};
}

#endif//!_APP_RTGI_WITH_RRF_MODEL_H_
