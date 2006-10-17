//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_semantics.h'                           *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     october 13th, 2006, at 16h32'15"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_semantics_DEFINED
#define goil_semantics_DEFINED

#include <string.h>

#include "galgas/C_GGS_Object.h"
#include "galgas/AC_galgas_io.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/C_Lexique.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_number_list ;
class GGS_number_set ;
class cPtr_number_set ;
class GGS_uint_range ;
class cPtr_uint_range ;
class GGS_uint_list ;
class cPtr_uint_list ;
class GGS_implementationSpec ;
class GGS_implementation ;
class GGS_os_imp ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           list '@number_list'                             *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_number_list ;

class GGS_number_list {
  public : typedef elementOf_GGS_number_list element_type ;
//--- Embedded class for list root
  protected : class cRootList {
    public : element_type * mFirstItem ;
    public : element_type * mLastItem ;
    public : sint32 mListLength ;
    public : sint32 mCountReference ;
  //--- Default constructor
    public : cRootList (void) ;
  //--- Destructor
    public : ~cRootList (void) ;
  //--- No Copy
    private : cRootList (const cRootList &) ;
    private : void operator = (const cRootList &) ;
  } ;
//--- Private attribute
  private : cRootList * _mRoot ;
//--- Default Constructor
  public : GGS_number_list (void) ;
//--- Copy Constructor
  public : GGS_number_list (const GGS_number_list & inSource) ;
//--- Assignment Operator
  public : void operator = (const GGS_number_list & inSource) ;
//--- Destructor
  public : ~GGS_number_list (void) ;

//--- Constructor 'emptyList'
  public : static GGS_number_list constructor_emptyList (C_Lexique & inLexique COMMA_LOCATION_ARGS) ;
//--- Function 'count'
  public : sint32 count (void) const ;
//--- Reader 'description'
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
//--- Get first object
  public : element_type * firstObject (void) const ;
//--- Handling '+=' GALGAS operator
  public : void _addAssign_operation (const GGS_luint & argument_0) ;
//--- Internal Methods
  protected : void _internalAppendItem (const GGS_luint & argument_0) ;
  protected : void _insulateList (void) ;
//--- '_isBuilt' method
  public : inline bool _isBuilt (void) const {
    return _mRoot != NULL ;
  }
//--- Handling GALGAS 'drop' instruction
  public : void _drop_operation (void) ;
//--- Handling GALGAS 'length' reader
  public : GGS_uint reader_length (C_Lexique & /* inLexique */
                                   COMMA_UNUSED_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      GALGAS class 'GGS_number_set'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_number_set {
//--- Pointer to actual instance
  protected : cPtr_number_set * mPointer ;
//--- Default constructor
  public : GGS_number_set (void) ;
//--- Copy constructor
  public : GGS_number_set (const GGS_number_set &) ;
//--- Virtual destructor
  public : virtual ~GGS_number_set (void) ;
//--- Assignment operator
  public : void operator = (const GGS_number_set &) ;
//--- _isBuilt
  public : inline bool _isBuilt (void) const { return mPointer != NULL ; }
//--- isEqualTo
  public : inline bool isEqualTo (const GGS_number_set & _inOperand) const {
    return mPointer == _inOperand.mPointer ;
  }
//--- getPtr
  public : inline cPtr_number_set * getPtr (void) const {
    return mPointer ;
  }
//--- drop
  public : void _drop_operation (void) ;
//--- 'description' reader
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_number_set * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_number_set * operator () (LOCATION_ARGS) const {
      return mPointer ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      GALGAS class 'GGS_uint_range'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_uint_range : public GGS_number_set {
//--- Default Constructor
  public : GGS_uint_range (void) ;
//--- 'description' reader
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
//--- 'new' constructor
  public : static GGS_uint_range constructor_new (C_Lexique & inLexique,
                                const GGS_luint & argument_0,
                                const GGS_luint & argument_1 COMMA_LOCATION_ARGS) ;
//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_uint_range * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_uint_range * operator () (LOCATION_ARGS) const {
      return (cPtr_uint_range *) mPointer ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       GALGAS class 'GGS_uint_list'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_uint_list : public GGS_number_set {
//--- Default Constructor
  public : GGS_uint_list (void) ;
//--- 'description' reader
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
//--- 'new' constructor
  public : static GGS_uint_list constructor_new (C_Lexique & inLexique,
                                const GGS_number_list & argument_0 COMMA_LOCATION_ARGS) ;
//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_uint_list * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_uint_list * operator () (LOCATION_ARGS) const {
      return (cPtr_uint_list *) mPointer ;
    }
  #endif
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Map '@implementationSpec'                          *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_implementationSpec ;

class GGS_implementationSpec : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_implementationSpec element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) internalRootObject () ; }
  public : inline element_type * firstObject (void) const { return (element_type *) internalFirstObject () ; }
  public : inline element_type * lastObject (void) const { return (element_type *) internalLastObject () ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_implementationSpec * operator () (UNUSED_LOCATION_ARGS) { return this ; }
  public : inline const GGS_implementationSpec * operator () (UNUSED_LOCATION_ARGS) const { return this ; }
//--- 'emptyMap' constructor
  public : static GGS_implementationSpec constructor_emptyMap (C_Lexique & inLexique COMMA_LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_lstring & inParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_lstring & outParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) const ;
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
  public : static GGS_implementationSpec constructor_mapWithMapToOverride (C_Lexique & inLexique,
                                            const GGS_implementationSpec & inMapToOverride
                                            COMMA_LOCATION_ARGS) ;
  public : GGS_implementationSpec reader_overriddenMap (C_Lexique & inLexique
                                            COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Map '@implementation'                            *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_implementation ;

class GGS_implementation : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_implementation element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) internalRootObject () ; }
  public : inline element_type * firstObject (void) const { return (element_type *) internalFirstObject () ; }
  public : inline element_type * lastObject (void) const { return (element_type *) internalLastObject () ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_implementation * operator () (UNUSED_LOCATION_ARGS) { return this ; }
  public : inline const GGS_implementation * operator () (UNUSED_LOCATION_ARGS) const { return this ; }
//--- 'emptyMap' constructor
  public : static GGS_implementation constructor_emptyMap (C_Lexique & inLexique COMMA_LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- 'insertSpec' Insert Method
  public : void method_insertSpec (C_Lexique & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_implementationSpec &  inParameter0 COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_implementationSpec & inParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_implementationSpec & outParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) const ;
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
  public : static GGS_implementation constructor_mapWithMapToOverride (C_Lexique & inLexique,
                                            const GGS_implementation & inMapToOverride
                                            COMMA_LOCATION_ARGS) ;
  public : GGS_implementation reader_overriddenMap (C_Lexique & inLexique
                                            COMMA_LOCATION_ARGS) const ;
} ;

void routine_generateHeader (C_Lexique &,
                                GGS_lstring  ,
                                GGS_lstring   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              Map '@os_imp'                                *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_os_imp ;

class GGS_os_imp : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_os_imp element_type ;
//--- Get pointers
  public : inline element_type * rootObject (void) const { return (element_type *) internalRootObject () ; }
  public : inline element_type * firstObject (void) const { return (element_type *) internalFirstObject () ; }
  public : inline element_type * lastObject (void) const { return (element_type *) internalLastObject () ; }
//--- Create a new element
  protected : virtual AC_galgas_map_element * new_element (const GGS_lstring & inKey, void * inInfo) ;
//--- Get object pointer (for method call)
  public : inline GGS_os_imp * operator () (UNUSED_LOCATION_ARGS) { return this ; }
  public : inline const GGS_os_imp * operator () (UNUSED_LOCATION_ARGS) const { return this ; }
//--- 'emptyMap' constructor
  public : static GGS_os_imp constructor_emptyMap (C_Lexique & inLexique COMMA_LOCATION_ARGS) ;
//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  const GGS_lstring & inParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Lexique & inLexique,
                                  const char * inErrorMessage,
                                  const GGS_lstring & inKey,
                                  GGS_lstring & outParameter0,
                                  GGS_luint * outIndex
                                  COMMA_LOCATION_ARGS) const ;
  public : GGS_string reader_description (C_Lexique & _inLexique COMMA_LOCATION_ARGS) const ;
  public : static GGS_os_imp constructor_mapWithMapToOverride (C_Lexique & inLexique,
                                            const GGS_os_imp & inMapToOverride
                                            COMMA_LOCATION_ARGS) ;
  public : GGS_os_imp reader_overriddenMap (C_Lexique & inLexique
                                            COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Element of list '@number_list'                       *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_number_list {
  private : elementOf_GGS_number_list * mNextItem ;
    public : GGS_luint  number ;
  public : elementOf_GGS_number_list (const GGS_luint & ) ;

  public : inline elementOf_GGS_number_list * nextObject (void) const { return mNextItem ; }
  private : elementOf_GGS_number_list (const elementOf_GGS_number_list &) ;
  private : void operator = (const elementOf_GGS_number_list &) ;
  public : inline ~elementOf_GGS_number_list (void) {}
  public : void appendForListDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
  friend class GGS_number_list ;
} ;

//---------------------------------------------------------------------------*

#include "include_number_set.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                            class 'uint_range'                             *
//                                                                           *
//---------------------------------------------------------------------------*

#include "include_uint_range.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                            class 'uint_list'                              *
//                                                                           *
//---------------------------------------------------------------------------*

#include "include_uint_list.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                   Element of map '@implementationSpec'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class e_implementationSpec {
  public : GGS_lstring  type ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_implementationSpec : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_implementationSpec (const GGS_lstring & inKey,
                                     const sint32 inIndex,
                                     const e_implementationSpec & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_implementationSpec * nextObject (void) const { return (elementOf_GGS_implementationSpec *) mNextItem ; }
  public : inline elementOf_GGS_implementationSpec * infObject (void) const { return (elementOf_GGS_implementationSpec *) mInfPtr ; }
  public : inline elementOf_GGS_implementationSpec * supObject (void) const { return (elementOf_GGS_implementationSpec *) mSupPtr ; }
//--- Data member
  public : e_implementationSpec mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Element of map '@implementation'                      *
//                                                                           *
//---------------------------------------------------------------------------*

class e_implementation {
  public : GGS_implementationSpec  spec ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_implementation : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_implementation (const GGS_lstring & inKey,
                                     const sint32 inIndex,
                                     const e_implementation & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_implementation * nextObject (void) const { return (elementOf_GGS_implementation *) mNextItem ; }
  public : inline elementOf_GGS_implementation * infObject (void) const { return (elementOf_GGS_implementation *) mInfPtr ; }
  public : inline elementOf_GGS_implementation * supObject (void) const { return (elementOf_GGS_implementation *) mSupPtr ; }
//--- Data member
  public : e_implementation mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Element of map '@os_imp'                          *
//                                                                           *
//---------------------------------------------------------------------------*

class e_os_imp {
  public : GGS_lstring  type ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_os_imp : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_os_imp (const GGS_lstring & inKey,
                                     const sint32 inIndex,
                                     const e_os_imp & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_os_imp * nextObject (void) const { return (elementOf_GGS_os_imp *) mNextItem ; }
  public : inline elementOf_GGS_os_imp * infObject (void) const { return (elementOf_GGS_os_imp *) mInfPtr ; }
  public : inline elementOf_GGS_os_imp * supObject (void) const { return (elementOf_GGS_os_imp *) mSupPtr ; }
//--- Data member
  public : e_os_imp mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (C_Lexique & _inLexique, C_String & ioString COMMA_LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

#endif
