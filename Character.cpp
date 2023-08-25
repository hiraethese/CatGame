#include "Spawner.h"
#include "Skill.h"

#include "Character.h"

Character::Character(b2World* world,
	Vector2 position,
	Vector2 size,
	float speed,
	int currentHealth,
	int maxHealth,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_physicsBody = new PhysicsBody(world, _transform, b2_dynamicBody, speed);
	_sprite = new Drawer(true, texture, _transform);
	_health = new Health(currentHealth, maxHealth, false, false);

	_healthBar = new Bar(_transform, GREEN, GRAY,
		_health->GetCurrentHealth(), _health->GetMaxHealth());

	_skill = new Skill(false, false);
	_isGarbage = false;
}

void Character::UpdateProtagonist(Spawner* spawner)
{
	_physicsBody->MoveWithKeyboard();

	_sprite->Draw();

	_skill->CheckAndPerformAction( spawner, _transform->GetPosition() );
}

void Character::UpdateEnemy(Vector2 target)
{
	_physicsBody->ChaseTarget(target);

	_sprite->Draw();
}

MyTransform* Character::GetTransform()
{
	return _transform;
}

Drawer* Character::GetDrawer()
{
	return _sprite;
}

PhysicsBody* Character::GetPhysicsBody()
{
	return _physicsBody;
}

Health* Character::GetHealth()
{
	return _health;
}

Skill* Character::GetSkill()
{
	return _skill;
}

bool Character::IsGarbage()
{
	return _isGarbage;
}
