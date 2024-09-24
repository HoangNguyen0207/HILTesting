//
// File: inverse_kinematic_GEN.h
//
// Code generated for Simulink model 'inverse_kinematic_GEN'.
//
// Model version                  : 10.0
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Jul 10 15:19:48 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_inverse_kinematic_GEN_h_
#define RTW_HEADER_inverse_kinematic_GEN_h_
#include "rtwtypes.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8N2SBvRBuOt8VmWYrAt5FG_
#define DEFINED_TYPEDEF_FOR_struct_8N2SBvRBuOt8VmWYrAt5FG_

struct struct_8N2SBvRBuOt8VmWYrAt5FG
{
  real_T rt;
  real_T Rd;
  real_T drt;
  real_T dRd;
  real_T xl_length_init;
  real_T stroke;
  real_T z_home;
};

#endif

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern struct_8N2SBvRBuOt8VmWYrAt5FG para6dof;// Variable: para6dof
                                                 //  Referenced by: '<Root>/InverseKinematic'


// Class declaration for model inverse_kinematic_GEN
class inverse_kinematic_GEN final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T pose[6];                    // '<Root>/pose'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T q_out[6];                   // '<Root>/q_out'
    real_T flag;                       // '<Root>/flag'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  inverse_kinematic_GEN(inverse_kinematic_GEN const&) = delete;

  // Assignment Operator
  inverse_kinematic_GEN& operator= (inverse_kinematic_GEN const&) & = delete;

  // Move Constructor
  inverse_kinematic_GEN(inverse_kinematic_GEN &&) = delete;

  // Move Assignment Operator
  inverse_kinematic_GEN& operator= (inverse_kinematic_GEN &&) = delete;

  // Real-Time Model get method
  inverse_kinematic_GEN::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  inverse_kinematic_GEN();

  // Destructor
  ~inverse_kinematic_GEN();

  void setInputInvert(real_T inputMPinvert[6]);

  double* getOutputActuator();
  double getStateFlag();
  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

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
//  '<Root>' : 'inverse_kinematic_GEN'
//  '<S1>'   : 'inverse_kinematic_GEN/InverseKinematic'

#endif                                 // RTW_HEADER_inverse_kinematic_GEN_h_

//
// File trailer for generated code.
//
// [EOF]
//
