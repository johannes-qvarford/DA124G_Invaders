#include "App\InvadersApp.h"

int main()
{
	int retVal;
	retVal = g_app.init();
	if( retVal != 0 )
		return retVal;
	return g_app.run();
    return 0;
}