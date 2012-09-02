#include <cassert>

#include "App/InvadersApp.h"
#include "App/Entity/SharedImport.h"

const char *kSharedDirName = "shared";
const char *kEntityNameInitGame = "InitGame";

#include <random>

std::random

InvadersApp::InvadersApp()
{

}


InvadersApp::~InvadersApp()
{
}

int InvadersApp::init()
{
	/*
		Fill a vector with SharedEntityInfo, collected by importing shared files located in kDirName.
		On any kind if error, abort.
	*/
	std::vector< SharedEntityInfo > vec;
	{
		
		bool success = loadSharedDir( kSharedDirName, &vec );
		if( !success )
			assert( 0 && "Could not read directory: \"shared\"" );
	}

	/*
		Iterate over imported SharedEntityInfo instances. 
		Add entity creating functions to lists and tables depending on the data stored in them. 
	*/
	{
		std::vector< SharedEntityInfo >::iterator it;
		std::vector< SharedEntityInfo >::iterator end = vec.end();
		SharedEntityInfo info;
		for( it = vec.begin(); it != end; ++it )
		{
			info = *it;
			m_createEntityTable.insert( std::make_pair( info.m_name, info.m_createEntity ) );
			if ( info.m_isEnemyRandomSpawnable )
				m_randomSpawnables.push_back( info.m_createEntity );
		}
	}

	createEntity( kEntityNameInitGame, NULL );
}