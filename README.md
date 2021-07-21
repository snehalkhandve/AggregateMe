# AggregateMe
A command-line program to peform file operatons. It takes a list of files and clubs them into a single file while keeping track of individual files.

add file1.txt: adds file1.txt to aggregator.txt and deletes original file1.txt

add file2.txt: results in creation of aggregation.txt that has contents of both file1.txt and file2.txt. Order of data is irrelavant. Deletes original file2.txt after its addition to aggregation.txt.

cut file1.txt: This will remove file1.txt from aggregation.txt and create a separate file cut_file1.txt which is exactly same as original file1.txt

copy file2.txt: This will keep file2.txt in the aggregation.txt and create a copy of original file2.txt as copy_file2.txt

copy file3.txt: Adds file3.txt to aggregator.txt and deletes the original.

list: this is a commond without any arguement that lists all the files present in aggregation.txt. Currently file2.txt and file3.txt are present in aggregator.txt and it should list the same.

All the metadata required to perform these operations should also be stored in aggreagation.txt.

The following operations are supported:
1. Adding a new file (add file.txt)
2. Remove a file (cut file.txt)
3. Listing all files(list)
4. Create copy of a file (copy file.txt) 
