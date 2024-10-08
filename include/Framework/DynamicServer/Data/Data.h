//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Data : Header File.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef DATA_H
#define DATA_H

#include "Framework/DynamicServer/Control/Data/Control_Data.h"
#include "Framework/DynamicServer/Control/Data/Input/Control_Data_Input.h"
#include "Framework/DynamicServer/Data/Input/Data_Input.h"
#include "Framework/DynamicServer/Control/Data/Output/Control_Data_Output.h"
#include "Framework/DynamicServer/Data/Output/Data_Output.h"

#include "vector"

namespace FLORENCE_Server_Assembly
{
    class Data
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
            Data(unsigned char* ptr_My_Num_Implemented_Cores);
            virtual ~Data();


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
            std::vector<class Data_Input*> getField_Data_Input_StackOfInputPraise();
            std::vector<class Data_Output*> getField_Data_Output_StackOfDistributeBuffer();
            class Control_Data* getInstance_Control_Data();
            class Data_Input* getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(unsigned char coreId);
            class Data_Input* getInstance_Data_Input_PraiseBuffer();
            class Data_Output* getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(unsigned char coreId);
            class Data_Output* getInstance_Data_Output_DistributeBuffer();

// SET
            void setField_Data_Input_Stack_InputPraise(std::vector<class Data_Input*> value);
            void setField_Data_Output_Stack_OutputDistribute(std::vector<Data_Output*> value);

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


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            static std::vector<class Data_Input*> data_Input_ConcurrentCoreId_InputRefferenceOfCore;
            static std::vector<class Data_Input*> data_Input_StackOfInputPraise;
            static std::vector<class Data_Output*> data_Output_ConcurrentCoreId_OutputRefferenceOfCore;
            static std::vector<class Data_Output*> data_Output_StackOfOutputDistribute;
            static class Control_Data* ptr_Control_Data;
            static class Data_Input* ptr_Data_Input_PraiseBuffer;
            static class Data_Output* ptr_Data_Output_DistributeBuffer;



//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


    };
}
#endif // DATA_H
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
