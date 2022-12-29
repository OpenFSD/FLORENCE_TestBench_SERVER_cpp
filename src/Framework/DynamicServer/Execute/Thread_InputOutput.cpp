//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Threads - Input / Output : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Execute/Thread_InputOutput.h"
#include "Framework/DynamicServer/Execute/Thread_Concurrency.h"//SIMULATION
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
    Thread_InputOutput::Thread_InputOutput()
    {

    }

    Thread_InputOutput::~Thread_InputOutput()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void Thread_InputOutput::thread_IO_ListenDistribute(
        Framework_DynamicServer* obj,
        unsigned char coreId,
        Logs* ptr_ServerLogs_For_IO,
        SIMULATION* ptr_Simulation_For_IO
    )
    {
        std::cout << ">> >> >> Thread STARTED : Dynamic_Server_Backend/Execute/thread_IO_ListenDistribute" << std::endl;//SIMULATION
        obj->getInstance_Control_Execute()->setConditionCodeOfThisThreadedCore(coreId);
        while(obj->getInstance_Control_Execute()->getFlag_SystemInitialised(coreId) != false)
        {
            /* wait untill thread initalised */
        }
        std::cout << "INSTANCIATION of Dynamic Architecture COMPLETE" << std::endl;//SIMULATION
        std::cout << "LAUNCH of CONCURRENT Dynamic Architecture COMPLETE" << std::endl;//SIMULATION
        std::cout << "" << std::endl;//SIMULATION

        std::cout << "        ,     \\      /      ," << std::endl;//SIMULATION
        std::cout << "       / \\    )\\ __ /(     / \\ " << std::endl;//SIMULATION
        std::cout << "      /   \\   (_\\  /_)    /   \\ " << std::endl;//SIMULATION
        std::cout << "____ / ____\\__ \\@  @/ ___/_____\\_____" << std::endl;//SIMULATION
        std::cout << "|              |\\../|               |" << std::endl;//SIMULATION
        std::cout << "|               \\VV/                |" << std::endl;//SIMULATION
        std::cout << "|             FLORANCE              |" << std::endl;//SIMULATION
        std::cout << "|        DEVELOPERS TEMPLATE        |" << std::endl;//SIMULATION
        std::cout << "|___________________________________|" << std::endl;//SIMULATION
        std::cout << "|    / \\ /        \\\\        \\ /\\    |" << std::endl;//SIMULATION
        std::cout << "|  /    V          ))        V   \\  |" << std::endl;//SIMULATION
        std::cout << "|/                //               \\| " << std::endl;//SIMULATION
        std::cout << "`                 V                 '" << std::endl;//SIMULATION

        //while(obj->getInstance_Control_Execute()->getFlag_ThreadInitialised(coreId) == false)
        //{
            if(obj->getInstance_Control_Algorithms_ListenRespond()->getFlag_IO_ThreadState(coreId) == true)
            {
                std::cout << "CoreID=" << int(coreId) << " getFlag_IO_ThreadState()=" << obj->getInstance_Control_Algorithms_ListenRespond()->getFlag_IO_ThreadState(coreId) << std::endl;//SIMULATION
                //TODO> client praise networking accepted and captured

                /*
                *   SIMULATION INPUT
                */
                /* set registers in praise buffer
                *  set ACK praise captured to equal TRUE (client side)
                *
                */
                if(ptr_Simulation_For_IO->getFlag_Done() == false)
                {
                    std::cout << "### thread_INPUTOutput A" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_Start(coreId);

                    std::cout << "### thread_INPUTOutput B" << std::endl;//SIMULATION
                    ptr_Simulation_For_IO->praiseServer(obj);//SIMULATION

                    ptr_Simulation_For_IO->setFlag_Done(true);
                /*
                *   END SIMULATION INPUT
                */

                    std::cout << "### thread_INPUTOutput C" << std::endl;//SIMULATION
                    obj->getInstance_Control_Data()->pushToStackOfInputPraises(
                        obj->getInstance_Data(),
                        obj->getInstance_Data()->getField_Data_Input_StackOfInputPraise(),
                        obj->getInstance_Data()->getInstance_Data_Input_PraiseBuffer()
                    );
                    std::cout << "### thread_INPUTOutput D" << std::endl;//SIMULATION
                    obj->getInstance_Control_Data()->setFlag_InputStackLoaded(true, coreId);
                    std::cout << "### thread_INPUTOutput E" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_LaunchConcurrency()->concurrent_Thread_Start(coreId);//Dynamic Launch

                    std::cout << "### thread_INPUTOutput F" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_End(coreId);
                }

                Thread_Concurrency::thread_Concurrency(
                    obj,
                    1,
                    ptr_ServerLogs_For_IO,
                    ptr_Simulation_For_IO
                );//SIMULATION

                std::cout << "### thread_INPUTOutput G" << std::endl;//SIMULATION
                obj->getInstance_Control_Algorithms_ListenRespond()->setFlag_IO_ThreadState(false, coreId);//DISTRIBUTE=FALSE
            }
            if(obj->getInstance_Control_Algorithms_ListenRespond()->getFlag_IO_ThreadState(coreId) == false)
            {
                std::cout << "### thread_inputOUTPUT H" << std::endl;//SIMULATION
                if(obj->getInstance_Control_Data()->getFlag_OutputStackLoaded(coreId) == true)
                {
                    std::cout << "### thread_inputOUTPUT I" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_Start(coreId);
                    std::cout << "### thread_inputOUTPUT J" << std::endl;//SIMULATION
                    obj->getInstance_Control_Data()->popFromStackOfOutput(
                        obj->getInstance_Data(),
                        obj->getInstance_Data()->getInstance_Data_Output_DistributeBuffer(),
                        obj->getInstance_Data()->getField_Data_Output_StackOfDistributeBuffer()
                    );
                    std::cout << "### thread_inputOUTPUT K" << std::endl;//SIMULATION
                    if(sizeof(obj->getInstance_Data()->getField_Data_Output_StackOfDistributeBuffer()) < 1)
                    {
                        obj->getInstance_Control_Data()->setFlag_OutputStackLoaded(false, coreId);
                    }
                    else
                    {
                        obj->getInstance_Control_Data()->setFlag_OutputStackLoaded(true, coreId);
                    }
                    //TODO> server distribute networking
                    /* send registers in distribute buffer
                    *  set ACK distribute sent to equal TRUE
                    *
                    */

                    /*
                    *
                    */
                    std::cout << "### thread_inputOUTPUT L" << std::endl;//SIMULATION
                    obj->getInstance_Execute()->getInstance_WriteEnable()->write_End(coreId);
                }
                std::cout << "### thread_inputOUTPUT M" << std::endl;//SIMULATION
                obj->getInstance_Control_Algorithms_ListenRespond()->setFlag_IO_ThreadState(true, coreId);//LISTEN=TRUE
            }
        //}
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
