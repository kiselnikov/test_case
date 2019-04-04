// Includes -------------------------------------------------------
#include <counter.h>
//-----------------------------------------------------------------

// Const ----------------------------------------------------------
#define  TEST_LIM_NEG -1
#define TEST_LIM_ZRO 0
#define TEST_LIM_SMALL 10
#define TEST_LIM_DEF 15
#define TEST_LIM_OVF 0x7FFFFFFF
//-----------------------------------------------------------------

// Types ----------------------------------------------------------

//-----------------------------------------------------------------


// Macros ---------------------------------------------------------

//-----------------------------------------------------------------


// Prototypes -----------------------------------------------------

//-----------------------------------------------------------------


// Public Vars ----------------------------------------------------

//-----------------------------------------------------------------


// Public Fxn -----------------------------------------------------

int counter_unit_test(void)
{
	int tmp_i32;
	
	// Testing negative limit case
	
	//RETURNS -1
	tmp_i32 = getNumber();
	setMaximumValue(TEST_LIM_NEG);
	if (tmp_i32 != getNumber()) return (-1);
	
	// Testing incrementing
	
	//RETURNS -2 
	tmp_i32 = getNumber();
	incrementNumber();
	if (getNumber() != (tmp_i32+1)) return (-2);
	
	tmp_i32 = getNumber();
	incrementNumber();
	if (getNumber() != (tmp_i32+1)) return (-2);
	
	
	// Testing negative limit case with non zero state
	
	//RETURNS -1
	tmp_i32 = getNumber();
	setMaximumValue(TEST_LIM_NEG);
	if (tmp_i32 != getNumber()) return (-1);
	
	
	// Testing zero limit case 
	
	//RETURNS -3
	setMaximumValue(TEST_LIM_ZRO);
	if (getNumber() != TEST_LIM_ZRO) return (-3);
	incrementNumber();
	if (getNumber() != TEST_LIM_ZRO) return (-3);
	
	// Testing counter overflow
	
	// RETURNS -4
	
	setMaximumValue(TEST_LIM_DEF);
	tmp_i32=0;
	while (tmp_i32 != (TEST_LIM_DEF))
	{
		incrementNumber();
		tmp_i32++;
	}

	if (getNumber() != TEST_LIM_ZRO) return (-4); 
}


//EOF-------------------------------------------------------------
