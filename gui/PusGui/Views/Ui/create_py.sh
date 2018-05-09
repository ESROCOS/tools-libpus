for file in *.ui
do
	pyside-uic $file -o "${file%.*}".py
done
