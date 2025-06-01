#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "/tmp/unp.h"

void show_list() {

	struct dirent* entry;
	DIR* dp;

	// 開啟當前目錄
	dp = opendir(".");
	if (dp == NULL) {
		printf("error \n");
		return;
	}

	// 讀取並列出目錄內容
	printf("list member:\n");
	while ((entry = readdir(dp))) {
		printf("%s\n", entry->d_name);
	}

	closedir(dp);
}

void str_cli(FILE * fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {
		Writen(sockfd, sendline, strlen(sendline));

		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		//recvline 自帶換行\n
		if (!strcmp(recvline, "ldir\n")) {
			show_list();
		}
		else {
			Fputs(recvline, stdout);
		}
	}
}