//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Thread - Concurrency : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Execute/Thread_Concurrency.h"
#include "Framework/DynamicServer/Control/Execute/LaunchConcurrency.h"
#include "Framework/DynamicServer/Control/Execute/WriteEnable.h"
#include "Framework/SIMULATION/SIMULATION.h"

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
    Thread_Concurrency::Thread_Concurrency()
    {

    }

    Thread_Concurrency::~Thread_Concurrency()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void Thread_Concurrency::thread_Concurrency(
        Framework_DynamicServer* obj,
        unsigned char coreId,
        Logs* ptr_ServerLogs,
        SIMULATION* ptr_Simulation
    )
    {
        std::cout << ">> >> >> Thread STARTED : Dynamic_Server_Backend/Execute/thread_Concurrency" << std::endl;//SIMULATION

        obj->getInstance_Control_Execute()->setConditionCodeOfThisThreadedCore(coreId);
        while(obj->getInstance_Control_Execute()->getFlag_SystemInitialised(coreId) != false) {} // wait untill thread initalised

        while(obj->getInstance_Control_Execute()->getFlag_ThreadInitialised(coreId) == false)
        {
            //std::cout << "CoreID=" << int(coreId) << " : getFlag_ConcurrentCoreState(coreId-1)=>" << obj->getInstance_Execute()->getInstance_LaunchConcurrency()->getFlag_ConcurrentCoreState(coreId-1) << std::endl;//SIMULATION
            if( obj->getInstance_Execute()->getInstance_LaunchConcurrency()->getFlag_ConcurrentCoreState(coreId-1) == obj->getInstance_Global()->getConst_Core_ACTIVE() )
            {
                std::cout << "CoreID=" << int(coreId) << " *** CONCURRENT THREAD ACTIVE ***" << std::endl;//SIMULATION
                //while(true){}

                if (obj->getInstance_Control_Data()->getFlag_InputStackLoaded(coreId) == true)
                {
                    std::cout << "*** thread_Concurrency A" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_Start(coreId);
                    std::cout << "*** thread_Concurrency B" << std::endl;//SIMULATION

                    obj->getInstance_Control_Data()->popFromStackOfInputPraises(
                        obj->getInstance_Data(),
                        obj->getInstance_Data()->getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(coreId),
                        obj->getInstance_Data()->getField_Data_Input_StackOfInputPraise(),
                        coreId
                    );

                    std::cout << "*** thread_Concurrency C" << std::endl;//SIMULATION
                    if(sizeof(obj->getInstance_Data()->getField_Data_Input_StackOfInputPraise()) < 1)
                    {
                        obj->getInstance_Control_Data()->setFlag_InputStackLoaded(false, coreId);
                    }
                    else
                    {
                        obj->getInstance_Control_Data()->setFlag_InputStackLoaded(true, coreId);
                    }
                    std::cout << "*** thread_Concurrency D" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_End(coreId);

                    std::cout << "*** thread_Concurrency E" << std::endl;//SIMULATION

                    obj->getInstance_Control_Algorithms_Concurrent(coreId)->doUserProjectAlgorithmsForPraiseEvent(
                        obj->getInstance_Data()->getInstance_Data_Input_ConcurrentCoreId_InputRefferenceOfCore(coreId),
                        obj->getInstance_Algorithms()->getInstance_Algorithms_Concurrent(coreId),
                        obj->getInstance_Data()->getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(coreId),
                        coreId
                    );

                    std::cout << "*** thread_Concurrency F" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_Start(coreId);
                    std::cout << "*** thread_Concurrency G" << std::endl;//SIMULATION
                    obj->getInstance_Control_Data()->pushToStackOfOutput(
                        obj->getInstance_Data(),
                        obj->getInstance_Data()->getField_Data_Output_StackOfDistributeBuffer(),
                        obj->getInstance_Data()->getInstance_Data_Output_ConcurrentCoreId_OutputRefferenceOfCore(coreId),
                        coreId
                    );
                    std::cout << "*** thread_Concurrency H" << std::endl;//SIMULATION
                    if (sizeof(obj->getInstance_Data()->getField_Data_Input_StackOfInputPraise()) < 1)
                    {
                        obj->getInstance_Control_Data()->setFlag_InputStackLoaded(false, coreId);
                    }
                    else
                    {
                        obj->getInstance_Control_Data()->setFlag_InputStackLoaded(true, coreId);
                    }
                    std::cout << "*** thread_Concurrency I" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_LaunchConcurrency()->thread_End(coreId);
                    std::cout << "*** thread_Concurrency J" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_End(coreId);
                    std::cout << "*** thread_Concurrency K" << std::endl;//SIMULATION
                }
            }
        }
    }


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------



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


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
