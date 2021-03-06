#ifndef _EVENTS_
#define _EVENTS_

#include <glm/vec2.hpp>
#include "Convex-Hull/ConvexHullAlgos.h"

struct Event 
{
public:
	enum class TYPE 
	{ 
		GEN_PTS,
		COMPUTE_CH,
		SET_TIMESTEP,
		SET_CH_ALGO,
	};
public:
	struct GenPointsEvent { int numPoints; };
	struct SetTimeStep { float timeStep; };
	struct SetChAlgo { CH_ALGO algoType; };
public:
	union 
	{
		GenPointsEvent genPtsData;
		SetTimeStep setTimeStepData;
		SetChAlgo setChAlgoData;
	};
public:
	TYPE type;
};

#endif
