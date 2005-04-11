// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "LifespanPolicyC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/enum_typecode.cpp:34

static char const * const _tao_enumerators_PortableServer_LifespanPolicyValue[] =
  {
    "TRANSIENT",
    "PERSISTENT"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_LifespanPolicyValue (
    "IDL:omg.org/PortableServer/LifespanPolicyValue:2.3",
    "LifespanPolicyValue",
    _tao_enumerators_PortableServer_LifespanPolicyValue,
    2);
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_LifespanPolicyValue =
    &_tao_tc_PortableServer_LifespanPolicyValue;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_LifespanPolicy (
    "IDL:omg.org/PortableServer/LifespanPolicy:2.3",
    "LifespanPolicy");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_LifespanPolicy =
    &_tao_tc_PortableServer_LifespanPolicy;
}



// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::LifespanPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::LifespanPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_LifespanPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::LifespanPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::LifespanPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_LifespanPolicyValue,
        _tao_elem 
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::LifespanPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::LifespanPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::LifespanPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::LifespanPolicy_ptr _tao_elem
  )
{
  PortableServer::LifespanPolicy_ptr _tao_objptr =
    PortableServer::LifespanPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::LifespanPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::LifespanPolicy>::insert (
      _tao_any,
      PortableServer::LifespanPolicy::_tao_any_destructor,
      PortableServer::_tc_LifespanPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::LifespanPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::LifespanPolicy>::extract (
        _tao_any,
        PortableServer::LifespanPolicy::_tao_any_destructor,
        PortableServer::_tc_LifespanPolicy,
        _tao_elem
      );
}
