/** Reference -----------------------------------------------------

int32_t getNumber(void) - returns current counter state

void incrementNumber(void) - increments counter value, and resets
it if it matches the limit value. Proposed realization assumes that
current counter state vill never exceeds the liit in any time moment.
Also it assumes "zero limit case" and "over flow avoidance"

void setMaximumValue(int lim) - sets the counter limit. Assume
avoidance of the negative limit setting and resets the counter if
it's current vaule will exceeds the limit after update. 

----------------------------------------------------------------**/


// Includes -------------------------------------------------------
#include <counter.h>
//-----------------------------------------------------------------

// Const ----------------------------------------------------------
#define DEFAULT_LIM 15
#define DEFAULT_VAL 0
//-----------------------------------------------------------------

// Types ----------------------------------------------------------

typedef struct{
  int val;
  int lim;
}ctr_t;


//-----------------------------------------------------------------


// Macros ---------------------------------------------------------
#define WRONG_SIGN(val) (val&0x80000000)
//-----------------------------------------------------------------


// Prototypes -----------------------------------------------------

//-----------------------------------------------------------------


// Public Vars ----------------------------------------------------

//-----------------------------------------------------------------


// Private Vars ---------------------------------------------------
ctr_t counter = {DEFAULT_VAL,DEFAULT_LIM};
//-----------------------------------------------------------------


// Private Fxn ----------------------------------------------------

//-----------------------------------------------------------------


// Public Fxn -----------------------------------------------------

int getNumber(void)
{
  return (counter.val);
}

void incrementNumber(void)
{
  // Check degenerate case "limit == zero"
  if (counter.lim == 0) return;
  
  // Check limit over flow
   if (counter.val == (counter.lim-1)){
    counter.val = 0;
    return;
  }
  
  // Incrementing
  counter.val++;

  return;
};


void setMaximumValue(int lim)
{
  // Check incoming data sign
  if WRONG_SIGN(lim) return;
  
  //Check new limit vs value condition 
  if (counter.val >= lim) counter.val = 0;
  
  //Update limit  
  counter.lim = lim;
  
  return;
}

//EOF-------------------------------------------------------------
