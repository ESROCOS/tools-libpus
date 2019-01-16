# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

import sys, os
from shutil import copyfile


def convert_py_to_hex(filedata):
    # concat
    file_super = os.environ["AUTOPROJ_CURRENT_ROOT"]+"/tools/libpus/mpy/superClass.py"

    copyfile(file_super, "./aux.py")

    with open("./aux.py", "a") as outfile:
        for line in filedata:
            outfile.write(line)

    file_py = "./aux.py"
    file_mpy = file_py.replace(".py", ".mpy")

    command = "$(taste-config --prefix)/../tool-src/upython-taste/mpy-cross/mpy-cross -v " + str(file_py)
    os.system(command)

    with open(file_mpy, 'rb') as f:
        data = f.read()

    length = len(data)
    out = ""
    for b in data:
        out += '{:02x}'.format(b)

    os.remove(file_py)
    os.remove(file_mpy)

    return length, list(bytes.fromhex(out))


if __name__ == '__main__':
    (l, string) = convert_py_to_hex(sys.argv[1])
    print(string)
    print(l)
