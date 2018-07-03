


if [ "$1" = "local" ]; then
	sed 's/Source_Text/--Source_Text/g' InterfaceView.aadl > interfaceview.aadl.local
elif [ "$1" = "export" ]; then
	sed 's/Source_Text/--Source_Text/g' interfaceview.aadl.local > interfaceview.aadl.export
else
	echo "Error, options are; local / export"
fi
