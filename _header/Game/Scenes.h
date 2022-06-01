#pragma once

#include "Scene/SceneList.h"
#include "SystemChainIDs.h"

namespace wasp::game{

	enum class SceneNames {
		main,
		difficulty,
		start_difficulty,		//goes to same difficulty scene
		practice_difficulty,	//goes to same difficulty scene
		shot,
		level,
		music,
		options,
		game,
		dialogue,
		pause,
		continues,
		credits
	};

	using Scene = scene::Scene<SystemChainIDs, SceneNames>;
	using SceneList = scene::SceneList<SystemChainIDs, SceneNames>;

	SceneList makeSceneList();
}