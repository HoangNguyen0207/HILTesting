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

class ProcessMotionClass
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
  ProcessMotionClass();

  // Destructor
  ~ProcessMotionClass();
void setInputMP(real_T inputPos[6]);

double *getOutputMP ();
  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

#endif
