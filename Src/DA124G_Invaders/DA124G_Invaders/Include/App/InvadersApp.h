#ifndef INVADERS_APP_H
#define INVADERS_APP_H
#pragma once

#include <vector>
#include <list>
#include <unordered_map>
#include <random>

#include "App/Entity/IEntity.h"

/*
	The main class for the entire application.
	Holds the global state, and offers a limited interface for queries from entities.
*/
class InvadersApp
{
	
public:
	InvadersApp();
	~InvadersApp();

	int init();
	int run();

	CreateEntityFunc getCreateFunc( const char* str )
	{
	#ifdef _DEBUG
		return m_createEntityTable.at( str );
	#else
		return m_createEntityTable[ str ];
	#endif
	}
	Guid createRandomSpawnable();
	IEntity * getEntity( Guid id );
	Guid createEntity( const char* entityHashName, void *pParams );
	void destroyEntity( Guid id );

private:

	typedef std::list< CreateEntityFunc > CreateEntityFuncVector;
	typedef std::unordered_map< const char*, CreateEntityFunc > HashToCreateEntityFuncTable;
	typedef std::map< Guid, IEntity > GuidToEntityTable;

	GuidToEntityTable m_entityTable;
	HashToCreateEntityFuncTable m_createEntityTable;
	CreateEntityFuncVector m_randomSpawnables;
};

extern InvadersApp g_app;
#endif