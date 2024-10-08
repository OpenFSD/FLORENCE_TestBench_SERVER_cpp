//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Global : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Global.h"

using namespace FLORENCE_Server_Assembly;
//	PUBLIC -==============================================================================================================================================
//  ======================================================================================================================================================
//  ======================================================================================================================================================
//	CONSTANTS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	CONSTRUCTOR ******************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    Global::Global()
    {
        this->num_Implemented_Cores = 3;
        this->ptr_Num_Implemented_Cores = &num_Implemented_Cores;
    }

    Global::~Global()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
    unsigned char* Global::get_NumCores()
    {
        return ptr_Num_Implemented_Cores;
    }

    bool Global::getConst_Write_IDLE(unsigned char index)
    {
        return this->write_IDLE[index];
    }
    bool Global::getConst_Write_WAIT(unsigned char index)
    {
        return this->write_WAIT[index];
    }
    bool Global::getConst_Write_WRITE(unsigned char index)
    {
        return this->write_WRITE[index];
    }

    bool Global::getConst_Core_IDLE()
    {
        return this->core_IDLE;
    }
    bool Global::getConst_Core_ACTIVE()
    {
        return this->core_ACTIVE;
    }

//	PROTECTED ============================================================================================================================================
//  ======================================================================================================================================================
//  ======================================================================================================================================================
//	CONSTANTS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------



//	PRIVATE ==============================================================================================================================================
//  ======================================================================================================================================================
//  ======================================================================================================================================================
//	CONSTANTS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    const bool write_IDLE[2]    = {false, false};
    const bool write_WAIT[2]    = {false, true};
    const bool write_WRITE[2]   = {true, false};

    const bool core_IDLE = false;
    const bool core_ACTIVE = true;


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    unsigned char Global::num_Implemented_Cores = 2;
    unsigned char* Global::ptr_Num_Implemented_Cores = &num_Implemented_Cores;

//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
