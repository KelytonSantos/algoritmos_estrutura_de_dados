#include <stdio.h>
#include <string.h>

int main()
{
    char line[1001];
    while (fgets(line, sizeof(line), stdin))
    {
        int freq[128] = {0};
        int len = strlen(line);
        // Count frequencies, ignore '\n' and '\r'
        for (int i = 0; i < len; i++)
        {
            unsigned char c = line[i];
            if (c != '\n' && c != '\r')
            {
                freq[c]++;
            }
        }
        // Prepare output: sort by frequency asc, then ASCII desc
        // Find all present characters
        int chars[128], count = 0;
        for (int i = 0; i < 128; i++)
        {
            if (freq[i] > 0)
            {
                chars[count++] = i;
            }
        }
        // Sort
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (freq[chars[i]] > freq[chars[j]] ||
                    (freq[chars[i]] == freq[chars[j]] && chars[i] < chars[j]))
                {
                    int tmp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = tmp;
                }
            }
        }
        // Print
        for (int i = 0; i < count; i++)
        {
            printf("%d %d\n", chars[i], freq[chars[i]]);
        }
        printf("\n"); // Blank line between outputs
    }
    return 0;
}