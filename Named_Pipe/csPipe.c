#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> // file control
#include <errno.h> // it defines global variable 'errno' and the constants for which show the error status
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> // it include definitions pid_t, mode_t and etc..
#include <sys/stat.h> // it define the functions that are associated with data type, sturcture, constants for checking the file status
#define MAXLINE 4096
#define STDOUT_FILENO 1
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | O_CREAT | O_TRUNC)

int main(){
	int Cfd;
	int status;
	int terminatedPid;
	int Sfd;
	pid_t childpid;// pid_t : used for process IDs and process group IDs
	int len; // byte number to read or len of str
	//size_t n;
	int n;
	char FIFO1[MAXLINE];
	char access_type;
	char msg[MAXLINE];
	char str[MAXLINE];
	char clear;
	int re = 0;

	printf("file name : ");
	fgets(FIFO1, MAXLINE, stdin);
	FIFO1[strlen(FIFO1)-1] = '\0';
	while(1){
		printf("file access type(r/w) : ");
		scanf("%c", &access_type);
		if( access_type == 'r'){
			scanf("%*c", &clear);
			printf("byte number to read : ");
			scanf(" %d", &len);
			scanf("%*c", &clear);
		}
		else if( access_type == 'w'){
			scanf("%*c", &clear);
			printf("input : ");
			fgets(str, MAXLINE, stdin);
			len = strlen(str);
			if(str[len-1 == '\n']){
				str[len-1] = '\0';
				len--;
			}
		}

		else{
			printf("type the correct access type\n");
			// handle
		}
		if((childpid=fork()) == 0){
			/* server */
			if(re == 0){
				if ((mkfifo(FIFO1,FILE_MODE)) < 0){
					printf("can't create %s \n mkfifo() failed\n",FIFO1);
					exit(1);
				}
			}
			usleep(150);
			if((Sfd = open(FIFO1,O_RDWR)) < 0){
				printf("(server)file open error\n");
				exit(1);
			}
			printf("Already opened the file(server)\n");
			close(Sfd);
			if(access_type == 'r'){
				while((n=read(Sfd, msg, MAXLINE) > 0)){
					write(Sfd, msg, n);
				}
			}
			else if(access_type == 'w'){
				printf("The number of bytes that user wroted : %d\n", len);
			}
			printf("Ready to terminated\n");
			return 1;
		}
		usleep(100);
		if(access_type == 'w'){
			if((Cfd = open(FIFO1,O_WRONLY)) < 0){
				printf("file open error\n");
				return -1;
			}
			write(Cfd, str,strlen(str));
			close(Cfd);
			terminatedPid=wait(&status);
			printf("parent process wait process %d, status %d\n", terminatedPid, status);
			printf("child process end\n\n");
			re++;
		}

	}
}
