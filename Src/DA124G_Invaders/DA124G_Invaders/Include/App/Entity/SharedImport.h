/*
	Load entityInfo structure(s) from a shared file/directory, given its filename/directoryname.
	Implementation only exist for windows at the moment.
*/

#ifndef SHARED_IMPORT_H
#define SHARED_IMPORT_H
#pragma once

#include "App/Entity/IEntity.h"

struct SharedEntityInfo
{
	CreateEntityFunc m_createEntity;
	const char* m_name;
	bool m_isEnemyRandomSpawnable;
}

bool loadSharedFile( const char *sharedDirName, SharedEntityInfo *pInInfo );
bool loadSharedDir( const char *sharedFileName, std::vector< SharedEntityInfo > *pInInfoVector );'

#endif // SHARED_IMPORT_H