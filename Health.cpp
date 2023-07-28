#include "Health.h"

Health::Health(int currentHealth, int maxHealth, bool isInvunerable, bool isDead)
{
	_currentHealth = currentHealth;
	_maxHealth = maxHealth;
	_isInvunerable = isInvunerable;
	_isDead = isDead;
}

void Health::SetInvulnerability(bool isInvunerable)
{
	_isInvunerable = isInvunerable;
}

void Health::TakeDamage(int damagePoints)
{
	if (!_isInvunerable)
	{
		_currentHealth -= damagePoints;

		if (_currentHealth <= 0)
		{
			_currentHealth = 0;
			_isDead = true;
		}
	}
}

void Health::HealDamage(int healPoints)
{
	_currentHealth += healPoints;

	if (_currentHealth >= _maxHealth)
	{
		_currentHealth = _maxHealth;
	}
}

int Health::GetCurrentHealth()
{
	return _currentHealth;
}

int Health::GetMaxHealth()
{
	return _maxHealth;
}
