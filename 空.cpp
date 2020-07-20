// 空.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int _tmain(int argc, _TCHAR* argv[])
{

	int inputFd, outputFd;
	char buf[BUF_SIZE];
	ssize_t numRead;

	inputFd = open("data.txt", O_RDONLY);
	if (inputFd == -1) {
		exit(EXIT_FAILURE);
	}
	outputFd = open(
		"data_copy.txt", 
		O_CREAT | O_WRONLY | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
		);
	if (outputFd == -1) {
		exit(EXIT_FAILURE);
	}

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {
		if (write(outputFd, buf, numRead) != numRead) {
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

