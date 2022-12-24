//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Control Data : Header File.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CONTROL_DATA_H
#define CONTROL_DATA_H
#include "Framework/DynamicServer/Data/Data.h"
#include "Framework/DynamicServer/Data/Input/Data_Input.h"
#include "Framework/DynamicServer/Data/Output/Data_Output.h"

#include "vector"

namespace FLORENCE_Server_Assembly
{
    class Control_Data
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
            Control_Data();
            virtual ~Control_Data();


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            void popFromStackOfInputPraises(class Data* obj, Data_Input* referenceForCore, std::vector<class Data_Input*> ptr_InputStack, unsigned char coreId);
            void popFromStackOfOutput(class Data* obj_Data, Data_Output* distributeBuffer, std::vector<Data_Output*> outputStack);
            void pushToStackOfInputPraises(class Data* obj, std::vector<class Data_Input*> ptr_InputStack, Data_Input* praiseBuffer);
            void pushToStackOfOutput(class Data* obj_Data, std::vector<Data_Output*> outputStack, Data_Output* referenceForCore, unsigned char coreId);

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
            bool getFlag_InputStackLoaded(unsigned char coreId);
            bool getFlag_OutputStackLoaded(unsigned char coreId);

// SET
            void setFlag_InputStackLoaded(bool value, unsigned char coreId);
            void setFlag_OutputStackLoaded(bool value, unsigned char coreId);

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
            static bool flag_InputStackLoaded;
            static bool flag_OutputStackLoaded;

//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


    };
}
#endif // CONTROL_DATA_H
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
