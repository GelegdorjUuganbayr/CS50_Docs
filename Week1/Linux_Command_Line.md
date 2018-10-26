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
$ cp -r [source directory] [destination directory]
```
Use the **"cp"** command to copy files through the command line. It takes two arguments: The first is the location of the file to be copied, the second is where to copy.\
If you wish to copy entire direcory including all the contents inside of it, you can type **"cp -r"**. The **"-r"** stands for recursive ,and tells cp to dive down into the directory and copy everything inside of it.

## mv
```
$ mv [source directory] [detination directory]
$
```
