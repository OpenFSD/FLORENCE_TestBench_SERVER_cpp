//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Control Data : Script File.cpp
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "Framework/DynamicServer/Control/Data/Control_Data.h"
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
    Control_Data::Control_Data()
    {
        this->flag_InputStackLoaded = false;
        std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/Data_Output/flag_InputStackLoaded=FALSE" << std::endl;//SIMULATION

        this->flag_OutputStackLoaded = false;
        std::cout << ">> >> >> Field CREATED : Dynamic_Server_Framework/Data_Output/flag_InputStackLoaded=FALSE" << std::endl;//SIMULATION
    }

    Control_Data::~Control_Data()
    {
        //dtor
    }


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************
    void Control_Data::popFromStackOfInputPraises(Data* obj, Data_Input* referenceForCore, std::vector<class Data_Input*> inputStack, unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " Control_Data_Input::popFromStackOfInputPraises(Control_Algorithms_ListenRespond* obj, Data_Input* referenceForCore, std::vector<class Data_Input*> inputStack, unsigned char coreId)" << std::endl;//SIMULATION
        referenceForCore = inputStack.at(0);
        switch (inputStack.at(1)->getPraiseEventId())
        {
            case 0://NULL DEFAULT
                referenceForCore->setPraiseEventId( inputStack.at(1)->getPraiseEventId() );
                break;

            case 1://USER DEFINED
                //TODO>
                //reference.setMyRegister( stack.getMyRegister() );
                break;
        }
        inputStack.erase(inputStack.begin()+1);
        obj->setField_Data_Input_Stack_InputPraise(inputStack);
    }
    void Control_Data::popFromStackOfOutput(Data* obj_Data, Data_Output* distributeBuffer, std::vector<Data_Output*> outputStack)
    {
        std::cout << "CoreID=0 " << "Control_Data_Output::popFromStackOfOutput(Data_Output* distributeBuffer, std::vector<Data_Output*> outputStack)" << std::endl;//SIMULATION
        distributeBuffer = outputStack[0];
        switch (outputStack[1]->getPraiseEventId())
        {
            case 0://NULL DEFAULT
                distributeBuffer->setPraiseEventId( outputStack[1]->getPraiseEventId() );
                break;

            case 1://USER DEFINED
                //TODO>
                //distributeBuffer.setMyRegister( outputStack[0].getMyRegister() );
                break;
        }
        outputStack.erase(outputStack.begin()+1);
    }
    void Control_Data::pushToStackOfInputPraises(class Data* obj, std::vector<class Data_Input*> inputStack, class Data_Input* praiseBuffer)
    {
        std::cout << "CoreID=0 " << "Control_Data_Input::pushToStackOfInputPraises(std::vector<class Data_Input*> inputStack, Data_Input* praiseBuffer)" << std::endl;//SIMULATION
        std::vector<class Data_Input*> temp;
        temp.resize(inputStack.size());
        for(int index_A = 0; index_A < inputStack.size(); index_A++)
        {
            temp.at(index_A) = inputStack.at(index_A);
        }
        temp.push_back( inputStack.at(0) );
        std::cout << "CoreID=0 " << "getPraiseEventId()=" << praiseBuffer->getPraiseEventId() << std::endl;
        switch(praiseBuffer->getPraiseEventId())
        {
            case 0://NULL DEFAULT
            {
                temp.at(temp.size()-1)->setPraiseEventId( praiseBuffer->getPraiseEventId() );
                break;
            }
            case 1://USER DEFINED
            {
                //TODO>
                //inputStack[inputStack.Length].setMyRegister( praiseBuffer.getMyRegister() );
                break;
            }
        }
        std::cout << "*** size of inputStack=" << temp.size() << std::endl;//SIMULATION
        obj->setField_Data_Input_Stack_InputPraise(temp);
    }
    void Control_Data::pushToStackOfOutput(Data* obj_Data, std::vector<Data_Output*> outputStack, Data_Output* referenceForCore, unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " Control_Data_Output::pushToStackOfOutput(std::vector<Data_Output*> outputStack, Data_Output* referenceForCore, unsigned char coreId)" << std::endl;//SIMULATION
        std::vector<class Data_Output*> temp;
        temp.resize( outputStack.size() );
        for(int index = 0; index < outputStack.size(); index++)
        {
            temp[index] = outputStack[index];
        }
        temp.push_back( outputStack.at(0) );
        std::cout << "CoreID=" << int(coreId) << " referenceForCore->getPraiseEventId()==" << referenceForCore->getPraiseEventId() << std::endl;//SIMULATION
        switch ( referenceForCore->getPraiseEventId() )
        {
            case 0://NULL DEFAULT
                temp.at( temp.size()-1 )->setPraiseEventId( referenceForCore->getPraiseEventId() );
                break;

            case 1://USER DEFINED
                //TODO>
                //outputStack[outputStack.Length].setMyRegister( referenceForCore.getMyRegister() );
                break;
        }
        obj_Data->setField_Data_Output_Stack_OutputDistribute(temp);
    }
//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------
// GET
    bool Control_Data::getFlag_InputStackLoaded(unsigned char coreId)
    {
        return this->flag_InputStackLoaded;
        std::cout << "CoreID=" << int(coreId) << " " << "Control_Data_Input::getFlag_InputStackLoaded()=>" << this->flag_InputStackLoaded << std::endl;//SIMULATION
    }
    bool Control_Data::getFlag_OutputStackLoaded(unsigned char coreId)
    {
        std::cout << "CoreID=" << int(coreId) << " " << "Control_Data_Output::getFlag_OutputStackLoaded(unsigned char coreId)<=" << this->flag_OutputStackLoaded << std::endl;//SIMULATION
        return this->flag_OutputStackLoaded;
    }

// SET
    void Control_Data::setFlag_InputStackLoaded(bool value, unsigned char coreId)
    {
        this->flag_InputStackLoaded = value;
        std::cout << "CoreID=" << int(coreId) << " " << "Control_Data_Input::setFlag_InputStackLoaded(bool value)<=" << this->flag_InputStackLoaded << std::endl;//SIMULATION
    }
    void Control_Data::setFlag_OutputStackLoaded(bool value, unsigned char coreId)
    {
        this->flag_OutputStackLoaded = value;
        std::cout << "CoreID=" << int(coreId) << " " << "Control_Data_Output::setFlag_OutputStackLoaded(bool value, unsigned char coreId)<=" << this->flag_OutputStackLoaded << std::endl;//SIMULATION
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
    bool Control_Data::flag_InputStackLoaded = false;
    bool Control_Data::flag_OutputStackLoaded = false;


//	METHODS **********************************************************************************************************************************************
// 	******************************************************************************************************************************************************

//	GET & SET --------------------------------------------------------------------------------------------------------------------------------------------


//End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
