#ifndef __SINGLETON__
#define __SINGLETON__

#include <mutex>

template < class T >
class Singleton {
protected:
	Singleton( ) { }
	~Singleton( ) { }

	Singleton( const Singleton& )				= delete;
	Singleton& operator = ( const Singleton& )	= delete;

	Singleton( Singleton&& )					= delete;
	Singleton& operator = ( Singleton&& )		= delete;

public:
	static T& Get() {
		static T Inst { };

		return Inst;
	}
};

#endif
