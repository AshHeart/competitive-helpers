
#include <stdio.h>
#include <stdlib.h>

char *getln()
{
	char *line = NULL, *tmp = NULL;
	size_t size = 0, index = 0;
	int ch = EOF;

	while(ch) {
		ch = getc(stdin);

		if (ch == EOF || ch == '\n')
			ch = 0;

		if (size <= index) {
			size += sizeof(char);
			tmp = realloc(line, size);
			if (!tmp) {
				free(line);
				line = NULL;
				break;
			}

			line = tmp;
		}

		line[index++] = ch;
	}

	return line;
}

void main() {
	char *line = getln();

	printf("%s\n", line);
}
