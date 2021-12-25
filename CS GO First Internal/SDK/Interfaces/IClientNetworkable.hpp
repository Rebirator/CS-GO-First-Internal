#ifndef __SDK_INTEFACES_ICLIENTNETWORKABLE_HPP__
#define __SDK_INTEFACES_ICLIENTNETWORKABLE_HPP__

#include <stierr.h>
#include "IClientUnknown.hpp"

enum ShouldTransmitState_t {
	SHOULDTRANSMIT_START = 0,	// The entity is starting to be transmitted (maybe it entered the PVS).

	SHOULDTRANSMIT_END			// Called when the entity isn't being transmitted by the server.
								// This signals a good time to hide the entity until next time
								// the server wants to transmit its state.
};

enum DataUpdateType_t {
	DATA_UPDATE_CREATED = 0,
//	DATA_UPDATE_ENTERED_PVS,
	DATA_UPDATE_DATATABLE_CHANGED,
//	DATA_UPDATE_LEFT_PVS,
//	DATA_UPDATE_DESTROYED,
	DATA_UPDATE_POST_UPDATE,
};

class IClientNetworkable {
	virtual IClientUnknown*	GetIClientUnknown( ) = 0;
	virtual void			Release( ) = 0;
	virtual void*			GetClientClass( ) = 0; // virtual ClientClass*	GetClientClass( ) = 0;
	virtual void			NotifyShouldTransmit( ShouldTransmitState_t state ) = 0;
	virtual void			OnPreDataChanged( DataUpdateType_t updateType ) = 0;
	virtual void			OnDataChanged( DataUpdateType_t updateType ) = 0;
	virtual void			PreDataUpdate( DataUpdateType_t updateType ) = 0;
	virtual void			PostDataUpdate( DataUpdateType_t updateType ) = 0;
	virtual void			OnDataUnchangedInPVS( ) = 0;
	virtual bool			IsDormant( void ) const = 0;
	virtual int				entindex( void ) const = 0;
	virtual void			ReceiveMessage( int classID/*, bf_read &msg*/ ) = 0;
	virtual void*			GetDataTableBasePtr( ) = 0;
	virtual void			SetDestroyedOnRecreateEntities( void ) = 0;
};

#endif//__SDK_INTEFACES_ICLIENTNETWORKABLE_HPP__
