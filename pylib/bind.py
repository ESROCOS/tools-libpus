# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

import re
import sys

def bind_class(route, _file, _ofile):
    classes = []
    comment = False
    flag = False
    lines = f.readlines()
    regex_1 = "(\t)*typedef struct( )*({){0,1}"
    regex_3 = "(\t)*}( )*\w+;[\s\S]*(\n)*"

    with open(route + _file, "r") as f:
        for line in lines:
            if "/*" in line:
                comment = True
            if "*/" in line:
                comment = False
            if comment:
                continue
            if re.match(regex_1, line) and not flag:
                flag = True
            if re.match(regex_3, line) and flag:
                flag = False
                line = line.split('{')[1][:-1]
                classes.append(line)
    return classes

def bind_fun(route, _file, _ofile):
    with open(route + _file, "r") as f:
        lines = f.readlines()
        regex = "(\w)+ (\w)+\("
        name = _file[:-2].split('_')
        name[1] = name[1][0].upper() + name[1][1:]
        name = ''.join(name)
        print name
        _ofile.write("\tpy::class_<"+name+"_t>(m, \""+name+"_t\")\n")
        _ofile.write("\t\t.def(py::init<>());\n")
        for line in lines:
            if re.match(regex, line):
                line = line.split(' ')
                line = line[1].split('(')
                name = line[0]
                _ofile.write("\tm.def(\"" + name + "\", &" + name + ", \"Binding for " + name + "\");\n")
        _ofile.write("\n")

def bind_header(_route, _file, _ofile):
    _ofile.write("#include \"" + _file +"\"\n")
    

def bind_module(route, _file, _ofile):
    _ofile.write("\tm.doc() = \"" + _file[:-2] + " binding\";\n")
    # bind_class(route, _file, _ofile)
    bind_fun(route, _file, _ofile)

if len(sys.argv) > 1:
    route_to_h = sys.argv[1] + "/"
else:
    route_to_h = ""

files = ["pus_packet.h", "pus_apid.h", "pus_st01_packets.h", "pus_st03_packets.h", "pus_st05_packets.h", "pus_st08_packets.h", "pus_st09_packets.h",
         "pus_st11_packets.h", "pus_st17_packets.h", "pus_st19_packets.h", "pus_st12_packets.h", "pus_st18_packets.h", "pus_st20_packets.h"]

with open("tempbinding" + ".cpp", "w") as outfile:
    outfile.write("#include \"pybind11/pybind11.h\"\n")
    for file_ in files:
        bind_header(route_to_h, file_, outfile)
    outfile.write("\nnamespace py = pybind11;\n\n")
    outfile.write("PYBIND11_MODULE(pusbinding, m) {\n")
    for file_ in files: 
        bind_module(route_to_h, file_, outfile)
    outfile.write("}\n\n")



