#include "Spawner.h"
#include "Skill.h"

#include "Character.h"

Character::Character(Vector2 position,
	Vector2 size,
	float speed,
	int currentHealth,
	int maxHealth,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_sprite = new Drawer(true, texture, _transform);
	_movement = new Movement(speed, _transform);
	_health = new Health(currentHealth, maxHealth, false, false);

	Vector2 healthBarLocation = Vector2Add( _transform->GetPosition(), { 0.0f, -10.0f } );
	_healthBar = new Bar( healthBarLocation, { 45.0f, 5.0f },
		GREEN, GRAY, _health->GetCurrentHealth(), _health->GetMaxHealth() );

	_skill = new Skill(false, false);
	_isGarbage = false;
}

void Character::UpdateProtagonist(Spawner* spawner)
{
	_movement->MoveWithKeyboard();

	_sprite->Draw();

	_skill->CheckAndPerformAction( spawner, _transform->GetPosition() );
}

void Character::UpdateEnemy(Vector2 target)
{
	_movement->ChaseTarget(target);

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

Movement* Character::GetMovement()
{
	return _movement;
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
