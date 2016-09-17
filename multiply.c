#include<stdio.h>
#include"request.h"

int main(int argc, char *argv[])
{
	struct request mult;
	int rfd, wfd, ret, res, byt;
	if(argc != 3)
	{
		printf("Error");
	}
	
	rfd = atoi(argv[1]);
	wfd = atoi(argv[2]);
	printf("File: %s\t rfd = %d\n",__FILE__, rfd);
	printf("File: %s\t wfd = %d\n",__FILE__, wfd);

	ret = read(rfd, &mult, sizeof(struct request));
	
	printf("File: %s Read %d bytes from rfd\n",__FILE__, ret);

	printf("File: %s mult.oper = %c\n",__FILE__,(char)mult.oper);
        printf("File: %s mult.opr1 = %d\n",__FILE__, (int)mult.opr1);
        printf("File: %s mult.opr2 = %d\n",__FILE__, (int)mult.opr2);
        res =mult.opr1 * mult.opr2;
        printf("File: %s res = %d\n",__FILE__, res);
        byt = write(wfd, &res,sizeof(int));
        printf("File: %s Wrote %d bytes\n", __FILE__, byt);	
}
