/*
	Jason Bonilla 2016
	This is testing out how to open, read, write and throw errors with a file.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i,fd,clo,errno;//set up variables
	ssize_t bytesRead,bytesWritten;
	uint8_t buf[1];
	if(argc == 1)//checks to see if there is no files
	{
		while(bytesRead >0)
		{
			bytesRead = read(STDIN_FILENO, buf, 1);
			if(bytesRead == -1)
			{
				perror("Cannot read file");
				exit(errno);
			}
			bytesWritten = write(STDOUT_FILENO, buf, 1);
			if(bytesWritten == -1)
			{
				perror("Cannot read file");
				exit(errno);
			}
		}
	}
	for(i = 1; i < argc;i++)//loop through all files
	{
		fd = open(argv[i],O_RDWR);//open files
		if(fd == -1)
		{
			perror("Cannot open file\n");
			exit(errno);
		}
			bytesRead = read(fd, buf, 1);//reads first byte
			while(bytesRead >0)
			{
				bytesWritten = write(STDOUT_FILENO, buf, 1);//writes the byte
				if(bytesRead == -1)
				{
					perror("Cannot read file\n");
					exit(errno);
				}
				bytesRead = read(fd, buf, 1);//reads again
				if(bytesWritten == -1)
				{
					perror("Cannot write file \n");
					exit(errno);
				}

			}
		clo = close(fd);
		if(clo == -1)
		{
			perror("Cannot close file");
			exit(errno);
		}		
	}
	return 0;
}
