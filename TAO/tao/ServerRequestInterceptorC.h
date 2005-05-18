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

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_SERVERREQUESTINTERCEPTORC_H_
#define _TAO_IDL_ORIG_SERVERREQUESTINTERCEPTORC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/InterceptorC.h"
#include "tao/OctetSeqC.h"
#include "tao/PIForwardRequestC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableInterceptor
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINFO__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINFO__VAR_OUT_CH_

  class ServerRequestInfo;
  typedef ServerRequestInfo *ServerRequestInfo_ptr;

  typedef
    TAO_Objref_Var_T<
        ServerRequestInfo
      >
    ServerRequestInfo_var;

  typedef
    TAO_Objref_Out_T<
        ServerRequestInfo
      >
    ServerRequestInfo_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR__VAR_OUT_CH_

  class ServerRequestInterceptor;
  typedef ServerRequestInterceptor *ServerRequestInterceptor_ptr;

  typedef
    TAO_Objref_Var_T<
        ServerRequestInterceptor
      >
    ServerRequestInterceptor_var;

  typedef
    TAO_Objref_Out_T<
        ServerRequestInterceptor
      >
    ServerRequestInterceptor_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR_CH_

  class TAO_Export ServerRequestInterceptor
    : public virtual ::PortableInterceptor::Interceptor
  {
  public:
    typedef ServerRequestInterceptor_ptr _ptr_type;
    typedef ServerRequestInterceptor_var _var_type;

    // The static operations.
    static ServerRequestInterceptor_ptr _duplicate (ServerRequestInterceptor_ptr obj);

    static void _tao_release (ServerRequestInterceptor_ptr obj);

    static ServerRequestInterceptor_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ServerRequestInterceptor_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ServerRequestInterceptor_ptr _nil (void)
    {
      return static_cast<ServerRequestInterceptor_ptr> (0);
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

#if TAO_HAS_EXTENDED_FT_INTERCEPTORS == 1

    virtual void tao_ft_interception_point (
        ::PortableInterceptor::ServerRequestInfo_ptr ri,
        ::CORBA::OctetSeq_out os
        ACE_ENV_ARG_DECL_NOT_USED
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) {}

#endif /* TAO_HAS_EXTENDED_FT_INTERCEPTORS */

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void receive_request_service_contexts (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void receive_request (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void send_reply (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void send_exception (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void send_other (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    ServerRequestInterceptor (void);

    virtual ~ServerRequestInterceptor (void);

  private:
    // Private and unimplemented for concrete interfaces.
    ServerRequestInterceptor (const ServerRequestInterceptor &);

    void operator= (const ServerRequestInterceptor &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_ServerRequestInterceptor;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINFO__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINFO__TRAITS_CH_

  template<>
  struct TAO_Export Objref_Traits< ::PortableInterceptor::ServerRequestInfo>
  {
    static ::PortableInterceptor::ServerRequestInfo_ptr duplicate (
        ::PortableInterceptor::ServerRequestInfo_ptr
      );
    static void release (
        ::PortableInterceptor::ServerRequestInfo_ptr
      );
    static ::PortableInterceptor::ServerRequestInfo_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableInterceptor::ServerRequestInfo_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR__TRAITS_CH_

  template<>
  struct TAO_Export Objref_Traits< ::PortableInterceptor::ServerRequestInterceptor>
  {
    static ::PortableInterceptor::ServerRequestInterceptor_ptr duplicate (
        ::PortableInterceptor::ServerRequestInterceptor_ptr
      );
    static void release (
        ::PortableInterceptor::ServerRequestInterceptor_ptr
      );
    static ::PortableInterceptor::ServerRequestInterceptor_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableInterceptor::ServerRequestInterceptor_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


