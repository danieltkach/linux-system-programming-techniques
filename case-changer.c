#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[20] = { 0 };
	char newcase[20] = { 0 };

	while(fgets(c, sizeof(c), stdin) != NULL)
	{
		for(int i=0; i<=sizeof(c); i++)
		{
			/* Keep it unchanged if it is not a letter */
			if ((c[i] >= 0 && c[i] <= 64) || c[i] == 126)
			{
				newcase[i] = c[i];
			}

			/* Upper case to lower case */
			if (c[i] >= 65 && c[i] <= 90)
			{
				newcase[i] = c[i] + 32;
			}

			/* Lower case to upper case */
			if (c[i] >= 97 && c[i] <= 122)
			{
				newcase[i] = c[i] - 32;
			}
		}

		printf("%s\n", newcase);
	}

	/* Zero out the arrays so there are no leftovers in the next run */
	memset(c, 0, sizeof(c));
	memset(newcase, 0, sizeof(newcase));
}
