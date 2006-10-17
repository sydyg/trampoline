//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_program.cpp'                           *
//         Generated by version GALGAS_BETA_VERSION (LL(1) grammar)          *
//                     october 13th, 2006, at 16h32'16"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "utilities/F_DisplayException.h"
#include "utilities/MF_MemoryControl.h"
#include "time/C_Timer.h"
#include "generic_arraies/TC_UniqueArray.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "utilities/MF_MemoryControl.h"

#ifdef TARGET_API_MAC_CARBON
  #include <SIOUX.H>
#endif

#ifdef COMPILE_FOR_WIN32
  #ifdef __MWERKS__
    #include <WINSIOUX.H>
  #endif
#endif

//---------------------------------------------------------------------------*

#include "goil_program.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                 C_options_for_goil_program  CONSTRUCTOR                   *
//                                                                           *
//---------------------------------------------------------------------------*

C_options_for_goil_program::
C_options_for_goil_program (const bool inAcceptsDebugOption)
:mBuiltinOptions (inAcceptsDebugOption) {
  add (& mBuiltinOptions) ;
  add (& mGalgasOptions) ;
  add (& mOptions_goil_options) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                          C O N S T R U C T O R                            *
//                                                                           *
//---------------------------------------------------------------------------*


goil_program::
goil_program (const C_galgas_io_parameters & inIOparameters COMMA_LOCATION_ARGS) :
mScannerPtr_ (NULL), mTerminalIO (inIOparameters) {
  mSourceFileExtension_ = "???" ;
  mScannerPtr_ = NULL ;
  macroMyNew (mScannerPtr_, goil_lexique (& mTerminalIO COMMA_THERE)) ;
  C_GGS_Object::attachPointer (mScannerPtr_ COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           D E S T R U C T O R                             *
//                                                                           *
//---------------------------------------------------------------------------*


goil_program::
~goil_program (void) {
  macroDetachPointer (mScannerPtr_, goil_lexique) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       D O    C O M P I L A T I O N                        *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_program::
doCompilation (const C_String & inSourceFileName_,
               const bool inVerboseOptionOn,
               sint16 & returnCode) {
  C_Timer timer ;
  try{
    /* if (mTerminalIO.versionModeOn ()) {
      co << "Reading '" << inSourceFileName_ << "'\n" ;
    } */
    mScannerPtr_->resetAndLoadSourceFromFile (inSourceFileName_) ;
    _beforeParsing () ;
    goil_grammar grammar_ ;
    grammar_.startParsing_ (*mScannerPtr_) ;
    if (mTerminalIO.getErrorTotalCount () == 0) {
      _afterParsing (inVerboseOptionOn) ;
    }
    if (inVerboseOptionOn || ((mTerminalIO.getErrorTotalCount () + mTerminalIO.getWarningsCount ()) > 0)) {
      co << "Analysis of '" << mScannerPtr_->sourceFileName ().lastPathComponent () << "' completed. " ;
    }
    switch (mTerminalIO.getErrorTotalCount ()) {
    case 0 :
      if (inVerboseOptionOn) {
        co << "No error, " ;
      }
      break ;
    case 1 :
      co << "1 error, " ;
      returnCode = 1 ; // Error code
      break ;
    default :
      co << mTerminalIO.getErrorTotalCount () << " errors, " ;
      returnCode = 1 ; // Error code
      break ;
    }
    switch (mTerminalIO.getWarningsCount ()) {
    case 0 :
      if (inVerboseOptionOn) {
        co << "no warning" ;
      }
      break ;
    case 1 :
      co << "1 warning" ;
      break ;
    default :
      co << mTerminalIO.getWarningsCount () << " warnings" ;
      break ;
    }
    timer.stopTimer () ;
    if (inVerboseOptionOn || ((mTerminalIO.getErrorTotalCount () + mTerminalIO.getWarningsCount ()) > 0)) {
      co << " (" << timer << ").\n" ;
    }
  }catch (const C_TextReadException & inFileReadError) {
    co << "Error: " << inFileReadError.what () << "\n" ; // Error when reading source file
    returnCode = 1 ;
  }
}

//---------------------------------------------------------------------------*

int mainForLIBPM  (const int argc, const char * argv []) {
  sint16 returnCode = 0 ; // No error
//--- Input/output parameters
  C_options_for_goil_program options (false) ;
  C_galgas_io_parameters IOparameters  (& options) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    IOparameters.mCompilerVersion = "version 1.0.0" " [debug]" ;
  #else
    IOparameters.mCompilerVersion = "version 1.0.0" ;
  #endif
  IOparameters.mMaxErrorsCount = 100 ;
  IOparameters.mMaxWarningsCount = 100 ;
  TC_UniqueArray <C_String> sourceFilesArray ;
//--- Analyze Command Line Options
  F_Analyze_CLI_Options (argc, argv,
                               "version 1.0.0",
                               options,
                               sourceFilesArray,
                               "???",
                               IOparameters.mCocoaOutput) ;
//--- Ask Save On Close ? (Carbon and Windows SIOUX Only)
  #ifdef SIOUX_IS_IMPLEMENTED
    SIOUXSettings.asktosaveonclose = options.boolOptionValueFromKeys ("generic_cli_options",
                                                                      ASK_TO_SAVE_ON_CLOSE,
                                                                      false) ;
  #endif
//--- Enable 64 bit alloc debug ? Only if compiled in 64 bit and in debug mode
  #ifndef DO_NOT_GENERATE_CHECKINGS
    #ifdef __LP64__
      if (options.boolOptionValueFromKeys ("generic_cli_options",
                                           "enable_allocation_debugging",
                                           false)) {
        enableAllocDebugFor64BitTool () ;
      }
    #endif
  #endif
  try{
    const bool verboseOptionOn = options.boolOptionValueFromKeys ("generic_galgas_cli_options",
                                                              "verbose_output",
                                                              false) ;
    goil_program_prologue (options) ;
    for (sint32 i=0 ; i<sourceFilesArray.count () ; i++) {
      goil_program * compiler = NULL ;
      macroMyNew (compiler, goil_program (IOparameters COMMA_HERE)) ;
      compiler->_prologue () ;
      sint16 r = 0 ;
      compiler->doCompilation (sourceFilesArray (i COMMA_HERE), verboseOptionOn, r) ;
      if (r != 0) {
        returnCode = r ;
      }
      compiler->_epilogue () ;
      macroMyDelete (compiler, goil_program) ;
    }
    goil_program_epilogue (options) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      C_GGS_Object::checkAllObjectsHaveBeenReleased () ;
    #endif
    if (verboseOptionOn) {
      #ifndef DO_NOT_GENERATE_CHECKINGS
        const uint64 maxUsedMemorySize = getMaxUsedMemorySize () ;
        const uint64 oneMegaByte = 1 << 20 ;
        const uint64 megaBytes = maxUsedMemorySize / oneMegaByte ;
        const uint64 fraction = ((maxUsedMemorySize % oneMegaByte) * 1000) / oneMegaByte ;
        co << getCreatedDynamicObjectsTotalCount ()
           << " C++ objects have been created ("
           << megaBytes << "." << widthWithZeroFill (3) << fraction
           << " MB).\n" ;
        deactivateMemoryControl () ;
        if ((getAllocationBalance () != 0) && (returnCode == 0)) {
          display_pointers () ;
        }
      #endif
    }
  }catch (const M_STD_NAMESPACE exception & e) {
    F_default_display_exception (e) ;
    returnCode = 1 ; // Error code
  }catch (...) {
    F_default_display_unknown_exception () ;
    returnCode = 2 ; // Error code
  }
  return returnCode ;
}

//---------------------------------------------------------------------------*

//--- START OF USER ZONE 2


//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    P R O L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_program_prologue (const C_options_for_goil_program & /* inOptions */) {
// ADD YOUR CODE HERE
}
//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    E P I L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_program_epilogue (const C_options_for_goil_program & /* inOptions */) {
// ADD YOUR CODE HERE
}
//---------------------------------------------------------------------------*
//                                                                           *
//                             P R O L O G U E                               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_program::
_prologue (void) {
//--- ADD YOUR CODE HERE
}
//---------------------------------------------------------------------------*
//                                                                           *
//                             E P I L O G U E                               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_program::
_epilogue (void) {
//--- ADD YOUR CODE HERE
}
//--- END OF USER ZONE 2


