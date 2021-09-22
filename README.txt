Rares Popa Assignment Readme

Date created: 27/10/2017

Date modified: 27/10/2017

Purpose: Check the spelling of the file which the user provided

Files in project:
	readme.txt
	check.h
    config.c
    config.h
    dictionary.c
    dictionary.h
    linked_list.c
    linked_list.h
    menu.c
    menu.h

Bugs: Linked list acting weird

Errors and how I fixed them:
I was getting many segmentation faults which means I was accessing memory which was not allocated, I went through my code and allocated memory
for the function which had that error, I had many memory leaks too which I fixed by looking through the files and creating free functions to
free up functions when used

What does it do:
This application gets a commandline input from the user and then uses the dictionary file to check the spellings of the words, outputs the
correct spelling for the word to the user.

