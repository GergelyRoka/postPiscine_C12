#include "ft_list.h"
#include <string.h>

char	**mf_creat_str_list()
{
	char	**p;

	if(!(p = malloc(sizeof(char*) * 3)))
		return (p);
	//missing malloc check
	p[0] = malloc(sizeof(char)*4);
	strcpy(p[0],"sor");
	p[1] = malloc(sizeof(char)*4);
	strcpy(p[1],"bor");
	p[2] = malloc(sizeof(char)*8);
	strcpy(p[2],"palinka");

	return (p);
}
