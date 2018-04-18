isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Ground_PI_newTm_OnBoard_RI_newTm','Ground.PI_newTm','->','TmDispatch.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Ground_PI_newTm_OnBoard_RI_newTm','Taste::coordinates','"66854 90896 62370 90896 62370 76607 57092 76607"','').
isComponentType('interfaceview::FV::Ground','PUBLIC','PI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Ground','PUBLIC','PI_newTm','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV','Ground','PI_newTm','PROVIDES','SUBPROGRAM','interfaceview::FV::Ground::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Ground','PI_newTm','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_newTm','Taste::coordinates','"57092 76607"','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_newTm','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_newTm','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_newTm','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_newTm','Taste::InterfaceName','"newTm"','').
isFeature('PARAMETER','interfaceview::FV::Ground','PI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Ground','PI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Ground','PI_newTm','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Ground','others','newTm_impl','SUBPROGRAM','interfaceview::FV::Ground::PI_newTm.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Ground','others','OpToPICnx_newTm_impl','newTm_impl','->','PI_newTm','NIL','').
isComponentType('interfaceview::FV::Ground','PUBLIC','PI_triggerTmGUI','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Ground','PUBLIC','PI_triggerTmGUI','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV','Ground','PI_triggerTmGUI','PROVIDES','SUBPROGRAM','interfaceview::FV::Ground::PI_triggerTmGUI.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Ground','PI_triggerTmGUI','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_triggerTmGUI','Taste::coordinates','"39199 59924"','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_triggerTmGUI','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_triggerTmGUI','Taste::RCMperiod','500 ms','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_triggerTmGUI','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','PI_triggerTmGUI','Taste::InterfaceName','"triggerTmGUI"','').
isProperty('NIL','=>','interfaceview::FV::Ground','PI_triggerTmGUI','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Ground','others','triggerTmGUI_impl','SUBPROGRAM','interfaceview::FV::Ground::PI_triggerTmGUI.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Ground','others','OpToPICnx_triggerTmGUI_impl','triggerTmGUI_impl','->','PI_triggerTmGUI','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoard_PI_newTc_Ground_RI_newTc','TcQueue.PI_newTc','->','Ground.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoard_PI_newTc_Ground_RI_newTc','Taste::coordinates','"57092 65981 64654 65981 64654 58403 66854 58403"','').
isComponentType('interfaceview::FV::Ground','PUBLIC','RI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Ground','PUBLIC','RI_newTc','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::FV::TcQueue','').
isFeature('ACCESS','interfaceview::IV','Ground','RI_newTc','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','RI_newTc','Taste::coordinates','"57092 65981"','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','RI_newTc','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','RI_newTc','Taste::InterfaceName','"newTc"','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','RI_newTc','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::Ground','RI_newTc','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Ground','RI_newTc','NIL','tcPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::Ground','PUBLIC','').
isComponentType('interfaceview::IV','PUBLIC','Ground','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV','PUBLIC','Ground','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV','Ground','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Ground','Taste::coordinates','"25410 59924 57092 83155"','').
isSubcomponent('interfaceview::IV','interfaceview','others','Ground','SYSTEM','interfaceview::IV::Ground.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::FV::Ground','').
isImportDeclaration('interfaceview::IV','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::Ground','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::Ground','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::Ground','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::TcQueue','PUBLIC','PI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcQueue','PUBLIC','PI_newTc','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','PI_newTc','PROVIDES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_newTc','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::coordinates','"90886 47221"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::InterfaceName','"newTc"','').
isFeature('PARAMETER','interfaceview::FV::TcQueue','PI_newTc','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_newTc','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_newTc','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TcQueue','others','newTc_impl','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TcQueue','others','OpToPICnx_newTc_impl','newTc_impl','->','PI_newTc','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TcQueue_PI_tcRequest_TcDispatch_RI_tcRequest','TcQueue.PI_tcRequest','->','TcDispatch.RI_tcRequest','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcQueue_PI_tcRequest_TcDispatch_RI_tcRequest','Taste::coordinates','"100417 47001 98903 47001 98903 44267 97390 44267"','').
isComponentType('interfaceview::FV::TcQueue','PUBLIC','PI_tcRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcQueue','PUBLIC','PI_tcRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','PI_tcRequest','PROVIDES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_tcRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_tcRequest','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::coordinates','"97390 44267"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::InterfaceName','"tcRequest"','').
isFeature('PARAMETER','interfaceview::FV::TcQueue','PI_tcRequest','tcPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_tcRequest','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::TcQueue','PI_tcRequest','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_tcRequest','NIL','isAvailable','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_tcRequest','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TcQueue','others','tcRequest_impl','SUBPROGRAM','interfaceview::FV::TcQueue::PI_tcRequest.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TcQueue','others','OpToPICnx_tcRequest_impl','tcRequest_impl','->','PI_tcRequest','NIL','').
isPackage('interfaceview::FV::TcQueue','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcQueue','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcQueue','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/tcqueue.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcQueue','Taste::coordinates','"90886 42934 97390 48864"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TcQueue','SYSTEM','interfaceview::IV::OnBoard::PusServices::TC::TcQueue.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::TcQueue','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TcQueue','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TcQueue','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TC','').
isImportDeclaration('interfaceview::FV::TcQueue','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','PI_tcTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','PI_tcTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','PI_tcTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::TcDispatch::PI_tcTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','PI_tcTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::coordinates','"101467 49220"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::InterfaceName','"tcTrigger"','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','PI_tcTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TcDispatch','others','tcTrigger_impl','SUBPROGRAM','interfaceview::FV::TcDispatch::PI_tcTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TcDispatch','others','OpToPICnx_tcTrigger_impl','tcTrigger_impl','->','PI_tcTrigger','NIL','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tcRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tcRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tcRequest','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_tcRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tcRequest','Taste::coordinates','"100417 47001"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tcRequest','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tcRequest','Taste::InterfaceName','"tcRequest"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tcRequest','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tcRequest','tcPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tcRequest','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tcRequest','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tcRequest','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc17','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc17','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST17','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc17','REQUIRES','SUBPROGRAM','interfaceview::FV::ST17::PI_tc17.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::coordinates','"109238 46090"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::InterfaceName','"tc17"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc17','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc17','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc08','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc08','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST08','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc08','REQUIRES','SUBPROGRAM','interfaceview::FV::ST08::PI_tc08.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::coordinates','"109238 44818"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::InterfaceName','"tc08"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc08','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc08','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc19','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc19','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST19','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc19','REQUIRES','SUBPROGRAM','interfaceview::FV::ST19::PI_tc19.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::coordinates','"109238 43495"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::InterfaceName','"tc19"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc19','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc19','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc09','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc09','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST09','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc09','REQUIRES','SUBPROGRAM','interfaceview::FV::ST09::PI_tc09.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::coordinates','"102567 49220"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::InterfaceName','"tc09"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc09','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc09','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc12','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc12','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST12','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc12','REQUIRES','SUBPROGRAM','interfaceview::FV::ST12::PI_tc12.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::coordinates','"109238 44144"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::InterfaceName','"tc12"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc12','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc12','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc11','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc11','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST11','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc11','REQUIRES','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::coordinates','"109238 45446"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::InterfaceName','"tc11"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc11','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc11','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc18','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc18','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST18','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc18','REQUIRES','SUBPROGRAM','interfaceview::FV::ST18::PI_tc18.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::coordinates','"109238 46715"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::InterfaceName','"tc18"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc18','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc18','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc23','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc23','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST23','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc23','REQUIRES','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::coordinates','"109238 48463"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::InterfaceName','"tc23"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc20','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc20','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST20','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc20','REQUIRES','SUBPROGRAM','interfaceview::FV::ST20::PI_tc20.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::coordinates','"109238 47491"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::InterfaceName','"tc20"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc20','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc20','NIL','tcPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::TcDispatch','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcDispatch','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcDispatch','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/tcdispatch.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcDispatch','Taste::coordinates','"100417 43091 109238 49220"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TcDispatch','SYSTEM','interfaceview::IV::OnBoard::PusServices::TC::TcDispatch.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::TcDispatch','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_newTc_EventServices_RI_newTc','TcQueue.PI_newTc','->','ST19.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_newTc_EventServices_RI_newTc','Taste::coordinates','"143435 54558 81573 54558 81573 43755 89032 43755"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_newTc_ST11_RI_newTc','TcQueue.PI_newTc','->','ST11.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_newTc_ST11_RI_newTc','Taste::coordinates','"149127 89956 81584 89956 81584 43755 89032 43755"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_newTc_OBCP_RI_newTc','TcQueue.PI_newTc','->','ObcpEngine.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_newTc_OBCP_RI_newTc','Taste::coordinates','"142102 111810 81583 111810 81583 43755 89032 43755"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_tcTrigger_trigger_RI_tcTrigger','TcDispatch.PI_tcTrigger','->','trigger.RI_tcTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_tcTrigger_trigger_RI_tcTrigger','Taste::coordinates','"84163 113099 84163 69321 90303 69321 90303 51954"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST17_PI_tc17_TC_RI_tc17','ST17.PI_tc17','->','TcDispatch.RI_tc17','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST17_PI_tc17_TC_RI_tc17','Taste::coordinates','"113303 46910 137779 46910 137779 98313 145745 98313"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST08_PI_tc08_TC_RI_tc08','ST08.PI_tc08','->','TcDispatch.RI_tc08','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST08_PI_tc08_TC_RI_tc08','Taste::coordinates','"113303 44622 139196 44622 139196 76753 149289 76753"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReports_PI_tc09_TC_RI_tc09','ST09.PI_tc09','->','TcDispatch.RI_tc09','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReports_PI_tc09_TC_RI_tc09','Taste::coordinates','"96598 51954 96598 82048 97938 82048"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_tc12_TC_RI_tc12','ST12.PI_tc12','->','TcDispatch.RI_tc12','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_tc12_TC_RI_tc12','Taste::coordinates','"113303 43476 140284 43476 140284 69000 145149 69000"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_tc19_TC_RI_tc19','ST19.PI_tc19','->','TcDispatch.RI_tc19','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_tc19_TC_RI_tc19','Taste::coordinates','"113303 42384 141372 42384 141372 48744 143435 48744"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST11_PI_tc11_TC_RI_tc11','ST11.PI_tc11','->','TcDispatch.RI_tc11','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST11_PI_tc11_TC_RI_tc11','Taste::coordinates','"113303 45759 138503 45759 138503 84551 149127 84551"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OBCP_PI_tc18_TC_RI_tc18','ST18.PI_tc18','->','TcDispatch.RI_tc18','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OBCP_PI_tc18_TC_RI_tc18','Taste::coordinates','"113303 48162 136746 48162 136746 108634 142102 108634"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FilesService_PI_tc23_TC_RI_tc23','ST23.PI_tc23','->','TcDispatch.RI_tc23','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FilesService_PI_tc23_TC_RI_tc23','Taste::coordinates','"113303 50868 134680 50868 134680 131681 141767 131681"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ParameterManagement_PI_tc20_TC_RI_tc20','ST20.PI_tc20','->','TcDispatch.RI_tc20','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ParameterManagement_PI_tc20_TC_RI_tc20','Taste::coordinates','"113303 49267 135713 49267 135713 118608 140893 118608"','').
isPackage('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','NIL','NIL','NIL','Taste::coordinates','"89032 39992 113303 51954"','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','PI_tmTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','PI_tmTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','PI_tmTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','PI_tmTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::coordinates','"94418 102049"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::RCMperiod','1000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::InterfaceName','"tmTrigger"','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','PI_tmTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TmDispatch','others','tmTrigger_impl','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TmDispatch','others','OpToPICnx_tmTrigger_impl','tmTrigger_impl','->','PI_tmTrigger','NIL','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::Ground','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::Ground::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::coordinates','"89067 96881"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TmDispatch','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TmQueue_PI_tmRequest_TmDispatch_RI_tmRequest','TmQueue.PI_tmRequest','->','TmDispatch.RI_tmRequest','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmQueue_PI_tmRequest_TmDispatch_RI_tmRequest','Taste::coordinates','"99119 99282 101562 99282 101562 98988 104006 98988"','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','RI_tmRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','RI_tmRequest','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','RI_tmRequest','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_tmRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_tmRequest','Taste::coordinates','"99119 99282"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_tmRequest','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_tmRequest','Taste::InterfaceName','"tmRequest"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_tmRequest','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TmDispatch','RI_tmRequest','tmPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','RI_tmRequest','NIL','tmPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::TmDispatch','RI_tmRequest','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','RI_tmRequest','NIL','isAvailable','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::TmDispatch','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','TmDispatch','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','TmDispatch','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/tmdispatch.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmDispatch','Taste::coordinates','"89067 94480 99119 102049"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TmDispatch','SYSTEM','interfaceview::IV::OnBoard::PusServices::TM::TmDispatch.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::TmDispatch','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TmDispatch','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TmDispatch','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TM','').
isImportDeclaration('interfaceview::FV::TmDispatch','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::TmQueue','PUBLIC','PI_tmRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmQueue','PUBLIC','PI_tmRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','PI_tmRequest','PROVIDES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_tmRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_tmRequest','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::coordinates','"104006 98988"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::InterfaceName','"tmRequest"','').
isFeature('PARAMETER','interfaceview::FV::TmQueue','PI_tmRequest','tmPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_tmRequest','NIL','tmPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::TmQueue','PI_tmRequest','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_tmRequest','NIL','isAvailable','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_tmRequest','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TmQueue','others','tmRequest_impl','SUBPROGRAM','interfaceview::FV::TmQueue::PI_tmRequest.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TmQueue','others','OpToPICnx_tmRequest_impl','tmRequest_impl','->','PI_tmRequest','NIL','').
isComponentType('interfaceview::FV::TmQueue','PUBLIC','PI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmQueue','PUBLIC','PI_newTm','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','PI_newTm','PROVIDES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_newTm','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::coordinates','"113729 96587"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::InterfaceName','"newTm"','').
isFeature('PARAMETER','interfaceview::FV::TmQueue','PI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','PI_newTm','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TmQueue','others','newTm_impl','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TmQueue','others','OpToPICnx_newTm_impl','newTm_impl','->','PI_newTm','NIL','').
isComponentType('interfaceview::FV::TmQueue','PUBLIC','RI_incCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmQueue','PUBLIC','RI_incCount','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::ST09','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','RI_incCount','REQUIRES','SUBPROGRAM','interfaceview::FV::ST09::PI_incCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','RI_incCount','Taste::coordinates','"106407 94186"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','RI_incCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','RI_incCount','Taste::InterfaceName','"incCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','RI_incCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TmQueue','RI_incCount','tmPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','RI_incCount','NIL','tmPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::TmQueue','RI_incCount','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmQueue','RI_incCount','NIL','isAvailable','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::TmQueue','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','TmQueue','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','TmQueue','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/tmqueue.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmQueue','Taste::coordinates','"104006 94186 113729 102283"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TmQueue','SYSTEM','interfaceview::IV::OnBoard::PusServices::TM::TmQueue.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST01_RI_newTm','TmQueue.PI_newTm','->','ST01.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST01_RI_newTm','Taste::coordinates','"180693 86936 176831 86936 176831 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTm','TmQueue.PI_newTm','->','ST19.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTm','Taste::coordinates','"143435 56355 124002 56355 124002 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTmNoInherit','TmQueue.PI_newTm','->','ST05.RI_newTmNoInherit','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTmNoInherit','Taste::coordinates','"143435 57802 124015 57802 124015 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_HousekeepingServices_RI_newTm','TmQueue.PI_newTm','->','ST03.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_HousekeepingServices_RI_newTm','Taste::coordinates','"145149 67648 123990 67648 123990 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_FilesService_RI_newTm','TmQueue.PI_newTm','->','ST23.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_FilesService_RI_newTm','Taste::coordinates','"141767 135335 123846 135335 123846 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ParameterManagement_RI_newTm','TmQueue.PI_newTm','->','ST20.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ParameterManagement_RI_newTm','Taste::coordinates','"140893 122372 123894 122372 123894 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST17_RI_newTm','TmQueue.PI_newTm','->','ST17.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST17_RI_newTm','Taste::coordinates','"145745 100109 131654 100109 131654 94843 117563 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_tmTrigger_trigger_RI_tmTrigger','TmDispatch.PI_tmTrigger','->','trigger.RI_tmTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_tmTrigger_trigger_RI_tmTrigger','Taste::coordinates','"95202 113099 95202 108811 92860 108811 92860 104524"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReports_PI_incCount_TM_RI_incCount','ST09.PI_incCount','->','TmQueue.RI_incCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReports_PI_incCount_TM_RI_incCount','Taste::coordinates','"89584 92378 89584 88896 104130 88896 104130 85415"','').
isPackage('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','NIL','NIL','NIL','Taste::coordinates','"85580 92378 117563 104524"','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST17','PUBLIC','PI_tc17','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','PI_tc17','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','PI_tc17','PROVIDES','SUBPROGRAM','interfaceview::FV::ST17::PI_tc17.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','PI_tc17','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::coordinates','"145745 98313"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::InterfaceName','"tc17"','').
isFeature('PARAMETER','interfaceview::FV::ST17','PI_tc17','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','PI_tc17','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST17','PI_tc17','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST17','others','tc17_impl','SUBPROGRAM','interfaceview::FV::ST17::PI_tc17.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST17','others','OpToPICnx_tc17_impl','tc17_impl','->','PI_tc17','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST17_RI_ACK','ST01.PI_ACK','->','ST17.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST17_RI_ACK','Taste::coordinates','"162929 96817 172105 96817 172105 92228 180693 92228"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_ACK','Taste::coordinates','"162929 96817"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST17_RI_getApid','OnBoardAPID.PI_getApid','->','ST17.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST17_RI_getApid','Taste::coordinates','"162929 98524 197375 98524 197375 76491 192957 76491"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::coordinates','"162929 98524"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST17_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST17.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST17_RI_getSequenceCount','Taste::coordinates','"162929 102180 194731 102180 194731 80615 192957 80615"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::coordinates','"162929 102180"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_newTm','Taste::coordinates','"145745 100109"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST17','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST17','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST17','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st17.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST17','Taste::coordinates','"145745 95039 162929 103928"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST17','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST17.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST17','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST08_RI_ACK','ST01.PI_ACK','->','ST08.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST08_RI_ACK','Taste::coordinates','"159786 81397 170239 81397 170239 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_TimeReports_RI_ACK','ST01.PI_ACK','->','ST09.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_TimeReports_RI_ACK','Taste::coordinates','"114702 83502 118275 83502 118275 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_EventServices_RI_ACK','ST01.PI_ACK','->','ST19.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_EventServices_RI_ACK','Taste::coordinates','"169638 56959 174091 56959 174091 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_HousekeepingServices_RI_ACK','ST01.PI_ACK','->','ST12.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_HousekeepingServices_RI_ACK','Taste::coordinates','"167548 74025 174120 74025 174120 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST11_RI_ACK','ST01.PI_ACK','->','ST11.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST11_RI_ACK','Taste::coordinates','"160191 89782 170282 89782 170282 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_OBCP_RI_ACK','ST01.PI_ACK','->','ST18.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_OBCP_RI_ACK','Taste::coordinates','"163525 112101 172109 112101 172109 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ParameterManagement_RI_ACK','ST01.PI_ACK','->','ST20.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ParameterManagement_RI_ACK','Taste::coordinates','"166115 121975 173404 121975 173404 92228 180693 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_FilesService_RI_ACK','ST01.PI_ACK','->','ST23.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_FilesService_RI_ACK','Taste::coordinates','"163471 131024 172082 131024 172082 92228 180693 92228"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','PI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','PI_ACK','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','PI_ACK','PROVIDES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::coordinates','"180693 92228"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::InterfaceName','"ACK"','').
isFeature('PARAMETER','interfaceview::FV::ST01','PI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST01','PI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST01','PI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST01','PI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST01','PI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','step','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST01','others','ACK_impl','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST01','others','OpToPICnx_ACK_impl','ACK_impl','->','PI_ACK','NIL','').
isComponentType('interfaceview::FV::ST01','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::coordinates','"180693 86936"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST01','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST01_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST01.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST01_RI_getSequenceCount','Taste::coordinates','"193187 92537 194647 92537 194647 80615 192957 80615"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::coordinates','"193187 92537"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST01','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST01_RI_getApid','OnBoardAPID.PI_getApid','->','ST01.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST01_RI_getApid','Taste::coordinates','"193187 86225 197307 86225 197307 76491 192957 76491"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getApid','Taste::coordinates','"193187 86225"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST01','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST01','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST01','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST01','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st01.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01','Taste::coordinates','"180693 84251 193187 94212"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST01','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST01.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST08','PUBLIC','PI_tc08','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST08','PUBLIC','PI_tc08','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST08','PI_tc08','PROVIDES','SUBPROGRAM','interfaceview::FV::ST08::PI_tc08.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','PI_tc08','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::coordinates','"149289 76753"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::InterfaceName','"tc08"','').
isFeature('PARAMETER','interfaceview::FV::ST08','PI_tc08','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','PI_tc08','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST08','PI_tc08','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST08','others','tc08_impl','SUBPROGRAM','interfaceview::FV::ST08::PI_tc08.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST08','others','OpToPICnx_tc08_impl','tc08_impl','->','PI_tc08','NIL','').
isComponentType('interfaceview::FV::ST08','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST08','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST08','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','RI_ACK','Taste::coordinates','"159786 81397"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST08','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST08','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST08','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST08','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST08','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST08','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST08','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST08','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st08.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST08','Taste::coordinates','"149289 75505 159786 82354"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST08','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST08.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST08','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','TASTE_IV_Properties','').
isSubcomponent('interfaceview::IV::OnBoard::PusServices','OnBoardAPID','others','APID','DATA','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','others','APID','Taste::FS_Default_Value','"2"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_EventServices_RI_getApid','OnBoardAPID.PI_getApid','->','ST05.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_EventServices_RI_getApid','Taste::coordinates','"169638 47495 197443 47495 197443 76491 192957 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_HousekeepingServices_RI_getApid','OnBoardAPID.PI_getApid','->','ST03.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_HousekeepingServices_RI_getApid','Taste::coordinates','"167548 66536 197443 66536 197443 76491 192957 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_FilesService_RI_getApid','OnBoardAPID.PI_getApid','->','ST23.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_FilesService_RI_getApid','Taste::coordinates','"163471 134962 197443 134962 197443 76491 192957 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ParameterManagement_RI_getApid','OnBoardAPID.PI_getApid','->','ST20.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ParameterManagement_RI_getApid','Taste::coordinates','"166115 124304 197375 124304 197375 76491 192957 76491"','').
isComponentType('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','PI_getApid','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getApid','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::coordinates','"192957 76491"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::RCMoperationKind','unprotected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::InterfaceName','"getApid"','').
isFeature('PARAMETER','interfaceview::FV::OnBoardAPID','PI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getApid','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnBoardAPID','others','getApid_impl','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnBoardAPID','others','OpToPICnx_getApid_impl','getApid_impl','->','PI_getApid','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_EventServices_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST05.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_EventServices_RI_getSequenceCount','Taste::coordinates','"169638 45180 194663 45180 194663 80615 192957 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_HousekeepingServices_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST03.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_HousekeepingServices_RI_getSequenceCount','Taste::coordinates','"167548 64324 194731 64324 194731 80615 192957 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_FilesService_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST23.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_FilesService_RI_getSequenceCount','Taste::coordinates','"163471 133812 194663 133812 194663 80615 192957 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ParameterManagement_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST20.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ParameterManagement_RI_getSequenceCount','Taste::coordinates','"166115 123213 194663 123213 194663 80615 192957 80615"','').
isComponentType('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','PI_getSequenceCount','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getSequenceCount','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::coordinates','"192957 80615"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isFeature('PARAMETER','interfaceview::FV::OnBoardAPID','PI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getSequenceCount','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnBoardAPID','others','getSequenceCount_impl','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnBoardAPID','others','OpToPICnx_getSequenceCount_impl','getSequenceCount_impl','->','PI_getSequenceCount','NIL','').
isPackage('interfaceview::FV::OnBoardAPID','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','OnBoardAPID','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','OnBoardAPID','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/onboardapid.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID','Taste::coordinates','"178583 75047 192957 81474"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnBoardAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::OnBoardAPID.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST09','PUBLIC','PI_incCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','PI_incCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','PI_incCount','PROVIDES','SUBPROGRAM','interfaceview::FV::ST09::PI_incCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_incCount','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::coordinates','"110965 83114"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::InterfaceName','"incCount"','').
isFeature('PARAMETER','interfaceview::FV::ST09','PI_incCount','tmPacket','OUT','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_incCount','NIL','tmPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST09','PI_incCount','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_incCount','NIL','isAvailable','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_incCount','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST09','others','incCount_impl','SUBPROGRAM','interfaceview::FV::ST09::PI_incCount.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST09','others','OpToPICnx_incCount_impl','incCount_impl','->','PI_incCount','NIL','').
isComponentType('interfaceview::FV::ST09','PUBLIC','PI_tc09','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','PI_tc09','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','PI_tc09','PROVIDES','SUBPROGRAM','interfaceview::FV::ST09::PI_tc09.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_tc09','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::coordinates','"108570 83114"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::InterfaceName','"tc09"','').
isFeature('PARAMETER','interfaceview::FV::ST09','PI_tc09','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_tc09','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_tc09','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST09','others','tc09_impl','SUBPROGRAM','interfaceview::FV::ST09::PI_tc09.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST09','others','OpToPICnx_tc09_impl','tc09_impl','->','PI_tc09','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getApid_ST09_RI_getApid','TimeReportAPID.PI_getApid','->','ST09.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getApid_ST09_RI_getApid','Taste::coordinates','"107939 81911 106401 81911 106401 81913 104864 81913"','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','interfaceview::FV::TimeReportAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::coordinates','"107939 81911"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getSequenceCount_ST09_RI_getSequenceCount','TimeReportAPID.PI_getSequenceCount','->','ST09.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getSequenceCount_ST09_RI_getSequenceCount','Taste::coordinates','"107939 80810 106401 80810 106401 80944 104864 80944"','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::coordinates','"107939 80810"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_ACK','Taste::coordinates','"112407 80648"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST09','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','ST09','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','ST09','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st19.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST09','Taste::coordinates','"107939 80243 112407 83114"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST09','SYSTEM','interfaceview::IV::OnBoard::PusServices::TimeReports::ST09.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','interfaceview::FV::ST09','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST09','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST09','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TimeReports','').
isImportDeclaration('interfaceview::FV::ST09','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','TASTE_IV_Properties','').
isSubcomponent('interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','others','APID','DATA','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','others','APID','Taste::FS_Default_Value','"2"','').
isComponentType('interfaceview::FV::TimeReportAPID','PUBLIC','PI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TimeReportAPID','PUBLIC','PI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','PI_getApid','PROVIDES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getApid','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::coordinates','"104864 81913"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::RCMoperationKind','unprotected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::InterfaceName','"getApid"','').
isFeature('PARAMETER','interfaceview::FV::TimeReportAPID','PI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getApid','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TimeReportAPID','others','getApid_impl','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getApid.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TimeReportAPID','others','OpToPICnx_getApid_impl','getApid_impl','->','PI_getApid','NIL','').
isComponentType('interfaceview::FV::TimeReportAPID','PUBLIC','PI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TimeReportAPID','PUBLIC','PI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','PI_getSequenceCount','PROVIDES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getSequenceCount','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::coordinates','"104864 80944"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isFeature('PARAMETER','interfaceview::FV::TimeReportAPID','PI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::TimeReportAPID','PI_getSequenceCount','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TimeReportAPID','others','getSequenceCount_impl','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getSequenceCount.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TimeReportAPID','others','OpToPICnx_getSequenceCount_impl','getSequenceCount_impl','->','PI_getSequenceCount','NIL','').
isPackage('interfaceview::FV::TimeReportAPID','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','TimeReportAPID','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','TimeReportAPID','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/timereportapid.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID','Taste::coordinates','"99250 80069 104864 82688"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TimeReportAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::TimeReports::TimeReportAPID.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','NIL','NIL','NIL','Taste::coordinates','"97938 78581 114702 85415"','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST05_RI_getNextEvent','Events.PI_getNextEvent','->','ST05.RI_getNextEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST05_RI_getNextEvent','Taste::coordinates','"153898 45834 155711 45834 155711 52458 163579 52458 163579 51531"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST19_RI_getNextEvent','Events.PI_getNextEvent','->','ST19.RI_getNextEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST19_RI_getNextEvent','Taste::coordinates','"156042 52046 163579 52046 163579 51531"','').
isComponentType('interfaceview::FV::Events','PUBLIC','PI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Events','PUBLIC','PI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','Events','PI_getNextEvent','PROVIDES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::coordinates','"163579 51531"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::InterfaceName','"getNextEvent"','').
isFeature('PARAMETER','interfaceview::FV::Events','PI_getNextEvent','eventInfo','OUT','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::Events','PI_getNextEvent','nextCounter','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','NIL','nextCounter','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::Events','PI_getNextEvent','actualCounter','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','NIL','actualCounter','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Events','others','getNextEvent_impl','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Events','others','OpToPICnx_getNextEvent_impl','getNextEvent_impl','->','PI_getNextEvent','NIL','').
isComponentType('interfaceview::FV::Events','PUBLIC','PI_pushNewEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Events','PUBLIC','PI_pushNewEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','Events','PI_pushNewEvent','PROVIDES','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_pushNewEvent','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::coordinates','"166086 50431"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isFeature('PARAMETER','interfaceview::FV::Events','PI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_pushNewEvent','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Events','others','pushNewEvent_impl','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Events','others','OpToPICnx_pushNewEvent_impl','pushNewEvent_impl','->','PI_pushNewEvent','NIL','').
isComponentType('interfaceview::FV::Events','PUBLIC','PI_debugEventsTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Events','PUBLIC','PI_debugEventsTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','Events','PI_debugEventsTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::Events::PI_debugEventsTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_debugEventsTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_debugEventsTrigger','Taste::coordinates','"158802 47526"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_debugEventsTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_debugEventsTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_debugEventsTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_debugEventsTrigger','Taste::InterfaceName','"debugEventsTrigger"','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_debugEventsTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Events','others','debugEventsTrigger_impl','SUBPROGRAM','interfaceview::FV::Events::PI_debugEventsTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Events','others','OpToPICnx_debugEventsTrigger_impl','debugEventsTrigger_impl','->','PI_debugEventsTrigger','NIL','').
isPackage('interfaceview::FV::Events','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','Events','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','Events','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/events.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events','Taste::coordinates','"158802 45629 166086 51531"','').
isSubcomponent('interfaceview::IV','interfaceview','others','Events','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::Events.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::Events','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::Events','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::Events','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::EventServices','').
isImportDeclaration('interfaceview::FV::Events','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST05','PUBLIC','PI_EventReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','PI_EventReportTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','PI_EventReportTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST05::PI_EventReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','PI_EventReportTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::coordinates','"150361 42262"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::InterfaceName','"EventReportTrigger"','').
isProperty('NIL','=>','interfaceview::FV::ST05','PI_EventReportTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST05','others','EventReportTrigger_impl','SUBPROGRAM','interfaceview::FV::ST05::PI_EventReportTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST05','others','OpToPICnx_EventReportTrigger_impl','EventReportTrigger_impl','->','PI_EventReportTrigger','NIL','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_newTmNoInherit','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_newTmNoInherit','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_newTmNoInherit','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::coordinates','"153898 46677"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::InterfaceName','"newTmNoInherit"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::labelInheritance','"false"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_newTmNoInherit','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_newTmNoInherit','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_getNextEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getNextEvent','Taste::coordinates','"153898 45834"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getNextEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getNextEvent','Taste::InterfaceName','"getNextEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getNextEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getNextEvent','eventInfo','OUT','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getNextEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getNextEvent','nextCounter','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getNextEvent','NIL','nextCounter','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getNextEvent','actualCounter','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getNextEvent','NIL','actualCounter','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::coordinates','"153898 45404"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getSequenceCount','Taste::coordinates','"153898 43873"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST05','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','ST05','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','ST05','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st05.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST05','Taste::coordinates','"147960 42262 153898 47234"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST05','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST05.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::ST05','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST19','PUBLIC','PI_tc19','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','PI_tc19','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','PI_tc19','PROVIDES','SUBPROGRAM','interfaceview::FV::ST19::PI_tc19.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_tc19','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::coordinates','"152190 50499"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::InterfaceName','"tc19"','').
isFeature('PARAMETER','interfaceview::FV::ST19','PI_tc19','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_tc19','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_tc19','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST19','others','tc19_impl','SUBPROGRAM','interfaceview::FV::ST19::PI_tc19.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST19','others','OpToPICnx_tc19_impl','tc19_impl','->','PI_tc19','NIL','').
isComponentType('interfaceview::FV::ST19','PUBLIC','PI_EventActionTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','PI_EventActionTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','PI_EventActionTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST19::PI_EventActionTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_EventActionTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::coordinates','"148975 51335"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::InterfaceName','"EventActionTrigger"','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_EventActionTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST19','others','EventActionTrigger_impl','SUBPROGRAM','interfaceview::FV::ST19::PI_EventActionTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST19','others','OpToPICnx_EventActionTrigger_impl','EventActionTrigger_impl','->','PI_EventActionTrigger','NIL','').
isComponentType('interfaceview::FV::ST19','PUBLIC','RI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','RI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','RI_getNextEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_getNextEvent','Taste::coordinates','"156042 52046"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_getNextEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_getNextEvent','Taste::InterfaceName','"getNextEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_getNextEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_getNextEvent','eventInfo','OUT','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_getNextEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_getNextEvent','nextCounter','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_getNextEvent','NIL','nextCounter','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_getNextEvent','actualCounter','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_getNextEvent','NIL','actualCounter','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST19','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_ACK','Taste::coordinates','"156042 54213"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST19','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::coordinates','"151047 54805"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST19','PUBLIC','RI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','RI_newTc','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::TcQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','RI_newTc','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTc','Taste::coordinates','"148975 53562"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTc','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTc','Taste::InterfaceName','"newTc"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTc','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_newTc','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_newTc','NIL','tcPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST19','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','ST19','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','ST19','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st19.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST19','Taste::coordinates','"148975 50499 156042 54805"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST19','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST19.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::ST19','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_HousekeepingServices_RI_pushNewEvent','Events.PI_pushNewEvent','->','ST12.RI_pushNewEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_HousekeepingServices_RI_pushNewEvent','Taste::coordinates','"167548 71004 171156 71004 171156 51738 169638 51738"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_OBCP_RI_pushNewEvent','Events.PI_pushNewEvent','->','ObcpEngine.RI_pushNewEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_OBCP_RI_pushNewEvent','Taste::coordinates','"163525 105470 172392 105470 172392 51738 169638 51738"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_EventReportTrigger_trigger_RI_EventReportTrigger','ST05.PI_EventReportTrigger','->','trigger.RI_EventReportTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_EventReportTrigger_trigger_RI_EventReportTrigger','Taste::coordinates','"117285 116504 127137 116504 127137 49847 143435 49847"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_debugEventsTrigger_trigger_RI_debugEventsTrigger','Events.PI_debugEventsTrigger','->','trigger.RI_debugEventsTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_debugEventsTrigger_trigger_RI_debugEventsTrigger','Taste::coordinates','"117285 117684 128224 117684 128224 52685 143435 52685"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_EventActionTrigger_trigger_RI_EventActionTrigger','ST19.PI_EventActionTrigger','->','trigger.RI_EventActionTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_EventActionTrigger_trigger_RI_EventActionTrigger','Taste::coordinates','"117285 113921 127654 113921 127654 51341 143435 51341"','').
isPackage('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','NIL','NIL','NIL','Taste::coordinates','"143435 40886 169638 58710"','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::Housekeeping','PUBLIC','PI_setParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Housekeeping','PUBLIC','PI_setParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','PI_setParamValue','PROVIDES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_setParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_setParamValue','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::coordinates','"162990 70150"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::InterfaceName','"setParamValue"','').
isFeature('PARAMETER','interfaceview::FV::Housekeeping','PI_setParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_setParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::Housekeeping','PI_setParamValue','paramValue','IN','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_setParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_setParamValue','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Housekeeping','others','setParamValue_impl','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_setParamValue.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Housekeeping','others','OpToPICnx_setParamValue_impl','setParamValue_impl','->','PI_setParamValue','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST03_RI_getParamValue','Housekeeping.PI_getParamValue','->','ST03.RI_getParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST03_RI_getParamValue','Taste::coordinates','"156005 66052 157603 66052 157603 68206 159201 68206"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST12_RI_getParamValue','Housekeeping.PI_getParamValue','->','ST12.RI_getParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST12_RI_getParamValue','Taste::coordinates','"155823 69886 157512 69886 157512 68206 159201 68206"','').
isComponentType('interfaceview::FV::Housekeeping','PUBLIC','PI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Housekeeping','PUBLIC','PI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','PI_getParamValue','PROVIDES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::coordinates','"159201 68206"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::InterfaceName','"getParamValue"','').
isFeature('PARAMETER','interfaceview::FV::Housekeeping','PI_getParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::Housekeeping','PI_getParamValue','paramValue','OUT','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::Housekeeping','PI_getParamValue','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','NIL','isAvailable','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Housekeeping','others','getParamValue_impl','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Housekeeping','others','OpToPICnx_getParamValue_impl','getParamValue_impl','->','PI_getParamValue','NIL','').
isPackage('interfaceview::FV::Housekeeping','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','Housekeeping','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','Housekeeping','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/housekeeping.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping','Taste::coordinates','"159201 67126 166283 70150"','').
isSubcomponent('interfaceview::IV','interfaceview','others','Housekeeping','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::Housekeeping.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::Housekeeping','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::Housekeeping','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::Housekeeping','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','').
isImportDeclaration('interfaceview::FV::Housekeeping','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST03','PUBLIC','PI_HkReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','PI_HkReportTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','PI_HkReportTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST03::PI_HkReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','PI_HkReportTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::coordinates','"149601 64322"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::InterfaceName','"HkReportTrigger"','').
isProperty('NIL','=>','interfaceview::FV::ST03','PI_HkReportTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST03','others','HkReportTrigger_impl','SUBPROGRAM','interfaceview::FV::ST03::PI_HkReportTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST03','others','OpToPICnx_HkReportTrigger_impl','HkReportTrigger_impl','->','PI_HkReportTrigger','NIL','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::coordinates','"150972 67006"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_getParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getParamValue','Taste::coordinates','"156005 66052"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getParamValue','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getParamValue','Taste::InterfaceName','"getParamValue"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getParamValue','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getParamValue','paramValue','OUT','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getParamValue','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getParamValue','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::coordinates','"156005 65128"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getSequenceCount','Taste::coordinates','"156005 64359"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST03','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','ST03','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','ST03','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st03.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST03','Taste::coordinates','"149601 63651 156005 67006"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST03','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST03.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::ST03','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST12','PUBLIC','PI_PmonTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','PI_PmonTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','PI_PmonTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST12::PI_PmonTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_PmonTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::coordinates','"149753 71096"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::InterfaceName','"PmonTrigger"','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_PmonTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST12','others','PmonTrigger_impl','SUBPROGRAM','interfaceview::FV::ST12::PI_PmonTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST12','others','OpToPICnx_PmonTrigger_impl','PmonTrigger_impl','->','PI_PmonTrigger','NIL','').
isComponentType('interfaceview::FV::ST12','PUBLIC','PI_tc12','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','PI_tc12','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','PI_tc12','PROVIDES','SUBPROGRAM','interfaceview::FV::ST12::PI_tc12.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_tc12','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::coordinates','"149753 69300"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::InterfaceName','"tc12"','').
isFeature('PARAMETER','interfaceview::FV::ST12','PI_tc12','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_tc12','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_tc12','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST12','others','tc12_impl','SUBPROGRAM','interfaceview::FV::ST12::PI_tc12.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST12','others','OpToPICnx_tc12_impl','tc12_impl','->','PI_tc12','NIL','').
isComponentType('interfaceview::FV::ST12','PUBLIC','RI_pushNewEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','RI_pushNewEvent','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::Events','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','RI_pushNewEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::coordinates','"155823 71001"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST12','PUBLIC','RI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','RI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','RI_getParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_getParamValue','Taste::coordinates','"155823 69886"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_getParamValue','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_getParamValue','Taste::InterfaceName','"getParamValue"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_getParamValue','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_getParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_getParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_getParamValue','paramValue','OUT','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_getParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_getParamValue','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_getParamValue','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST12','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_ACK','Taste::coordinates','"151104 72037"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST12','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','ST12','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','ST12','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st12.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST12','Taste::coordinates','"149753 68638 155823 72037"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST12','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST12.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::ST12','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_HkReportTrigger_trigger_RI_HkReportTrigger','ST03.PI_HkReportTrigger','->','trigger.RI_HkReportTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_HkReportTrigger_trigger_RI_HkReportTrigger','Taste::coordinates','"117285 120228 128990 120228 128990 66104 145149 66104"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_PmonTrigger_trigger_RI_PmonTrigger','ST12.PI_PmonTrigger','->','trigger.RI_PmonTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_PmonTrigger_trigger_RI_PmonTrigger','Taste::coordinates','"117285 115165 129617 115165 129617 71113 145149 71113"','').
isPackage('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','NIL','NIL','NIL','Taste::coordinates','"145149 60082 167548 74455"','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST11','PUBLIC','PI_tc11','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','PI_tc11','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','PI_tc11','PROVIDES','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::coordinates','"149127 84551"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::InterfaceName','"tc11"','').
isFeature('PARAMETER','interfaceview::FV::ST11','PI_tc11','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST11','others','tc11_impl','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST11','others','OpToPICnx_tc11_impl','tc11_impl','->','PI_tc11','NIL','').
isComponentType('interfaceview::FV::ST11','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_ACK','Taste::coordinates','"160191 89782"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST11','PUBLIC','RI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','RI_newTc','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::TcQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','RI_newTc','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_newTc','Taste::coordinates','"149127 89956"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_newTc','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_newTc','Taste::InterfaceName','"newTc"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_newTc','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST11','RI_newTc','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','RI_newTc','NIL','tcPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST11','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST11','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','ST11','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st11.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST11','Taste::coordinates','"149127 83512 160191 90921"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST11','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST11.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST11','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST18','PUBLIC','PI_tc18','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST18','PUBLIC','PI_tc18','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','PI_tc18','PROVIDES','SUBPROGRAM','interfaceview::FV::ST18::PI_tc18.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','PI_tc18','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::coordinates','"145280 108899"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::InterfaceName','"tc18"','').
isFeature('PARAMETER','interfaceview::FV::ST18','PI_tc18','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','PI_tc18','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST18','PI_tc18','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST18','others','tc18_impl','SUBPROGRAM','interfaceview::FV::ST18::PI_tc18.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST18','others','OpToPICnx_tc18_impl','tc18_impl','->','PI_tc18','NIL','').
isComponentType('interfaceview::FV::ST18','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST18','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_ACK','Taste::coordinates','"147754 111509"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ObcpEngine_PI_loadDirect_ST18_RI_loadDirect','ObcpEngine.PI_loadDirect','->','ST18.RI_loadDirect','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ObcpEngine_PI_loadDirect_ST18_RI_loadDirect','Taste::coordinates','"149622 108993 151694 108993 151694 108994 153766 108994"','').
isComponentType('interfaceview::FV::ST18','PUBLIC','RI_loadDirect','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST18','PUBLIC','RI_loadDirect','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::ObcpEngine','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','RI_loadDirect','REQUIRES','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadDirect.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadDirect','Taste::coordinates','"149622 108993"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadDirect','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadDirect','Taste::InterfaceName','"loadDirect"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadDirect','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_loadDirect','obcpId','IN','NIL','DataView::PusSt18ObcpId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_loadDirect','NIL','obcpId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_loadDirect','obcpCode','IN','NIL','DataView::PusSt18ObcpCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_loadDirect','NIL','obcpCode','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ObcpEngine_PI_loadReference_ST18_RI_loadReference','ObcpEngine.PI_loadReference','->','ST18.RI_loadReference','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ObcpEngine_PI_loadReference_ST18_RI_loadReference','Taste::coordinates','"149622 110549 151694 110549 151694 110338 153766 110338"','').
isComponentType('interfaceview::FV::ST18','PUBLIC','RI_loadReference','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST18','PUBLIC','RI_loadReference','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','RI_loadReference','REQUIRES','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadReference.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadReference','Taste::coordinates','"149622 110549"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadReference','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadReference','Taste::InterfaceName','"loadReference"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_loadReference','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST18','RI_loadReference','referenceData','IN','NIL','DataView::PusTC_18_13_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','RI_loadReference','NIL','referenceData','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST18','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ST18','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ST18','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st18.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST18','Taste::coordinates','"145280 108315 149622 111509"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST18','SYSTEM','interfaceview::IV::OnBoard::PusServices::OBCP::ST18.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::ST18','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::OBCP','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','PI_loadDirect','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','PI_loadDirect','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','PI_loadDirect','PROVIDES','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadDirect.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadDirect','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadDirect','Taste::coordinates','"153766 108994"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadDirect','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadDirect','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadDirect','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadDirect','Taste::InterfaceName','"loadDirect"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','PI_loadDirect','obcpId','IN','NIL','DataView::PusSt18ObcpId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadDirect','NIL','obcpId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','PI_loadDirect','obcpCode','IN','NIL','DataView::PusSt18ObcpCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadDirect','NIL','obcpCode','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadDirect','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ObcpEngine','others','loadDirect_impl','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadDirect.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ObcpEngine','others','OpToPICnx_loadDirect_impl','loadDirect_impl','->','PI_loadDirect','NIL','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','PI_loadReference','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','PI_loadReference','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','PI_loadReference','PROVIDES','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadReference.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadReference','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadReference','Taste::coordinates','"153766 110338"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadReference','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadReference','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadReference','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','PI_loadReference','Taste::InterfaceName','"loadReference"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','PI_loadReference','referenceData','IN','NIL','DataView::PusTC_18_13_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadReference','NIL','referenceData','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','PI_loadReference','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ObcpEngine','others','loadReference_impl','SUBPROGRAM','interfaceview::FV::ObcpEngine::PI_loadReference.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ObcpEngine','others','OpToPICnx_loadReference_impl','loadReference_impl','->','PI_loadReference','NIL','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','RI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','RI_newTc','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::TcQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','RI_newTc','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_newTc','Taste::coordinates','"154641 111597"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_newTc','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_newTc','Taste::InterfaceName','"newTc"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_newTc','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_newTc','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_newTc','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','RI_getOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','RI_getOnBoardParam','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::OnBoardParams','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','RI_getOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_getOnBoardParam','Taste::coordinates','"160443 109399"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_getOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_getOnBoardParam','Taste::InterfaceName','"getOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_getOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','paramValue','OUT','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_getOnBoardParam','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','RI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','RI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','RI_setOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_setOnBoardParam','Taste::coordinates','"160443 110731"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_setOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_setOnBoardParam','Taste::InterfaceName','"setOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_setOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_setOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_setOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_setOnBoardParam','paramValue','IN','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_setOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ObcpEngine','PUBLIC','RI_pushNewEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ObcpEngine','PUBLIC','RI_pushNewEvent','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::Events','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','RI_pushNewEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_pushNewEvent','Taste::coordinates','"158086 108211"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_pushNewEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','RI_pushNewEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ObcpEngine','RI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ObcpEngine','RI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ObcpEngine','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ObcpEngine','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ObcpEngine','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ObcpEngine','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/obcpengine.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ObcpEngine','Taste::coordinates','"153766 108211 160443 111597"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ObcpEngine','SYSTEM','interfaceview::IV::OnBoard::PusServices::OBCP::ObcpEngine.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::ObcpEngine','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ObcpEngine','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ObcpEngine','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ParameterManagement_PI_setOnBoardParam_OBCP_RI_setOnBoardParam','OnBoardParams.PI_setOnBoardParam','->','ObcpEngine.RI_setOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ParameterManagement_PI_setOnBoardParam_OBCP_RI_setOnBoardParam','Taste::coordinates','"163525 111395 167465 111395 167465 116959 166115 116959"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ParameterManagement_PI_getOnBoardParam_OBCP_RI_getOnBoardParam','OnBoardParams.PI_getOnBoardParam','->','ObcpEngine.RI_getOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ParameterManagement_PI_getOnBoardParam_OBCP_RI_getOnBoardParam','Taste::coordinates','"163525 109057 168637 109057 168637 119080 166115 119080"','').
isPackage('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','NIL','NIL','NIL','Taste::coordinates','"142102 104813 163525 112669"','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST23','PUBLIC','PI_tc23','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','PI_tc23','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','PI_tc23','PROVIDES','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','PI_tc23','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::coordinates','"144779 131027"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::InterfaceName','"tc23"','').
isProperty('NIL','=>','interfaceview::FV::ST23','PI_tc23','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST23','others','tc23_impl','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST23','others','OpToPICnx_tc23_impl','tc23_impl','->','PI_tc23','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_copy_ST23_RI_copy','FileManagement.PI_copy','->','ST23.RI_copy','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_copy_ST23_RI_copy','Taste::coordinates','"150130 131156 152315 131156 152315 131169 154501 131169"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_copy','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_copy','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::FileManagement','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_copy','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_copy.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::coordinates','"150130 131156"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::InterfaceName','"copy"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::labelInheritance','"true"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_delete_ST23_RI_delete','FileManagement.PI_delete','->','ST23.RI_delete','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_delete_ST23_RI_delete','Taste::coordinates','"150130 130393 152315 130393 152315 130390 154501 130390"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_delete','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_delete','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_delete','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::coordinates','"150130 130393"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::InterfaceName','"delete"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::labelInheritance','"true"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_create_ST23_RI_create','FileManagement.PI_create','->','ST23.RI_create','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_create_ST23_RI_create','Taste::coordinates','"150130 129619 152315 129619 152315 129583 154501 129583"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_create','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_create','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_create','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::coordinates','"150130 129619"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::InterfaceName','"create"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::labelInheritance','"true"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_getAttributes_ST23_RI_getAttributes','FileManagement.PI_getAttributes','->','ST23.RI_getAttributes','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_getAttributes_ST23_RI_getAttributes','Taste::coordinates','"150130 131861 152315 131861 152315 131880 154501 131880"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getAttributes','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getAttributes','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getAttributes','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::coordinates','"150130 131861"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::InterfaceName','"getAttributes"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::coordinates','"144779 132069"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::coordinates','"145890 133000"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::coordinates','"148018 133000"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_ACK','Taste::coordinates','"148617 128742"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST23','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','ST23','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','ST23','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st23.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST23','Taste::coordinates','"144779 128742 150130 133000"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST23','SYSTEM','interfaceview::IV::OnBoard::PusServices::FilesService::ST23.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::ST23','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST23','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST23','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::FilesService','').
isImportDeclaration('interfaceview::FV::ST23','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_copy','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_copy','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_copy','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_copy.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::coordinates','"154501 131169"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::InterfaceName','"copy"','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','copy_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_copy.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_copy_impl','copy_impl','->','PI_copy','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_delete','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_delete','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_delete','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::coordinates','"154501 130390"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::InterfaceName','"delete"','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','delete_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_delete_impl','delete_impl','->','PI_delete','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_create','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_create','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_create','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::coordinates','"154501 129583"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::InterfaceName','"create"','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','create_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_create_impl','create_impl','->','PI_create','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_getAttributes','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_getAttributes','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_getAttributes','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::coordinates','"154501 131880"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::InterfaceName','"getAttributes"','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','getAttributes_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_getAttributes_impl','getAttributes_impl','->','PI_getAttributes','NIL','').
isPackage('interfaceview::FV::FileManagement','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','FileManagement','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','FileManagement','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/filemanagement.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement','Taste::coordinates','"154501 128954 162954 133142"','').
isSubcomponent('interfaceview::IV','interfaceview','others','FileManagement','SYSTEM','interfaceview::IV::OnBoard::PusServices::FilesService::FileManagement.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','NIL','NIL','NIL','Taste::coordinates','"141767 126761 163471 136280"','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST20','PUBLIC','PI_tc20','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','PI_tc20','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','PI_tc20','PROVIDES','SUBPROGRAM','interfaceview::FV::ST20::PI_tc20.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','PI_tc20','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::coordinates','"144935 118341"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::InterfaceName','"tc20"','').
isFeature('PARAMETER','interfaceview::FV::ST20','PI_tc20','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','PI_tc20','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST20','PI_tc20','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST20','others','tc20_impl','SUBPROGRAM','interfaceview::FV::ST20::PI_tc20.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST20','others','OpToPICnx_tc20_impl','tc20_impl','->','PI_tc20','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardParams_PI_setOnBoardParam_ST20_RI_setOnBoardParam','OnBoardParams.PI_setOnBoardParam','->','ST20.RI_setOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams_PI_setOnBoardParam_ST20_RI_setOnBoardParam','Taste::coordinates','"152396 118574 153938 118574 153938 118522 155480 118522"','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::OnBoardParams','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_setOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::coordinates','"152396 118574"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::InterfaceName','"setOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_setOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_setOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_setOnBoardParam','paramValue','IN','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_setOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardParams_PI_getOnBoardParam_ST20_RI_getOnBoardParam','OnBoardParams.PI_getOnBoardParam','->','ST20.RI_getOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams_PI_getOnBoardParam_ST20_RI_getOnBoardParam','Taste::coordinates','"152396 120144 153938 120144 153938 120131 155480 120131"','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_getOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_getOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_getOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getOnBoardParam','Taste::coordinates','"152396 120144"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getOnBoardParam','Taste::InterfaceName','"getOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getOnBoardParam','paramValue','OUT','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getOnBoardParam','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getOnBoardParam','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::coordinates','"144935 120193"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_ACK','Taste::coordinates','"151463 121058"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::coordinates','"146783 121058"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getSequenceCount','Taste::coordinates','"149224 121058"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST20','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','ST20','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','ST20','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/st20.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST20','Taste::coordinates','"144935 117757 152396 121058"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST20','SYSTEM','interfaceview::IV::OnBoard::PusServices::ParameterManagement::ST20.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::ST20','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST20','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST20','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::ParameterManagement','').
isImportDeclaration('interfaceview::FV::ST20','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::OnBoardParams','PUBLIC','PI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardParams','PUBLIC','PI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','PI_setOnBoardParam','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::coordinates','"155480 118522"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::InterfaceName','"setOnBoardParam"','').
isFeature('PARAMETER','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','paramValue','IN','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_setOnBoardParam','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnBoardParams','others','setOnBoardParam_impl','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnBoardParams','others','OpToPICnx_setOnBoardParam_impl','setOnBoardParam_impl','->','PI_setOnBoardParam','NIL','').
isComponentType('interfaceview::FV::OnBoardParams','PUBLIC','PI_getOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardParams','PUBLIC','PI_getOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','PI_getOnBoardParam','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::coordinates','"155480 120131"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::InterfaceName','"getOnBoardParam"','').
isFeature('PARAMETER','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','paramValue','OUT','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','NIL','isAvailable','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnBoardParams','PI_getOnBoardParam','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnBoardParams','others','getOnBoardParam_impl','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnBoardParams','others','OpToPICnx_getOnBoardParam_impl','getOnBoardParam_impl','->','PI_getOnBoardParam','NIL','').
isPackage('interfaceview::FV::OnBoardParams','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','OnBoardParams','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','OnBoardParams','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/onboardparams.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams','Taste::coordinates','"155480 117837 164199 120929"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnBoardParams','SYSTEM','interfaceview::IV::OnBoard::PusServices::ParameterManagement::OnBoardParams.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','NIL','NIL','NIL','Taste::coordinates','"140893 113528 166115 124629"','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_HkReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_HkReportTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_HkReportTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_HkReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_HkReportTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_HkReportTrigger','Taste::coordinates','"80138 126232"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_HkReportTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_HkReportTrigger','Taste::RCMperiod','10000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_HkReportTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_HkReportTrigger','Taste::InterfaceName','"HkReportTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_HkReportTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','HkReportTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_HkReportTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_HkReportTrigger_impl','HkReportTrigger_impl','->','PI_HkReportTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_TmDispatchTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_TmDispatchTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_TmDispatchTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_TmDispatchTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_TmDispatchTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TmDispatchTrigger','Taste::coordinates','"80138 117191"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TmDispatchTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TmDispatchTrigger','Taste::RCMperiod','1000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TmDispatchTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TmDispatchTrigger','Taste::InterfaceName','"TmDispatchTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_TmDispatchTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','TmDispatchTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_TmDispatchTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_TmDispatchTrigger_impl','TmDispatchTrigger_impl','->','PI_TmDispatchTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_EventActionTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_EventActionTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_EventActionTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_EventActionTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_EventActionTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventActionTrigger','Taste::coordinates','"80138 127991"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventActionTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventActionTrigger','Taste::RCMperiod','10000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventActionTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventActionTrigger','Taste::InterfaceName','"EventActionTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_EventActionTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','EventActionTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_EventActionTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_EventActionTrigger_impl','EventActionTrigger_impl','->','PI_EventActionTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_TcDispatchTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_TcDispatchTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_TcDispatchTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_TcDispatchTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_TcDispatchTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TcDispatchTrigger','Taste::coordinates','"80138 115813"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TcDispatchTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TcDispatchTrigger','Taste::RCMperiod','1000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TcDispatchTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_TcDispatchTrigger','Taste::InterfaceName','"TcDispatchTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_TcDispatchTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','TcDispatchTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_TcDispatchTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_TcDispatchTrigger_impl','TcDispatchTrigger_impl','->','PI_TcDispatchTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_PmonTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_PmonTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_PmonTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_PmonTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_PmonTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_PmonTrigger','Taste::coordinates','"80138 118389"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_PmonTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_PmonTrigger','Taste::RCMperiod','10000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_PmonTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_PmonTrigger','Taste::InterfaceName','"PmonTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_PmonTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','PmonTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_PmonTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_PmonTrigger_impl','PmonTrigger_impl','->','PI_PmonTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_EventReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_EventReportTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_EventReportTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_EventReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_EventReportTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventReportTrigger','Taste::coordinates','"80138 119879"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventReportTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventReportTrigger','Taste::RCMperiod','1000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventReportTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_EventReportTrigger','Taste::InterfaceName','"EventReportTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_EventReportTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','EventReportTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_EventReportTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_EventReportTrigger_impl','EventReportTrigger_impl','->','PI_EventReportTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','PI_debugEventTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','PI_debugEventTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','PI_debugEventTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::trigger::PI_debugEventTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_debugEventTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_debugEventTrigger','Taste::coordinates','"80138 124760"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_debugEventTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_debugEventTrigger','Taste::RCMperiod','15000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_debugEventTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','PI_debugEventTrigger','Taste::InterfaceName','"debugEventTrigger"','').
isProperty('NIL','=>','interfaceview::FV::trigger','PI_debugEventTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','trigger','others','debugEventTrigger_impl','SUBPROGRAM','interfaceview::FV::trigger::PI_debugEventTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','trigger','others','OpToPICnx_debugEventTrigger_impl','debugEventTrigger_impl','->','PI_debugEventTrigger','NIL','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_tmTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_tmTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::TmDispatch','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_tmTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tmTrigger','Taste::coordinates','"95202 113099"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tmTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tmTrigger','Taste::InterfaceName','"tmTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tmTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_HkReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_HkReportTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST03','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_HkReportTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST03::PI_HkReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_HkReportTrigger','Taste::coordinates','"117285 120228"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_HkReportTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_HkReportTrigger','Taste::InterfaceName','"HkReportTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_HkReportTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_PmonTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_PmonTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST12','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_PmonTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST12::PI_PmonTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_PmonTrigger','Taste::coordinates','"117285 115165"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_PmonTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_PmonTrigger','Taste::InterfaceName','"PmonTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_PmonTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_EventReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_EventReportTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST05','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_EventReportTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST05::PI_EventReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventReportTrigger','Taste::coordinates','"117285 116504"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventReportTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventReportTrigger','Taste::InterfaceName','"EventReportTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventReportTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_tcTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_tcTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::TcDispatch','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_tcTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::TcDispatch::PI_tcTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tcTrigger','Taste::coordinates','"84163 113099"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tcTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tcTrigger','Taste::InterfaceName','"tcTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_tcTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_debugEventsTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_debugEventsTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::Events','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_debugEventsTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_debugEventsTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_debugEventsTrigger','Taste::coordinates','"117285 117684"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_debugEventsTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_debugEventsTrigger','Taste::InterfaceName','"debugEventsTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_debugEventsTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::trigger','PUBLIC','RI_EventActionTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::trigger','PUBLIC','RI_EventActionTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST19','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','trigger','RI_EventActionTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST19::PI_EventActionTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventActionTrigger','Taste::coordinates','"117285 113921"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventActionTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventActionTrigger','Taste::InterfaceName','"EventActionTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','RI_EventActionTrigger','Taste::labelInheritance','"true"','').
isPackage('interfaceview::FV::trigger','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices','PUBLIC','trigger','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices','PUBLIC','trigger','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','trigger','NIL','NIL','Source_Text','("/home/esrocos/esrocos-ws-pus/tools-libpus/taste/trigger.zip")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','trigger','Taste::coordinates','"80138 113099 117285 129496"','').
isSubcomponent('interfaceview::IV','interfaceview','others','trigger','SYSTEM','interfaceview::IV::OnBoard::PusServices::trigger.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::trigger','').
isImportDeclaration('interfaceview::FV::trigger','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::trigger','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::trigger','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_setParamValue_OnboardSoftware_RI_setParamValue','Housekeeping.PI_setParamValue','->','OnboardSoftware.RI_setParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_setParamValue_OnboardSoftware_RI_setParamValue','Taste::coordinates','"219639 58507 211918 58507 211918 69681 203022 69681"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_getParamValue_OnboardSoftware_RI_getParamValue','Housekeeping.PI_getParamValue','->','OnboardSoftware.RI_getParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_getParamValue_OnboardSoftware_RI_getParamValue','Taste::coordinates','"219639 60439 214676 60439 214676 72647 203022 72647"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_pushNewEvent_OnboardSoftware_RI_pushNewEvent','Events.PI_pushNewEvent','->','OnboardSoftware.RI_pushNewEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_pushNewEvent_OnboardSoftware_RI_pushNewEvent','Taste::coordinates','"219639 56026 211887 56026 211887 51769 203022 51769"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_setOnBoardParam_OnboardSoftware_RI_setOnBoardParam','OnBoardParams.PI_setOnBoardParam','->','OnboardSoftware.RI_setOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_setOnBoardParam_OnboardSoftware_RI_setOnBoardParam','Taste::coordinates','"219639 84343 209927 84343 209927 106637 203022 106637"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_getOnBoardParam_OnboardSoftware_RI_getOnBoardParam','OnBoardParams.PI_getOnBoardParam','->','OnboardSoftware.RI_getOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_getOnBoardParam_OnboardSoftware_RI_getOnBoardParam','Taste::coordinates','"219639 91417 212991 91417 212991 113194 203022 113194"','').
isPackage('interfaceview::IV::OnBoard::PusServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','NIL','NIL','NIL','Taste::coordinates','"76800 33193 203022 139274"','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::PusServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard','').
isImportDeclaration('interfaceview::FV::PusServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::PusServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_debugTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_debugTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_debugTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_debugTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_debugTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_debugTrigger','Taste::coordinates','"227997 44167"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_debugTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_debugTrigger','Taste::RCMperiod','15000 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_debugTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_debugTrigger','Taste::InterfaceName','"debugTrigger"','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_debugTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','debugTrigger_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_debugTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_debugTrigger_impl','debugTrigger_impl','->','PI_debugTrigger','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setParamValue','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::Housekeeping','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_setParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_setParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setParamValue','Taste::coordinates','"219639 58507"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setParamValue','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setParamValue','Taste::InterfaceName','"setParamValue"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setParamValue','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_setParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_setParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_setParamValue','paramValue','IN','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_setParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_getParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getParamValue','Taste::coordinates','"219639 60439"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getParamValue','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getParamValue','Taste::InterfaceName','"getParamValue"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getParamValue','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getParamValue','paramId','IN','NIL','DataView::PusSt03ParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getParamValue','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getParamValue','paramValue','OUT','NIL','DataView::PusSt03StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getParamValue','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getParamValue','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getParamValue','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_pushNewEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_pushNewEvent','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::Events','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_pushNewEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::coordinates','"219639 56026"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::OnBoardParams','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_setOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setOnBoardParam','Taste::coordinates','"219639 84343"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setOnBoardParam','Taste::InterfaceName','"setOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_setOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_setOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_setOnBoardParam','paramValue','IN','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_setOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_getOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::coordinates','"219639 91417"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::InterfaceName','"getOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','paramValue','OUT','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','isAvailable','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::OnboardSoftware','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard','PUBLIC','OnboardSoftware','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard','PUBLIC','OnboardSoftware','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware','Taste::coordinates','"219639 44167 238379 98482"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnboardSoftware','SYSTEM','interfaceview::IV::OnBoard::OnboardSoftware.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::OnboardSoftware','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','NIL','NIL','NIL','Taste::coordinates','"66854 18968 241992 150587"','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','TASTE_IV_Properties','').
isProperty('_','_','_','_','_','_','LMP::Unparser_ID_Case','AsIs','').
isProperty('_','_','_','_','_','_','LMP::Unparser_Insert_Header','Yes','').
isPackage('interfaceview::IV','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::dataView','("DataView")','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::dataViewPath','("DataView.aadl")','').
isVersion('AADL2.1','TASTE type interfaceview','','generated code: do not edit').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::coordinates','"0 0 297000 210000"','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::version','"1.3"','').
isComponentType('interfaceview::IV','PUBLIC','interfaceview','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV','PUBLIC','interfaceview','others','SYSTEM','NIL','others','').

