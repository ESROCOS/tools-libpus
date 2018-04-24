from PySide import QtGui
from Model import App
from Controller import MainViewController
from Views import MainView
from Utilities import PacketTranslator
import os, sys
# dir_path = os.path.dirname(os.path.realpath(__file__))
lib_path = os.path.join('/home/esrocos/esrocos-ws-pus/tools-libpus/debug/pylib')
sys.path.append(lib_path)
import pusbinding as pb


def main():
    os.chdir("/home/esrocos/esrocos-ws-pus/tools-pusconsole/app")
    gui = QtGui.QApplication(())
    app = App()
    view = MainView()
    controller = MainViewController(app, view)

    #args = sys.argv

    # pt = PacketTranslator()

    #if len(args) > 1:
        #if args[1] == "-test":
    controller.show()
    # packet = pb.pusPacket_t()
    # pb.ret_packets(packet, 13)
    # app.add(packet)

    """
    test purpose below
    """
    # for i in range(12):
    #     packet = pb.pusPacket_t()
    #     pb.ret_packets(packet, i)
    #     app.add(pt.packet2json(packet), packet)
    #     packet0 = pb.pusPacket_t()
    #     pb.pus_tc_17_1_createConnectionTestRequest(packet0, 0, 0)
    #     packet = pb.pusPacket_t()
    #     pb.pus_tm_1_1_createAcceptanceReportSuccess(packet, 0, 0, packet0)
    #     app.add(pt.packet2json(packet), packet)

    code = gui.exec_()
    sys.exit(code)


if __name__ == "__main__":
    main()
