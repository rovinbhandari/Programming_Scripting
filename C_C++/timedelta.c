#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval t_start, t_end;
	double t_elapsed;

	// place START-FLAG
	gettimeofday(&t_start, NULL);

	// place code to measure time delta for
	// ...

	// place END-FLAG
	gettimeofday(&t_end, NULL);

	// compute Time Elapsed in Milliseconds
	t_elapsed = (t_end.tv_sec - t_start.tv_sec) * 1000.0;	// s to ms
	t_elapsed += (t_end.tv_usec - t_start.tv_usec) / 1000.0;	// us to ms

	printf("Elapsed time = %lfms\n", t_elapsed);

	return 0;
}

