//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Framework : Script File.cs
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef EXECUTE_H
#define EXECUTE_H

#include "Framework/DynamicServer/Control/Execute/Control_Execute.h"
#include "Framework/DynamicServer/Global.h"
#include "Framework/DynamicServer/Control/Execute/LaunchConcurrency.h"
#include "Framework/DynamicServer/Control/Execute/WriteEnable.h"

#include "vector"
#include "thread"

using namespace FLORENCE_Server_Assembly;

namespace FLORENCE_Server_Assembly
{
    class Execute
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
            Execute(Global* glob, unsigned char* ptr_My_Num_Implemented_Cores);
            virtual ~Execute();


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
            void initialise(
                class Framework_DynamicServer* ptr_Framework_DynamicServer_pass,
                class Logs* ptr_ServerLogs_pass,
                class SIMULATION* ptr_Simulation_pass
            );

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
            class Control_Execute* getInstance_Control_Execute();
            class LaunchConcurrency* getInstance_LaunchConcurrency();
            std::thread* getThread_WithCoreId(unsigned char coreId);
            class WriteEnable* getInstance_WriteEnable();


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
            static class Control_Execute* ptr_Control_Execute;
            static class Framework_DynamicServer* ptr_Framework_DynamicServer_For_Execute;
            static class LaunchConcurrency* ptr_LaunchConcurrency_For_Execute;
            static unsigned char* ptr_MyNumImplementedCores_For_Execute;
            static class Logs* ptr_ServerLogs_For_Execute;
            static std::vector<std::thread*> ptr_Thread_WithCoreId;
            static class SIMULATION* ptr_Simulation_For_Execute;
            static class WriteEnable* ptr_WriteEnable_For_Execute;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------

    };
}
#endif // EXECUTE_H
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
