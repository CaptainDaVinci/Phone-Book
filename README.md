#INTRODUCTION
This is a very basic Phone-Book which can store the first name and the phone number of a person.
It uses Linked List data structure to store the data and then perform various operations on it such as:
* Deleting a contact.
* Sorting them alphabetically.
* adding new contacts.
* Searching a contact.
* Saving the changes to the file **_Phone-Book.txt_**.

##USAGE

###LINUX
First you must give permission to execute the file **build.sh**, then complile and run the code as follows:
```
$ chmod +x build.sh
$ ./build.sh
$ ./phonebook
```

###WINDOWS
Simply compile and run the program as follows:
```
$ gcc main.c add.c delete.c display.c load.c search.c -o phonebook
$ ./phonebook
```

select the option '1' to display all the contacts in "**_Phone-Book.txt_**" file. Notice that these are just example values which can be altered.
