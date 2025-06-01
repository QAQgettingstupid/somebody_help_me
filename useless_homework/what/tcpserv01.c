#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "/tmp/unp.h"

void show_list(int sockfd) {

    struct dirent* entry;
    DIR* dp;

    // 開啟當前目錄
    dp = opendir(".");
    if (dp == NULL) {
        printf("error \n");
        return;
    }

    char filename[MAXLINE];
    char* msg = "server list member:\n";
    Writen(sockfd, msg, strlen(msg));

    // 讀取並列出目錄內容
    while ((entry = readdir(dp))) {
        snprintf(filename, MAXLINE, "%s\n", entry->d_name);
        Writen(sockfd, filename, strlen(filename));
    }

    msg = "<end>\n";
    Writen(sockfd, msg, strlen(msg));

    closedir(dp);
}

void str_echo(int sockfd)
{
    ssize_t n;
    char line[MAXLINE];

    for (; ; ) {

        if ((n = Readline(sockfd, line, MAXLINE)) == 0)
            return; /* connection closed by other end */
        
        if (!strcmp(line, "exit\n"))
            return;
        else if (strncmp(line, "put ", 4) == 0) {

            char filename[MAXLINE], buffer[MAXLINE];

            // 提取檔案名稱
            sscanf(line + 4, "%s", filename);

            // 創建檔案
            int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);

            if (fd < 0) {
                printf("fail to create\n");
                continue;
            }

            // 接收檔案內容
            ssize_t n;

            while ((n = read(sockfd, buffer, MAXLINE)) > 0) {
                
                char* eof_pos = strstr(buffer, "<EOF>");

                if (eof_pos != NULL) {
                    // 只寫入到 EOF 之前的內容
                    write(fd, buffer, eof_pos - buffer);
                    break; // 收到 EOF，跳出迴圈
                }

                write(fd, buffer, n);
            }

            close(fd);

            char* msg = "file has been updated.\n";

            Writen(sockfd, msg, strlen(msg));
        }
        else if (!strcmp(line, "dir\n")) {
            Writen(sockfd, line, n);
            show_list(sockfd);
        }
        else {
            Writen(sockfd, line, n);
        }
    }
}

int main(int argc, char **argv){

    if (argc != 2) {
        err_quit("usage: tcpserv01 [server port]");
    }

    int port = atoi(argv[1]); // 將埠號從參數轉為整數

    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);

    for ( ; ; ) {
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);

        if ( (childpid = Fork()) == 0) { /* child process */
            Close(listenfd); /* close listening socket */
            str_echo(connfd); /* process the request */
            exit(0);
        }

        Close(connfd); /* parent closes connected socket */
    }
}


