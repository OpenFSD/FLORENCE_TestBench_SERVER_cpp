//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Control Execute : Header File.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CONTROL_EXECUTE_H
#define CONTROL_EXECUTE_H

#include "Framework/DynamicServer/Global.h"

namespace FLORENCE_Server_Assembly
{
    class Control_Execute
    {
//	PUBLIC -==============================================================================================================================================
//  ======================================================================================================================================================
//  ======================================================================================================================================================
        public:
//	CONSTANTS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	CONSTRUCTOR ******************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            Control_Execute(Global* ptr_Global_pass, unsigned char* ptr_My_Num_Implemented_Cores);
            virtual ~Control_Execute();


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
            bool getFlag_ThreadInitialised(unsigned char coreId);
            bool getFlag_SystemInitialised(unsigned char coreId);
// SET
            void setConditionCodeOfThisThreadedCore(unsigned char coreId);


//	PROTECTED ============================================================================================================================================
//  ======================================================================================================================================================
//  ======================================================================================================================================================
        protected:
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
        private:
//	CONSTANTS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            class Global* ptr_Global_For_ControlExecute;
            unsigned char* ptr_Num_Implemented_Cores_For_ControlExecute;

//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            static bool thread_Initialised[3];//NUMBER OF CORES :: getInstance_Global()->get_NumCores()


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET

// SET
            void setFlag_ThreadInitialised(unsigned char coreId, bool value);
    };
}
#endif // CONTROL_EXECUTE_H
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
