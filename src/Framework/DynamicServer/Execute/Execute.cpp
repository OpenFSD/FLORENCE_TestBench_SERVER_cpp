//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Framework : Script File.cs
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Execute/Execute.h"
#include "Framework/DynamicServer/Control/Execute/LaunchConcurrency.h"
#include "Framework/DynamicServer/Control/Execute/WriteEnable.h"
#include "Framework/DynamicServer/Execute/Thread_Concurrency.h"
#include "Framework/DynamicServer/Execute/Thread_InputOutput.h"
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
    Execute::Execute(Global* glob, unsigned char* ptr_MyNumImplementedCores_pass)
    {
        this->ptr_Control_Execute = new Control_Execute(glob, ptr_MyNumImplementedCores_pass);
        std::cout << ">> >> >> Object CREATED : Dynamic_Server_Framework/Control/Execute" << std::endl;//SIMULATION

        this->ptr_Framework_DynamicServer_For_Execute = nullptr;

        this->ptr_LaunchConcurrency_For_Execute = new LaunchConcurrency(glob, ptr_MyNumImplementedCores_pass);

        this->ptr_MyNumImplementedCores_For_Execute = ptr_MyNumImplementedCores_pass;

        this->ptr_ServerLogs_For_Execute = nullptr;

        this->ptr_Simulation_For_Execute = nullptr;

        this->ptr_WriteEnable_For_Execute = new WriteEnable(glob, ptr_MyNumImplementedCores_pass);

        for(unsigned char index = 0; index < *ptr_MyNumImplementedCores_pass; index++)
        {
            this->ptr_Thread_WithCoreId.at(index) = nullptr;
        }
    }

    Execute::~Execute()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void Execute::initialise(
        class Framework_DynamicServer* ptr_Framework_DynamicServer_pass,
        class Logs* ptr_ServerLogs_pass,
        class SIMULATION* ptr_Simulation_pass
    )
    {
        this->ptr_Framework_DynamicServer_For_Execute = ptr_Framework_DynamicServer_pass;
        this->ptr_ServerLogs_For_Execute = ptr_ServerLogs_pass;
        this->ptr_Simulation_For_Execute = ptr_Simulation_pass;

        for(unsigned char coreId = 1; coreId < *ptr_MyNumImplementedCores_For_Execute; coreId++)
        {
            this->ptr_Thread_WithCoreId.at(coreId) = new std::thread(
                Thread_Concurrency::thread_Concurrency,
                this->ptr_Framework_DynamicServer_For_Execute,
                coreId,
                this->ptr_ServerLogs_For_Execute,
                this->ptr_Simulation_For_Execute
            );
            while(this->getInstance_Control_Execute()->getFlag_ThreadInitialised(coreId) != false) {} //wait untill thread initialised
            std::cout << ">> >> >> Object CREATED : Threads/thread_Concurrency[" << int(coreId) << "]" << std::endl;//SIMULATION
        }
        Thread_InputOutput::thread_IO_ListenDistribute(
            this->ptr_Framework_DynamicServer_For_Execute,
            0,
            this->ptr_ServerLogs_For_Execute,
            this->ptr_Simulation_For_Execute
        );
/*
        this->ptr_Thread_WithCoreId.at(0) = new std::thread(
            Thread_InputOutput::thread_IO_ListenDistribute,
            this->ptr_Framework_DynamicServer_For_Execute,
            0,
            this->ptr_ServerLogs_For_Execute,
            this->ptr_Simulation_For_Execute
        );//Server_FREE
        while(this->getInstance_Control_Execute()->getFlag_ThreadInitialised(0) != false) {} //wait untill thread initialised
        std::cout << ">> >> >> Object CREATED : Threads/InputOutput" << std::endl;//SIMULATION
*/
    }

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    Control_Execute* Execute::getInstance_Control_Execute()
    {
        return this->ptr_Control_Execute;
    }
            //class Thread_Concurrency* ptr_Thread_Concurrency;
            //class Thread_InputOutput* ptr_Thread_InputOutput;
    LaunchConcurrency* Execute::getInstance_LaunchConcurrency()
    {
        return this->ptr_LaunchConcurrency_For_Execute;
    }
    std::thread* Execute::getThread_WithCoreId(unsigned char coreId)
    {
        return this->ptr_Thread_WithCoreId[coreId];
    }
    WriteEnable* Execute::getInstance_WriteEnable()
    {
        return this->ptr_WriteEnable_For_Execute;
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
    class Control_Execute* Execute::ptr_Control_Execute = nullptr;
    class Framework_DynamicServer* Execute::ptr_Framework_DynamicServer_For_Execute = nullptr;
    class LaunchConcurrency* Execute::ptr_LaunchConcurrency_For_Execute = nullptr;
    unsigned char* Execute::ptr_MyNumImplementedCores_For_Execute = nullptr;
    class Logs* Execute::ptr_ServerLogs_For_Execute = nullptr;
    class SIMULATION* Execute::ptr_Simulation_For_Execute = nullptr;
    std::vector<std::thread*> Execute::ptr_Thread_WithCoreId = { nullptr, nullptr, nullptr };
    class WriteEnable* Execute::ptr_WriteEnable_For_Execute = nullptr;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------

//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
