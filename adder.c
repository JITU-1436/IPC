#include<stdio.h>
#include"request.h"

int main(int argc, char *argv[])
{
	struct request add;
	int rfd, wfd, ret, res, byt;
	if(argc != 3)
	{
		printf("Error");
	}
	
	rfd = atoi(argv[1]);
	wfd = atoi(argv[2]);
	printf("File: %s\t rfd = %d\n",__FILE__, rfd);
	printf("File: %s\t wfd = %d\n",__FILE__, wfd);

	ret = read(rfd, &add, sizeof(struct request));
	
	printf("File: %s Read %d bytes from rfd\n",__FILE__, ret);

	printf("File: %s add.oper = %c\n",__FILE__,(char)add.oper);
        printf("File: %s add.opr1 = %d\n",__FILE__, (int)add.opr1);
        printf("File: %s add.opr2 = %d\n",__FILE__, (int)add.opr2);
        res =add.opr1 + add.opr2;
        printf("File: %s res = %d\n",__FILE__, res);
        byt = write(wfd, &res,sizeof(int));
        printf("File: %s Wrote %d bytes\n", __FILE__, byt);	
}
