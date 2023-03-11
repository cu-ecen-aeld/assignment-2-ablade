#include <stdio.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/*
3. Write a C application “writer” (finder-app/writer.c)  which can be used as an alternative to the “writer.sh” test script created in assignment1 and using File IO as described in LSP chapter 2.  See the Assignment 1 requirements for the writer.sh test script and these additional instructions:

One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

Setup syslog logging for your utility using the LOG_USER facility.

Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

Use the syslog capability to log any unexpected errors with LOG_ERR level.
*/

int main(const int argc,const char** argv)
{
	int fd;
	ssize_t nr;
	//Check that we have a least 2 arguments provided
	if(argc < 3)
	{
	  printf("You must provide 2 arguments:\n1. The filename\n2. The word to write to the file\n");
	  return 1;
	}	
	//Set up syslog logging
	openlog("Assignment 2",LOG_CONS,LOG_USER);
	//Open file
	fd = creat(argv[1], 0644);
	if (fd == -1){
		syslog(LOG_ERR,"%s : %s ",argv[1],strerror(errno));
		goto ERROR;
	}
	//Write to the file
	nr = write (fd,argv[2], strlen(argv[2]));
	if (nr == -1){
		syslog(LOG_ERR,"Can't write to the file %s errno : %s ",argv[1],strerror(errno));
		close(fd);
		goto ERROR;

	}

	return 0;
ERROR:
	return 1;
}
