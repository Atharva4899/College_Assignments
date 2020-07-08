#! /bin/sh

display() {
	echo "\n-------------------STUEDNT DATA--------------------"
	echo "\nName\tRoll Number\tMob Number\n"
	cat student.txt
	echo "\n---------------------------------------------------"

}

insert() {
	echo "\nEnter Details :-"
	
	echo "\nEnter Name :-\c"
	read sname

	echo "\nEnter Roll Number :-\c"
	read roll

	echo "\nEnter Mobile Number :-\c"
	read mob

	echo $sname"\t"$roll"\t\t"$mob >> student.txt

	echo "\nRecord Inserted Successfully!"
}

search() {
	echo "\nEnter Roll Number to be searched:"
	read roll

	echo "\nName\tRoll Number\tMob Number\n"

	grep -w $roll student.txt
}

delete() {
	echo "\nEnter Roll Number to be deleted:"
	read roll

	grep -v $roll student.txt > temp.txt
	#sed "/"$roll"/d" student.txt > temp.txt
	mv temp.txt student.txt

	echo "\nRecord deleted Successfully!!"
}

modify() {
	echo "\nEnter Roll number: \c"
	read r1

	echo "\nEnter new name:-\c"
	read name
	
	sed -i "/$r1/c\\$r1 $name" student.txt
	#mv temp.txt student.txt

	echo "\nData Modified!!"
}

while(true)
	do
	echo "\n-----------------STUEDNT DATABASE------------------\n"
	echo "1.Insert Record  \n"
	echo "2.Display Record \n"
	echo "3.Search Record  \n"
	echo "4.Delete Record  \n"
	echo "5.Modify Record  \n"
	echo "6.Exit"
	echo "\n---------------------------------------------------"
	echo "\nEnter your choice:-\c"
	read choice

		case "$choice" in
				1) insert;;
				2) display;;
				3) search;;
				4) delete;;
				5) modify;;
				6) exit;;
				*) echo "\nYou entered wrong choice"
		esac 
	done
