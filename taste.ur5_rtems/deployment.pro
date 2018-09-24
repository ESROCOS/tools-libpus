isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV','').
isSubcomponent('deploymentview::DV','Node2','others','IV_Ground','SYSTEM','interfaceview::IV::Ground.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node2','others','IV_Ground','Taste::FunctionName','"Ground"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node2','others','IV_Ground','Taste::APLC_Binding','(reference (Partition1))','').
isComponentType('deploymentview::DV::Node2','PUBLIC','Partition1','PROCESS','NIL','').
isComponentImplementation('deploymentview::DV::Node2','PUBLIC','Partition1','others','PROCESS','NIL','others','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node2','others','Partition1','Actual_Processor_Binding','(reference (x86_linux))','').
isSubcomponent('deploymentview::DV','Node2','others','Partition1','PROCESS','deploymentview::DV::Node2::Partition1.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node2','others','Partition1','Taste::coordinates','"39936 75206 82180 125895"','').
isProperty('NIL','=>','deploymentview::DV','Node2','others','Partition1','Deployment::Port_Number','0','').
isImportDeclaration('deploymentview::DV','PUBLIC','ocarina_processors_x86','').
isProperty('NIL','=>','deploymentview::DV','x86','NIL','NIL','Scheduling_Protocol','Posix_1003_Highest_Priority_First_Protocol','').
isSubcomponent('deploymentview::DV','Node2','others','x86_linux','PROCESSOR','ocarina_processors_x86::x86.linux','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node2','others','x86_linux','Taste::coordinates','"34656 60723 87460 133136"','').
isConnection('BUS ACCESS','deploymentview::DV','deploymentview','others','Connection2','ip_i','->','Node2.generic_sockets_ip_pohic_ip_i','NIL','').
isProperty('NIL','=>','deploymentview::DV','deploymentview','others','Connection2','Taste::coordinates','"38596 153147 28557 153147 28557 187587 85409 187587"','').
isConnection('BUS ACCESS','deploymentview::DV','Node2','others','generic_sockets_ip_pohic_ip_i_link','generic_sockets_ip_pohic_ip_i','->','generic_sockets_ip_pohic.link','NIL','').
isFeature('ACCESS','deploymentview::DV','Node2','generic_sockets_ip_pohic_ip_i','REQUIRES','BUS','ocarina_buses::ip.i','NIL','NIL','').
isProperty('NIL','APPLIES TO','deploymentview::DV::Node2','generic_sockets_ip_pohic','NIL','link','Taste::Interface_Coordinates','"85409 187587"','').
isImportDeclaration('deploymentview::DV::Node2','PUBLIC','ocarina_buses','').
isFeature('ACCESS','deploymentview::DV::Node2','generic_sockets_ip_pohic','link','REQUIRES','BUS','ocarina_buses::ip.i','NIL','REFINED TO','').
isProperty('NIL','=>','deploymentview::DV::Node2','generic_sockets_ip_pohic','NIL','link','Taste::coordinates','"38596 153147"','').
isImportDeclaration('deploymentview::DV::Node2','PUBLIC','ocarina_drivers','').
isComponentType('deploymentview::DV::Node2','PUBLIC','generic_sockets_ip_pohic','DEVICE','ocarina_drivers::generic_sockets_ip','').
isComponentImplementation('deploymentview::DV::Node2','PUBLIC','generic_sockets_ip_pohic','others','DEVICE','ocarina_drivers::generic_sockets_ip','pohic','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node2','others','generic_sockets_ip_pohic','Actual_Processor_Binding','(reference (x86_linux))','').
isSubcomponent('deploymentview::DV','Node2','others','generic_sockets_ip_pohic','DEVICE','deploymentview::DV::Node2::generic_sockets_ip_pohic.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node2','others','generic_sockets_ip_pohic','Taste::coordinates','"38596 145749 79541 160545"','').
isProperty('NIL','=>','deploymentview::DV::Node2','generic_sockets_ip_pohic','NIL','NIL','Deployment::Help','"Write your ASN.1 configuration here"','').
isProperty('NIL','=>','deploymentview::DV::Node2','generic_sockets_ip_pohic','NIL','NIL','Deployment::Config','"/home/taste/tool-inst/include/ocarina/runtime/polyorb-hi-c/src/drivers/configuration/ip.asn"','').
isProperty('NIL','=>','deploymentview::DV::Node2','generic_sockets_ip_pohic','NIL','NIL','Deployment::Version','"0.1beta"','').
isComponentType('deploymentview::DV','PUBLIC','Node2','SYSTEM','NIL','').
isComponentImplementation('deploymentview::DV','PUBLIC','Node2','others','SYSTEM','NIL','others','').
isSubcomponent('deploymentview::DV','deploymentview','others','Node2','SYSTEM','Node2.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','deploymentview','others','Node2','Taste::coordinates','"27575 53714 93580 166283"','').
isPackage('deploymentview::DV::Node2','PUBLIC','').
isImportDeclaration('deploymentview::DV::Node2','PUBLIC','Taste','').
isImportDeclaration('deploymentview::DV::Node2','PUBLIC','Deployment','').
isImportDeclaration('deploymentview::DV::Node2','PUBLIC','TASTE_DV_Properties','').
isImportDeclaration('deploymentview::DV','PUBLIC','deploymentview::DV::Node2','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TC','').
isSubcomponent('deploymentview::DV','Node1','others','IV_TcQueue','SYSTEM','interfaceview::IV::OnBoard::PusServices::TC::TcQueue.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_TcQueue','Taste::FunctionName','"TcQueue"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_TcQueue','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_TcDispatch','SYSTEM','interfaceview::IV::OnBoard::PusServices::TC::TcDispatch.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_TcDispatch','Taste::FunctionName','"TcDispatch"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_TcDispatch','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TM','').
isSubcomponent('deploymentview::DV','Node1','others','IV_TmDispatch','SYSTEM','interfaceview::IV::OnBoard::PusServices::TM::TmDispatch.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_TmDispatch','Taste::FunctionName','"TmDispatch"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_TmDispatch','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_TmQueue','SYSTEM','interfaceview::IV::OnBoard::PusServices::TM::TmQueue.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_TmQueue','Taste::FunctionName','"TmQueue"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_TmQueue','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST17','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST17.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST17','Taste::FunctionName','"ST17"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST17','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST01','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST01.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST01','Taste::FunctionName','"ST01"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST01','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST08','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST08.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST08','Taste::FunctionName','"ST08"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST08','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_OnBoardAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::OnBoardAPID.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_OnBoardAPID','Taste::FunctionName','"OnBoardAPID"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_OnBoardAPID','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::TimeReports','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST09','SYSTEM','interfaceview::IV::OnBoard::PusServices::TimeReports::ST09.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST09','Taste::FunctionName','"ST09"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST09','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_TimeReportAPID','SYSTEM','interfaceview::IV::OnBoard::PusServices::TimeReports::TimeReportAPID.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_TimeReportAPID','Taste::FunctionName','"TimeReportAPID"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_TimeReportAPID','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::EventServices','').
isSubcomponent('deploymentview::DV','Node1','others','IV_Events','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::Events.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_Events','Taste::FunctionName','"Events"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_Events','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST05','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST05.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST05','Taste::FunctionName','"ST05"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST05','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST19','SYSTEM','interfaceview::IV::OnBoard::PusServices::EventServices::ST19.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST19','Taste::FunctionName','"ST19"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST19','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::HousekeepingServices','').
isSubcomponent('deploymentview::DV','Node1','others','IV_Housekeeping','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::Housekeeping.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_Housekeeping','Taste::FunctionName','"Housekeeping"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_Housekeeping','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST03','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST03.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST03','Taste::FunctionName','"ST03"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST03','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST12','SYSTEM','interfaceview::IV::OnBoard::PusServices::HousekeepingServices::ST12.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST12','Taste::FunctionName','"ST12"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST12','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST11','SYSTEM','interfaceview::IV::OnBoard::PusServices::ST11.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST11','Taste::FunctionName','"ST11"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST11','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::OBCP','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST18','SYSTEM','interfaceview::IV::OnBoard::PusServices::OBCP::ST18.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST18','Taste::FunctionName','"ST18"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST18','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::FilesService','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST23','SYSTEM','interfaceview::IV::OnBoard::PusServices::FilesService::ST23.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST23','Taste::FunctionName','"ST23"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST23','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_FileManagement','SYSTEM','interfaceview::IV::OnBoard::PusServices::FilesService::FileManagement.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_FileManagement','Taste::FunctionName','"FileManagement"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_FileManagement','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::ParameterManagement','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST20','SYSTEM','interfaceview::IV::OnBoard::PusServices::ParameterManagement::ST20.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST20','Taste::FunctionName','"ST20"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST20','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_OnBoardParams','SYSTEM','interfaceview::IV::OnBoard::PusServices::ParameterManagement::OnBoardParams.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_OnBoardParams','Taste::FunctionName','"OnBoardParams"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_OnBoardParams','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard::PusServices::RobotControl','').
isSubcomponent('deploymentview::DV','Node1','others','IV_ST201','SYSTEM','interfaceview::IV::OnBoard::PusServices::RobotControl::ST201.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_ST201','Taste::FunctionName','"ST201"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_ST201','Taste::APLC_Binding','(reference (gr740_partition))','').
isSubcomponent('deploymentview::DV','Node1','others','IV_robot_control_manager','SYSTEM','interfaceview::IV::OnBoard::PusServices::RobotControl::robot_control_manager.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_robot_control_manager','Taste::FunctionName','"robot_control_manager"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_robot_control_manager','Taste::APLC_Binding','(reference (gr740_partition))','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV::OnBoard','').
isSubcomponent('deploymentview::DV','Node1','others','IV_OnboardSoftware','SYSTEM','interfaceview::IV::OnBoard::OnboardSoftware.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','IV_OnboardSoftware','Taste::FunctionName','"OnboardSoftware"','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','IV_OnboardSoftware','Taste::APLC_Binding','(reference (gr740_partition))','').
isComponentType('deploymentview::DV::Node1','PUBLIC','gr740_partition','PROCESS','NIL','').
isComponentImplementation('deploymentview::DV::Node1','PUBLIC','gr740_partition','others','PROCESS','NIL','others','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','gr740_partition','Actual_Processor_Binding','(reference (gr740_rtems51_posix))','').
isSubcomponent('deploymentview::DV','Node1','others','gr740_partition','PROCESS','deploymentview::DV::Node1::gr740_partition.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','gr740_partition','Taste::coordinates','"156661 71823 215340 130392"','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','gr740_partition','Deployment::Port_Number','0','').
isImportDeclaration('deploymentview::DV','PUBLIC','ocarina_processors_leon','').
isProperty('NIL','=>','deploymentview::DV','gr740','NIL','NIL','Scheduling_Protocol','Posix_1003_Highest_Priority_First_Protocol','').
isSubcomponent('deploymentview::DV','Node1','others','gr740_rtems51_posix','PROCESSOR','ocarina_processors_leon::gr740.rtems51_posix','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','gr740_rtems51_posix','Taste::coordinates','"149326 55089 222675 138759"','').
isConnection('BUS ACCESS','deploymentview::DV','deploymentview','others','Connection1','ip_i','->','Node1.leon_ethernet_greth_ip_i','NIL','').
isProperty('NIL','=>','deploymentview::DV','deploymentview','others','Connection1','Taste::coordinates','"156074 152828 145806 152828 145806 183760 138982 183760"','').
isConnection('BUS ACCESS','deploymentview::DV','Node1','others','leon_ethernet_greth_ip_i_link','leon_ethernet_greth_ip_i','->','leon_ethernet_greth.link','NIL','').
isFeature('ACCESS','deploymentview::DV','Node1','leon_ethernet_greth_ip_i','REQUIRES','BUS','ocarina_buses::ip.i','NIL','NIL','').
isProperty('NIL','APPLIES TO','deploymentview::DV::Node1','leon_ethernet_greth','NIL','link','Taste::Interface_Coordinates','"138982 183760"','').
isImportDeclaration('deploymentview::DV::Node1','PUBLIC','ocarina_buses','').
isFeature('ACCESS','deploymentview::DV::Node1','leon_ethernet_greth','link','REQUIRES','BUS','ocarina_buses::ip.i','NIL','REFINED TO','').
isProperty('NIL','=>','deploymentview::DV::Node1','leon_ethernet_greth','NIL','link','Taste::coordinates','"156074 152828"','').
isImportDeclaration('deploymentview::DV::Node1','PUBLIC','ocarina_drivers','').
isComponentType('deploymentview::DV::Node1','PUBLIC','leon_ethernet_greth','DEVICE','ocarina_drivers::leon_ethernet','').
isComponentImplementation('deploymentview::DV::Node1','PUBLIC','leon_ethernet_greth','others','DEVICE','ocarina_drivers::leon_ethernet','greth','').
isProperty('NIL','APPLIES TO','deploymentview::DV','Node1','others','leon_ethernet_greth','Actual_Processor_Binding','(reference (gr740_rtems51_posix))','').
isSubcomponent('deploymentview::DV','Node1','others','leon_ethernet_greth','DEVICE','deploymentview::DV::Node1::leon_ethernet_greth.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','Node1','others','leon_ethernet_greth','Taste::coordinates','"156074 145876 199316 159780"','').
isProperty('NIL','=>','deploymentview::DV::Node1','leon_ethernet_greth','NIL','NIL','Deployment::Help','"Write your ASN.1 configuration here"','').
isProperty('NIL','=>','deploymentview::DV::Node1','leon_ethernet_greth','NIL','NIL','Deployment::Config','"/home/taste/tool-inst/include/ocarina/runtime/polyorb-hi-c/src/drivers/configuration/ip.asn"','').
isProperty('NIL','=>','deploymentview::DV::Node1','leon_ethernet_greth','NIL','NIL','Deployment::Version','"0.1beta"','').
isComponentType('deploymentview::DV','PUBLIC','Node1','SYSTEM','NIL','').
isComponentImplementation('deploymentview::DV','PUBLIC','Node1','others','SYSTEM','NIL','others','').
isSubcomponent('deploymentview::DV','deploymentview','others','Node1','SYSTEM','Node1.others','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','deploymentview','others','Node1','Taste::coordinates','"139917 47504 231604 167033"','').
isPackage('deploymentview::DV::Node1','PUBLIC','').
isImportDeclaration('deploymentview::DV::Node1','PUBLIC','Taste','').
isImportDeclaration('deploymentview::DV::Node1','PUBLIC','Deployment','').
isImportDeclaration('deploymentview::DV::Node1','PUBLIC','TASTE_DV_Properties','').
isImportDeclaration('deploymentview::DV','PUBLIC','deploymentview::DV::Node1','').
isProperty('NIL','APPLIES TO','deploymentview::DV','deploymentview','others','interfaceview.Ground_PI_newTm_OnBoard_RI_newTm','Actual_Connection_Binding','(reference (ip_i))','').
isProperty('NIL','APPLIES TO','deploymentview::DV','deploymentview','others','interfaceview.OnBoard_PI_newTc_Ground_RI_newTc','Actual_Connection_Binding','(reference (ip_i))','').
isImportDeclaration('deploymentview::DV','PUBLIC','ocarina_buses','').
isSubcomponent('deploymentview::DV','deploymentview','others','ip_i','BUS','ocarina_buses::ip.i','NIL','NIL','').
isProperty('NIL','=>','deploymentview::DV','deploymentview','others','ip_i','Taste::coordinates','"85409 179296 138982 195878"','').
isProperty('_','_','_','_','_','_','LMP::Unparser_ID_Case','AsIs','').
isProperty('_','_','_','_','_','_','LMP::Unparser_Insert_Header','Yes','').
isVersion('AADL2.1','TASTE type deploymentview','','generated code: do not edit').
isPackage('deploymentview::DV','PUBLIC','').
isImportDeclaration('deploymentview::DV','PUBLIC','Taste','').
isImportDeclaration('deploymentview::DV','PUBLIC','Deployment','').
isProperty('NIL','=>','deploymentview::DV','NIL','NIL','NIL','Taste::coordinates','"0 0 297000 210000"','').
isProperty('NIL','=>','deploymentview::DV','NIL','NIL','NIL','Taste::version','"1.3"','').
isProperty('NIL','=>','deploymentview::DV','NIL','NIL','NIL','Taste::interfaceView','"InterfaceView.aadl"','').
isProperty('NIL','=>','deploymentview::DV','NIL','NIL','NIL','Taste::HWLibraries','("../../../../tool-inst/share/ocarina/AADLv2/ocarina_components.aadl")','').
isComponentType('deploymentview::DV','PUBLIC','deploymentview','SYSTEM','NIL','').
isComponentImplementation('deploymentview::DV','PUBLIC','deploymentview','others','SYSTEM','NIL','others','').
isImportDeclaration('deploymentview::DV','PUBLIC','interfaceview::IV','').
isSubcomponent('deploymentview::DV','deploymentview','others','interfaceview','SYSTEM','interfaceview::IV::interfaceview.others','NIL','NIL','').
isImportDeclaration('deploymentview::DV','PUBLIC','TASTE_DV_Properties','').

