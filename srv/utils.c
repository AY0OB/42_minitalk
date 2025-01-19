#include "../include/minitalk.h"

void	Signal(int signal, void *handler, bool use_siginfo)
{
	struct sigaction	sa = {0};

	// met la fonction "handler" dans la struct
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;


	sigemptyset(&sa.sa_mask);

	if (sigaction(signal, &sa, NULL) < 0)
	{
		perror("Sigaction failed");
		exit(0);
	}
}
