#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"
#include <vector>
#include <map>

struct Ability
{
	std::string myName;
	int myDamage;
};

enum ItemTypes
{
	WEAPON,
	HELMET,
	CHESTPLATE,
	LEGGINGS,
	SHOES,
	SCROLL,
	CONSUMABLE,
	LENGTH
};

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update();

	virtual void ModifyHealth(int someHealth); //Modifies Entity Health
	virtual void ModifyAbilities(int aAbilityNumber, std::string aName, int anAmount);
	virtual void SetItemType(ItemTypes aType);
	virtual void SetDamageMultiplier(int anAmount);
	virtual void SetProtectionMultiplier(int anAmount);
	virtual void SetHealthMultiplier(int anAmount);
	virtual void SetEnchantable(bool aStatement);
	virtual void SetHealingConstant(int anAmount);
	virtual void SetCost(int anAmount);
	virtual void SetValue(int anAmount);
	virtual void SetGold(int someGold);
	virtual void SetExperience(int anAmount);
	virtual void SetName(std::string aName);
	virtual void SetId(int anId);
	virtual void SetHealthMax(int anAmount);
	virtual void SetHealth(int anAmount);
	virtual void SetDamage(int anAmount);
	virtual void SetDropRate(float anAmount);
	virtual void SetActiveFlag(bool aStatement);
	virtual void SetAbilities(std::map<int, Ability> someAbilities);

	virtual const bool& GetActiveFlag();
	virtual const int& GetHealth();
	virtual const int& GetHealthMax();
	virtual const int& GetGold();
	virtual const int& GetDamage();
	virtual const int& GetProtection();
	virtual const int& GetID();
	virtual const int& GetLevel();
	virtual const int& GetProtectionMultiplier();
	virtual const int& GetDamageMultiplier();
	virtual const int& GetHealingConstant();
	virtual const int& GetHealthMultiplier();
	virtual const int& GetCost();
	virtual const int& GetValue();
	virtual const std::string& GetName();
	virtual const float& GetDropRate();
	virtual const ItemTypes& GetItemType();
	virtual const int& GetExperience();
	virtual const std::map<int, Ability>& GetAbilities();

protected:
	std::string myName;
	bool myActiveFlag;
	int
		myLevel,
		myGold,
		myProtection;
	float
		myDropRate;
	int
		myHealth,
		myHealthMax,
		myDamage,
		myId,
		myHealthMultiplier,
		myDamageMultiplier,
		myProtectionMultiplier,
		myHealingConstant,
		myCost,
		myExperience,
		myValue;
	bool myEnchantable;

	ItemTypes myItemType;
	std::map<int, Ability> myAbilities;
};

#endif