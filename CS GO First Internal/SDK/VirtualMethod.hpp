#ifndef __SDK_VIRTUALMETHOD_HPP__
#define __SDK_VIRTUALMETHOD_HPP__

#define __create_thiscall_fn( return_type, ... ) return_type( __thiscall* )( void*, __VA_ARGS__ )
//===============================================//
#define __thiscall_fn( varname, ... ) ( __thiscall* varname )( void*, __VA_ARGS__ )  

#define GET_VIRTUAL_METHOD( return_type, method_index, ... ) ( *reinterpret_cast< return_type ( __thiscall*** )( void*, __VA_ARGS__ ) >( this ) )[ method_index ]
//===============================================//
#define VIRTUAL_METHOD( return_type, name, method_index, call_args, ... ) \
return_type name( __VA_ARGS__ ) noexcept { \
    return GET_VIRTUAL_METHOD( return_type, method_index, __VA_ARGS__ )call_args;  \
}

#endif  __SDK_VIRTUALMETHOD_HPP__
