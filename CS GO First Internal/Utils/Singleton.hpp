#ifndef __SINGLETON__
#define __SINGLETON__

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
	static T& G( ) {
		static T Inst { };

		return Inst;
	}

	static T*& pG( ) {
		static T* Inst { };

		return Inst;
	}
};

template < class T >
class _Singleton_ {
public:
	static T& G( ) {
		static T Inst { };

		return Inst;
	}

	static T*& pG( ) {
		static T* Inst { };

		return Inst;
	}
};

#endif//__SINGLETON__
