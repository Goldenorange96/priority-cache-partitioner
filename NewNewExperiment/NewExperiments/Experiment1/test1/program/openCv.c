#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <papi.h>
#include <pthread.h>
#define RAM 192




int main ()
{
	
	FILE *fp = NULL;
	char out[30][20];
	int pids[10];
	char pid1 [8];
	char pid2 [8];
	char path [50] = "sudo sh script.sh ";
	int i = 0;
	int index = 0;
	fp = popen("top -bn1 | head  -n8 | tail -n1 | awk '{print$1}'", "r");
	if (fp != NULL)
	{
		while ((fgets (out[i], sizeof(out)-1, fp)) != NULL)
		{
			//printf("%s", out[i]);		
			i++;
		}

	}

	strcat(path, out[0]);
	//printf("%s\n", path );
	system(path);
	
return 0;
}