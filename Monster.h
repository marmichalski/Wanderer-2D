#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"


class BitmapFont;
class Player;

class Monster : public Creature
{
public:
	Monster();

	virtual ~Monster()
	{
		std::cout << "Destruktor klasy Monster" << std::endl;
	}

	virtual void Think( void );
	virtual void Draw( void );

	void SetBaseDamage( int baseDamage ) { m_baseDamage = baseDamage; }
	int GetBaseDamage( void ) const { return m_baseDamage; }

	void SetNextMove( int nextMove )
	{
		m_nextMove = nextMove;
	}

	int GetNextMove( void )
	{
		return m_nextMove;
	}

	void SetNextAttack( int nextAttack )
	{
		m_nextAttack = nextAttack;
	}

	int GetNextAttack( void ) 
	{
		return m_nextAttack;
	}

	void SetAttackingPlayer( bool b )
	{
		m_attackingPlayer = b;
	}

	bool GetAttackingPlayer( void )
	{
		return m_attackingPlayer;
	}

	void SetAttackedByPlayer( bool b )
	{
		m_attackedByPlayer = b;
	}

	bool GetAttackedByPlayer( void )
	{
		return m_attackedByPlayer;
	}

	int GetRespawnTime( void )
	{
		return m_respawnTime;
	}

	Position GetRespawnPosition( void )
	{
		return m_respawnPosition;
	}

	void SetRespawnPosition( Position respawnPosition )
	{
		m_respawnPosition.x = respawnPosition.x;
		m_respawnPosition.y = respawnPosition.y;
	}

	void SetRespawnTime( int respawnTime )
	{
		m_respawnTime = respawnTime;
	}

	int GetDeathTime ( void )
	{
		return m_deathTime;
	}

	void SetDeathTime( int deathTime )
	{
		m_deathTime = deathTime;
	}

	bool IsAlive( void )
	{
		if( GetHealthPoints() > 0 )
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void RandomMovement( void );
	void AttackPlayer();
	void CreateCorpse( void );
	void DrawHealthBar( void );

private:
	int m_baseDamage;
	int m_nextMove;
	int m_nextAttack;

	Position m_respawnPosition;
	int m_respawnTime;
	int m_deathTime;

	bool m_attackingPlayer;
	bool m_attackedByPlayer;

	Sprite m_attackingPlayerSprite;
	Sprite m_attackedByPlayerSprite;
	Sprite m_healthBarSprite;
	BitmapFont* m_healthPointsFont;
};

#endif