﻿/*
作者:蔡芳宇
學號:111216019
自評:20%+30%+30%+20% 會動,但不曉得有甚麼我沒看到的bug (´;ω;`)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "/tmp/unp.h"

// 讀server list
void read_slist(int sockfd) {

	char buffer[MAXLINE];

	while (Readline(sockfd, buffer, MAXLINE) != 0) {

		// server_list尾端，跳出迴圈
		if (!strcmp(buffer, "<end>\n")) {
			Fputs(buffer, stdout);
			break; 
		}
		Fputs(buffer, stdout);
	}
}

// 上傳檔案
void update(char* sendline, int sockfd) {
	char filename[MAXLINE];

	// 提取檔案名稱
	sscanf(sendline + 4, "%s", filename);

	// 嘗試開啟檔案
	int fd = open(filename, O_RDONLY);

	if (fd < 0) {
		printf("no such file exist.\n");
		return;
	}
	Writen(sockfd, sendline, strlen(sendline));

	// 傳送檔案內容
	char buffer[MAXLINE];
	ssize_t n;
	while ((n = read(fd, buffer, MAXLINE)) > 0) {
		Writen(sockfd, buffer, n);
	}

	close(fd);

	// 傳送檔案結束註記
	Writen(sockfd, "<EOF>\n", 6);

	// 讀 file has been updated.\n
	Readline(sockfd, buffer, MAXLINE);
	Fputs(buffer, stdout);
}

// 讀 list
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
	printf("<end>\n");
}

void str_cli(FILE* fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		if (!strncmp(sendline, "put ", 4)) {
			update(sendline, sockfd);
		}
		else if (!strcmp(sendline, "exit\n")) {
			printf("Disconnecting from server...\n");
			return;
		}
		else {

			Writen(sockfd, sendline, strlen(sendline));

			if (Readline(sockfd, recvline, MAXLINE) == 0)
				err_quit("str_cli: server terminated prematurely");
			
			//recvline 自帶換行\n
			else if (!strcmp(recvline, "ldir\n"))
				show_list();
			else if (!strcmp(recvline, "dir\n"))
				read_slist(sockfd);
			else
				Fputs(recvline, stdout);
		}
	}
}

int main(int argc, char **argv){

	int sockfd;
	struct sockaddr_in servaddr;

	if (argc != 3)
		err_quit("usage: tcpcli01 [server IP address] [server port]");

	int port = atoi(argv[2]);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	str_cli(stdin, sockfd); /* do it all */
	exit(0);
}

