#include "NetVarManager.hpp"
#include "Interfaces.hpp"

CNetVar g_NetVar { };

RecvProp CNetVar::GetPropPtrFromTable( const char* prop, RecvTable* recv_table ) {
    for ( int i = 0; i < recv_table->m_nProps; i++ ) {
        RecvProp recv_prop = recv_table->m_pProps[ i ];

        if ( _stricmp( recv_prop.m_pVarName, prop ) == 0 )
            return recv_prop;
    }

    return RecvProp( 0 );
}

intptr_t CNetVar::GetPropOffsetFromTable( const char* prop, RecvTable* recv_table ) {
    for ( int i = 0; i < recv_table->m_nProps; i++ ) {
        RecvProp recv_prop = recv_table->m_pProps[ i ];

        if ( _stricmp( recv_prop.m_pVarName, prop ) == 0 )
            return recv_prop.m_Offset;

        if ( recv_prop.m_pDataTable != nullptr ) {
            intptr_t extra = GetPropOffsetFromTable( prop, recv_prop.m_pDataTable );

            if ( extra )
                return recv_prop.m_Offset + extra;
        }
    }

    return 0;
}

RecvProp CNetVar::GetPropPtr( const char* table, const char* prop ) {
    for ( CClientClass* cur_class = g_Interfaces.m_pClient->GetAllClasses( ); cur_class != nullptr; cur_class = cur_class->m_pNext ) {
        if ( _stricmp( cur_class->m_pRecvTable->m_pNetTableName, table ) == 0 )
            return GetPropPtrFromTable( prop, cur_class->m_pRecvTable );
    }

    return RecvProp( 0 );
}

intptr_t CNetVar::GetPropOffset( const char* table, const char* prop ) {
    for ( CClientClass* cur_class = g_Interfaces.m_pClient->GetAllClasses( ); cur_class != nullptr; cur_class = cur_class->m_pNext ) {
        if ( _stricmp( cur_class->m_pRecvTable->m_pNetTableName, table ) == 0 )
            return GetPropOffsetFromTable( prop, cur_class->m_pRecvTable );
    }

    return 0;
}
