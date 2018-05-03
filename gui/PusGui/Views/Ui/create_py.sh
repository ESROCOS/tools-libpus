rm *.py
touch __init__.py
for file in *.qrc
do
	pyside-rcc -py3 $file -o ${file%.*}_rc.py
	echo  "from . import ${file%.*}_rc" >> __init__.py
done
for file in *.ui
do
	pyside-uic --from-imports $file -o Ui_${file%.*}.py
	echo "from .Ui_${file%.*} import Ui_${file%.*}" >> __init__.py
done
