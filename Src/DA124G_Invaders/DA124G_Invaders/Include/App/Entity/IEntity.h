#ifndef IENTITY_H
#define IENTITY_H
#pragma once

typedef size_t Guid;

/*
	The common interface for updateable entities in the game world.
*/
class IEntity
{
	virtual bool update( int msecs );
	virtual Guid getGuid();
};

typedef IEntity* (*CreateEntityFunc) ( void *pParams );

#endif