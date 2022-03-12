#ifndef _SCENE_CONVEX_HULL_2D_
#define _SCENE_CONVEX_HULL_2D_

#include <vector>
#include <queue>

#include <raylib-cpp.hpp>

#include <glm/gtc/random.hpp>
#include <glm/vec2.hpp>

#include "../Convex-Hull/IConvexHull.h"
#include "SceneSystem/SceneManager.h"
#include "../Utils.h"

class SceneCH2D : public IScene
{
public:
	explicit SceneCH2D(std::shared_ptr<SceneManager> pSceneManager,
					   const std::string& sceneID,
					   const int width,
					   const int height);
	
	void OnInitialize() override;
	void OnRender() override;
	void OnHandleEvent(const Event& event) override;

	void RegeneratePoints(const int numPoints);
private:
	std::vector<glm::vec2> m_allPoints;
	std::vector<int> m_hullIndices;

	std::shared_ptr<IConvexHull2D> m_ch2D;

	std::queue<std::shared_ptr<IAnimFrame2D>> m_animFrameQueue;
};

#endif
