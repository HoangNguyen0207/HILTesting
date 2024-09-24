//
// File: full_limmit_motion_GEN.h
//
// Code generated for Simulink model 'full_limmit_motion_GEN'.
//
// Model version                  : 1.17
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 10 11:20:50 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_full_limmit_motion_GEN_h_
#define RTW_HEADER_full_limmit_motion_GEN_h_
#include "rtwtypes.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Block signals and states (default storage) for system '<Root>'
struct DW {
  real_T UD_DSTATE[6];                 // '<S1>/UD'
  real_T Memory1_PreviousInput[6];     // '<Root>/Memory1'
  real_T Memory_PreviousInput[6];      // '<Root>/Memory'
};

// External inputs (root inport signals with default storage)
struct ExtU {
  real_T q_input[6];                   // '<Root>/q_input'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T q_excute[6];                  // '<Root>/q_excute'
};

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern real_T q_2dot_max[6];           // Variable: q_2dot_max
                                          //  Referenced by: '<Root>/Constant3'

extern real_T q_dot_init[6];           // Variable: q_dot_init
                                          //  Referenced by: '<Root>/Memory'

extern real_T q_dot_max[6];            // Variable: q_dot_max
                                          //  Referenced by: '<Root>/Constant2'

extern real_T q_init[6];               // Variable: q_init
                                          //  Referenced by:
                                          //    '<Root>/Memory1'
                                          //    '<S1>/UD'

extern real_T q_max[6];                // Variable: q_max
                                          //  Referenced by: '<Root>/Constant1'

extern real_T q_min[6];                // Variable: q_min
                                          //  Referenced by: '<Root>/Constant'

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInfe;
  extern real_T rtMinusInfe;
  extern real_T rtNaNe;
  extern real32_T rtInfFe;
  extern real32_T rtMinusInfFe;
  extern real32_T rtNaNFe;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDoublee {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDoublee {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESinglee {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

// Class declaration for model full_limmit_motion_GEN
class full_limmit_motion_GENModelClass
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  full_limmit_motion_GENModelClass();

  // Destructor
  ~full_limmit_motion_GENModelClass();
void setInputMP(real_T inputPos[6]);

double *getOutputMP ();
  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Data Type Duplicate' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'full_limmit_motion_GEN'
//  '<S1>'   : 'full_limmit_motion_GEN/Discrete Derivative'
//  '<S2>'   : 'full_limmit_motion_GEN/MATLAB Function'
//  '<S3>'   : 'full_limmit_motion_GEN/MATLAB Function1'
//  '<S4>'   : 'full_limmit_motion_GEN/MATLAB Function2'

#endif                                 // RTW_HEADER_full_limmit_motion_GEN_h_

//
// File trailer for generated code.
//
// [EOF]
//
