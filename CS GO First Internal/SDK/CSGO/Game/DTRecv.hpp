#ifndef __SDK_GAME_DTRECV_HPP__
#define __SDK_GAME_DTRECV_HPP__

// Predeclares
struct RecvProp;
struct RecvTable;

struct CRecvProxyData {
	RecvProp* m_pRecvProp;	// The property it's receiving.
	union {					// The value given to you to store. 
		float m_fFloat;
		long  m_lInt;
		char* m_pString;
		void* m_pData;
		float m_fX;
		float m_fY;
		float m_fZ;
		INT64 m_lInt64;
	} m_pValue;
	int		  m_iElement;	// Which array element you're getting.
	int		  m_iObjectID;	// The object being referred to.
};

using RecvVarProxy = void( * )( const CRecvProxyData& data, void* structure, void* out );

struct RecvProp {
	char*					m_pVarName;
	int						m_RecvType;
	int						m_Flags;
	int						m_StringBufferSize;
	bool					m_bInsideArray;			// Set to true by the engine if this property sits inside an array.
	const void*				m_pExtraData;			// Extra data that certain special property types bind to the property here.
	RecvProp*				m_pArrayProp;			// If this is an array (DPT_Array).
	void*					m_ArrayLengthProxy;
	RecvVarProxy			m_Proxy;
	void*					m_DataTableProxy;		// For RDT_DataTable.
	RecvTable*				m_pDataTable;			// For RDT_DataTable.
	int						m_Offset;
	int						m_ElementStride;
	int						m_nElements;
	const char*				m_pParentArrayPropName;	// If it's one of the numbered "000", "001", etc properties in an array, then these can be used to get its array property name for debugging.
};

struct RecvTable {
	RecvProp*		m_pProps;		 // Properties described in a table.
	int				m_nProps;
	void*			m_pDecoder;
	char*			m_pNetTableName; // The name matched between client and server.
	bool			m_bInitialized;
	bool			m_bInMainList;
};

#endif  __SDK_GAME_DTRECV_HPP__
