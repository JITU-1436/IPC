#include<stdio.h>
#include"request.h"

int main(int argc, char *argv[])
{
	struct request req;
	int rfd, wfd, ret, buff, count;

	if(argc != 3)
	{
		printf("Error");
	}
	
	rfd = atoi(argv[1]);
	wfd = atoi(argv[2]);
	printf("rfd = %d\n", rfd);
	printf("wfd = %d\n", wfd);
	
	req.oper = '*';
	req.opr1 = 20;
	req.opr2 = 2;	

	printf("req.oper = %c\n", req.oper);	
	printf("req.opr1 = %d\n", req.opr1);	
	printf("req.opr2 = %d\n", req.opr2);

	ret = write(wfd, &req, sizeof(struct request));
	printf("File: %s Wrote %d bytes to wfd\n",__FILE__, ret);

	count = read(rfd, &buff, sizeof(int));
        printf("File: %s Read %d bytes from rfd\n",__FILE__, count);
        printf("File: %s Result recieved = %d\n",__FILE__, buff);
	
}
