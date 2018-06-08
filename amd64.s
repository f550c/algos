        .global _start
_start: mov $39,%eax    #system call 39: getpid
        syscall         #call the system
        mov %eax,%edi   #move pid into register edi
        mov $60,%eax    #system call 60: exit
        syscall        
#as -o amd64.o amd64.s
#ld -o amd64 amd64.o
