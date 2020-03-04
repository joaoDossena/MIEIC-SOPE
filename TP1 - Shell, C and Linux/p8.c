#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <string.h>


int main(int argc, char* argv[], char* envp[])
{
	srand(time(NULL));

	clock_t start = clock();
	struct tms start_tms, end_tms;
	times(&start_tms);

	int no = -1, counter = 0;

	while(no != atoi(argv[2]))
	{
		no = rand() % atoi(argv[1]);
		printf("%d: %d\n", counter, no);
		
		counter++;
	}

	clock_t end = clock();
	times(&end_tms);

	

	printf("Real time elapsed: %fms\n", (double)(end - start)*1000/CLOCKS_PER_SEC);
	printf("User time elapsed: %fms\n", (double)(end_tms.tms_utime - start_tms.tms_utime)*1000/CLOCKS_PER_SEC); //Doesn't work
	printf("System time elapsed: %fms\n", (double)(end_tms.tms_stime - start_tms.tms_stime)*1000/CLOCKS_PER_SEC); //Doesn't work

	return 0;
}