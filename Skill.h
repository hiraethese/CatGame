#pragma once

#include <unordered_map>
#include "skillLibrary.h"

class Skill
{
private:
	std::unordered_map<std::string, bool> _skills;

public:
	Skill(bool canShootWithLMB,
		bool canRandomlySpawnEnemy);

	void ChangeSkill(const std::string& skillName, bool newValue);
	void CheckAndPerformAction(Spawner* spawner, Vector2 startPos);
};
