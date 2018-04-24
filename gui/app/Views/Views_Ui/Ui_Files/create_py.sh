for file in *; do
	if [ "$file" != "create_py.sh" ]; then
		pyside-uic $file -o ../Ui_"${file%.*}".py
	fi 
done
