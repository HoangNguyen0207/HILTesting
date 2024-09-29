
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

extern struct_8N2SBvRBuOt8VmWYrAt5FG para6dof;// Variable: para6dof
                                                 //  Referenced by: '<Root>/InverseKinematic'


class ProcessInv final
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
  ProcessInv(ProcessInv const&) = delete;

  // Assignment Operator
  ProcessInv& operator= (ProcessInv const&) & = delete;

  // Move Constructor
  ProcessInv(ProcessInv &&) = delete;

  // Move Assignment Operator
  ProcessInv& operator= (ProcessInv &&) = delete;

  // Real-Time Model get method
  ProcessInv::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  ProcessInv();

  // Destructor
  ~ProcessInv();

  void setInputInvert(real_T inputMPinvert[6]);

  double* getOutputActuator();
  double getStateFlag();
  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

#endif                                 // RTW_HEADER_inverse_kinematic_GEN_h_
