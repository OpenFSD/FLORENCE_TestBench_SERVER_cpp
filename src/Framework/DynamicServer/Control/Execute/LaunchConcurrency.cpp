//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Control Ececute - Launch Concurrency : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Control/Execute/LaunchConcurrency.h"

#include "Framework/DynamicServer/Global.h"
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
    LaunchConcurrency::LaunchConcurrency(Global* ptr_Global_pass, unsigned char* ptr_My_Num_Implemented_Cores)
    {
        this->ptr_ServerLogs_For_LaunchConcurrency = nullptr;

        this->ptr_NumImplementedCores_For_LaunchConcurrency = ptr_My_Num_Implemented_Cores;
        this->ptr_Global_For_LaunchConcurrency = ptr_Global_pass;

        this->count_CoreId_LaunchActive[*ptr_NumImplementedCores_For_LaunchConcurrency-1];
        for(unsigned char coreId = 0; coreId < *ptr_NumImplementedCores_For_LaunchConcurrency-1; coreId++)
        {
            this->count_CoreId_LaunchActive[coreId] = 0;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/LaunchConcurrency/count_CoreId_LaunchActive[" << coreId << "] = 0" << std::endl;//SIMULATION
        }

        this->count_CoreId_LaunchIdle[*ptr_NumImplementedCores_For_LaunchConcurrency-1];
        for(unsigned char coreId = 0; coreId < *ptr_NumImplementedCores_For_LaunchConcurrency-1; coreId++)
        {
            this->count_CoreId_LaunchIdle[coreId] = 0;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/LaunchConcurrency/count_CoreId_LaunchIdle[" << coreId << "] = 0" << std::endl;//SIMULATION
        }

        this->flag_ConcurrentCoreState[*this->ptr_NumImplementedCores_For_LaunchConcurrency-1];
        for(unsigned char coreId = 0; coreId < *this->ptr_NumImplementedCores_For_LaunchConcurrency-1; coreId++)
        {
            this->setFlag_ConcurrentCoreState(coreId, this->ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE());
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/LaunchConcurrency/flag_CoreStatus[" << int(coreId)+1 << "]<=" << this->getFlag_ConcurrentCoreState(coreId) << std::endl;//SIMULATION
        }

        this->que_CoreToLaunch[*ptr_NumImplementedCores_For_LaunchConcurrency-1];
        for(unsigned char coreId = 1; coreId < *ptr_NumImplementedCores_For_LaunchConcurrency; coreId++)
        {
            this->que_CoreToLaunch[coreId-1] = coreId;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/LaunchConcurrency/que_CoreToLaunch[" << int(coreId)-1 << "]=" << int(coreId) << std::endl;//SIMULATION
        }
    }

    LaunchConcurrency::~LaunchConcurrency()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void LaunchConcurrency::concurrent_Thread_Start(unsigned char coreId)
    {

            this->launchEnable_Request(coreId);
            std::cout << "### thread_INPUTOutput E.1" << std::endl;//SIMULATION
            this->launchQue_Update(coreId);
            std::cout << "### thread_INPUTOutput E.2" << std::endl;//SIMULATION
            this->launchEnable_SortQue(coreId);
            std::cout << "### thread_INPUTOutput E.3" << std::endl;//SIMULATION
            this->launchEnable_Activate(coreId);
            std::cout << "### thread_INPUTOutput E.4" << std::endl;//SIMULATION
            this->launchQue_Update(coreId);
            std::cout << "### thread_INPUTOutput E.5" << std::endl;//SIMULATION
            this->launchEnable_SortQue(coreId);
            std::cout << "### thread_INPUTOutput E.6" << std::endl;//SIMULATION
            this->praisingLaunch = false;
            std::cout << "### thread_INPUTOutput E.7" << std::endl;//SIMULATION
    }
    void LaunchConcurrency::thread_End(unsigned char coreId)
    {
        while(this->praisingLaunch == true)
        {
            /* */
            //std::cout << "CoreID=" << int(coreId) << " " << "WAIT" << std::endl;//SIMULATION
        }
        this->praisingLaunch = true;
        this->coreIdForLaunchPraiseIndex = this->new_coreIdForLaunchPraiseIndex;
        if(this->coreIdForLaunchPraiseIndex == coreId)
        {
            this->setFlag_ConcurrentCoreState(coreId-1, ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE());
            std::cout << "CoreID=" << int(coreId) << " *** THREAD IDLE ***" << this->praisingLaunch << std::endl;//SIMULATION
            // Function exit.
        }
        else
        {
            this->new_coreIdForLaunchPraiseIndex = this->coreIdForLaunchPraiseIndex + 1;
            if(this->new_coreIdForLaunchPraiseIndex == 3)
            {
                this->new_coreIdForLaunchPraiseIndex = 0;
            }
            this->praisingLaunch = false;
            this->thread_End(coreId);
        }
        //setflag_ConcurrnetCoreStategetFlag_ConcurrentCoreState(coreId, 0);//IDLE=0
    }


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    unsigned char LaunchConcurrency::getFlag_CoreId_CoreToLaunch()
    {
        return this->que_CoreToLaunch[0];
    }
    bool LaunchConcurrency::getFlag_ConcurrentCoreState(unsigned char coreId)
    {
        return this->flag_ConcurrentCoreState[coreId];
    }

// SET
    void LaunchConcurrency::setFlag_ConcurrentCoreState(unsigned char coreId, bool value)
    {
        this->flag_ConcurrentCoreState[coreId] = value;
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
    class Global* LaunchConcurrency::ptr_Global_For_LaunchConcurrency = nullptr;
    class Logs* LaunchConcurrency::ptr_ServerLogs_For_LaunchConcurrency = nullptr;
    unsigned char* LaunchConcurrency::ptr_NumImplementedCores_For_LaunchConcurrency = nullptr;


//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    unsigned char LaunchConcurrency::coreIdForLaunchPraiseIndex = 0;
    int LaunchConcurrency::count_CoreId_LaunchActive[2] = { 0, 0 };//NUMBER OF CONCURNT CORES :: getInstance_Global()->get_NumCores() -1
    int LaunchConcurrency::count_CoreId_LaunchIdle[2] = { 0, 0 };
    bool LaunchConcurrency::flag_ConcurrentCoreState[2] = { false, false };//NUMBER OF CONCURRENT CORES :: getInstance_Global()->get_NumCores() -1
    unsigned char LaunchConcurrency::new_coreIdForLaunchPraiseIndex = 0;
    bool LaunchConcurrency::praisingLaunch = false;
    unsigned char LaunchConcurrency::que_CoreToLaunch[2] = { 1, 2 };//NUMBER OF CONCURRENT CORES :: getInstance_Global()->get_NumCores() -1


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void LaunchConcurrency::launchEnable_Activate(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "LaunchConcurrency::launchEnable_Activate(unsigned char coreId)" << std::endl;//SIMULATION
        std::cout << "CoreID=" << int(coreId) << " Core_To_Launch_Status(" << int(this->getFlag_CoreId_CoreToLaunch()) << ")<=ACTIVE=";
        this->setFlag_ConcurrentCoreState(
            this->getFlag_CoreId_CoreToLaunch()-1,
            this->ptr_Global_For_LaunchConcurrency->getConst_Core_ACTIVE()
        );
       std::cout << this->getFlag_ConcurrentCoreState(this->getFlag_CoreId_CoreToLaunch()-1) << std::endl;//SIMULATION
    }
    void LaunchConcurrency::launchEnable_ShiftQueValues(unsigned char coreId, unsigned char coreId_A, unsigned char coreId_B)
    {
        int temp_A = this->count_CoreId_LaunchActive[coreId_A];
        this->count_CoreId_LaunchActive[coreId_A] = this->count_CoreId_LaunchActive[coreId_B];
        this->count_CoreId_LaunchActive[coreId_B] = temp_A;

        int temp_B = this->count_CoreId_LaunchIdle[coreId_A];
        this->count_CoreId_LaunchIdle[coreId_A] = this->count_CoreId_LaunchIdle[coreId_B];
        this->count_CoreId_LaunchIdle[coreId_B] = temp_B;

        unsigned char temp_D = this->que_CoreToLaunch[coreId_A];
        this->que_CoreToLaunch[coreId_A] = this->que_CoreToLaunch[coreId_B];
        this->que_CoreToLaunch[coreId_B] = temp_D;

        std::cout << "CoreID=" << int(coreId) << " que_CoreTo_LAUNCH=[" << int(this->que_CoreToLaunch[0]) << "][" << int(this->que_CoreToLaunch[1]) << "]" << std::endl;//SIMULATION
    }
    void LaunchConcurrency::launchEnable_SortQue(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "LaunchConcurrency::launchEnable_SortQue(unsigned char coreId)" << std::endl;//SIMULATION
        std::cout << "CoreID=" << int(coreId) << " START que_CoreTo_LAUNCH=[" << int(this->que_CoreToLaunch[0]) << "][" << int(this->que_CoreToLaunch[1]) << "]" << std::endl;//SIMULATION
        for(unsigned char index_A = 0; index_A < *this->ptr_NumImplementedCores_For_LaunchConcurrency-2; index_A++)
        {
            for(unsigned char index_B = index_A+1; index_B < *this->ptr_NumImplementedCores_For_LaunchConcurrency-1; index_B++)
            {
                if( this->flag_ConcurrentCoreState[ this->que_CoreToLaunch[index_A] ] ==  this->ptr_Global_For_LaunchConcurrency->getConst_Core_ACTIVE() )
                {
                    if( this->flag_ConcurrentCoreState[ this->que_CoreToLaunch[index_B] ] ==  this->ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE() )
                    {
                        this->launchEnable_ShiftQueValues(coreId, index_A, index_B);
                    }
                    else if( this->flag_ConcurrentCoreState[ this->que_CoreToLaunch[index_B] ] ==  this->ptr_Global_For_LaunchConcurrency->getConst_Core_ACTIVE() )
                    {
                        if( this->count_CoreId_LaunchActive[index_A] > this->count_CoreId_LaunchActive[index_B] )
                        {
                            this->launchEnable_ShiftQueValues(coreId, index_A, index_B);
                        }
                    }
                }
                else if( this->flag_ConcurrentCoreState[ this->que_CoreToLaunch[index_A] ] ==  this->ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE() )
                {
                    if( this->flag_ConcurrentCoreState[ this->que_CoreToLaunch[index_B] ] ==  this->ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE() )
                    {
                        if( this->count_CoreId_LaunchIdle[index_A] < this->count_CoreId_LaunchIdle[index_B] )
                        {
                            this->launchEnable_ShiftQueValues(coreId, index_A, index_B);
                        }
                    }
                }
            }
        }
        std::cout << "CoreID=" << int(coreId) << " FINAL que_CoreTo_LAUNCH=[" << int(this->que_CoreToLaunch[0]) << "][" << int(this->que_CoreToLaunch[1]) << "]" << std::endl;//SIMULATION
    }
    void LaunchConcurrency::launchEnable_Request(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "LaunchConcurrency::launchEnable_Request(unsigned char coreId)" << std::endl;//SIMULATION
        while( this->getFlag_ConcurrentCoreState( this->getFlag_CoreId_CoreToLaunch() ) != this->ptr_Global_For_LaunchConcurrency->getConst_Core_IDLE() )
        {
            /* wait for que[0] launch state to be equal to WAIT */
        }
        while(this->getFlag_Launch_Open() == true)
        {
            /* */
            //std::cout << "CoreID=" << int(coreId) << " " << "WAIT" << std::endl;//SIMULATION
        }
        this->setFlag_Launch_Open(true);
        this->coreIdForLaunchPraiseIndex = this->new_coreIdForLaunchPraiseIndex;
        if(this->coreIdForLaunchPraiseIndex == coreId)
        {
            // Function exit.
        }
        else
        {
            this->new_coreIdForLaunchPraiseIndex = this->coreIdForLaunchPraiseIndex + 1;
            if(this->new_coreIdForLaunchPraiseIndex == 3)
            {
                this->new_coreIdForLaunchPraiseIndex = 0;
            }
            this->praisingLaunch = false;
            this->launchEnable_Request(coreId);
        }
    }
    void LaunchConcurrency::launchQue_Update(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "LaunchConcurrency::launchQue_Update(unsigned char coreId)" << std::endl;//SIMULATION
        for (unsigned char index = 0; index < *this->ptr_NumImplementedCores_For_LaunchConcurrency-1; index++)
        {
            std::cout << "CoreID=" << int(coreId) << " LAUNCH_STATE(" << int(index) << ")=" << this->flag_ConcurrentCoreState[index];
            switch(this->getFlag_ConcurrentCoreState(index))
            {
                case false:
                {
                    this->count_CoreId_LaunchActive[index] = 0;
                    this->count_CoreId_LaunchIdle[index] = this->count_CoreId_LaunchIdle[index]+1;
                    break;
                }
                case true:
                {
                    this->count_CoreId_LaunchActive[index] = this->count_CoreId_LaunchActive[index]+1;
                    this->count_CoreId_LaunchIdle[index] = 0;
                    break;
                }
            }
            std::cout << " :: Idle=" << this->count_CoreId_LaunchIdle[index] << " Active=" << this->count_CoreId_LaunchActive[index] << std::endl;//SIMULATION
        }
    }


//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    int LaunchConcurrency::getCount_LaunchActive(unsigned char index)
    {
        this->count_CoreId_LaunchActive[index];
    }
    int LaunchConcurrency::getCount_LaunchIdle(unsigned char index)
    {
        this->count_CoreId_LaunchIdle[index];
    }
    bool LaunchConcurrency::getFlag_Launch_Open()
    {
        return this->praisingLaunch;
    }
// SET
    void LaunchConcurrency::setCount_LaunchActive(unsigned char index, int value)
    {
        this->count_CoreId_LaunchActive[index] = value;
        //std::cout << "@@ Active=" << this->count_CoreId_LaunchActive[index] << std::endl;//SIMULATION);
    }
    void LaunchConcurrency::setCount_LaunchIdle(unsigned char index, int value)
    {
        this->count_CoreId_LaunchIdle[index] = value;
        //std::cout << "@@ Idle=" << this->count_CoreId_LaunchIdle[index] << std::endl;//SIMULATION);
    }
    void LaunchConcurrency::setFlag_Launch_Open(bool value)
    {
        this->praisingLaunch = value;
    }

//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
