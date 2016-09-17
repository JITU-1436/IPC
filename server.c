#include"header.h"
#include"request.h"

int main()
{
	struct request r;
	int arr[2], arr1[2], arr2[2], arr3[2], arr4[2], arr5[2];
	int sum, diff, mult;
	int bytes, count, count1,count2,count3,count4,count5,count6, count7, count8, count9, count10;
	int fret1, fret2, fret3, fret4, fret5, fret6;
	char rfdp1[4], wfdp1[4], rfdp2[4], wfdp2[4], rfdp3[4], wfdp3[4], rfdp4[4], wfdp4[4], rfdp5[4], wfdp5[4], rfdp6[4], wfdp6[4];
	
	printf("File: %s, Running\n", __FILE__);
	
	if(pipe(arr) != 0)
	{
		printf("ERROR");
	}
	printf("file descriptors are arr[0]= %d ; arr[1] = %d\n", arr[0], arr[1]);	
	sprintf(rfdp1, "%d", arr[0]);
	sprintf(wfdp1, "%d", arr[1]);
	fret1 = fork();
	switch(fret1)
	{
		case -1:
			perror("fork");
			break;
		case 0:
			printf("child process is running %s\n", __FILE__);
			execl("./client1", "client1", rfdp1, wfdp1, NULL);
			break;
		default:

			printf("%s process Running successfully\n", __FILE__);
			bytes = read(arr[0], &r, sizeof(struct request));
			printf("File: %s Read %d bytes\n", __FILE__, bytes);

			if(pipe(arr1) != 0)
			{
				perror("pipe");	
			}

			printf("File: %s fd of pipe2 arr1[0]= %d ; arr1[1] = %d\n",__FILE__, arr1[0], arr1[1]);	

			sprintf(rfdp2, "%d", arr1[0]);
			sprintf(wfdp2, "%d", arr1[1]);
			sleep(1);
			fret2 = fork();
			switch(fret2)
			{
				case -1:
					perror("fork");
					break;
				case 0:
					printf("File: %s Child 2 Forked\n", __FILE__);
					execl("./adder", "adder", rfdp2, wfdp2, NULL);
					break;
				default:

					count = write(arr1[1], &r, sizeof(struct request));	
                        		printf("File: %s Write %d bytes\n", __FILE__, count);
					sleep(1);
					count1 = read(arr1[0], &sum, sizeof(int));
                        		printf("File: %s Read %d bytes\n", __FILE__, count1);
					sleep(1);
					count2 = write(arr[1], &sum, sizeof(int));	
                        		printf("File: %s Read from pipe 2 and Wrote to pipe 1 %d bytes\n", __FILE__, count2);
					
					// pipe 3;
					if(pipe(arr2) != 0)
					{
						perror("pipe");
					}
					
					printf("File: %s fd's of PIPE 3 arr2[0] = %d ; arr2[1] = %d\n", __FILE__, arr2[0], arr2[1]);

					
					sprintf(rfdp3, "%d", arr2[0]);
					sprintf(wfdp3, "%d", arr2[1]);
					sleep(1);
					fret3 = fork();
					switch(fret3)
					{
						case -1:
							perror("fork");
							break;
						case 0:
							printf("File: %s Child 3 Forked\n", __FILE__);
							execl("./client2", "client2", rfdp3, wfdp3, NULL);
							break;
						default:
							count3 = read(arr2[0], &r, sizeof(struct request));
							printf("File: %s Read %d bytes\n", __FILE__, count3);

		//pipe 4;			
							if(pipe(arr3) != 0)
							{
								perror("pipe");	
							}

							printf("File: %s fd of pipe4 arr3[0]= %d ; arr3[1] = %d\n",__FILE__, arr3[0], arr3[1]);	
	
							sprintf(rfdp4, "%d", arr3[0]);
							sprintf(wfdp4, "%d", arr3[1]);
							sleep(1);
							fret4 = fork();
							switch(fret4)
							{
							    case -1:
								perror("fork");
								break;
							    case 0:
								printf("File: %s Child 4 Forked\n", __FILE__);
								execl("./substract", "substract", rfdp4, wfdp4, NULL);
								break;
							    default:						
								count4 = write(arr3[1], &r, sizeof(struct request));	
        				                	printf("File: %s Write %d bytes\n", __FILE__, count4);
								sleep(1);
								count5 = read(arr3[0], &diff, sizeof(int));
                        					printf("File: %s Read %d bytes\n", __FILE__, count5);
								sleep(1);
								count6 = write(arr2[1], &diff, sizeof(int));	
				                        	printf("File: %s Read from pipe 2 and Wrote to pipe 1 %d bytes\n", __FILE__, count6);
								sleep(1);
								// pipe 5;
								if(pipe(arr4) != 0)
									{
										perror("pipe");
									}
						
								printf("File: %s fd's of PIPE 5 arr4[0] = %d ; arr4[1] = %d\n", __FILE__, arr4[0], arr4[1]);

					
								sprintf(rfdp4, "%d", arr4[0]);
								sprintf(wfdp4, "%d", arr4[1]);
								sleep(1);
								fret5 = fork();
								switch(fret5)
								{
									case -1:
										perror("fork");
										break;
									case 0:
										printf("File: %s Child 5 Forked\n", __FILE__);
										execl("./client3", "client3", rfdp4, wfdp4, NULL);
										break;
									default:
										count7 = read(arr4[0], &r, sizeof(struct request));
										printf("File: %s Read %d bytes\n", __FILE__, count7);
										sleep(1);
								//pipe 6;			
									if(pipe(arr5) != 0)
									{
										perror("pipe");	
									}

									printf("File: %s fd of pipe6 arr5[0]= %d ; arr5[1] = %d\n",__FILE__, arr5[0], arr5[1]);	
	
									sprintf(rfdp6, "%d", arr5[0]);
									sprintf(wfdp6, "%d", arr5[1]);
									sleep(1);
									fret6 = fork();
									switch(fret6)
									{
									    case -1:
										perror("fork");
										break;
									    case 0:
										printf("File: %s Child 6 Forked\n", __FILE__);
										execl("./multiply", "multiply", rfdp6, wfdp6, NULL);
										break;
									    default:						
										count8 = write(arr5[1], &r, sizeof(struct request));	
        				                			printf("File: %s Write %d bytes\n", __FILE__, count8);
										sleep(1);
										count9 = read(arr5[0], &mult, sizeof(int));
                        							printf("File: %s Read %d bytes\n", __FILE__, count9);
										sleep(1);
										count10 = write(arr4[1], &mult, sizeof(int));	
				                        			printf("File: %s Read from pipe 2 and Wrote to pipe 1 %d bytes\n", __FILE__, count10);
										break;
									}
									break;
								}
								break;
							}
							break;		
					}
			}		
			break;
	}
}
