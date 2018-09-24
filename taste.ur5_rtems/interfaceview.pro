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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoard_PI_newTc_Ground_RI_newTc','Taste::coordinates','"57092 65981 61439 65981 61439 58403 66854 58403"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_newTc','Taste::coordinates','"91014 47221"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcQueue_PI_tcRequest_TcDispatch_RI_tcRequest','Taste::coordinates','"100545 47001 99031 47001 99031 44267 97518 44267"','').
isComponentType('interfaceview::FV::TcQueue','PUBLIC','PI_tcRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcQueue','PUBLIC','PI_tcRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','PI_tcRequest','PROVIDES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_tcRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcQueue','PI_tcRequest','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcQueue','NIL','PI_tcRequest','Taste::coordinates','"97518 44267"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcQueue','Taste::coordinates','"91014 42934 97518 48864"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','PI_tcTrigger','Taste::coordinates','"101595 49220"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tcRequest','Taste::coordinates','"100545 47001"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::coordinates','"109366 46090"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::InterfaceName','"tc17"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc17','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc17','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc17','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc08','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc08','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST08','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc08','REQUIRES','SUBPROGRAM','interfaceview::FV::ST08::PI_tc08.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::coordinates','"109366 44818"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::InterfaceName','"tc08"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc08','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc08','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc08','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc19','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc19','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST19','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc19','REQUIRES','SUBPROGRAM','interfaceview::FV::ST19::PI_tc19.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::coordinates','"109366 43495"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::InterfaceName','"tc19"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc19','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc19','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc19','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc09','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc09','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST09','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc09','REQUIRES','SUBPROGRAM','interfaceview::FV::ST09::PI_tc09.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::coordinates','"102695 49220"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::InterfaceName','"tc09"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc09','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc09','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc09','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc12','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc12','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST12','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc12','REQUIRES','SUBPROGRAM','interfaceview::FV::ST12::PI_tc12.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::coordinates','"109366 44144"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::InterfaceName','"tc12"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc12','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc12','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc12','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc11','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc11','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST11','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc11','REQUIRES','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::coordinates','"109366 45446"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::InterfaceName','"tc11"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc11','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc11','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc11','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc18','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc18','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST18','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc18','REQUIRES','SUBPROGRAM','interfaceview::FV::ST18::PI_tc18.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::coordinates','"109366 46715"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::InterfaceName','"tc18"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc18','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc18','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc18','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc23','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc23','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST23','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc23','REQUIRES','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::coordinates','"109366 48463"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::InterfaceName','"tc23"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc23','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc23','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc23','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc20','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc20','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST20','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc20','REQUIRES','SUBPROGRAM','interfaceview::FV::ST20::PI_tc20.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::coordinates','"109366 47491"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::InterfaceName','"tc20"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc20','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc20','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc20','NIL','tcPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::TcDispatch','PUBLIC','RI_tc201','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TcDispatch','PUBLIC','RI_tc201','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::ST201','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','RI_tc201','REQUIRES','SUBPROGRAM','interfaceview::FV::ST201::PI_tc201.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc201','Taste::coordinates','"105468 49220"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc201','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc201','Taste::InterfaceName','"tc201"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','RI_tc201','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TcDispatch','RI_tc201','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TcDispatch','RI_tc201','NIL','tcPacket','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::TcDispatch','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcDispatch','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','TcDispatch','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','TcDispatch','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TcDispatch','Taste::coordinates','"100545 43091 109366 49220"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TcDispatch','SYSTEM','interfaceview::IV::OnBoard::PusServices::TC::TcDispatch.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','interfaceview::FV::TcDispatch','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TcDispatch','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_newTc_EventServices_RI_newTc','TcQueue.PI_newTc','->','ST19.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_newTc_EventServices_RI_newTc','Taste::coordinates','"143563 54558 81701 54558 81701 43755 89160 43755"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TC_PI_newTc_ST11_RI_newTc','TcQueue.PI_newTc','->','ST11.RI_newTc','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TC_PI_newTc_ST11_RI_newTc','Taste::coordinates','"149255 89956 81712 89956 81712 43755 89160 43755"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST17_PI_tc17_TC_RI_tc17','ST17.PI_tc17','->','TcDispatch.RI_tc17','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST17_PI_tc17_TC_RI_tc17','Taste::coordinates','"113431 46910 137907 46910 137907 98313 145873 98313"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST08_PI_tc08_TC_RI_tc08','ST08.PI_tc08','->','TcDispatch.RI_tc08','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST08_PI_tc08_TC_RI_tc08','Taste::coordinates','"113431 44622 139324 44622 139324 76753 149417 76753"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReports_PI_tc09_TC_RI_tc09','ST09.PI_tc09','->','TcDispatch.RI_tc09','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReports_PI_tc09_TC_RI_tc09','Taste::coordinates','"96726 51954 96726 82048 98066 82048"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_tc12_TC_RI_tc12','ST12.PI_tc12','->','TcDispatch.RI_tc12','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','HousekeepingServices_PI_tc12_TC_RI_tc12','Taste::coordinates','"113431 43476 140412 43476 140412 69000 145277 69000"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_tc19_TC_RI_tc19','ST19.PI_tc19','->','TcDispatch.RI_tc19','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_tc19_TC_RI_tc19','Taste::coordinates','"113431 42384 141500 42384 141500 48744 143563 48744"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST11_PI_tc11_TC_RI_tc11','ST11.PI_tc11','->','TcDispatch.RI_tc11','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST11_PI_tc11_TC_RI_tc11','Taste::coordinates','"113431 45759 138631 45759 138631 84551 149255 84551"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OBCP_PI_tc18_TC_RI_tc18','ST18.PI_tc18','->','TcDispatch.RI_tc18','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OBCP_PI_tc18_TC_RI_tc18','Taste::coordinates','"113431 48162 136874 48162 136874 108634 142230 108634"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FilesService_PI_tc23_TC_RI_tc23','ST23.PI_tc23','->','TcDispatch.RI_tc23','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FilesService_PI_tc23_TC_RI_tc23','Taste::coordinates','"113431 50197 134808 50197 134808 131681 141895 131681"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ParameterManagement_PI_tc20_TC_RI_tc20','ST20.PI_tc20','->','TcDispatch.RI_tc20','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ParameterManagement_PI_tc20_TC_RI_tc20','Taste::coordinates','"113431 49267 135841 49267 135841 118608 141021 118608"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','RobotControl_PI_tc201_TC_RI_tc201','ST201.PI_tc201','->','TcDispatch.RI_tc201','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','RobotControl_PI_tc201_TC_RI_tc201','Taste::coordinates','"113431 51642 124617 51642 124617 167054 135804 167054"','').
isPackage('interfaceview::IV::OnBoard::PusServices::TC','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TC','NIL','NIL','NIL','Taste::coordinates','"89160 39992 113431 51954"','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TC','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','PI_tmTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','PI_tmTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','PI_tmTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','PI_tmTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::coordinates','"94546 102049"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','PI_tmTrigger','Taste::InterfaceName','"tmTrigger"','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','PI_tmTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','TmDispatch','others','tmTrigger_impl','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','TmDispatch','others','OpToPICnx_tmTrigger_impl','tmTrigger_impl','->','PI_tmTrigger','NIL','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::Ground','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::Ground::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::coordinates','"89195 96881"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::TmDispatch','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::TmDispatch','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TmQueue_PI_tmRequest_TmDispatch_RI_tmRequest','TmQueue.PI_tmRequest','->','TmDispatch.RI_tmRequest','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmQueue_PI_tmRequest_TmDispatch_RI_tmRequest','Taste::coordinates','"99247 99282 101690 99282 101690 98988 104134 98988"','').
isComponentType('interfaceview::FV::TmDispatch','PUBLIC','RI_tmRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::TmDispatch','PUBLIC','RI_tmRequest','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','RI_tmRequest','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_tmRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmDispatch','NIL','RI_tmRequest','Taste::coordinates','"99247 99282"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmDispatch','Taste::coordinates','"89195 94480 99247 102049"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_tmRequest','Taste::coordinates','"104134 98988"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','PI_newTm','Taste::coordinates','"113857 96587"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','TmQueue','NIL','RI_incCount','Taste::coordinates','"106535 94186"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TmQueue','Taste::coordinates','"104134 94186 113857 102283"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TmQueue','SYSTEM','interfaceview::IV::OnBoard::PusServices::TM::TmQueue.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TmQueue','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST01_RI_newTm','TmQueue.PI_newTm','->','ST01.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST01_RI_newTm','Taste::coordinates','"180821 86936 176959 86936 176959 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTm','TmQueue.PI_newTm','->','ST19.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTm','Taste::coordinates','"143563 56355 124130 56355 124130 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTmNoInherit','TmQueue.PI_newTm','->','ST05.RI_newTmNoInherit','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_EventServices_RI_newTmNoInherit','Taste::coordinates','"143563 57802 124143 57802 124143 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_HousekeepingServices_RI_newTm','TmQueue.PI_newTm','->','ST03.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_HousekeepingServices_RI_newTm','Taste::coordinates','"145277 67648 124118 67648 124118 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_FilesService_RI_newTm','TmQueue.PI_newTm','->','ST23.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_FilesService_RI_newTm','Taste::coordinates','"141895 135335 123974 135335 123974 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ParameterManagement_RI_newTm','TmQueue.PI_newTm','->','ST20.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ParameterManagement_RI_newTm','Taste::coordinates','"141021 122372 124022 122372 124022 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST17_RI_newTm','TmQueue.PI_newTm','->','ST17.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_ST17_RI_newTm','Taste::coordinates','"145873 100109 131782 100109 131782 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TM_PI_newTm_RobotControl_RI_newTm','TmQueue.PI_newTm','->','ST201.RI_newTm','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TM_PI_newTm_RobotControl_RI_newTm','Taste::coordinates','"135804 170599 126747 170599 126747 94843 117691 94843"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReports_PI_incCount_TM_RI_incCount','ST09.PI_incCount','->','TmQueue.RI_incCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReports_PI_incCount_TM_RI_incCount','Taste::coordinates','"89712 92378 89712 88896 104258 88896 104258 85415"','').
isPackage('interfaceview::IV::OnBoard::PusServices::TM','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TM','NIL','NIL','NIL','Taste::coordinates','"85708 92378 117691 104524"','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TM','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST17','PUBLIC','PI_tc17','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','PI_tc17','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','PI_tc17','PROVIDES','SUBPROGRAM','interfaceview::FV::ST17::PI_tc17.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','PI_tc17','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','PI_tc17','Taste::coordinates','"145873 98313"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST17_RI_ACK','Taste::coordinates','"163057 96817 172233 96817 172233 92228 180821 92228"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_ACK','Taste::coordinates','"163057 96817"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST17_RI_getApid','Taste::coordinates','"163057 98524 197503 98524 197503 76491 193085 76491"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::coordinates','"163057 98524"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST17_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST17.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST17_RI_getSequenceCount','Taste::coordinates','"163057 102180 194859 102180 194859 80615 193085 80615"','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::coordinates','"163057 102180"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST17','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST17','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST17','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST17','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST17','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST17','NIL','RI_newTm','Taste::coordinates','"145873 100109"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST17','Taste::coordinates','"145873 95039 163057 103928"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST17','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST17.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST17','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST17','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST08_RI_ACK','ST01.PI_ACK','->','ST08.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST08_RI_ACK','Taste::coordinates','"159914 81397 170367 81397 170367 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_TimeReports_RI_ACK','ST01.PI_ACK','->','ST09.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_TimeReports_RI_ACK','Taste::coordinates','"114830 83502 118403 83502 118403 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_EventServices_RI_ACK','ST01.PI_ACK','->','ST19.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_EventServices_RI_ACK','Taste::coordinates','"169766 56959 174219 56959 174219 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_HousekeepingServices_RI_ACK','ST01.PI_ACK','->','ST12.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_HousekeepingServices_RI_ACK','Taste::coordinates','"167676 74025 174248 74025 174248 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST11_RI_ACK','ST01.PI_ACK','->','ST11.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ST11_RI_ACK','Taste::coordinates','"160319 89782 170410 89782 170410 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_OBCP_RI_ACK','ST01.PI_ACK','->','ST18.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_OBCP_RI_ACK','Taste::coordinates','"163653 112101 172237 112101 172237 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ParameterManagement_RI_ACK','ST01.PI_ACK','->','ST20.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_ParameterManagement_RI_ACK','Taste::coordinates','"166243 121975 173532 121975 173532 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_FilesService_RI_ACK','ST01.PI_ACK','->','ST23.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_FilesService_RI_ACK','Taste::coordinates','"163599 131024 172210 131024 172210 92228 180821 92228"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST01_PI_ACK_RobotControl_RI_ACK','ST01.PI_ACK','->','ST201.RI_ACK','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01_PI_ACK_RobotControl_RI_ACK','Taste::coordinates','"163327 163811 171217 163811 171217 92228 180821 92228"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','PI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','PI_ACK','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','PI_ACK','PROVIDES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','PI_ACK','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','PI_ACK','Taste::coordinates','"180821 92228"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::coordinates','"180821 86936"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST01','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST01_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST01.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ST01_RI_getSequenceCount','Taste::coordinates','"193315 92537 194775 92537 194775 80615 193085 80615"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::coordinates','"193315 92537"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST01','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST01','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST01_RI_getApid','OnBoardAPID.PI_getApid','->','ST01.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ST01_RI_getApid','Taste::coordinates','"193315 86225 197435 86225 197435 76491 193085 76491"','').
isComponentType('interfaceview::FV::ST01','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST01','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST01','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST01','NIL','RI_getApid','Taste::coordinates','"193315 86225"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST01','Taste::coordinates','"180821 84251 193315 94212"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST01','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST01.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST01','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST08','PUBLIC','PI_tc08','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST08','PUBLIC','PI_tc08','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST08','PI_tc08','PROVIDES','SUBPROGRAM','interfaceview::FV::ST08::PI_tc08.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST08','PI_tc08','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','PI_tc08','Taste::coordinates','"149417 76753"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST08','NIL','RI_ACK','Taste::coordinates','"159914 81397"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST08','Taste::coordinates','"149417 75505 159914 82354"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST08','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST08.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST08','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST08','PUBLIC','TASTE_IV_Properties','').
isSubcomponent('interfaceview::IV::OnBoard::PusServices','OnBoardAPID','others','APID','DATA','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','others','APID','Taste::FS_Default_Value','"2"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_EventServices_RI_getApid','OnBoardAPID.PI_getApid','->','ST05.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_EventServices_RI_getApid','Taste::coordinates','"169766 47495 197571 47495 197571 76491 193085 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_HousekeepingServices_RI_getApid','OnBoardAPID.PI_getApid','->','ST03.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_HousekeepingServices_RI_getApid','Taste::coordinates','"167676 66536 197571 66536 197571 76491 193085 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_FilesService_RI_getApid','OnBoardAPID.PI_getApid','->','ST23.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_FilesService_RI_getApid','Taste::coordinates','"163599 134962 197571 134962 197571 76491 193085 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ParameterManagement_RI_getApid','OnBoardAPID.PI_getApid','->','ST20.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_ParameterManagement_RI_getApid','Taste::coordinates','"166243 124304 197503 124304 197503 76491 193085 76491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_RobotControl_RI_getApid','OnBoardAPID.PI_getApid','->','ST201.RI_getApid','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getApid_RobotControl_RI_getApid','Taste::coordinates','"163327 165183 198813 165183 198813 76491 193085 76491"','').
isComponentType('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','PI_getApid','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getApid','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getApid','Taste::coordinates','"193085 76491"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_EventServices_RI_getSequenceCount','Taste::coordinates','"169766 45180 194791 45180 194791 80615 193085 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_HousekeepingServices_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST03.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_HousekeepingServices_RI_getSequenceCount','Taste::coordinates','"167676 64324 194859 64324 194859 80615 193085 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_FilesService_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST23.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_FilesService_RI_getSequenceCount','Taste::coordinates','"163599 133812 194791 133812 194791 80615 193085 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ParameterManagement_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST20.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_ParameterManagement_RI_getSequenceCount','Taste::coordinates','"166243 123213 194791 123213 194791 80615 193085 80615"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_RobotControl_RI_getSequenceCount','OnBoardAPID.PI_getSequenceCount','->','ST201.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID_PI_getSequenceCount_RobotControl_RI_getSequenceCount','Taste::coordinates','"163327 166175 198813 166175 198813 80615 193085 80615"','').
isComponentType('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnBoardAPID','PUBLIC','PI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','PI_getSequenceCount','PROVIDES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnBoardAPID','PI_getSequenceCount','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','OnBoardAPID','NIL','PI_getSequenceCount','Taste::coordinates','"193085 80615"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardAPID','Taste::coordinates','"178711 75047 193085 81474"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnBoardAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::OnBoardAPID.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoardAPID','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST09','PUBLIC','PI_incCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','PI_incCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','PI_incCount','PROVIDES','SUBPROGRAM','interfaceview::FV::ST09::PI_incCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','PI_incCount','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_incCount','Taste::coordinates','"111093 83114"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','PI_tc09','Taste::coordinates','"108698 83114"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getApid_ST09_RI_getApid','Taste::coordinates','"108067 81911 106529 81911 106529 81913 104992 81913"','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','interfaceview::FV::TimeReportAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::coordinates','"108067 81911"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getSequenceCount_ST09_RI_getSequenceCount','TimeReportAPID.PI_getSequenceCount','->','ST09.RI_getSequenceCount','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID_PI_getSequenceCount_ST09_RI_getSequenceCount','Taste::coordinates','"108067 80810 106529 80810 106529 80944 104992 80944"','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::TimeReportAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::coordinates','"108067 80810"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST09','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST09','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST09','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST09','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','ST09','NIL','RI_ACK','Taste::coordinates','"112535 80648"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST09','Taste::coordinates','"108067 80243 112535 83114"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getApid','Taste::coordinates','"104992 81913"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','TimeReportAPID','NIL','PI_getSequenceCount','Taste::coordinates','"104992 80944"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','TimeReportAPID','Taste::coordinates','"99378 80069 104992 82688"','').
isSubcomponent('interfaceview::IV','interfaceview','others','TimeReportAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::TimeReports::TimeReportAPID.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TimeReportAPID','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::TimeReports','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::TimeReports','NIL','NIL','NIL','Taste::coordinates','"98066 78581 114830 85415"','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::TimeReports','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST05_RI_getNextEvent','Events.PI_getNextEvent','->','ST05.RI_getNextEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST05_RI_getNextEvent','Taste::coordinates','"154026 45834 155839 45834 155839 52458 163707 52458 163707 51531"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST19_RI_getNextEvent','Events.PI_getNextEvent','->','ST19.RI_getNextEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events_PI_getNextEvent_ST19_RI_getNextEvent','Taste::coordinates','"156170 52046 163707 52046 163707 51531"','').
isComponentType('interfaceview::FV::Events','PUBLIC','PI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Events','PUBLIC','PI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','Events','PI_getNextEvent','PROVIDES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_getNextEvent','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_getNextEvent','Taste::coordinates','"163707 51531"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::coordinates','"166214 50431"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','PI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isFeature('PARAMETER','interfaceview::FV::Events','PI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::Events','PI_pushNewEvent','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','Events','others','pushNewEvent_impl','SUBPROGRAM','interfaceview::FV::Events::PI_pushNewEvent.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','Events','others','OpToPICnx_pushNewEvent_impl','pushNewEvent_impl','->','PI_pushNewEvent','NIL','').
isPackage('interfaceview::FV::Events','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','Events','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','Events','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','Events','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Events','Taste::coordinates','"158930 45629 166214 51531"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','PI_EventReportTrigger','Taste::coordinates','"150489 42262"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::coordinates','"154026 46677"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::InterfaceName','"newTmNoInherit"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_newTmNoInherit','Taste::labelInheritance','"false"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_newTmNoInherit','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_newTmNoInherit','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_getNextEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getNextEvent','Taste::coordinates','"154026 45834"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::coordinates','"154026 45404"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST05','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST05','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST05','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST05','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST05','NIL','RI_getSequenceCount','Taste::coordinates','"154026 43873"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST05','Taste::coordinates','"148088 42262 154026 47234"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST05','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST05.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::ST05','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST05','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST19','PUBLIC','PI_tc19','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','PI_tc19','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','PI_tc19','PROVIDES','SUBPROGRAM','interfaceview::FV::ST19::PI_tc19.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','PI_tc19','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_tc19','Taste::coordinates','"152318 50499"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','PI_EventActionTrigger','Taste::coordinates','"149103 51335"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_getNextEvent','Taste::coordinates','"156170 52046"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_ACK','Taste::coordinates','"156170 54213"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::coordinates','"151175 54805"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST19','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST19','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST19','PUBLIC','RI_newTc','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST19','PUBLIC','RI_newTc','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::TcQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','RI_newTc','REQUIRES','SUBPROGRAM','interfaceview::FV::TcQueue::PI_newTc.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','ST19','NIL','RI_newTc','Taste::coordinates','"149103 53562"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST19','Taste::coordinates','"149103 50499 156170 54805"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST19','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST19.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','interfaceview::FV::ST19','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST19','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_HousekeepingServices_RI_pushNewEvent','Events.PI_pushNewEvent','->','ST12.RI_pushNewEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','EventServices_PI_pushNewEvent_HousekeepingServices_RI_pushNewEvent','Taste::coordinates','"167676 71004 171284 71004 171284 51738 169766 51738"','').
isPackage('interfaceview::IV::OnBoard::PusServices::EventServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::EventServices','NIL','NIL','NIL','Taste::coordinates','"143563 40886 169766 58710"','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::EventServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::Housekeeping','PUBLIC','PI_setParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Housekeeping','PUBLIC','PI_setParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','PI_setParamValue','PROVIDES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_setParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_setParamValue','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_setParamValue','Taste::coordinates','"163118 70150"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST03_RI_getParamValue','Taste::coordinates','"156133 66052 157731 66052 157731 68206 159329 68206"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST12_RI_getParamValue','Housekeeping.PI_getParamValue','->','ST12.RI_getParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping_PI_getParamValue_ST12_RI_getParamValue','Taste::coordinates','"155951 69886 157640 69886 157640 68206 159329 68206"','').
isComponentType('interfaceview::FV::Housekeeping','PUBLIC','PI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::Housekeeping','PUBLIC','PI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','PI_getParamValue','PROVIDES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::Housekeeping','PI_getParamValue','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','Housekeeping','NIL','PI_getParamValue','Taste::coordinates','"159329 68206"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','Housekeeping','Taste::coordinates','"159329 67126 166411 70150"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','PI_HkReportTrigger','Taste::coordinates','"149729 64322"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::coordinates','"151100 67006"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_getParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getParamValue','Taste::coordinates','"156133 66052"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::coordinates','"156133 65128"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST03','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST03','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST03','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST03','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST03','NIL','RI_getSequenceCount','Taste::coordinates','"156133 64359"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST03','Taste::coordinates','"149729 63651 156133 67006"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST03','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST03.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::ST03','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST03','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST12','PUBLIC','PI_PmonTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','PI_PmonTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','PI_PmonTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST12::PI_PmonTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','PI_PmonTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_PmonTrigger','Taste::coordinates','"149881 71096"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','PI_tc12','Taste::coordinates','"149881 69300"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::coordinates','"155951 71001"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_pushNewEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST12','RI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST12','RI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST12','PUBLIC','RI_getParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST12','PUBLIC','RI_getParamValue','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','RI_getParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_getParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_getParamValue','Taste::coordinates','"155951 69886"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','ST12','NIL','RI_ACK','Taste::coordinates','"151232 72037"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST12','Taste::coordinates','"149881 68638 155951 72037"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST12','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST12.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','interfaceview::FV::ST12','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST12','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::HousekeepingServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','NIL','NIL','NIL','Taste::coordinates','"145277 60082 167676 74455"','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::HousekeepingServices','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST11','PUBLIC','PI_tc11','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','PI_tc11','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','PI_tc11','PROVIDES','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::coordinates','"149255 84551"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_tc11','Taste::InterfaceName','"tc11"','').
isFeature('PARAMETER','interfaceview::FV::ST11','PI_tc11','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_tc11','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST11','others','tc11_impl','SUBPROGRAM','interfaceview::FV::ST11::PI_tc11.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST11','others','OpToPICnx_tc11_impl','tc11_impl','->','PI_tc11','NIL','').
isComponentType('interfaceview::FV::ST11','PUBLIC','PI_schedulingTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','PI_schedulingTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','PI_schedulingTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::ST11::PI_schedulingTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_schedulingTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_schedulingTrigger','Taste::coordinates','"160319 86757"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_schedulingTrigger','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_schedulingTrigger','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_schedulingTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','PI_schedulingTrigger','Taste::InterfaceName','"schedulingTrigger"','').
isProperty('NIL','=>','interfaceview::FV::ST11','PI_schedulingTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST11','others','schedulingTrigger_impl','SUBPROGRAM','interfaceview::FV::ST11::PI_schedulingTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST11','others','OpToPICnx_schedulingTrigger_impl','schedulingTrigger_impl','->','PI_schedulingTrigger','NIL','').
isComponentType('interfaceview::FV::ST11','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST11','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices','ST11','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_ACK','Taste::coordinates','"160319 89782"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','ST11','NIL','RI_newTc','Taste::coordinates','"149255 89956"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST11','Taste::coordinates','"149255 83512 160319 90921"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST11','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST11.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices','PUBLIC','interfaceview::FV::ST11','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST11','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST18','PUBLIC','PI_tc18','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST18','PUBLIC','PI_tc18','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','PI_tc18','PROVIDES','SUBPROGRAM','interfaceview::FV::ST18::PI_tc18.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST18','PI_tc18','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','PI_tc18','Taste::coordinates','"148661 107301"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','RI_ACK','Taste::coordinates','"155171 108726"','').
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
isPackage('interfaceview::FV::ST18','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ST18','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','ST18','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','ST18','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST18','Taste::coordinates','"148661 106717 155171 111059"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST18','SYSTEM','interfaceview::IV::OnBoard::PusServices::OBCP::ST18.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','interfaceview::FV::ST18','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::OBCP','').
isImportDeclaration('interfaceview::FV::ST18','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::OBCP','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::OBCP','NIL','NIL','NIL','Taste::coordinates','"142230 104813 163653 112669"','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OBCP','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST23','PUBLIC','PI_tc23','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','PI_tc23','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','PI_tc23','PROVIDES','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','PI_tc23','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::coordinates','"144907 131027"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','PI_tc23','Taste::InterfaceName','"tc23"','').
isFeature('PARAMETER','interfaceview::FV::ST23','PI_tc23','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','PI_tc23','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST23','PI_tc23','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST23','others','tc23_impl','SUBPROGRAM','interfaceview::FV::ST23::PI_tc23.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST23','others','OpToPICnx_tc23_impl','tc23_impl','->','PI_tc23','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_copy_ST23_RI_copy','FileManagement.PI_copy','->','ST23.RI_copy','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_copy_ST23_RI_copy','Taste::coordinates','"150258 131156 152443 131156 152443 131112 153404 131112"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_copy','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_copy','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::FileManagement','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_copy','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_copy.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::coordinates','"150258 131156"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::InterfaceName','"copy"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_copy','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_copy','sourceRepository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_copy','NIL','sourceRepository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_copy','sourceFile','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_copy','NIL','sourceFile','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_copy','targetRepository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_copy','NIL','targetRepository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_copy','targetFile','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_copy','NIL','targetFile','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_copy','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_copy','NIL','confirmation','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_delete_ST23_RI_delete','FileManagement.PI_delete','->','ST23.RI_delete','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_delete_ST23_RI_delete','Taste::coordinates','"150258 130393 152443 130393 152443 130333 153404 130333"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_delete','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_delete','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_delete','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::coordinates','"150258 130393"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::InterfaceName','"delete"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_delete','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_delete','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_delete','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_delete','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_delete','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_delete','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_delete','NIL','confirmation','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_create_ST23_RI_create','FileManagement.PI_create','->','ST23.RI_create','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_create_ST23_RI_create','Taste::coordinates','"150258 129619 152443 129619 152443 129526 153404 129526"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_create','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_create','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_create','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::coordinates','"150258 129619"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::InterfaceName','"create"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_create','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_create','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_create','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_create','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_create','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_create','maxSize','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_create','NIL','maxSize','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_create','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_create','NIL','confirmation','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','FileManagement_PI_getAttributes_ST23_RI_getAttributes','FileManagement.PI_getAttributes','->','ST23.RI_getAttributes','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement_PI_getAttributes_ST23_RI_getAttributes','Taste::coordinates','"150258 131861 152443 131861 152443 131823 153404 131823"','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getAttributes','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getAttributes','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getAttributes','REQUIRES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::coordinates','"150258 131861"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::InterfaceName','"getAttributes"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getAttributes','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getAttributes','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getAttributes','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getAttributes','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getAttributes','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getAttributes','maxSize','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getAttributes','NIL','maxSize','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getAttributes','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getAttributes','NIL','confirmation','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::coordinates','"144907 132069"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::coordinates','"146018 133000"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::coordinates','"148146 133000"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST23','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST23','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST23','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST23','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','ST23','NIL','RI_ACK','Taste::coordinates','"148745 128742"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST23','Taste::coordinates','"144907 128742 150258 133000"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::coordinates','"153404 131112"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_copy','Taste::InterfaceName','"copy"','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_copy','sourceRepository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','sourceRepository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_copy','sourceFile','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','sourceFile','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_copy','targetRepository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','targetRepository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_copy','targetFile','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','targetFile','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_copy','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','NIL','confirmation','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_copy','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','copy_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_copy.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_copy_impl','copy_impl','->','PI_copy','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_delete','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_delete','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_delete','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::coordinates','"153404 130333"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_delete','Taste::InterfaceName','"delete"','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_delete','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_delete','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_delete','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','NIL','confirmation','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_delete','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','delete_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_delete.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_delete_impl','delete_impl','->','PI_delete','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_create','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_create','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_create','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::coordinates','"153404 129526"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_create','Taste::InterfaceName','"create"','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_create','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_create','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_create','maxSize','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','maxSize','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_create','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','NIL','confirmation','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_create','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','create_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_create.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_create_impl','create_impl','->','PI_create','NIL','').
isComponentType('interfaceview::FV::FileManagement','PUBLIC','PI_getAttributes','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::FileManagement','PUBLIC','PI_getAttributes','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','PI_getAttributes','PROVIDES','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::coordinates','"153404 131823"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','PI_getAttributes','Taste::InterfaceName','"getAttributes"','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_getAttributes','repository','IN','NIL','DataView::PusSt23RepositoryPath','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','repository','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_getAttributes','file','IN','NIL','DataView::PusSt23FileName','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','file','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_getAttributes','maxSize','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','maxSize','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::FileManagement','PI_getAttributes','confirmation','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','NIL','confirmation','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::FileManagement','PI_getAttributes','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','FileManagement','others','getAttributes_impl','SUBPROGRAM','interfaceview::FV::FileManagement::PI_getAttributes.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','FileManagement','others','OpToPICnx_getAttributes_impl','getAttributes_impl','->','PI_getAttributes','NIL','').
isPackage('interfaceview::FV::FileManagement','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','FileManagement','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','FileManagement','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','FileManagement','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','FileManagement','Taste::coordinates','"153404 128897 161857 133085"','').
isSubcomponent('interfaceview::IV','interfaceview','others','FileManagement','SYSTEM','interfaceview::IV::OnBoard::PusServices::FilesService::FileManagement.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::FileManagement','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::FilesService','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::FilesService','NIL','NIL','NIL','Taste::coordinates','"141895 126761 163599 136280"','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::FilesService','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST20','PUBLIC','PI_tc20','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','PI_tc20','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','PI_tc20','PROVIDES','SUBPROGRAM','interfaceview::FV::ST20::PI_tc20.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','PI_tc20','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','PI_tc20','Taste::coordinates','"145063 118341"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams_PI_setOnBoardParam_ST20_RI_setOnBoardParam','Taste::coordinates','"152524 118574 154066 118574 154066 118522 155644 118522"','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::OnBoardParams','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_setOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::coordinates','"152524 118574"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::InterfaceName','"setOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_setOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_setOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_setOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_setOnBoardParam','paramValue','IN','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_setOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnBoardParams_PI_getOnBoardParam_ST20_RI_getOnBoardParam','OnBoardParams.PI_getOnBoardParam','->','ST20.RI_getOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams_PI_getOnBoardParam_ST20_RI_getOnBoardParam','Taste::coordinates','"152524 120144 154066 120144 154066 120131 155644 120131"','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_getOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_getOnBoardParam','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_getOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_getOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getOnBoardParam','Taste::coordinates','"152524 120144"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::coordinates','"145063 120193"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_ACK','Taste::coordinates','"151591 121058"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::coordinates','"146911 121058"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST20','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST20','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST20','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST20','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','ST20','NIL','RI_getSequenceCount','Taste::coordinates','"149352 121058"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST20','Taste::coordinates','"145063 117757 152524 121058"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_setOnBoardParam','Taste::coordinates','"155644 118522"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','OnBoardParams','NIL','PI_getOnBoardParam','Taste::coordinates','"155644 120131"','').
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
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnBoardParams','Taste::coordinates','"155644 117837 164363 120929"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnBoardParams','SYSTEM','interfaceview::IV::OnBoard::PusServices::ParameterManagement::OnBoardParams.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoardParams','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::ParameterManagement','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::ParameterManagement','NIL','NIL','NIL','Taste::coordinates','"141021 113528 166243 124629"','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ParameterManagement','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::ST201','PUBLIC','PI_tc201','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','PI_tc201','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','PI_tc201','PROVIDES','SUBPROGRAM','interfaceview::FV::ST201::PI_tc201.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_tc201','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_tc201','Taste::coordinates','"138338 167307"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_tc201','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_tc201','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_tc201','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_tc201','Taste::InterfaceName','"tc201"','').
isFeature('PARAMETER','interfaceview::FV::ST201','PI_tc201','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_tc201','NIL','tcPacket','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_tc201','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST201','others','tc201_impl','SUBPROGRAM','interfaceview::FV::ST201::PI_tc201.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST201','others','OpToPICnx_tc201_impl','tc201_impl','->','PI_tc201','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','ST201_PI_report_robot_control_manager_RI_report','ST201.PI_report','->','robot_control_manager.RI_report','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST201_PI_report_robot_control_manager_RI_report','Taste::coordinates','"151797 168871 149835 168871 149835 168625 147873 168625"','').
isComponentType('interfaceview::FV::ST201','PUBLIC','PI_report','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','PI_report','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','PI_report','PROVIDES','SUBPROGRAM','interfaceview::FV::ST201::PI_report.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_report','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_report','Taste::coordinates','"147873 168625"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_report','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_report','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_report','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','PI_report','Taste::InterfaceName','"report"','').
isFeature('PARAMETER','interfaceview::FV::ST201','PI_report','observation','IN','NIL','DataView::PusSt201PlanObservation','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_report','NIL','observation','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::ST201','PI_report','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','ST201','others','report_impl','SUBPROGRAM','interfaceview::FV::ST201::PI_report.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','ST201','others','OpToPICnx_report_impl','report_impl','->','PI_report','NIL','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_getSequenceCount','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_getSequenceCount','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::OnBoardAPID','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_getSequenceCount','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getSequenceCount.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getSequenceCount','Taste::coordinates','"147873 167327"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getSequenceCount','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getSequenceCount','Taste::InterfaceName','"getSequenceCount"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getSequenceCount','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_getSequenceCount','sequenceCount','OUT','NIL','DataView::PusSequenceCount','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_getSequenceCount','NIL','sequenceCount','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_getApid','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_getApid','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_getApid','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardAPID::PI_getApid.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getApid','Taste::coordinates','"146711 164203"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getApid','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getApid','Taste::InterfaceName','"getApid"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_getApid','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_getApid','apid','OUT','NIL','DataView::PusApid','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_getApid','NIL','apid','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_ACK','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_ACK','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::ST01','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_ACK','REQUIRES','SUBPROGRAM','interfaceview::FV::ST01::PI_ACK.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_ACK','Taste::coordinates','"144520 164203"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_ACK','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_ACK','Taste::InterfaceName','"ACK"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_ACK','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_ACK','tcPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_ACK','NIL','tcPacket','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_ACK','reportType','IN','NIL','DataView::PusSubserviceType','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_ACK','NIL','reportType','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_ACK','error','IN','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_ACK','NIL','error','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_ACK','errorInfo','IN','NIL','DataView::PusSt01FailureInfo','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_ACK','NIL','errorInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_ACK','step','IN','NIL','DataView::PusStepId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_ACK','NIL','step','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_newTm','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_newTm','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::TmQueue','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_newTm','REQUIRES','SUBPROGRAM','interfaceview::FV::TmQueue::PI_newTm.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_newTm','Taste::coordinates','"138338 170876"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_newTm','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_newTm','Taste::InterfaceName','"newTm"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_newTm','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_newTm','tmPacket','IN','NIL','DataView::PusPacket','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_newTm','NIL','tmPacket','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','robot_control_manager_PI_setHome_ST201_RI_setHome','robot_control_manager.PI_setHome','->','ST201.RI_setHome','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','robot_control_manager_PI_setHome_ST201_RI_setHome','Taste::coordinates','"147873 170398 149835 170398 149835 170275 151797 170275"','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_setHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_setHome','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::robot_control_manager','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_setHome','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_setHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_setHome','Taste::coordinates','"147873 170398"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_setHome','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_setHome','Taste::InterfaceName','"setHome"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_setHome','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_setHome','pusPose','IN','NIL','DataView::PusTC_201_1_3_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_setHome','NIL','pusPose','Taste::encoding','NATIVE','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','robot_control_manager_PI_planHomeRequest_ST201_RI_planHomeRequest','robot_control_manager.PI_planHomeRequest','->','ST201.RI_planHomeRequest','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','robot_control_manager_PI_planHomeRequest_ST201_RI_planHomeRequest','Taste::coordinates','"147873 171229 149835 171229 149835 171355 151797 171355"','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_planHomeRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_planHomeRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_planHomeRequest','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planHomeRequest','Taste::coordinates','"147873 171229"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planHomeRequest','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planHomeRequest','Taste::InterfaceName','"planHomeRequest"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planHomeRequest','Taste::labelInheritance','"true"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','robot_control_manager_PI_planMoveRequest_ST201_RI_planMoveRequest','robot_control_manager.PI_planMoveRequest','->','ST201.RI_planMoveRequest','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','robot_control_manager_PI_planMoveRequest_ST201_RI_planMoveRequest','Taste::coordinates','"147873 169517 149835 169517 149835 169651 151797 169651"','').
isComponentType('interfaceview::FV::ST201','PUBLIC','RI_planMoveRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::ST201','PUBLIC','RI_planMoveRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','RI_planMoveRequest','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planMoveRequest','Taste::coordinates','"147873 169517"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planMoveRequest','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planMoveRequest','Taste::InterfaceName','"planMoveRequest"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','RI_planMoveRequest','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::ST201','RI_planMoveRequest','pusPose','IN','NIL','DataView::PusTC_201_1_3_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::ST201','RI_planMoveRequest','NIL','pusPose','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::ST201','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','ST201','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','ST201','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','ST201','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','ST201','Taste::coordinates','"138338 164203 147873 173795"','').
isSubcomponent('interfaceview::IV','interfaceview','others','ST201','SYSTEM','interfaceview::IV::OnBoard::PusServices::RobotControl::ST201.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::ST201','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::ST201','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::ST201','PUBLIC','DataView','').
isImportDeclaration('interfaceview::IV','PUBLIC','interfaceview::IV::OnBoard::PusServices::RobotControl','').
isImportDeclaration('interfaceview::FV::ST201','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','TASTE_IV_Properties','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_setHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_setHome','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_setHome','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_setHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_setHome','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_setHome','Taste::coordinates','"151797 170275"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_setHome','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_setHome','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_setHome','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_setHome','Taste::InterfaceName','"setHome"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','PI_setHome','pusPose','IN','NIL','DataView::PusTC_201_1_3_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_setHome','NIL','pusPose','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_setHome','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','setHome_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_setHome.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_setHome_impl','setHome_impl','->','PI_setHome','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_planHomeRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_planHomeRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_planHomeRequest','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planHomeRequest','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeRequest','Taste::coordinates','"151797 171355"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeRequest','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeRequest','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeRequest','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeRequest','Taste::InterfaceName','"planHomeRequest"','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planHomeRequest','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','planHomeRequest_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeRequest.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_planHomeRequest_impl','planHomeRequest_impl','->','PI_planHomeRequest','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_planMoveRequest','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_planMoveRequest','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_planMoveRequest','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveRequest.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveRequest','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveRequest','Taste::coordinates','"151797 169651"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveRequest','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveRequest','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveRequest','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveRequest','Taste::InterfaceName','"planMoveRequest"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','PI_planMoveRequest','pusPose','IN','NIL','DataView::PusTC_201_1_3_Data','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveRequest','NIL','pusPose','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveRequest','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','planMoveRequest_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveRequest.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_planMoveRequest_impl','planMoveRequest_impl','->','PI_planMoveRequest','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_planHomeReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_planHomeReport','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_planHomeReport','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planHomeReport','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeReport','Taste::coordinates','"160068 171543"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeReport','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeReport','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeReport','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planHomeReport','Taste::InterfaceName','"planHomeReport"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','PI_planHomeReport','status','IN','NIL','DataView::PlanCmdStatus','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planHomeReport','NIL','status','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planHomeReport','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','planHomeReport_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeReport.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_planHomeReport_impl','planHomeReport_impl','->','PI_planHomeReport','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_planMoveReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_planMoveReport','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_planMoveReport','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveReport','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveReport','Taste::coordinates','"160068 170691"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveReport','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveReport','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveReport','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_planMoveReport','Taste::InterfaceName','"planMoveReport"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','PI_planMoveReport','status','IN','NIL','DataView::PlanCmdStatus','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveReport','NIL','status','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_planMoveReport','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','planMoveReport_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveReport.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_planMoveReport_impl','planMoveReport_impl','->','PI_planMoveReport','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_configHomeReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_configHomeReport','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_configHomeReport','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_configHomeReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_configHomeReport','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_configHomeReport','Taste::coordinates','"160068 172421"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_configHomeReport','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_configHomeReport','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_configHomeReport','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_configHomeReport','Taste::InterfaceName','"configHomeReport"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','PI_configHomeReport','status','IN','NIL','DataView::T_Boolean','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_configHomeReport','NIL','status','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_configHomeReport','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','configHomeReport_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_configHomeReport.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_configHomeReport_impl','configHomeReport_impl','->','PI_configHomeReport','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','PI_trigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','PI_trigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','PI_trigger','PROVIDES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_trigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_trigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_trigger','Taste::coordinates','"156711 167151"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_trigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_trigger','Taste::RCMperiod','50 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_trigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','PI_trigger','Taste::InterfaceName','"trigger"','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','PI_trigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','robot_control_manager','others','trigger_impl','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_trigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','robot_control_manager','others','OpToPICnx_trigger_impl','trigger_impl','->','PI_trigger','NIL','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','RI_report','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','RI_report','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','RI_report','REQUIRES','SUBPROGRAM','interfaceview::FV::ST201::PI_report.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_report','Taste::coordinates','"151797 168871"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_report','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_report','Taste::InterfaceName','"report"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_report','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','RI_report','observation','IN','NIL','DataView::PusSt201PlanObservation','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','RI_report','NIL','observation','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','RI_planMove','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','RI_planMove','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','interfaceview::FV::OnboardSoftware','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','RI_planMove','REQUIRES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planMove.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planMove','Taste::coordinates','"160068 168798"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planMove','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planMove','Taste::InterfaceName','"planMove"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planMove','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','RI_planMove','pose','IN','NIL','DataView::Base_Pose','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','RI_planMove','NIL','pose','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','RI_planHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','RI_planHome','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','RI_planHome','REQUIRES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planHome','Taste::coordinates','"160068 168086"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planHome','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planHome','Taste::InterfaceName','"planHome"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_planHome','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','RI_planHome','trigger','IN','NIL','DataView::T_Boolean','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','RI_planHome','NIL','trigger','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','RI_configHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','RI_configHome','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','RI_configHome','REQUIRES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_configHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_configHome','Taste::coordinates','"159357 167151"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_configHome','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_configHome','Taste::InterfaceName','"configHome"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_configHome','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','RI_configHome','target_home','IN','NIL','DataView::Base_Pose','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','RI_configHome','NIL','target_home','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::robot_control_manager','PUBLIC','RI_setRobotReportOBSW','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::robot_control_manager','PUBLIC','RI_setRobotReportOBSW','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','RI_setRobotReportOBSW','REQUIRES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_setRoboReportOBSW.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_setRobotReportOBSW','Taste::coordinates','"160068 169806"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_setRobotReportOBSW','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_setRobotReportOBSW','Taste::InterfaceName','"setRobotReportOBSW"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','RI_setRobotReportOBSW','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::robot_control_manager','RI_setRobotReportOBSW','status','IN','NIL','DataView::PusSt201PlanObservation','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::robot_control_manager','RI_setRobotReportOBSW','NIL','status','Taste::encoding','NATIVE','').
isPackage('interfaceview::FV::robot_control_manager','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','robot_control_manager','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','robot_control_manager','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','robot_control_manager','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','robot_control_manager','Taste::coordinates','"151797 167151 160068 173125"','').
isSubcomponent('interfaceview::IV','interfaceview','others','robot_control_manager','SYSTEM','interfaceview::IV::OnBoard::PusServices::RobotControl::robot_control_manager.others','NIL','NIL','').
isImportDeclaration('interfaceview::FV::robot_control_manager','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::robot_control_manager','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::robot_control_manager','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard::PusServices::RobotControl','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices::RobotControl','NIL','NIL','NIL','Taste::coordinates','"135804 161798 163327 175830"','').
isImportDeclaration('interfaceview::FV::RobotControl','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::RobotControl','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::RobotControl','PUBLIC','TASTE_IV_Properties','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_setParamValue_OnboardSoftware_RI_setParamValue','Housekeeping.PI_setParamValue','->','OnboardSoftware.RI_setParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_setParamValue_OnboardSoftware_RI_setParamValue','Taste::coordinates','"219639 67168 211918 67168 211918 69681 203150 69681"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_getParamValue_OnboardSoftware_RI_getParamValue','Housekeeping.PI_getParamValue','->','OnboardSoftware.RI_getParamValue','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_getParamValue_OnboardSoftware_RI_getParamValue','Taste::coordinates','"219639 71777 214676 71777 214676 72647 203150 72647"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_pushNewEvent_OnboardSoftware_RI_pushNewEvent','Events.PI_pushNewEvent','->','OnboardSoftware.RI_pushNewEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_pushNewEvent_OnboardSoftware_RI_pushNewEvent','Taste::coordinates','"219639 51932 211887 51932 211887 51769 203150 51769"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_setOnBoardParam_OnboardSoftware_RI_setOnBoardParam','OnBoardParams.PI_setOnBoardParam','->','OnboardSoftware.RI_setOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_setOnBoardParam_OnboardSoftware_RI_setOnBoardParam','Taste::coordinates','"219639 105950 209927 105950 209927 106637 203150 106637"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_getOnBoardParam_OnboardSoftware_RI_getOnBoardParam','OnBoardParams.PI_getOnBoardParam','->','OnboardSoftware.RI_getOnBoardParam','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_getOnBoardParam_OnboardSoftware_RI_getOnBoardParam','Taste::coordinates','"219639 117065 212991 117065 212991 113194 203150 113194"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_getNextEvent_OnboardSoftware_RI_getNextEvent','Events.PI_getNextEvent','->','OnboardSoftware.RI_getNextEvent','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_getNextEvent_OnboardSoftware_RI_getNextEvent','Taste::coordinates','"219639 54542 208687 54542 208687 55970 203150 55970"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_tcTrigger_OnboardSoftware_RI_tcTrigger','TcDispatch.PI_tcTrigger','->','OnboardSoftware.RI_tcTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_tcTrigger_OnboardSoftware_RI_tcTrigger','Taste::coordinates','"219639 80951 60783 80951 60783 63329 76928 63329"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_tmTrigger_OnboardSoftware_RI_tmTrigger','TmDispatch.PI_tmTrigger','->','OnboardSoftware.RI_tmTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_tmTrigger_OnboardSoftware_RI_tmTrigger','Taste::coordinates','"219639 85131 60783 85131 60783 105491 76928 105491"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_EventReportTrigger_OnboardSoftware_RI_EventReportTrigger','ST05.PI_EventReportTrigger','->','OnboardSoftware.RI_EventReportTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_EventReportTrigger_OnboardSoftware_RI_EventReportTrigger','Taste::coordinates','"219639 85967 203494 85967 203494 22585 117094 22585 117094 33193"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_EventActionTrigger_OnboardSoftware_RI_EventActionTrigger','ST19.PI_EventActionTrigger','->','OnboardSoftware.RI_EventActionTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_EventActionTrigger_OnboardSoftware_RI_EventActionTrigger','Taste::coordinates','"219639 87639 203494 87639 203494 22585 128551 22585 128551 33193"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_HkReportTrigger_OnboardSoftware_RI_HkReportTrigger','ST03.PI_HkReportTrigger','->','OnboardSoftware.RI_HkReportTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_HkReportTrigger_OnboardSoftware_RI_HkReportTrigger','Taste::coordinates','"219639 89311 203494 89311 203494 22585 139707 22585 139707 33193"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_PmonTrigger_OnboardSoftware_RI_PmonTrigger','ST12.PI_PmonTrigger','->','OnboardSoftware.RI_PmonTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_PmonTrigger_OnboardSoftware_RI_PmonTrigger','Taste::coordinates','"219639 90147 203494 90147 203494 22585 151917 22585 151917 33193"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_planMoveReport_OnboardSoftware_RI_planMoveReport','robot_control_manager.PI_planMoveReport','->','OnboardSoftware.RI_planMoveReport','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_planMoveReport_OnboardSoftware_RI_planMoveReport','Taste::coordinates','"219639 170986 211394 170986 211394 171142 203150 171142"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_planHomeReport_OnboardSoftware_RI_planHomeReport','robot_control_manager.PI_planHomeReport','->','OnboardSoftware.RI_planHomeReport','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_planHomeReport_OnboardSoftware_RI_planHomeReport','Taste::coordinates','"219639 173365 211394 173365 211394 172413 203150 172413"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_configHomeReport_OnboardSoftware_RI_configHomeReport','robot_control_manager.PI_configHomeReport','->','OnboardSoftware.RI_configHomeReport','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_configHomeReport_OnboardSoftware_RI_configHomeReport','Taste::coordinates','"219639 174552 211394 174552 211394 174363 203150 174363"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','PusServices_PI_schedulingTrigger_OnboardSoftware_RI_schedulingTrigger','ST11.PI_schedulingTrigger','->','OnboardSoftware.RI_schedulingTrigger','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','PusServices_PI_schedulingTrigger_OnboardSoftware_RI_schedulingTrigger','Taste::coordinates','"219639 94477 203494 94477 203494 23103 160180 23103 160180 33193"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_planHome_PusServices_RI_planHome','OnboardSoftware.PI_planHome','->','robot_control_manager.RI_planHome','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_planHome_PusServices_RI_planHome','Taste::coordinates','"203150 165295 209294 165295 209294 165111 219639 165111"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_planMove_PusServices_RI_planMove','OnboardSoftware.PI_planMove','->','robot_control_manager.RI_planMove','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_planMove_PusServices_RI_planMove','Taste::coordinates','"203150 167040 211394 167040 211394 167088 219639 167088"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_configHome_PusServices_RI_configHome','OnboardSoftware.PI_configHome','->','robot_control_manager.RI_configHome','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_configHome_PusServices_RI_configHome','Taste::coordinates','"203150 163882 211394 163882 211394 163658 219639 163658"','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_setRoboReportOBSW_PusServices_RI_setRobotReportOBSW','OnboardSoftware.PI_setRoboReportOBSW','->','robot_control_manager.RI_setRobotReportOBSW','NIL','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware_PI_setRoboReportOBSW_PusServices_RI_setRobotReportOBSW','Taste::coordinates','"203150 169512 211394 169512 211394 168652 219639 168652"','').
isPackage('interfaceview::IV::OnBoard::PusServices','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard::PusServices','NIL','NIL','NIL','Taste::coordinates','"76928 33193 203150 177791"','').
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
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_pusTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_pusTrigger','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_pusTrigger','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_pusTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_pusTrigger','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_pusTrigger','Taste::coordinates','"238379 90271"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_pusTrigger','Taste::RCMoperationKind','cyclic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_pusTrigger','Taste::RCMperiod','500 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_pusTrigger','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_pusTrigger','Taste::InterfaceName','"pusTrigger"','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_pusTrigger','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','pusTrigger_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_pusTrigger.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_pusTrigger_impl','pusTrigger_impl','->','PI_pusTrigger','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_planHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_planHome','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_planHome','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planHome','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planHome','Taste::coordinates','"219639 165111"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planHome','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planHome','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planHome','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planHome','Taste::InterfaceName','"planHome"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','PI_planHome','trigger','IN','NIL','DataView::T_Boolean','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planHome','NIL','trigger','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planHome','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','planHome_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planHome.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_planHome_impl','planHome_impl','->','PI_planHome','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_planMove','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_planMove','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_planMove','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planMove.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planMove','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planMove','Taste::coordinates','"219639 167088"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planMove','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planMove','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planMove','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_planMove','Taste::InterfaceName','"planMove"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','PI_planMove','pose','IN','NIL','DataView::Base_Pose','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planMove','NIL','pose','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_planMove','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','planMove_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_planMove.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_planMove_impl','planMove_impl','->','PI_planMove','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_configHome','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_configHome','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_configHome','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_configHome.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_configHome','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_configHome','Taste::coordinates','"219639 163658"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_configHome','Taste::RCMoperationKind','sporadic','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_configHome','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_configHome','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_configHome','Taste::InterfaceName','"configHome"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','PI_configHome','target_home','IN','NIL','DataView::Base_Pose','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_configHome','NIL','target_home','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_configHome','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','configHome_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_configHome.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_configHome_impl','configHome_impl','->','PI_configHome','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','PI_setRoboReportOBSW','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','PI_setRoboReportOBSW','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','PI_setRoboReportOBSW','PROVIDES','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_setRoboReportOBSW.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_setRoboReportOBSW','NIL','NIL','Taste::Associated_Queue_Size','1','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_setRoboReportOBSW','Taste::coordinates','"219639 168652"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_setRoboReportOBSW','Taste::RCMoperationKind','protected','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_setRoboReportOBSW','Taste::RCMperiod','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_setRoboReportOBSW','Taste::Deadline','0 ms','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','PI_setRoboReportOBSW','Taste::InterfaceName','"setRoboReportOBSW"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','PI_setRoboReportOBSW','status','IN','NIL','DataView::PusSt201PlanObservation','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_setRoboReportOBSW','NIL','status','Taste::encoding','NATIVE','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','PI_setRoboReportOBSW','others','NIL','Compute_Execution_Time','0 ms .. 0 ms','').
isSubcomponent('interfaceview::IV','OnboardSoftware','others','setRoboReportOBSW_impl','SUBPROGRAM','interfaceview::FV::OnboardSoftware::PI_setRoboReportOBSW.others','NIL','NIL','').
isConnection('SUBPROGRAM ACCESS','interfaceview::IV','OnboardSoftware','others','OpToPICnx_setRoboReportOBSW_impl','setRoboReportOBSW_impl','->','PI_setRoboReportOBSW','NIL','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setParamValue','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setParamValue','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::Housekeeping','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_setParamValue','REQUIRES','SUBPROGRAM','interfaceview::FV::Housekeeping::PI_setParamValue.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setParamValue','Taste::coordinates','"219639 67168"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getParamValue','Taste::coordinates','"219639 71777"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::coordinates','"219639 51932"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::InterfaceName','"pushNewEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_pushNewEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_pushNewEvent','eventInfo','IN','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_pushNewEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setOnBoardParam','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_setOnBoardParam','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::OnBoardParams','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_setOnBoardParam','REQUIRES','SUBPROGRAM','interfaceview::FV::OnBoardParams::PI_setOnBoardParam.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_setOnBoardParam','Taste::coordinates','"219639 105950"','').
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
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::coordinates','"219639 117065"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::InterfaceName','"getOnBoardParam"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getOnBoardParam','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','paramId','IN','NIL','DataView::PusSt20OnBoardParameterId','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','paramId','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','paramValue','OUT','NIL','DataView::PusSt20StoredParam','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','paramValue','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','isAvailable','OUT','NIL','DataView::PusSt01FailureCode','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getOnBoardParam','NIL','isAvailable','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getNextEvent','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_getNextEvent','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_getNextEvent','REQUIRES','SUBPROGRAM','interfaceview::FV::Events::PI_getNextEvent.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getNextEvent','Taste::coordinates','"219639 54542"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getNextEvent','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getNextEvent','Taste::InterfaceName','"getNextEvent"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_getNextEvent','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getNextEvent','eventInfo','OUT','NIL','DataView::PusSt05Event','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getNextEvent','NIL','eventInfo','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getNextEvent','nextCounter','OUT','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getNextEvent','NIL','nextCounter','Taste::encoding','NATIVE','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_getNextEvent','actualCounter','IN','NIL','DataView::PusUInt64','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_getNextEvent','NIL','actualCounter','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_tcTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_tcTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::TcDispatch','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_tcTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::TcDispatch::PI_tcTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tcTrigger','Taste::coordinates','"219639 80951"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tcTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tcTrigger','Taste::InterfaceName','"tcTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tcTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_tmTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_tmTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::TmDispatch','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_tmTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::TmDispatch::PI_tmTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tmTrigger','Taste::coordinates','"219639 85131"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tmTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tmTrigger','Taste::InterfaceName','"tmTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_tmTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_EventReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_EventReportTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::ST05','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_EventReportTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST05::PI_EventReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventReportTrigger','Taste::coordinates','"219639 85967"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventReportTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventReportTrigger','Taste::InterfaceName','"EventReportTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventReportTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_EventActionTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_EventActionTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::ST19','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_EventActionTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST19::PI_EventActionTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventActionTrigger','Taste::coordinates','"219639 87639"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventActionTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventActionTrigger','Taste::InterfaceName','"EventActionTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_EventActionTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_HkReportTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_HkReportTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::ST03','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_HkReportTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST03::PI_HkReportTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_HkReportTrigger','Taste::coordinates','"219639 89311"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_HkReportTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_HkReportTrigger','Taste::InterfaceName','"HkReportTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_HkReportTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_PmonTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_PmonTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::ST12','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_PmonTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST12::PI_PmonTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_PmonTrigger','Taste::coordinates','"219639 90147"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_PmonTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_PmonTrigger','Taste::InterfaceName','"PmonTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_PmonTrigger','Taste::labelInheritance','"true"','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_planHomeReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_planHomeReport','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::robot_control_manager','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_planHomeReport','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planHomeReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planHomeReport','Taste::coordinates','"219639 173365"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planHomeReport','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planHomeReport','Taste::InterfaceName','"planHomeReport"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planHomeReport','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_planHomeReport','status','IN','NIL','DataView::PlanCmdStatus','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_planHomeReport','NIL','status','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_planMoveReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_planMoveReport','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_planMoveReport','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_planMoveReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planMoveReport','Taste::coordinates','"219639 170986"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planMoveReport','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planMoveReport','Taste::InterfaceName','"planMoveReport"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_planMoveReport','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_planMoveReport','status','IN','NIL','DataView::PlanCmdStatus','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_planMoveReport','NIL','status','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_configHomeReport','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_configHomeReport','others','SUBPROGRAM','NIL','others','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_configHomeReport','REQUIRES','SUBPROGRAM','interfaceview::FV::robot_control_manager::PI_configHomeReport.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_configHomeReport','Taste::coordinates','"219639 174552"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_configHomeReport','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_configHomeReport','Taste::InterfaceName','"configHomeReport"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_configHomeReport','Taste::labelInheritance','"true"','').
isFeature('PARAMETER','interfaceview::FV::OnboardSoftware','RI_configHomeReport','status','IN','NIL','DataView::T_Boolean','NIL','NIL','').
isProperty('NIL','=>','interfaceview::FV::OnboardSoftware','RI_configHomeReport','NIL','status','Taste::encoding','NATIVE','').
isComponentType('interfaceview::FV::OnboardSoftware','PUBLIC','RI_schedulingTrigger','SUBPROGRAM','NIL','').
isComponentImplementation('interfaceview::FV::OnboardSoftware','PUBLIC','RI_schedulingTrigger','others','SUBPROGRAM','NIL','others','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::ST11','').
isFeature('ACCESS','interfaceview::IV::OnBoard','OnboardSoftware','RI_schedulingTrigger','REQUIRES','SUBPROGRAM','interfaceview::FV::ST11::PI_schedulingTrigger.others','NIL','NIL','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_schedulingTrigger','Taste::coordinates','"219639 94477"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_schedulingTrigger','Taste::RCMoperationKind','any','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_schedulingTrigger','Taste::InterfaceName','"schedulingTrigger"','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','RI_schedulingTrigger','Taste::labelInheritance','"true"','').
isPackage('interfaceview::FV::OnboardSoftware','PUBLIC','').
isComponentType('interfaceview::IV::OnBoard','PUBLIC','OnboardSoftware','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV::OnBoard','PUBLIC','OnboardSoftware','others','SYSTEM','NIL','others','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','NIL','Source_Language','(C)','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','OnboardSoftware','NIL','NIL','Taste::Active_Interfaces','any','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','others','OnboardSoftware','Taste::coordinates','"219639 44167 238379 176782"','').
isSubcomponent('interfaceview::IV','interfaceview','others','OnboardSoftware','SYSTEM','interfaceview::IV::OnBoard::OnboardSoftware.others','NIL','NIL','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','interfaceview::FV::OnboardSoftware','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','Taste','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnboardSoftware','PUBLIC','TASTE_IV_Properties','').
isImportDeclaration('interfaceview::IV::OnBoard','PUBLIC','TASTE_IV_Properties','').
isPackage('interfaceview::IV::OnBoard','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV::OnBoard','NIL','NIL','NIL','Taste::coordinates','"66854 18968 241992 185822"','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','Taste','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','DataView','').
isImportDeclaration('interfaceview::FV::OnBoard','PUBLIC','TASTE_IV_Properties','').
isProperty('_','_','_','_','_','_','LMP::Unparser_ID_Case','AsIs','').
isProperty('_','_','_','_','_','_','LMP::Unparser_Insert_Header','Yes','').
isPackage('interfaceview::IV','PUBLIC','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::dataView','("DataView")','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::dataViewPath','("DataView.aadl")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','NIL','NIL','Taste::dataView','("DataView")','').
isProperty('NIL','=>','interfaceview::IV','interfaceview','NIL','NIL','Taste::dataViewPath','("DataView.aadl")','').
isVersion('AADL2.1','TASTE type interfaceview','','generated code: do not edit').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::coordinates','"0 0 297000 210000"','').
isProperty('NIL','=>','interfaceview::IV','NIL','NIL','NIL','Taste::version','"1.3"','').
isComponentType('interfaceview::IV','PUBLIC','interfaceview','SYSTEM','NIL','').
isComponentImplementation('interfaceview::IV','PUBLIC','interfaceview','others','SYSTEM','NIL','others','').

