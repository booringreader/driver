// file to test the connection between driver and device file

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  // provides functions to interact with POSIX OS api
#include <fcntl.h>  // declares file control operations


int main(){
    int state = open("/dev/mydevice", O_RDONLY); // macros to define the state of opening
                                                 // returns a 'file descriptor' masked as an integer, that is unique for each dev file 
                                                 // lsof or other commands can be used to see list of open files (and their file descriptors)
    if(state == -1){
        printf("device file cannot be opened\n");
        return -1;
    }
    printf("device file opened successfully\n");
    close(state);
    return 0;
}
