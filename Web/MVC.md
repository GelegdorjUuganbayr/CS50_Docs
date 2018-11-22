# MVC
MVC is a programming paradigm that is very commonly-used for web design
- Protect the model from the user
- Abstract away certain details form the user:
  - Not necessary/uninteresting for user
  - Essential for the website to work properly
  - The primary motivation for this is **data security**
  
### Model
- Where the importatn data for site lives
- It may be updated, referenced, or part of the user experience

### View
- The pages the user sees when they are interacting with the site
- Based on interaction with the model

### Controller
- Where the business logic (PHP) of site lives.
- User may submit information to the controller, which will decide what to present to the user.

## Paradigm
```
|User| -Submit-> |Controller| -Queries-> |Model| -Transfer-> |View| -Display-> |User| 
```
- Sperate the data required for the websit
- Seprate from the logic (PHP) that implements the website's functionality
- Seprate from the simple aesthetic and page templates
- Make files that is needed to run the website but, will never be accessed by user
  - 403 Forbidden

### Change the permissions of a file
```
$ chmod <permissions> <file(s)>
```
- octal numbers permissions scheme
  - assigns permissions to three categories of users simultaneously
  - chmod 711 file
    - 7 (you): Assign you the right to read, write, and execute the file
    - 1 (your-group): Allow others to only execute the file.
    - 1 (the world): Allow others to only execute the file.
    
| Octal # 	| Read (r) 	| Write (w) 	| Execute (x_ 	|
|---------	|----------	|-----------	|-------------	|
|    0    	|    No    	|     No    	|      No     	|
|    1    	|    No    	|     No    	|     Yes     	|
|    2    	|    No    	|    Yes    	|      No     	|
|    3    	|    No    	|    Yes    	|     Yes     	|
|    4    	|    Yes   	|     No    	|      No     	|
|    5    	|    Yes   	|     No    	|     Yes     	|
|    6    	|    Yes   	|    Yes    	|      No     	|
|    7    	|    Yes   	|    Yes    	|     Yes     	|

- symbolic permissions scheme
  - assigns permissions to three categories of users simultaneously
  - chmod a+x file
    - +: add/maintain the right
    - x: to execute the file
    - a: to all three categories
    
| Reference 	|  Class 	| Mode 	|  Description  	| Operation 	|       Description       	|
|:---------:	|:------:	|:----:	|:-------------:	|:---------:	|:-----------------------:	|
|     a     	|   all  	|   r  	|  read access  	|     +     	|      add permission     	|
|     g     	|  group 	|   w  	|  write access 	|     -     	|    remove permission    	|
|     o     	| others 	|   x  	| execute acess 	|     =     	| exactly this permission 	|
|     u     	|  user  	|      	|               	|           	|                         	|
    
### Checking the permission of a file
```
$ ls -l
```
### Output
```
drwx-w---- : read write execute
drwx-w---- : read write execute
-rw--w---- : read write
```
d: directory\
-: regular file
