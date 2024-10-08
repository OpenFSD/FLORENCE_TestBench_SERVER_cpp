//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Framework Dynamic Server : Header File.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef FRAMEWORK_DYNAMIC_SERVER_H
#define FRAMEWORK_DYNAMIC_SERVER_H

#include "Framework/DynamicServer/Algorithms/Algorithms.h"
#include "Framework/DynamicServer/Control/Control.h"
#include "Framework/DynamicServer/Data/Data.h"
#include "Framework/DynamicServer/Execute/Execute.h"

namespace FLORENCE_Server_Assembly
{
    class Framework_DynamicServer
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
            Framework_DynamicServer();
            virtual ~Framework_DynamicServer();


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    // FIELDS
            std::vector<class Data_Input*> getField_Data_Input_StackOfInputPraise();
            std::vector<class Data_Output*> getField_Data_Output_StackOfDistributeBuffer();

    // INSTANCE(S)
            class Algorithms* getInstance_Algorithms();
            class Algorithms_Concurrent* getInstance_Algorithms_Concurrent(unsigned char coreId);
            class Algorithms_ListenRespond* getInstance_Algorithms_ListenRespond();

            class Control_Algorithms* getInstance_Control_Algorithms();
            class Control_Algorithms_Concurrent* getInstance_Control_Algorithms_Concurrent(unsigned char coreId);
            class Control_Algorithms_ListenRespond* getInstance_Control_Algorithms_ListenRespond();
            class Control_Data* getInstance_Control_Data();
            //class Control_Data_Input* getInstance_Control_Data_Input();
            //class Control_Data_Output* getInstance_Control_Data_Output();
            class Control_Execute* getInstance_Control_Execute();

            class Data* getInstance_Data();
            class Data_Input* getInstance_Data_Input();
            class Data_Input* getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(unsigned char coreId);
            class Data_Input* getInstance_Data_Input_PraiseBuffer();

            class Data_Output* getInstance_Data_Output();
            class Data_Output* getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(unsigned char coreId);
            class Data_Output* getInstance_Data_Output_DistributeBuffer();

            class Global* getInstance_Global();

            class Execute* getInstance_Execute();

// SET


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
// INSTANCE(S)
            static class Algorithms* ptr_Algorithms;
            //static class Control* ptr_Control;
            static class Data* ptr_Data;
            static class Global* ptr_Global;
            static class Execute* ptr_Execute;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------

    };
}
#endif // FRAMEWORK_DYNAMIC_SERVER_H
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
