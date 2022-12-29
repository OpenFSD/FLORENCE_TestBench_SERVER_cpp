//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Framework Dynamic Server : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Framework_DynamicServer.h"

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
    Framework_DynamicServer::Framework_DynamicServer()
    {
// INSTANCE(S)
        this->ptr_Global = new Global();
        std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Global" << std::endl;

        this->ptr_Algorithms = new Algorithms(getInstance_Global()->get_NumCores());
        std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/algorithms" << std::endl;

        //this->ptr_Control = new Control();
        //std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/control" << std::endl;//SIMULATION

        this->ptr_Data = new Data(getInstance_Global()->get_NumCores());
        std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/data" << std::endl;//SIMULATION

        this->ptr_Execute = new Execute( getInstance_Global(), getInstance_Global()->get_NumCores() );
        std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/execute" << std::endl;//SIMULATION

        //std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/wrapper" << std::endl;//SIMULATION
    }

    Framework_DynamicServer::~Framework_DynamicServer()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// FIELDS
    std::vector<class Data_Input*> Framework_DynamicServer::getField_Data_Input_StackOfInputPraise()
    {
        return getInstance_Data()->getField_Data_Input_StackOfInputPraise();
    }
    std::vector<Data_Output*> Framework_DynamicServer::getField_Data_Output_StackOfDistributeBuffer()
    {
        return getInstance_Data()->getField_Data_Output_StackOfDistributeBuffer();
    }

// INSTANCE(S)
    Algorithms* Framework_DynamicServer::getInstance_Algorithms()
    {
        return ptr_Algorithms;
    }
    Algorithms_Concurrent* Framework_DynamicServer::getInstance_Algorithms_Concurrent(unsigned char coreId)
    {
        return getInstance_Algorithms()->getInstance_Algorithms_Concurrent(coreId);
    }
    Algorithms_ListenRespond* Framework_DynamicServer::getInstance_Algorithms_ListenRespond()
    {
        return getInstance_Algorithms()->getInstance_Algorithms_ListenRespond();
    }

    Control_Algorithms* Framework_DynamicServer::getInstance_Control_Algorithms()
    {
        return getInstance_Algorithms()->getInstance_Control_Algorithms();
    }
    Control_Algorithms_Concurrent* Framework_DynamicServer::getInstance_Control_Algorithms_Concurrent(unsigned char coreId)
    {
        return getInstance_Algorithms()->getInstance_Algorithms_Concurrent(coreId)->getInstance_Control_Algorithms_Concurrent();
    }
    Control_Algorithms_ListenRespond* Framework_DynamicServer::getInstance_Control_Algorithms_ListenRespond()
    {
        return getInstance_Algorithms()->getInstance_Algorithms_ListenRespond()->getInstance_Control_Algorithms_ListenRespond();
    }
    Control_Data* Framework_DynamicServer::getInstance_Control_Data()
    {
        return getInstance_Data()->getInstance_Control_Data();
    }
    Control_Execute* Framework_DynamicServer::getInstance_Control_Execute()
    {
        return getInstance_Execute()->getInstance_Control_Execute();
    }

    Data* Framework_DynamicServer::getInstance_Data()
    {
        return ptr_Data;
    }
    Data_Input* Framework_DynamicServer::getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(unsigned char coreId)
    {
        return getInstance_Data()->getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(coreId);
    }
    Data_Input* Framework_DynamicServer::getInstance_Data_Input_PraiseBuffer()
    {
        return getInstance_Data()->getInstance_Data_Input_PraiseBuffer();
    }
    Data_Output* Framework_DynamicServer::getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(unsigned char coreId)
    {
        return getInstance_Data()->getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(coreId);
    }
    Data_Output* Framework_DynamicServer::getInstance_Data_Output_DistributeBuffer()
    {
        return getInstance_Data()->getInstance_Data_Output_DistributeBuffer();
    }

    Global* Framework_DynamicServer::getInstance_Global()
    {
        return ptr_Global;
    }

    Execute* Framework_DynamicServer::getInstance_Execute()
    {
        return ptr_Execute;
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
// INSTANCE(S)
    class Algorithms* Framework_DynamicServer::ptr_Algorithms = nullptr;
    //class Control* Framework_DynamicServer::ptr_Control = nullptr;
    class Data* Framework_DynamicServer::ptr_Data = nullptr;
    class Global* Framework_DynamicServer::ptr_Global = nullptr;
    class Execute* Framework_DynamicServer::ptr_Execute = nullptr;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
