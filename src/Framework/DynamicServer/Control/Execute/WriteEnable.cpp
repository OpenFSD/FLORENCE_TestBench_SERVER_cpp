//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Control Ececute - Write Enable : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Control/Execute/WriteEnable.h"

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
    WriteEnable::WriteEnable(Global* ptr_Global_pass, unsigned char* ptr_My_Num_Implemented_Cores)
    {
        this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable = ptr_My_Num_Implemented_Cores;
        this->ptr_Global_For_Control_Execute_WriteEnable = ptr_Global_pass;

        this->coreIdForWritePraiseIndex = 0;
        std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/coreIdForWritePraiseIndex" << std::endl;//SIMULATION

        this->new_coreIdForWritePraiseIndex = 1;
        std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/new_coreIdForWritePraiseIndex" << std::endl;//SIMULATION

        this->count_CoreId_WriteActive[*this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable];
        for(unsigned char coreId = 0; coreId < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; coreId++)
        {
            this->count_CoreId_WriteActive[coreId] = 0;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/count_CoreId_WriteActive[" << coreId << "] = 0" << std::endl;//SIMULATION
        }

        this->count_CoreId_WriteIdle[*this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable];
        for(unsigned char coreId = 0; coreId < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; coreId++)
        {
            this->count_CoreId_WriteIdle[coreId] = 0;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/count_CoreId_WiteIdle[" << coreId << "] = 0" << std::endl;//SIMULATION
        }

        this->count_CoreId_WriteWait[*this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable];
        for(unsigned char coreId = 0; coreId < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; coreId++)
        {
            this->count_CoreId_WriteWait[coreId] = 0;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/count_CoreId_WriteWait[" << coreId << "] = 0" << std::endl;//SIMULATION
        }

        this->flag_WriteState[*this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable][2];
        for(unsigned char coreId = 0; coreId < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; coreId++)
        {
            for(unsigned char index = 0; index < 2; index++)
            {
                this->setFlag_WriteState(coreId, index, ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(index));
            }
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/flag_WriteState[" << int(coreId) << "] =" << this->getFlag_WriteState(coreId, 0) << this->getFlag_WriteState(coreId, 1) <<std::endl;//SIMULATION
        }

        this->new_coreIdForWritePraiseIndex = 1;

        this->praisingWrite = false;
        std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/praisingWrite<=FALSE" << std::endl;//SIMULATION

        this->que_CoreToWrite[*this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable];
        for(unsigned char coreId = 0; coreId < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; coreId++)
        {
            this->que_CoreToWrite[coreId] = coreId;
            std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/WriteEnable/que_CoreToWrite[" << coreId << "]" << std::endl;//SIMULATION
        }
    }

    WriteEnable::~WriteEnable()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void WriteEnable::write_End(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable::write_End(unsigned char coreId))" << std::endl;//SIMULATION
        for(unsigned char index = 0; index < 2; index++)
        {
            this->setFlag_WriteState(coreId, index, this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(index));
        }
        this->new_coreIdForWritePraiseIndex = this->coreIdForWritePraiseIndex + 1;
        if(this->new_coreIdForWritePraiseIndex == 3)
        {
           this->new_coreIdForWritePraiseIndex = 0;
        }
        this->writeQue_Update(coreId);
        this->writeEnable_SortQue(coreId);
        this->setFlag_ReadWrite_Open(false);
        std::cout << "CoreID=" << int(coreId) << " this->setFlag_ReadWrite_Open(" << this->getFlag_ReadWrite_Open() << ");" << std::endl;//SIMULATION
        std::cout << "CoreID=" << int(coreId) << " *** WRITE END ***" << this->getFlag_ReadWrite_Open() << std::endl;//SIMULATION
    }
    void WriteEnable::write_Start(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable::write_Start(unsigned char coreId)" << std::endl;//SIMULATION
        this->writeEnable_Request(coreId);
        this->writeQue_Update(coreId);
        this->writeEnable_SortQue(coreId);
        this->writeEnable_Activate(coreId);
    }

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    unsigned char WriteEnable::getFlag_CoreId_WriteEnable()
    {
        return this->que_CoreToWrite[0];
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
    class Global* WriteEnable::ptr_Global_For_Control_Execute_WriteEnable = nullptr;
    unsigned char* WriteEnable::ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable = nullptr;

//	REGISTERS ********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    unsigned char WriteEnable::coreIdForWritePraiseIndex = 0;
    int WriteEnable::count_CoreId_WriteActive[3] = { 0, 0, 0 };//NUMBER OF CORES :: getInstance_Global()->get_NumCores()
    int WriteEnable::count_CoreId_WriteIdle[3] = { 0, 0, 0 };//NUMBER OF CORES :: getInstance_Global()->get_NumCores()
    int WriteEnable::count_CoreId_WriteWait[3] = { 0, 0, 0 };//NUMBER OF CORES :: getInstance_Global()->get_NumCores()
    bool WriteEnable::flag_WriteState[3][2] = { {false, false}, {false, false}, {false, false} };//NUMBER OF CORES :: getInstance_Global()->get_NumCores() // [2]
    unsigned char WriteEnable::new_coreIdForWritePraiseIndex = 0;
    bool WriteEnable::praisingWrite = false;
    unsigned char WriteEnable::que_CoreToWrite[3] = { 0, 1, 2 };//NUMBER OF CORES :: getInstance_Global()->get_NumCores()

//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void WriteEnable::writeEnable_Activate(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable->writeEnable_Activate(unsigned char coreId)" << std::endl;//SIMULATION
        std::cout << "CoreID=" << int(coreId) << " " << "getFlag_CoreId_WriteEnable(0)=" << int(this->getFlag_CoreId_WriteEnable()) << std::endl;//SIMULATION
        for(unsigned char index = 0; index < 2; index++)
        {
            this->setFlag_WriteState(this->getFlag_CoreId_WriteEnable(), index, this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WRITE(index));
        }
        std::cout << "CoreID=" << int(coreId) << " " << "*** WRITE ACTIVE ***" << std::endl;//SIMULATION);
    }
    void WriteEnable::writeEnable_ShiftQueValues(unsigned char coreId, unsigned char coreId_A, unsigned char coreId_B)
    {
        int temp_A = this->count_CoreId_WriteActive[coreId_A];
        this->count_CoreId_WriteActive[coreId_A] = this->count_CoreId_WriteActive[coreId_B];
        this->count_CoreId_WriteActive[coreId_B] = temp_A;

        int temp_B = this->count_CoreId_WriteIdle[coreId_A];
        this->count_CoreId_WriteIdle[coreId_A] = this->count_CoreId_WriteIdle[coreId_B];
        this->count_CoreId_WriteIdle[coreId_B] = temp_B;

        int temp_C = this->count_CoreId_WriteWait[coreId_A];
        this->count_CoreId_WriteWait[coreId_A] = this->count_CoreId_WriteWait[coreId_B];
        this->count_CoreId_WriteWait[coreId_B] = temp_C;

        unsigned char temp_D = this->que_CoreToWrite[coreId_A];
        this->que_CoreToWrite[coreId_A] = this->que_CoreToWrite[coreId_B];
        this->que_CoreToWrite[coreId_B] = temp_D;

        std::cout << "CoreID=" << int(coreId) << " que_CoreTo_WRITE=[" << int(this->que_CoreToWrite[0]) << "][" << int(this->que_CoreToWrite[1]) << "][" << int(this->que_CoreToWrite[2]) << "]" << std::endl;//SIMULATION
    }
    void WriteEnable::writeEnable_SortQue(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable::writeEnable_SortQue()" << std::endl;//SIMULATION
        std::cout << "CoreID=" << int(coreId) << " START que_CoreTo_WRITE=[" << int(this->que_CoreToWrite[0]) << "][" << int(this->que_CoreToWrite[1]) << "][" << int(this->que_CoreToWrite[2]) << "]" << std::endl;//SIMULATION
        for(unsigned char index_A = 0; index_A < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable-1; index_A++)
        {
            for(unsigned char index_B = index_A+1; index_B < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; index_B++)
            {
                if( this->flag_WriteState[ this->que_CoreToWrite[index_A] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WRITE(0)
                    && this->flag_WriteState[ this->que_CoreToWrite[index_A] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WRITE(1) )
                {
                    if( (this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(0)
                        && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(1))
                            || ( this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(0)
                                && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(1)) )
                    {
                        this->writeEnable_ShiftQueValues(coreId, index_A, index_B);
                    }
                    else if( this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WRITE(0)
                        && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WRITE(1) )
                    {
                        if( this->count_CoreId_WriteActive[index_A] > this->count_CoreId_WriteActive[index_B] )
                        {
                            this->writeEnable_ShiftQueValues(coreId, index_A, index_B);
                        }
                    }
                }
                else if( this->flag_WriteState[ this->que_CoreToWrite[index_A] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(0)
                    && this->flag_WriteState[ this->que_CoreToWrite[index_A] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(1) )
                {
                    if( this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(0)
                        && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(1) )
                    {
                        this->writeEnable_ShiftQueValues(coreId, index_A, index_B);
                    }
                    else if( this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(0)
                        && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_IDLE(1) )
                    {
                        if( this->count_CoreId_WriteIdle[index_A] < this->count_CoreId_WriteIdle[index_B] )
                        {
                            this->writeEnable_ShiftQueValues(coreId, index_A, index_B);
                        }
                    }
                }
                else if( this->flag_WriteState[ this->que_CoreToWrite[index_A] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(0)
                    && this->flag_WriteState[ this->que_CoreToWrite[index_A] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(1) )
                {
                    if( this->flag_WriteState[ this->que_CoreToWrite[index_B] ][0] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(0)
                        && this->flag_WriteState[ this->que_CoreToWrite[index_B] ][1] ==  this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(1) )
                    {
                        if( this->count_CoreId_WriteWait[index_A] > this->count_CoreId_WriteWait[index_B] )
                        {
                            this->writeEnable_ShiftQueValues(coreId, index_A, index_B);
                        }
                    }
                }
            }
        }
        std::cout << "CoreID=" << int(coreId) << " FINAL que_CoreTo_WRITE=[" << int(this->que_CoreToWrite[0]) << "][" << int(this->que_CoreToWrite[1]) << "][" << int(this->que_CoreToWrite[2]) << "]" << std::endl;//SIMULATION
    }
    void WriteEnable::writeEnable_Request(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable::writeEnable_Request(unsigned char coreId)" << std::endl;//SIMULATION
        while(this->getFlag_ReadWrite_Open() == true)
        {
            /* wait while one thread at a time is scanned */
        }
        this->setFlag_ReadWrite_Open(true);
        this->coreIdForWritePraiseIndex = this->new_coreIdForWritePraiseIndex;
        if(this->coreIdForWritePraiseIndex == coreId)
        {
            for( unsigned char index = 0; index < 2; index++ )
            {
                this->setFlag_WriteState(coreId, index, this->ptr_Global_For_Control_Execute_WriteEnable->getConst_Write_WAIT(index));
            }
            std::cout << "CoreID=" << int(coreId) << " *** WRITE WAIT ***" << std::endl;//SIMULATION
            // Function exit.
        }
        else
        {
            this->new_coreIdForWritePraiseIndex = this->coreIdForWritePraiseIndex + 1;
            if(this->new_coreIdForWritePraiseIndex == 3)
            {
                this->new_coreIdForWritePraiseIndex = 0;
            }
            this->setFlag_ReadWrite_Open(false);
            this->writeEnable_Request(coreId);
        }
    }
    void WriteEnable::writeQue_Update(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "WriteEnable::writeQue_Update()" << std::endl;//SIMULATION
        for (unsigned char index = 0; index < *this->ptr_Num_Implemented_Cores_For_Control_Execute_WriteEnable; index++)
        {
            std::cout << "CoreID=" << int(coreId) << " WRITE_STATE(" << int(index) << ")=" << this->getFlag_WriteState(index, 0) << this->getFlag_WriteState(index, 1);
            if(this->getFlag_WriteState(index, 0) == false)
            {
                if(this->getFlag_WriteState(index, 1) == false)
                {
                    this->setCount_WriteActive(index, 0);
                    this->setCount_WriteIdle(index, this->getCount_WriteIdle(index) + 1);
                    this->setCount_WriteWait(index, 0);
                }
                else if (this->getFlag_WriteState(index, 1) == true)
                {
                    this->setCount_WriteActive(index, 0);
                    this->setCount_WriteIdle(index, 0);
                    this->setCount_WriteWait(index, this->getCount_WriteWait(index) + 1);
                }
            }
            else if (this->getFlag_WriteState(index, 0) == true)
            {
                if(this->getFlag_WriteState(index, 1) == false)
                {
                    this->setCount_WriteActive(index, this->getCount_WriteActive(index) + 1);
                    this->setCount_WriteIdle(index, 0);
                    this->setCount_WriteWait(index, 0);
                }
            }
            std::cout << " :: Wait= " << this->getCount_WriteWait(index) <<" Idle=" << this->getCount_WriteIdle(index) << " Active=" << this->getCount_WriteActive(index) << std::endl;//SIMULATION
        }
    }

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    int WriteEnable::getCount_WriteActive(unsigned char index)
    {
        return this->count_CoreId_WriteActive[index];
    }
    int WriteEnable::getCount_WriteIdle(unsigned char index)
    {
        return this->count_CoreId_WriteIdle[index];
    }
    int WriteEnable::getCount_WriteWait(unsigned char index)
    {
        return this->count_CoreId_WriteWait[index];
    }
    bool WriteEnable::getFlag_ReadWrite_Open()
    {
        return this->praisingWrite;
    }
    bool WriteEnable::getFlag_WriteState(unsigned char coreId, unsigned char index)
    {
        return this->flag_WriteState[coreId][index];
    }

// SET
    void WriteEnable::setCount_WriteActive(unsigned char index, int value)
    {
        this->count_CoreId_WriteActive[index] = value;
    }
    void WriteEnable::setCount_WriteIdle(unsigned char index, int value)
    {
        this->count_CoreId_WriteIdle[index] = value;
    }
    void WriteEnable::setCount_WriteWait(unsigned char index, int value)
    {
        this->count_CoreId_WriteWait[index] = value;
    }
    void WriteEnable::setFlag_ReadWrite_Open(bool value)
    {
        this->praisingWrite = value;
    }
    void WriteEnable::setFlag_WriteState(unsigned char coreId, unsigned char index, bool value)
    {
        this->flag_WriteState[coreId][index] = value;
    }
//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
