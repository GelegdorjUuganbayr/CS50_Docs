# Linux Commands
### pwd
```
$ pwd
```
Present working directory where I am. It gives us the absolute path, which means the path that starts from the root.


### ls
```
$ ls
$ ls-a
```
List of files in the directory you are in. Read all the folder and file in the directory where you are.\
You can see all the hidden files by using the cammand **ls-a**.

### cd
```
$ cd [dir_name]
$ cd
% cd ..
```
To go to a directory, use **"cd"**. This command is case sensitive, so you have to type in the name of the folder exactly as it is.
In case directory name is **"Raspberry Pi"**, you need to type **"cd Raspberry\\ Pi"**.\
To go to home directory, you just need to type **"cd"**.\
To go back from a folder to the folder before that, you can type **"cd .."**. The two dots represet back.

### mkdir
```
$ mkdir [dir_name]
```
When you need to create a folder or directory, you can use **"mkdir"**. To make a directory called **"new_dir"**, you can type **"mkdir new_dir"**.\
If you want to create a directory named **"new dir"**, you can type **"mkdir new\ dir"**.

### rm
```
$ rm [dir_name/file_name]
$ rm -f [file_name]
$ rm -r [dir_name]
$ rm -rf [dir_name]
```
When you need to remove directory, you can use **"rm"**, and this command will delete file after it asks you to confirm (y/n) you want to delet it.\
you can skip the confirmation by typing **"rm -f"**. Consider there is no undo.\
To delete entire directories, you need to use the **"rm -r"**.\
You can also use **"rm -rf"** to delete entire directories without confirmation.

### touch
```
$ touch [file_name]
```
To create a file, you can use **"touch"**. The format can be anything from empty txt file to an empty zip file. For example you can create new text file by typing **"touch new.txt"**.

### cp
```
$ cp [location of the file to be copied] [where to copy]
$ cp -r [src_dir] [dest_dir]
```
Use the **"cp"** command to copy files through the command line. It takes two arguments: The first is the location of the file to be copied, the second is where to copy.\
If you wish to copy entire direcory including all the contents inside of it, you can type **"cp -r"**. The **"-r"** stands for recursive ,and tells cp to dive down into the directory and copy everything inside of it.

### mv
```
$ mv [src] [dest]
```
**"mv"** command will allow you to **rename a file**, or **move** it from [src] to [destination].\

## Intermediate Commands
### echo
```
$ echo [string you want to put] >> [file_name]
```
**"echo"** is usually used to put text into a file. For example, if you want to create a new text file or add to an already exist text file, you just need to type **"echo hello, my name is Ha >> new.txt"**. This does not require back slash for space.

### cat
```
$ cat [file_name]
```
Command **"cat"** is used to display the contents of a file. It is usually used to easiliy view programs.

### sudo
```
$ sudo [command]
```
A widely used command in the Linux command line, sudo stands for **"SuperUser Do"**. So, if you want any command to be done with administrative or root privileges, you can use the sudo command.

### df
```
$ df
$ df -m
```
**"df"** command to see the available disk space in each of the partitions in your system. This will allow you to see each mounted partition and their used/available space in % and in KBs.\
If you want it shown in megabytes, you can use the command **"df -m"**.

### du
```
$ du [dir_name/file_name]
```
**"du"** is used to know the disk usage of a file in your system. To know the disk usage for a particular folder or file, you can type **"du folder/file_name"**. For example, if you want to know the disk space used by the documents folder in Linux, you can use the command **"du Documents"**. You can also use the command “ls -lah” to view the file sizes of all the files in a folder.
