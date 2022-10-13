### Femto Shell Extension #1
#### 1- Executing external commands using fork and exec
#####Built in functions:
- To save local variables
> variableName=variableValue
'''
Example :
	$x=10
	$
'''

- Use 'set' to show all stored local variables.
'''
Example :
	 $ set
	local_vars[0] : x = 10
	local_vars[1] : y = 15
	local_vars[2] : z = 20
'''

- Use 'export' to export local variable to environment variables.
'''
Example :
	$ export x
	$ env
	....................
	x=10
'''

- Use 'get' to get the value of a local variable. 
'''
Example :
	$ get x
	local_vars[0] : x = 10
'''

- Use 'getenv' to get the value of an environment variable and store it in local variable.
'''
Example :
	$ getenv 
	x = 10
'''

- Use 'exit' to exit the running shell
'''
Example :
	$ exit
	Shell terminted
'''

- Any other shell command will be forked and run in child process till finish then kill the child process and return to parent process.
'''
Example :
	$ ls
	FemtoShell  FemtoShell.c  README.md
	$ ls -la
	total 60
	drwxr-xr-x 1 mrostom mrostom   512 Oct 13 03:35 .
	drwxr-xr-x 1 mrostom mrostom   512 Oct  7 22:39 ..
	-rw-r--r-- 1 mrostom mrostom 12288 Oct 13 03:45 .README.md.swp
	-rwxr-xr-x 1 mrostom mrostom 21904 Oct 13 03:35 FemtoShell
	-rw-r--r-- 1 mrostom mrostom  8519 Oct 13 03:35 FemtoShell.c
	-rw-r--r-- 1 mrostom mrostom    86 Oct  8 04:56 README.md
'''
