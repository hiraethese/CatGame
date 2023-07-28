#pragma once

class Health
{
private:
	int _currentHealth;
	int _maxHealth;
	bool _isInvunerable;
	bool _isDead;

public:
	Health(int currentHealth, int maxHealth, bool isInvunerable, bool isDead);
	void SetInvulnerability(bool isInvunerable);
	void TakeDamage(int damagePoints);
	void HealDamage(int healPoints);
	int GetCurrentHealth();
	int GetMaxHealth();
};
