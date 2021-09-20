#ifndef __ENTITY__
#define __ENTITY__

class Entity
{
public:
	BYTE	GetFlags( );
	int		GetTeam( );
	bool	IsDormant( );
	bool	IsSpotted( );
};

#endif