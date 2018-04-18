#! /usr/bin/python

Ada, C, GUI, SIMULINK, VHDL, OG, RTDS, SYSTEM_C, SCADE6, VDM, CPP = range(11)
thread, passive, unknown = range(3)
PI, RI = range(2)
synch, asynch = range(2)
param_in, param_out = range(2)
UPER, NATIVE, ACN = range(3)
cyclic, sporadic, variator, protected, unprotected = range(5)
enumerated, sequenceof, sequence, set, setof, integer, boolean, real, choice, octetstring, string = range(11)
functions = {}

functions['ground'] = {
    'name_with_case' : 'Ground',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['ground']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'ground',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['ground']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['ground']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['ground']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['ground']['interfaces']['triggerTmGUI'] = {
    'port_name': 'triggerTmGUI',
    'parent_fv': 'ground',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 500,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['ground']['interfaces']['triggerTmGUI']['paramsInOrdered'] = []

functions['ground']['interfaces']['triggerTmGUI']['paramsOutOrdered'] = []

functions['ground']['interfaces']['newTc'] = {
    'port_name': 'newTc',
    'parent_fv': 'ground',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcqueue',
    'calling_threads': {},
    'distant_name': 'newTc',
    'queue_size': 1
}

functions['ground']['interfaces']['newTc']['paramsInOrdered'] = ['tcPacket']

functions['ground']['interfaces']['newTc']['paramsOutOrdered'] = []

functions['ground']['interfaces']['newTc']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTc',
    'param_direction': param_in
}

functions['tcqueue'] = {
    'name_with_case' : 'TcQueue',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['tcqueue']['interfaces']['newTc'] = {
    'port_name': 'newTc',
    'parent_fv': 'tcqueue',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tcqueue']['interfaces']['newTc']['paramsInOrdered'] = ['tcPacket']

functions['tcqueue']['interfaces']['newTc']['paramsOutOrdered'] = []

functions['tcqueue']['interfaces']['newTc']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTc',
    'param_direction': param_in
}

functions['tcqueue']['interfaces']['tcRequest'] = {
    'port_name': 'tcRequest',
    'parent_fv': 'tcqueue',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tcqueue']['interfaces']['tcRequest']['paramsInOrdered'] = []

functions['tcqueue']['interfaces']['tcRequest']['paramsOutOrdered'] = ['tcPacket', 'isAvailable']

functions['tcqueue']['interfaces']['tcRequest']['out']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tcRequest',
    'param_direction': param_out
}

functions['tcqueue']['interfaces']['tcRequest']['out']['isAvailable'] = {
    'type': 'T_Boolean',
    'asn1_module': 'TASTE_BasicTypes',
    'basic_type': boolean,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tcRequest',
    'param_direction': param_out
}

functions['tcdispatch'] = {
    'name_with_case' : 'TcDispatch',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['tcdispatch']['interfaces']['tcTrigger'] = {
    'port_name': 'tcTrigger',
    'parent_fv': 'tcdispatch',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tcTrigger']['paramsInOrdered'] = []

functions['tcdispatch']['interfaces']['tcTrigger']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tcRequest'] = {
    'port_name': 'tcRequest',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcqueue',
    'calling_threads': {},
    'distant_name': 'tcRequest',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tcRequest']['paramsInOrdered'] = []

functions['tcdispatch']['interfaces']['tcRequest']['paramsOutOrdered'] = ['tcPacket', 'isAvailable']

functions['tcdispatch']['interfaces']['tcRequest']['out']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tcRequest',
    'param_direction': param_out
}

functions['tcdispatch']['interfaces']['tcRequest']['out']['isAvailable'] = {
    'type': 'T_Boolean',
    'asn1_module': 'TASTE_BasicTypes',
    'basic_type': boolean,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tcRequest',
    'param_direction': param_out
}

functions['tcdispatch']['interfaces']['tc17'] = {
    'port_name': 'tc17',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st17',
    'calling_threads': {},
    'distant_name': 'tc17',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc17']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc17']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc17']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc17',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc08'] = {
    'port_name': 'tc08',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st08',
    'calling_threads': {},
    'distant_name': 'tc08',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc08']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc08']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc08']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc08',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc19'] = {
    'port_name': 'tc19',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st19',
    'calling_threads': {},
    'distant_name': 'tc19',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc19']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc19']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc19']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc19',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc09'] = {
    'port_name': 'tc09',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st09',
    'calling_threads': {},
    'distant_name': 'tc09',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc09']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc09']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc09']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc09',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc12'] = {
    'port_name': 'tc12',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st12',
    'calling_threads': {},
    'distant_name': 'tc12',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc12']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc12']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc12']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc12',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc11'] = {
    'port_name': 'tc11',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st11',
    'calling_threads': {},
    'distant_name': 'tc11',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc11']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc11']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc11']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc11',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc18'] = {
    'port_name': 'tc18',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st18',
    'calling_threads': {},
    'distant_name': 'tc18',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc18']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc18']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc18']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc18',
    'param_direction': param_in
}

functions['tcdispatch']['interfaces']['tc23'] = {
    'port_name': 'tc23',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st23',
    'calling_threads': {},
    'distant_name': 'tc23',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc23']['paramsInOrdered'] = []

functions['tcdispatch']['interfaces']['tc23']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc20'] = {
    'port_name': 'tc20',
    'parent_fv': 'tcdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st20',
    'calling_threads': {},
    'distant_name': 'tc20',
    'queue_size': 1
}

functions['tcdispatch']['interfaces']['tc20']['paramsInOrdered'] = ['tcPacket']

functions['tcdispatch']['interfaces']['tc20']['paramsOutOrdered'] = []

functions['tcdispatch']['interfaces']['tc20']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc20',
    'param_direction': param_in
}

functions['tmdispatch'] = {
    'name_with_case' : 'TmDispatch',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['tmdispatch']['interfaces']['tmTrigger'] = {
    'port_name': 'tmTrigger',
    'parent_fv': 'tmdispatch',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 1000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tmdispatch']['interfaces']['tmTrigger']['paramsInOrdered'] = []

functions['tmdispatch']['interfaces']['tmTrigger']['paramsOutOrdered'] = []

functions['tmdispatch']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'tmdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'ground',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['tmdispatch']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['tmdispatch']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['tmdispatch']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['tmdispatch']['interfaces']['tmRequest'] = {
    'port_name': 'tmRequest',
    'parent_fv': 'tmdispatch',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'tmRequest',
    'queue_size': 1
}

functions['tmdispatch']['interfaces']['tmRequest']['paramsInOrdered'] = []

functions['tmdispatch']['interfaces']['tmRequest']['paramsOutOrdered'] = ['tmPacket', 'isAvailable']

functions['tmdispatch']['interfaces']['tmRequest']['out']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tmRequest',
    'param_direction': param_out
}

functions['tmdispatch']['interfaces']['tmRequest']['out']['isAvailable'] = {
    'type': 'T_Boolean',
    'asn1_module': 'TASTE_BasicTypes',
    'basic_type': boolean,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tmRequest',
    'param_direction': param_out
}

functions['tmqueue'] = {
    'name_with_case' : 'TmQueue',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['tmqueue']['interfaces']['tmRequest'] = {
    'port_name': 'tmRequest',
    'parent_fv': 'tmqueue',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tmqueue']['interfaces']['tmRequest']['paramsInOrdered'] = []

functions['tmqueue']['interfaces']['tmRequest']['paramsOutOrdered'] = ['tmPacket', 'isAvailable']

functions['tmqueue']['interfaces']['tmRequest']['out']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tmRequest',
    'param_direction': param_out
}

functions['tmqueue']['interfaces']['tmRequest']['out']['isAvailable'] = {
    'type': 'T_Boolean',
    'asn1_module': 'TASTE_BasicTypes',
    'basic_type': boolean,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tmRequest',
    'param_direction': param_out
}

functions['tmqueue']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'tmqueue',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['tmqueue']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['tmqueue']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['tmqueue']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['tmqueue']['interfaces']['incCount'] = {
    'port_name': 'incCount',
    'parent_fv': 'tmqueue',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st09',
    'calling_threads': {},
    'distant_name': 'incCount',
    'queue_size': 1
}

functions['tmqueue']['interfaces']['incCount']['paramsInOrdered'] = []

functions['tmqueue']['interfaces']['incCount']['paramsOutOrdered'] = ['tmPacket', 'isAvailable']

functions['tmqueue']['interfaces']['incCount']['out']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'incCount',
    'param_direction': param_out
}

functions['tmqueue']['interfaces']['incCount']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'incCount',
    'param_direction': param_out
}

functions['st17'] = {
    'name_with_case' : 'ST17',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st17']['interfaces']['tc17'] = {
    'port_name': 'tc17',
    'parent_fv': 'st17',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st17']['interfaces']['tc17']['paramsInOrdered'] = ['tcPacket']

functions['st17']['interfaces']['tc17']['paramsOutOrdered'] = []

functions['st17']['interfaces']['tc17']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc17',
    'param_direction': param_in
}

functions['st17']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st17',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st17']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st17']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st17']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st17']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st17']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st17']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st17']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st17']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st17',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st17']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st17']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st17']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st17']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st17',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st17']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st17']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st17']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st17']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st17',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st17']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st17']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st17']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st01'] = {
    'name_with_case' : 'ST01',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st01']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st01',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st01']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st01']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st01']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st01']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st01']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st01']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st01']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st01']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st01',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st01']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st01']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st01']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st01']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st01',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st01']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st01']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st01']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st01']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st01',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st01']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st01']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st01']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st08'] = {
    'name_with_case' : 'ST08',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st08']['interfaces']['tc08'] = {
    'port_name': 'tc08',
    'parent_fv': 'st08',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st08']['interfaces']['tc08']['paramsInOrdered'] = ['tcPacket']

functions['st08']['interfaces']['tc08']['paramsOutOrdered'] = []

functions['st08']['interfaces']['tc08']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc08',
    'param_direction': param_in
}

functions['st08']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st08',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st08']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st08']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st08']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st08']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st08']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st08']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st08']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['onboardapid'] = {
    'name_with_case' : 'OnBoardAPID',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['onboardapid']['functional_states']['apid'] = {
    'fullFsName' : 'APID',
    'typeName' : 'PusApid',
    'moduleName' : 'PUS-CcsdsPacketFields',
    'asn1FileName' : '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn'
}

functions['onboardapid']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'onboardapid',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['onboardapid']['interfaces']['getApid']['paramsInOrdered'] = []

functions['onboardapid']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['onboardapid']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['onboardapid']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'onboardapid',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['onboardapid']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['onboardapid']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['onboardapid']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st09'] = {
    'name_with_case' : 'ST09',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st09']['interfaces']['incCount'] = {
    'port_name': 'incCount',
    'parent_fv': 'st09',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st09']['interfaces']['incCount']['paramsInOrdered'] = []

functions['st09']['interfaces']['incCount']['paramsOutOrdered'] = ['tmPacket', 'isAvailable']

functions['st09']['interfaces']['incCount']['out']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'incCount',
    'param_direction': param_out
}

functions['st09']['interfaces']['incCount']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'incCount',
    'param_direction': param_out
}

functions['st09']['interfaces']['tc09'] = {
    'port_name': 'tc09',
    'parent_fv': 'st09',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st09']['interfaces']['tc09']['paramsInOrdered'] = ['tcPacket']

functions['st09']['interfaces']['tc09']['paramsOutOrdered'] = []

functions['st09']['interfaces']['tc09']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc09',
    'param_direction': param_in
}

functions['st09']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st09',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'timereportapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st09']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st09']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st09']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st09']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st09',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'timereportapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st09']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st09']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st09']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st09']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st09',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st09']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st09']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st09']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st09']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st09']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st09']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st09']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['timereportapid'] = {
    'name_with_case' : 'TimeReportAPID',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['timereportapid']['functional_states']['apid'] = {
    'fullFsName' : 'APID',
    'typeName' : 'PusApid',
    'moduleName' : 'PUS-CcsdsPacketFields',
    'asn1FileName' : '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn'
}

functions['timereportapid']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'timereportapid',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['timereportapid']['interfaces']['getApid']['paramsInOrdered'] = []

functions['timereportapid']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['timereportapid']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['timereportapid']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'timereportapid',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['timereportapid']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['timereportapid']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['timereportapid']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['events'] = {
    'name_with_case' : 'Events',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['events']['interfaces']['getNextEvent'] = {
    'port_name': 'getNextEvent',
    'parent_fv': 'events',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['events']['interfaces']['getNextEvent']['paramsInOrdered'] = ['actualCounter']

functions['events']['interfaces']['getNextEvent']['paramsOutOrdered'] = ['eventInfo', 'nextCounter']

functions['events']['interfaces']['getNextEvent']['in']['actualCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_in
}

functions['events']['interfaces']['getNextEvent']['out']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['events']['interfaces']['getNextEvent']['out']['nextCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['events']['interfaces']['pushNewEvent'] = {
    'port_name': 'pushNewEvent',
    'parent_fv': 'events',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['events']['interfaces']['pushNewEvent']['paramsInOrdered'] = ['eventInfo']

functions['events']['interfaces']['pushNewEvent']['paramsOutOrdered'] = []

functions['events']['interfaces']['pushNewEvent']['in']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'pushNewEvent',
    'param_direction': param_in
}

functions['events']['interfaces']['debugEventsTrigger'] = {
    'port_name': 'debugEventsTrigger',
    'parent_fv': 'events',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': variator,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['events']['interfaces']['debugEventsTrigger']['paramsInOrdered'] = []

functions['events']['interfaces']['debugEventsTrigger']['paramsOutOrdered'] = []

functions['st05'] = {
    'name_with_case' : 'ST05',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st05']['interfaces']['EventReportTrigger'] = {
    'port_name': 'EventReportTrigger',
    'parent_fv': 'st05',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st05']['interfaces']['EventReportTrigger']['paramsInOrdered'] = []

functions['st05']['interfaces']['EventReportTrigger']['paramsOutOrdered'] = []

functions['st05']['interfaces']['newTmNoInherit'] = {
    'port_name': 'newTmNoInherit',
    'parent_fv': 'st05',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st05']['interfaces']['newTmNoInherit']['paramsInOrdered'] = ['tmPacket']

functions['st05']['interfaces']['newTmNoInherit']['paramsOutOrdered'] = []

functions['st05']['interfaces']['newTmNoInherit']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTmNoInherit',
    'param_direction': param_in
}

functions['st05']['interfaces']['getNextEvent'] = {
    'port_name': 'getNextEvent',
    'parent_fv': 'st05',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'getNextEvent',
    'queue_size': 1
}

functions['st05']['interfaces']['getNextEvent']['paramsInOrdered'] = ['actualCounter']

functions['st05']['interfaces']['getNextEvent']['paramsOutOrdered'] = ['eventInfo', 'nextCounter']

functions['st05']['interfaces']['getNextEvent']['in']['actualCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_in
}

functions['st05']['interfaces']['getNextEvent']['out']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['st05']['interfaces']['getNextEvent']['out']['nextCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['st05']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st05',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st05']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st05']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st05']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st05']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st05',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st05']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st05']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st05']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st19'] = {
    'name_with_case' : 'ST19',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st19']['interfaces']['tc19'] = {
    'port_name': 'tc19',
    'parent_fv': 'st19',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st19']['interfaces']['tc19']['paramsInOrdered'] = ['tcPacket']

functions['st19']['interfaces']['tc19']['paramsOutOrdered'] = []

functions['st19']['interfaces']['tc19']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc19',
    'param_direction': param_in
}

functions['st19']['interfaces']['EventActionTrigger'] = {
    'port_name': 'EventActionTrigger',
    'parent_fv': 'st19',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': variator,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st19']['interfaces']['EventActionTrigger']['paramsInOrdered'] = []

functions['st19']['interfaces']['EventActionTrigger']['paramsOutOrdered'] = []

functions['st19']['interfaces']['getNextEvent'] = {
    'port_name': 'getNextEvent',
    'parent_fv': 'st19',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'getNextEvent',
    'queue_size': 1
}

functions['st19']['interfaces']['getNextEvent']['paramsInOrdered'] = ['actualCounter']

functions['st19']['interfaces']['getNextEvent']['paramsOutOrdered'] = ['eventInfo', 'nextCounter']

functions['st19']['interfaces']['getNextEvent']['in']['actualCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_in
}

functions['st19']['interfaces']['getNextEvent']['out']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['st19']['interfaces']['getNextEvent']['out']['nextCounter'] = {
    'type': 'PusUInt64',
    'asn1_module': 'PUS_NbitIntegers',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getNextEvent',
    'param_direction': param_out
}

functions['st19']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st19',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st19']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st19']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st19']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st19']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st19']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st19']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st19']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st19']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st19',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st19']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st19']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st19']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st19']['interfaces']['newTc'] = {
    'port_name': 'newTc',
    'parent_fv': 'st19',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcqueue',
    'calling_threads': {},
    'distant_name': 'newTc',
    'queue_size': 1
}

functions['st19']['interfaces']['newTc']['paramsInOrdered'] = ['tcPacket']

functions['st19']['interfaces']['newTc']['paramsOutOrdered'] = []

functions['st19']['interfaces']['newTc']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTc',
    'param_direction': param_in
}

functions['housekeeping'] = {
    'name_with_case' : 'Housekeeping',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['housekeeping']['interfaces']['setParamValue'] = {
    'port_name': 'setParamValue',
    'parent_fv': 'housekeeping',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['housekeeping']['interfaces']['setParamValue']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['housekeeping']['interfaces']['setParamValue']['paramsOutOrdered'] = []

functions['housekeeping']['interfaces']['setParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setParamValue',
    'param_direction': param_in
}

functions['housekeeping']['interfaces']['setParamValue']['in']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setParamValue',
    'param_direction': param_in
}

functions['housekeeping']['interfaces']['getParamValue'] = {
    'port_name': 'getParamValue',
    'parent_fv': 'housekeeping',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['housekeeping']['interfaces']['getParamValue']['paramsInOrdered'] = ['paramId']

functions['housekeeping']['interfaces']['getParamValue']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['housekeeping']['interfaces']['getParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_in
}

functions['housekeeping']['interfaces']['getParamValue']['out']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['housekeeping']['interfaces']['getParamValue']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['st03'] = {
    'name_with_case' : 'ST03',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st03']['interfaces']['HkReportTrigger'] = {
    'port_name': 'HkReportTrigger',
    'parent_fv': 'st03',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st03']['interfaces']['HkReportTrigger']['paramsInOrdered'] = []

functions['st03']['interfaces']['HkReportTrigger']['paramsOutOrdered'] = []

functions['st03']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st03',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st03']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st03']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st03']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st03']['interfaces']['getParamValue'] = {
    'port_name': 'getParamValue',
    'parent_fv': 'st03',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'housekeeping',
    'calling_threads': {},
    'distant_name': 'getParamValue',
    'queue_size': 1
}

functions['st03']['interfaces']['getParamValue']['paramsInOrdered'] = ['paramId']

functions['st03']['interfaces']['getParamValue']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['st03']['interfaces']['getParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_in
}

functions['st03']['interfaces']['getParamValue']['out']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['st03']['interfaces']['getParamValue']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['st03']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st03',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st03']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st03']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st03']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st03']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st03',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st03']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st03']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st03']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st12'] = {
    'name_with_case' : 'ST12',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st12']['interfaces']['PmonTrigger'] = {
    'port_name': 'PmonTrigger',
    'parent_fv': 'st12',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st12']['interfaces']['PmonTrigger']['paramsInOrdered'] = []

functions['st12']['interfaces']['PmonTrigger']['paramsOutOrdered'] = []

functions['st12']['interfaces']['tc12'] = {
    'port_name': 'tc12',
    'parent_fv': 'st12',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st12']['interfaces']['tc12']['paramsInOrdered'] = ['tcPacket']

functions['st12']['interfaces']['tc12']['paramsOutOrdered'] = []

functions['st12']['interfaces']['tc12']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc12',
    'param_direction': param_in
}

functions['st12']['interfaces']['pushNewEvent'] = {
    'port_name': 'pushNewEvent',
    'parent_fv': 'st12',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'pushNewEvent',
    'queue_size': 1
}

functions['st12']['interfaces']['pushNewEvent']['paramsInOrdered'] = ['eventInfo']

functions['st12']['interfaces']['pushNewEvent']['paramsOutOrdered'] = []

functions['st12']['interfaces']['pushNewEvent']['in']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'pushNewEvent',
    'param_direction': param_in
}

functions['st12']['interfaces']['getParamValue'] = {
    'port_name': 'getParamValue',
    'parent_fv': 'st12',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'housekeeping',
    'calling_threads': {},
    'distant_name': 'getParamValue',
    'queue_size': 1
}

functions['st12']['interfaces']['getParamValue']['paramsInOrdered'] = ['paramId']

functions['st12']['interfaces']['getParamValue']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['st12']['interfaces']['getParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_in
}

functions['st12']['interfaces']['getParamValue']['out']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['st12']['interfaces']['getParamValue']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['st12']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st12',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st12']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st12']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st12']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st12']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st12']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st12']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st12']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11'] = {
    'name_with_case' : 'ST11',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st11']['interfaces']['tc11'] = {
    'port_name': 'tc11',
    'parent_fv': 'st11',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st11']['interfaces']['tc11']['paramsInOrdered'] = ['tcPacket']

functions['st11']['interfaces']['tc11']['paramsOutOrdered'] = []

functions['st11']['interfaces']['tc11']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc11',
    'param_direction': param_in
}

functions['st11']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st11',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st11']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st11']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st11']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st11']['interfaces']['newTc'] = {
    'port_name': 'newTc',
    'parent_fv': 'st11',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcqueue',
    'calling_threads': {},
    'distant_name': 'newTc',
    'queue_size': 1
}

functions['st11']['interfaces']['newTc']['paramsInOrdered'] = ['tcPacket']

functions['st11']['interfaces']['newTc']['paramsOutOrdered'] = []

functions['st11']['interfaces']['newTc']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTc',
    'param_direction': param_in
}

functions['st18'] = {
    'name_with_case' : 'ST18',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st18']['interfaces']['tc18'] = {
    'port_name': 'tc18',
    'parent_fv': 'st18',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st18']['interfaces']['tc18']['paramsInOrdered'] = ['tcPacket']

functions['st18']['interfaces']['tc18']['paramsOutOrdered'] = []

functions['st18']['interfaces']['tc18']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc18',
    'param_direction': param_in
}

functions['st18']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st18',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st18']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st18']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st18']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st18']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st18']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st18']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st18']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st18']['interfaces']['loadDirect'] = {
    'port_name': 'loadDirect',
    'parent_fv': 'st18',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'obcpengine',
    'calling_threads': {},
    'distant_name': 'loadDirect',
    'queue_size': 1
}

functions['st18']['interfaces']['loadDirect']['paramsInOrdered'] = ['obcpId', 'obcpCode']

functions['st18']['interfaces']['loadDirect']['paramsOutOrdered'] = []

functions['st18']['interfaces']['loadDirect']['in']['obcpId'] = {
    'type': 'PusSt18ObcpId',
    'asn1_module': 'PUS_ST18',
    'basic_type': string,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadDirect',
    'param_direction': param_in
}

functions['st18']['interfaces']['loadDirect']['in']['obcpCode'] = {
    'type': 'PusSt18ObcpCode',
    'asn1_module': 'PUS_ST18',
    'basic_type': string,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadDirect',
    'param_direction': param_in
}

functions['st18']['interfaces']['loadReference'] = {
    'port_name': 'loadReference',
    'parent_fv': 'st18',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'obcpengine',
    'calling_threads': {},
    'distant_name': 'loadReference',
    'queue_size': 1
}

functions['st18']['interfaces']['loadReference']['paramsInOrdered'] = ['referenceData']

functions['st18']['interfaces']['loadReference']['paramsOutOrdered'] = []

functions['st18']['interfaces']['loadReference']['in']['referenceData'] = {
    'type': 'PusTC_18_13_Data',
    'asn1_module': 'PUS_ST18',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadReference',
    'param_direction': param_in
}

functions['obcpengine'] = {
    'name_with_case' : 'ObcpEngine',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['obcpengine']['interfaces']['loadDirect'] = {
    'port_name': 'loadDirect',
    'parent_fv': 'obcpengine',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['loadDirect']['paramsInOrdered'] = ['obcpId', 'obcpCode']

functions['obcpengine']['interfaces']['loadDirect']['paramsOutOrdered'] = []

functions['obcpengine']['interfaces']['loadDirect']['in']['obcpId'] = {
    'type': 'PusSt18ObcpId',
    'asn1_module': 'PUS_ST18',
    'basic_type': string,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadDirect',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['loadDirect']['in']['obcpCode'] = {
    'type': 'PusSt18ObcpCode',
    'asn1_module': 'PUS_ST18',
    'basic_type': string,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadDirect',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['loadReference'] = {
    'port_name': 'loadReference',
    'parent_fv': 'obcpengine',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['loadReference']['paramsInOrdered'] = ['referenceData']

functions['obcpengine']['interfaces']['loadReference']['paramsOutOrdered'] = []

functions['obcpengine']['interfaces']['loadReference']['in']['referenceData'] = {
    'type': 'PusTC_18_13_Data',
    'asn1_module': 'PUS_ST18',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'loadReference',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['newTc'] = {
    'port_name': 'newTc',
    'parent_fv': 'obcpengine',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcqueue',
    'calling_threads': {},
    'distant_name': 'newTc',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['newTc']['paramsInOrdered'] = ['tcPacket']

functions['obcpengine']['interfaces']['newTc']['paramsOutOrdered'] = []

functions['obcpengine']['interfaces']['newTc']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTc',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['getOnBoardParam'] = {
    'port_name': 'getOnBoardParam',
    'parent_fv': 'obcpengine',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'getOnBoardParam',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['getOnBoardParam']['paramsInOrdered'] = ['paramId']

functions['obcpengine']['interfaces']['getOnBoardParam']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['obcpengine']['interfaces']['getOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['getOnBoardParam']['out']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['obcpengine']['interfaces']['getOnBoardParam']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['obcpengine']['interfaces']['setOnBoardParam'] = {
    'port_name': 'setOnBoardParam',
    'parent_fv': 'obcpengine',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'setOnBoardParam',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['setOnBoardParam']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['obcpengine']['interfaces']['setOnBoardParam']['paramsOutOrdered'] = []

functions['obcpengine']['interfaces']['setOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['setOnBoardParam']['in']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['obcpengine']['interfaces']['pushNewEvent'] = {
    'port_name': 'pushNewEvent',
    'parent_fv': 'obcpengine',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'pushNewEvent',
    'queue_size': 1
}

functions['obcpengine']['interfaces']['pushNewEvent']['paramsInOrdered'] = ['eventInfo']

functions['obcpengine']['interfaces']['pushNewEvent']['paramsOutOrdered'] = []

functions['obcpengine']['interfaces']['pushNewEvent']['in']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'pushNewEvent',
    'param_direction': param_in
}

functions['st23'] = {
    'name_with_case' : 'ST23',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st23']['interfaces']['tc23'] = {
    'port_name': 'tc23',
    'parent_fv': 'st23',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st23']['interfaces']['tc23']['paramsInOrdered'] = []

functions['st23']['interfaces']['tc23']['paramsOutOrdered'] = []

functions['st23']['interfaces']['copy'] = {
    'port_name': 'copy',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'filemanagement',
    'calling_threads': {},
    'distant_name': 'copy',
    'queue_size': 1
}

functions['st23']['interfaces']['copy']['paramsInOrdered'] = []

functions['st23']['interfaces']['copy']['paramsOutOrdered'] = []

functions['st23']['interfaces']['delete'] = {
    'port_name': 'delete',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'filemanagement',
    'calling_threads': {},
    'distant_name': 'delete',
    'queue_size': 1
}

functions['st23']['interfaces']['delete']['paramsInOrdered'] = []

functions['st23']['interfaces']['delete']['paramsOutOrdered'] = []

functions['st23']['interfaces']['create'] = {
    'port_name': 'create',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'filemanagement',
    'calling_threads': {},
    'distant_name': 'create',
    'queue_size': 1
}

functions['st23']['interfaces']['create']['paramsInOrdered'] = []

functions['st23']['interfaces']['create']['paramsOutOrdered'] = []

functions['st23']['interfaces']['getAttributes'] = {
    'port_name': 'getAttributes',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'filemanagement',
    'calling_threads': {},
    'distant_name': 'getAttributes',
    'queue_size': 1
}

functions['st23']['interfaces']['getAttributes']['paramsInOrdered'] = []

functions['st23']['interfaces']['getAttributes']['paramsOutOrdered'] = []

functions['st23']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st23']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st23']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st23']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st23']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st23']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st23']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st23']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st23']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st23']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st23']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st23']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['st23']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st23',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st23']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st23']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st23']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st23']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st23']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st23']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st23']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['filemanagement'] = {
    'name_with_case' : 'FileManagement',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['filemanagement']['interfaces']['copy'] = {
    'port_name': 'copy',
    'parent_fv': 'filemanagement',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['filemanagement']['interfaces']['copy']['paramsInOrdered'] = []

functions['filemanagement']['interfaces']['copy']['paramsOutOrdered'] = []

functions['filemanagement']['interfaces']['delete'] = {
    'port_name': 'delete',
    'parent_fv': 'filemanagement',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['filemanagement']['interfaces']['delete']['paramsInOrdered'] = []

functions['filemanagement']['interfaces']['delete']['paramsOutOrdered'] = []

functions['filemanagement']['interfaces']['create'] = {
    'port_name': 'create',
    'parent_fv': 'filemanagement',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['filemanagement']['interfaces']['create']['paramsInOrdered'] = []

functions['filemanagement']['interfaces']['create']['paramsOutOrdered'] = []

functions['filemanagement']['interfaces']['getAttributes'] = {
    'port_name': 'getAttributes',
    'parent_fv': 'filemanagement',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['filemanagement']['interfaces']['getAttributes']['paramsInOrdered'] = []

functions['filemanagement']['interfaces']['getAttributes']['paramsOutOrdered'] = []

functions['st20'] = {
    'name_with_case' : 'ST20',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['st20']['interfaces']['tc20'] = {
    'port_name': 'tc20',
    'parent_fv': 'st20',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['st20']['interfaces']['tc20']['paramsInOrdered'] = ['tcPacket']

functions['st20']['interfaces']['tc20']['paramsOutOrdered'] = []

functions['st20']['interfaces']['tc20']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'tc20',
    'param_direction': param_in
}

functions['st20']['interfaces']['setOnBoardParam'] = {
    'port_name': 'setOnBoardParam',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'setOnBoardParam',
    'queue_size': 1
}

functions['st20']['interfaces']['setOnBoardParam']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['st20']['interfaces']['setOnBoardParam']['paramsOutOrdered'] = []

functions['st20']['interfaces']['setOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['st20']['interfaces']['setOnBoardParam']['in']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['st20']['interfaces']['getOnBoardParam'] = {
    'port_name': 'getOnBoardParam',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'getOnBoardParam',
    'queue_size': 1
}

functions['st20']['interfaces']['getOnBoardParam']['paramsInOrdered'] = ['paramId']

functions['st20']['interfaces']['getOnBoardParam']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['st20']['interfaces']['getOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_in
}

functions['st20']['interfaces']['getOnBoardParam']['out']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['st20']['interfaces']['getOnBoardParam']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['st20']['interfaces']['newTm'] = {
    'port_name': 'newTm',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmqueue',
    'calling_threads': {},
    'distant_name': 'newTm',
    'queue_size': 1
}

functions['st20']['interfaces']['newTm']['paramsInOrdered'] = ['tmPacket']

functions['st20']['interfaces']['newTm']['paramsOutOrdered'] = []

functions['st20']['interfaces']['newTm']['in']['tmPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'newTm',
    'param_direction': param_in
}

functions['st20']['interfaces']['ACK'] = {
    'port_name': 'ACK',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st01',
    'calling_threads': {},
    'distant_name': 'ACK',
    'queue_size': 1
}

functions['st20']['interfaces']['ACK']['paramsInOrdered'] = ['tcPacket', 'reportType', 'error', 'errorInfo', 'step']

functions['st20']['interfaces']['ACK']['paramsOutOrdered'] = []

functions['st20']['interfaces']['ACK']['in']['tcPacket'] = {
    'type': 'PusPacket',
    'asn1_module': 'PUS_CcsdsPacket',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st20']['interfaces']['ACK']['in']['reportType'] = {
    'type': 'PusSubserviceType',
    'asn1_module': 'PUS_Services',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st20']['interfaces']['ACK']['in']['error'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st20']['interfaces']['ACK']['in']['errorInfo'] = {
    'type': 'PusSt01FailureInfo',
    'asn1_module': 'PUS_ST01',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st20']['interfaces']['ACK']['in']['step'] = {
    'type': 'PusStepId',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'ACK',
    'param_direction': param_in
}

functions['st20']['interfaces']['getApid'] = {
    'port_name': 'getApid',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': unprotected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getApid',
    'queue_size': 1
}

functions['st20']['interfaces']['getApid']['paramsInOrdered'] = []

functions['st20']['interfaces']['getApid']['paramsOutOrdered'] = ['apid']

functions['st20']['interfaces']['getApid']['out']['apid'] = {
    'type': 'PusApid',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getApid',
    'param_direction': param_out
}

functions['st20']['interfaces']['getSequenceCount'] = {
    'port_name': 'getSequenceCount',
    'parent_fv': 'st20',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardapid',
    'calling_threads': {},
    'distant_name': 'getSequenceCount',
    'queue_size': 1
}

functions['st20']['interfaces']['getSequenceCount']['paramsInOrdered'] = []

functions['st20']['interfaces']['getSequenceCount']['paramsOutOrdered'] = ['sequenceCount']

functions['st20']['interfaces']['getSequenceCount']['out']['sequenceCount'] = {
    'type': 'PusSequenceCount',
    'asn1_module': 'PUS_CcsdsPacketFields',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getSequenceCount',
    'param_direction': param_out
}

functions['onboardparams'] = {
    'name_with_case' : 'OnBoardParams',
    'runtime_nature': passive,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['onboardparams']['interfaces']['setOnBoardParam'] = {
    'port_name': 'setOnBoardParam',
    'parent_fv': 'onboardparams',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['onboardparams']['interfaces']['setOnBoardParam']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['onboardparams']['interfaces']['setOnBoardParam']['paramsOutOrdered'] = []

functions['onboardparams']['interfaces']['setOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['onboardparams']['interfaces']['setOnBoardParam']['in']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['onboardparams']['interfaces']['getOnBoardParam'] = {
    'port_name': 'getOnBoardParam',
    'parent_fv': 'onboardparams',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['onboardparams']['interfaces']['getOnBoardParam']['paramsInOrdered'] = ['paramId']

functions['onboardparams']['interfaces']['getOnBoardParam']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['onboardparams']['interfaces']['getOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_in
}

functions['onboardparams']['interfaces']['getOnBoardParam']['out']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['onboardparams']['interfaces']['getOnBoardParam']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['trigger'] = {
    'name_with_case' : 'trigger',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['trigger']['interfaces']['HkReportTrigger'] = {
    'port_name': 'HkReportTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 10000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['HkReportTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['HkReportTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['TmDispatchTrigger'] = {
    'port_name': 'TmDispatchTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 1000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['TmDispatchTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['TmDispatchTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['EventActionTrigger'] = {
    'port_name': 'EventActionTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 10000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['EventActionTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['EventActionTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['TcDispatchTrigger'] = {
    'port_name': 'TcDispatchTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 1000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['TcDispatchTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['TcDispatchTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['PmonTrigger'] = {
    'port_name': 'PmonTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 10000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['PmonTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['PmonTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['EventReportTrigger'] = {
    'port_name': 'EventReportTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 1000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['EventReportTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['EventReportTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['debugEventTrigger'] = {
    'port_name': 'debugEventTrigger',
    'parent_fv': 'trigger',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 15000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['trigger']['interfaces']['debugEventTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['debugEventTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['tmTrigger'] = {
    'port_name': 'tmTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tmdispatch',
    'calling_threads': {},
    'distant_name': 'tmTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['tmTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['tmTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['HkReportTrigger'] = {
    'port_name': 'HkReportTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st03',
    'calling_threads': {},
    'distant_name': 'HkReportTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['HkReportTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['HkReportTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['PmonTrigger'] = {
    'port_name': 'PmonTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st12',
    'calling_threads': {},
    'distant_name': 'PmonTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['PmonTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['PmonTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['EventReportTrigger'] = {
    'port_name': 'EventReportTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st05',
    'calling_threads': {},
    'distant_name': 'EventReportTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['EventReportTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['EventReportTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['tcTrigger'] = {
    'port_name': 'tcTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'tcdispatch',
    'calling_threads': {},
    'distant_name': 'tcTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['tcTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['tcTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['debugEventsTrigger'] = {
    'port_name': 'debugEventsTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'debugEventsTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['debugEventsTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['debugEventsTrigger']['paramsOutOrdered'] = []

functions['trigger']['interfaces']['EventActionTrigger'] = {
    'port_name': 'EventActionTrigger',
    'parent_fv': 'trigger',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': sporadic,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'st19',
    'calling_threads': {},
    'distant_name': 'EventActionTrigger',
    'queue_size': 1
}

functions['trigger']['interfaces']['EventActionTrigger']['paramsInOrdered'] = []

functions['trigger']['interfaces']['EventActionTrigger']['paramsOutOrdered'] = []

functions['onboardsoftware'] = {
    'name_with_case' : 'OnboardSoftware',
    'runtime_nature': thread,
    'language': C,
    'zipfile': '',
    'interfaces': {},
    'functional_states' : {}
}

functions['onboardsoftware']['interfaces']['debugTrigger'] = {
    'port_name': 'debugTrigger',
    'parent_fv': 'onboardsoftware',
    'direction': PI,
    'in': {},
    'out': {},
    'synchronism': asynch,
    'rcm': cyclic,
    'period': 15000,
    'wcet_low': 0,
    'wcet_low_unit': 'ms',
    'wcet_high': 0,
    'wcet_high_unit': 'ms',
    'distant_fv': '',
    'calling_threads': {},
    'distant_name': '',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['debugTrigger']['paramsInOrdered'] = []

functions['onboardsoftware']['interfaces']['debugTrigger']['paramsOutOrdered'] = []

functions['onboardsoftware']['interfaces']['setParamValue'] = {
    'port_name': 'setParamValue',
    'parent_fv': 'onboardsoftware',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'housekeeping',
    'calling_threads': {},
    'distant_name': 'setParamValue',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['setParamValue']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['onboardsoftware']['interfaces']['setParamValue']['paramsOutOrdered'] = []

functions['onboardsoftware']['interfaces']['setParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setParamValue',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['setParamValue']['in']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setParamValue',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['getParamValue'] = {
    'port_name': 'getParamValue',
    'parent_fv': 'onboardsoftware',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'housekeeping',
    'calling_threads': {},
    'distant_name': 'getParamValue',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['getParamValue']['paramsInOrdered'] = ['paramId']

functions['onboardsoftware']['interfaces']['getParamValue']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['onboardsoftware']['interfaces']['getParamValue']['in']['paramId'] = {
    'type': 'PusSt03ParameterId',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['getParamValue']['out']['paramValue'] = {
    'type': 'PusSt03StoredParam',
    'asn1_module': 'PUS_ST03',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['onboardsoftware']['interfaces']['getParamValue']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getParamValue',
    'param_direction': param_out
}

functions['onboardsoftware']['interfaces']['pushNewEvent'] = {
    'port_name': 'pushNewEvent',
    'parent_fv': 'onboardsoftware',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'events',
    'calling_threads': {},
    'distant_name': 'pushNewEvent',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['pushNewEvent']['paramsInOrdered'] = ['eventInfo']

functions['onboardsoftware']['interfaces']['pushNewEvent']['paramsOutOrdered'] = []

functions['onboardsoftware']['interfaces']['pushNewEvent']['in']['eventInfo'] = {
    'type': 'PusSt05Event',
    'asn1_module': 'PUS_ST05',
    'basic_type': sequence,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'pushNewEvent',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['setOnBoardParam'] = {
    'port_name': 'setOnBoardParam',
    'parent_fv': 'onboardsoftware',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'setOnBoardParam',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['setOnBoardParam']['paramsInOrdered'] = ['paramId', 'paramValue']

functions['onboardsoftware']['interfaces']['setOnBoardParam']['paramsOutOrdered'] = []

functions['onboardsoftware']['interfaces']['setOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['setOnBoardParam']['in']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'setOnBoardParam',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['getOnBoardParam'] = {
    'port_name': 'getOnBoardParam',
    'parent_fv': 'onboardsoftware',
    'direction': RI,
    'in': {},
    'out': {},
    'synchronism': synch,
    'rcm': protected,
    'period': 0,
    'wcet_low': 0,
    'wcet_low_unit': '',
    'wcet_high': 0,
    'wcet_high_unit': '',
    'distant_fv': 'onboardparams',
    'calling_threads': {},
    'distant_name': 'getOnBoardParam',
    'queue_size': 1
}

functions['onboardsoftware']['interfaces']['getOnBoardParam']['paramsInOrdered'] = ['paramId']

functions['onboardsoftware']['interfaces']['getOnBoardParam']['paramsOutOrdered'] = ['paramValue', 'isAvailable']

functions['onboardsoftware']['interfaces']['getOnBoardParam']['in']['paramId'] = {
    'type': 'PusSt20OnBoardParameterId',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_in
}

functions['onboardsoftware']['interfaces']['getOnBoardParam']['out']['paramValue'] = {
    'type': 'PusSt20StoredParam',
    'asn1_module': 'PUS_ST20',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}

functions['onboardsoftware']['interfaces']['getOnBoardParam']['out']['isAvailable'] = {
    'type': 'PusSt01FailureCode',
    'asn1_module': 'PUS_ST01',
    'basic_type': integer,
    'asn1_filename': '/tmp/uniqhomeesrocosesrocos-ws-pustools-libpustaste__iv_1_3.aadl/dataview-uniq.asn',
    'encoding': NATIVE,
    'interface': 'getOnBoardParam',
    'param_direction': param_out
}
