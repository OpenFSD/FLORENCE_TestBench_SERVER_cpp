//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Data : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Data/Data.h"

#include "vector"
#include "iostream"

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
    Data::Data(unsigned char* ptr_My_Num_Implemented_Cores)
    {
            this->ptr_Control_Data = new Control_Data();
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Control/Data" << std::endl;//SIMULATION

            this->data_Input_ConcurrentCoreId_InputRefferenceOfCore.resize(*ptr_My_Num_Implemented_Cores-1);
            for(unsigned char index = 0; index < *ptr_My_Num_Implemented_Cores-1; index++)
            {
                this->data_Input_ConcurrentCoreId_InputRefferenceOfCore.push_back(new Data_Input());
                std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Input/Concurrent_InputRefferenceOfCore[" << int(index) << "]" << std::endl;//SIMULATION
                this->data_Input_ConcurrentCoreId_InputRefferenceOfCore.erase(this->data_Input_ConcurrentCoreId_InputRefferenceOfCore.begin());
            }

            std::vector<Data_Input*> data_Input_StackOfInputPraise (1, new Data_Input());
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Input/Stack_InputPraise" << std::endl;//SIMULATION

            this->data_Output_ConcurrentCoreId_OutputRefferenceOfCore[*ptr_My_Num_Implemented_Cores-1];
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Control/Data/Output" << std::endl;//SIMULATION
            for(unsigned char index = 0; index < *ptr_My_Num_Implemented_Cores-1; index++)
            {
                this->data_Output_ConcurrentCoreId_OutputRefferenceOfCore[index] = new Data_Output();
                std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Output/Concurrent_OutputRefferenceOfCore" << std::endl;//SIMULATION
            }

            std::vector<Data_Output*> data_Output_StackOfOutputDistribute (1, new Data_Output());
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Output/Stack_OutputDistribute" << std::endl;//SIMULATION

            this->ptr_Data_Input_PraiseBuffer = new Data_Input();
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Input/PraiseBuffer" << std::endl;//SIMULATION

            this->ptr_Data_Output_DistributeBuffer = new Data_Output();
            std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Data/Output/DistributeBuffer" << std::endl;//SIMULATION
    }

    Data::~Data()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    std::vector<class Data_Input*> Data::getField_Data_Input_StackOfInputPraise()
    {
        return this->data_Input_StackOfInputPraise;
    }
    std::vector<Data_Output*> Data::getField_Data_Output_StackOfDistributeBuffer()
    {
        return this->data_Output_StackOfOutputDistribute;
    }
    Control_Data* Data::getInstance_Control_Data()
    {
        return this->ptr_Control_Data;
    }
    Data_Input* Data::getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(unsigned char coreId)
    {
        return this->data_Input_ConcurrentCoreId_InputRefferenceOfCore[coreId];
    }
    Data_Input* Data::getInstance_Data_Input_PraiseBuffer()
    {
        return this->ptr_Data_Input_PraiseBuffer;
    }
    Data_Output* Data::getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(unsigned char coreId)
    {
        return this->data_Output_ConcurrentCoreId_OutputRefferenceOfCore[coreId];
    }
    Data_Output* Data::getInstance_Data_Output_DistributeBuffer()
    {
        return this->ptr_Data_Output_DistributeBuffer;
    }


// SET
    void Data::setField_Data_Input_Stack_InputPraise(std::vector<class Data_Input*> value)
    {
        this->data_Input_StackOfInputPraise = value;
    }
    void Data::setField_Data_Output_Stack_OutputDistribute(std::vector<Data_Output*> value)
    {
        this->data_Output_StackOfOutputDistribute = value;
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


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    std::vector<class Data_Input*> Data::data_Input_ConcurrentCoreId_InputRefferenceOfCore (2, nullptr);
    std::vector<class Data_Input*> Data::data_Input_StackOfInputPraise (1, nullptr);
    std::vector<class Data_Output*> Data::data_Output_ConcurrentCoreId_OutputRefferenceOfCore (2, nullptr);
    std::vector<class Data_Output*> Data::data_Output_StackOfOutputDistribute (1, nullptr);
    class Control_Data* Data::ptr_Control_Data = nullptr;
    class Data_Input* Data::ptr_Data_Input_PraiseBuffer = nullptr;
    class Data_Output* Data::ptr_Data_Output_DistributeBuffer = nullptr;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
