/********************************************************************
	Rhapsody	: 9.0 
	Login		: yanev
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: UC_SortGarbage
//!	Generated Date	: Sun, 16, Jul 2023  
	File Path	: DefaultComponent\DefaultConfig\UC_SortGarbage.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "UC_SortGarbage.h"
//#[ ignore
#define SGCS_USECASE_UC_SortGarbage_UC_SortGarbage_SERIALIZE OM_NO_OP

#define SGCS_USECASE_UC_SortGarbage_showBinStaus_SERIALIZE OM_NO_OP
//#]

//## package SGCS_USECASE

//## class UC_SortGarbage
UC_SortGarbage::UC_SortGarbage(IOxfActive* const theActiveContext) : OMReactive(), nonRecyclableBin(0), recyclableBin(0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(UC_SortGarbage, UC_SortGarbage(), 0, SGCS_USECASE_UC_SortGarbage_UC_SortGarbage_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

UC_SortGarbage::~UC_SortGarbage(void) {
    NOTIFY_DESTRUCTOR(~UC_SortGarbage, true);
}

void UC_SortGarbage::showBinStaus(void) {
    NOTIFY_OPERATION(showBinStaus, showBinStaus(), 0, SGCS_USECASE_UC_SortGarbage_showBinStaus_SERIALIZE);
    //#[ operation showBinStaus()
    std::cout << "Recyclable Bin: "<< recyclableBin << " None RecyclableBin: "<< nonRecyclableBin << std::endl;
    //#]
}

const int UC_SortGarbage::getNonRecyclableBin(void) const {
    return nonRecyclableBin;
}

void UC_SortGarbage::setNonRecyclableBin(const int p_nonRecyclableBin) {
    nonRecyclableBin = p_nonRecyclableBin;
}

const bool UC_SortGarbage::getRecyclable(void) const {
    return recyclable;
}

void UC_SortGarbage::setRecyclable(const bool p_recyclable) {
    recyclable = p_recyclable;
}

const int UC_SortGarbage::getRecyclableBin(void) const {
    return recyclableBin;
}

void UC_SortGarbage::setRecyclableBin(const int p_recyclableBin) {
    recyclableBin = p_recyclableBin;
}

bool UC_SortGarbage::startBehavior(void) {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void UC_SortGarbage::initStatechart(void) {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void UC_SortGarbage::rootState_entDef(void) {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.WaitForSorting");
        rootState_subState = WaitForSorting;
        rootState_active = WaitForSorting;
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus UC_SortGarbage::rootState_processEvent(void) {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State WaitForSorting
        case WaitForSorting:
        {
            if(IS_EVENT_TYPE_OF(evStartSorting_SGCS_USECASE_id) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    NOTIFY_STATE_EXITED("ROOT.WaitForSorting");
                    NOTIFY_STATE_ENTERED("ROOT.Sorting");
                    pushNullTransition();
                    rootState_subState = Sorting;
                    rootState_active = Sorting;
                    //#[ state Sorting.(Entry) 
                    setRecyclable(1);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Sorting
        case Sorting:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    //## transition 1 
                    if(recyclable == true)
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.Sorting");
                            NOTIFY_STATE_ENTERED("ROOT.AddRecyclable");
                            pushNullTransition();
                            rootState_subState = AddRecyclable;
                            rootState_active = AddRecyclable;
                            //#[ state AddRecyclable.(Entry) 
                            setRecyclableBin(recyclableBin + 1);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 2 
                            if(recyclable == false)
                                {
                                    NOTIFY_TRANSITION_STARTED("2");
                                    popNullTransition();
                                    NOTIFY_STATE_EXITED("ROOT.Sorting");
                                    NOTIFY_STATE_ENTERED("ROOT.AddNonRecyclable");
                                    pushNullTransition();
                                    rootState_subState = AddNonRecyclable;
                                    rootState_active = AddNonRecyclable;
                                    //#[ state AddNonRecyclable.(Entry) 
                                    setNonRecyclableBin(nonRecyclableBin + 1);
                                    //#]
                                    NOTIFY_TRANSITION_TERMINATED("2");
                                    res = eventConsumed;
                                }
                        }
                }
            
        }
        break;
        // State AddRecyclable
        case AddRecyclable:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.AddRecyclable");
                    //#[ transition 5 
                    showBinStaus();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.WaitForSorting");
                    rootState_subState = WaitForSorting;
                    rootState_active = WaitForSorting;
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
        }
        break;
        // State AddNonRecyclable
        case AddNonRecyclable:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId) == 1)
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.AddNonRecyclable");
                    //#[ transition 5 
                    showBinStaus();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.WaitForSorting");
                    rootState_subState = WaitForSorting;
                    rootState_active = WaitForSorting;
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedUC_SortGarbage::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("recyclable", x2String(myReal->recyclable));
    aomsAttributes->addAttribute("recyclableBin", x2String(myReal->recyclableBin));
    aomsAttributes->addAttribute("nonRecyclableBin", x2String(myReal->nonRecyclableBin));
}

void OMAnimatedUC_SortGarbage::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case UC_SortGarbage::WaitForSorting:
        {
            WaitForSorting_serializeStates(aomsState);
        }
        break;
        case UC_SortGarbage::Sorting:
        {
            Sorting_serializeStates(aomsState);
        }
        break;
        case UC_SortGarbage::AddRecyclable:
        {
            AddRecyclable_serializeStates(aomsState);
        }
        break;
        case UC_SortGarbage::AddNonRecyclable:
        {
            AddNonRecyclable_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedUC_SortGarbage::WaitForSorting_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.WaitForSorting");
}

void OMAnimatedUC_SortGarbage::Sorting_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Sorting");
}

void OMAnimatedUC_SortGarbage::AddRecyclable_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.AddRecyclable");
}

void OMAnimatedUC_SortGarbage::AddNonRecyclable_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.AddNonRecyclable");
}
//#]

IMPLEMENT_REACTIVE_META_P(UC_SortGarbage, SGCS_USECASE, SGCS_USECASE, false, OMAnimatedUC_SortGarbage)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\UC_SortGarbage.cpp
*********************************************************************/
