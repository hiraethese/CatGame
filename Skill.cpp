#include "Skill.h"

Skill::Skill(bool canShootWithLMB,
	bool canRandomlySpawnEnemy)
{
	_skills["canShootWithLMB"] = canShootWithLMB;
	_skills["canRandomlySpawnEnemy"] = canRandomlySpawnEnemy;
}

void Skill::ChangeSkill(const std::string& skillName, bool newValue)
{
	auto skill = _skills.find(skillName);

	if ( skill != _skills.end() ) {
		skill->second = newValue;
	}
}

void Skill::CheckAndPerformAction(Spawner* spawner, Vector2 startPos)
{
	if ( _skills["canShootWithLMB"] )
	{
		ShootWithLMB(spawner, startPos);
	}

	if (_skills["canRandomlySpawnEnemy"])
	{
		RandomlySpawnEnemy(spawner);
	}
}
