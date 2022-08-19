#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

#define MAX_LIMIT 50
#define MAX_LINE_LENGTH 70

void print_prompt(); // T
void take_input();
int check_cmd(char *cmd);
void exe_cmd(char *cmd);
void calc(char *expr);
void t();	// T
void path(); // T
void sys();	// ~ 
void put(char *dir_name, char *file_name);
void get();	// T												

int main()
{
	// print_prompt();
	// take_input();
	t();
	return 0;
}

void sys()
{
	struct utsname uname_pointer;
	uname(&uname_pointer);
	printf("System name - %s \n", uname_pointer.sysname);
	printf("Nodename    - %s \n", uname_pointer.nodename);
	printf("Release     - %s \n", uname_pointer.release);
	printf("Version     - %s \n", uname_pointer.version);
	printf("Machine     - %s \n", uname_pointer.machine);
}

void print_prompt()
{
	printf("Welcome to command shell!\n");
}

void tran_cmd(char a[MAX_LIMIT], char b[5])
{
	for (int i = 0; i <= 5; i++)
		b[i] = a[i];
}

void take_input()
{
	printf("Enter command: \n");
	char input[MAX_LIMIT];
	fgets(input, MAX_LIMIT, stdin);
	char cmd[5];
	tran_cmd(input, cmd);
	/*
	if (check_cmd(cmd) == 1)
		exe_cmd(cmd); */
}

int check_cmd(char *cmd)
{
}

void exe_cmd(char *cmd)
{
}

void calc(char *expr)
{
}

void t()
{
	time_t t;  
    time(&t);
    printf("%s\n", ctime(&t));
}

void path()
{
	char directory[MAX_LINE_LENGTH];
	if (getcwd(directory, MAX_LINE_LENGTH) != NULL)
	{
		printf("Current working dir: %s\n", directory);
	}
}

void put(char *dir_nam, char *file_name)
{
}

void get()
{	int count = 0; 
	char *file_name = "main.c";
	char line[MAX_LINE_LENGTH] = {0};
	FILE *infile = fopen(file_name, "r");
	if (infile == NULL)
	{
		printf("Cannot open file");
		exit(1);
	}
	while (fgets(line, 60, infile) != NULL)
	{
		printf("%s\n", line);
		count++;
		if (count%40 == 0)
			getchar();
	}
	fclose(infile);
}

