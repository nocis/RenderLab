#ifndef _RASTER_SCENE_CREATOR_H_
#define _RASTER_SCENE_CREATOR_H_

#include <CppUtil/Basic/HeapObj.h>

namespace CppUtil {
	namespace Basic {
		class Operation;
	}

	namespace Qt {
		class RawAPI_OGLW;

		class RasterSceneCreator {
		public:
			RasterSceneCreator(RawAPI_OGLW * pOGLW);

		public:
			class SceneOp : public Basic::HeapObj {
				HEAP_OBJ_SETUP(SceneOp)
					friend class RasterSceneCreator;

			public:
				SceneOp(Qt::RawAPI_OGLW * pOGLW);
				bool SetOp();
				Qt::RawAPI_OGLW * GetOGLW() { return pOGLW; }

			private:
				Basic::Ptr<Basic::Operation> GetDefaultResizeOp();
				Basic::Ptr<Basic::Operation> GetDefaultListenerInitOp();

			private:
				Qt::RawAPI_OGLW * pOGLW;

				Basic::Ptr<Basic::Operation> initOp;
				Basic::Ptr<Basic::Operation> paintOp;
				Basic::Ptr<Basic::Operation> resizeOp;
				Basic::Ptr<Basic::Operation> listenerInitOp;
			};

			SceneOp::Ptr GenScenePaintOp(int n);

		private:
			SceneOp::Ptr GenScenePaintOp_0();
			SceneOp::Ptr GenScenePaintOp_1();

		private:
			Qt::RawAPI_OGLW * pOGLW;
		};

	}
}


#endif // !_RASTER_SCENE_CREATOR_H_
