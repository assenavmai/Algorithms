#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * preprocess(char * str);
void manacher(char * str,  const char * t);
int min(int x, int y);

int main(int argc, char const *argv[])
{
    char t[100] = "TCTATAGTCTACCTCACAGTCGATTTT";
    const char * str;

    str = preprocess(t);
    manacher(t, str);

    return 0;
}

/*adds a # between each character in the string and a start and end char*/
const char * preprocess(char * str)
{
    int i, ctr, len = 0;
    char * c;
    char ch[100];

    len = strlen(str);

    if(len == 0)
    {
        return "^$";
    }

    c = malloc(sizeof(char) * len + 10);

    ctr = 0;

    /*since we are skipping positions, we need to run this for 2x longer*/
    for(i = 0; i < len*2; i++)
    {
        if(i == 0)
        {
            ch[i] = '^';
        }
        else
        {
            ch[i] = '#';
            i++;
            ch[i] = str[ctr];
            ctr++;
        } 
    }
    ch[i] = '#';
    i++;
    ch[i] = '$';

    strcpy(c, ch);

    return c;
}

/*to get longest palindrome*/
void manacher(char * str,  const char * t){

    int len = 0, centerID,center, right, left, size, end, start,i, iprime;
    int arr[1000] = {0};

    t = preprocess(str);

    len = strlen(t);
    center = 0;
    right = 0;

   centerID = 1;

   for(i = 0; i < len - 1; i++)
   {
        /*get i' which is the value that mirror i over the center*/
        iprime = 2 * center - i;

        if(right > i)
        {
            arr[i] = min(right - i, arr[iprime]);
        }
        else
        {
            arr[i] = 0;
        }

        /*finding the expansion on both sides of the sequence from centered position*/
        while(t[i+1 + arr[i]] == t[i - 1 - arr[i]])
        {
            arr[i]++;
        }

        /*keeping track of the size*/
        if(arr[i] > arr[centerID])
        {
            centerID = i;
        }

        /*expand after the right position and adjust the center positon*/
        if(i + arr[i] > right)
        {
            center = i;
            right = i + arr[i];
        }
   }

    size = arr[centerID];
    start = (centerID - 1 - size)/2; /*palindrome start position*/
    end = start + size - 1;

    len = 0;
    /*print out the longest palindrome*/
    for(i = start; i <= end; i++)
    {
        printf("%c", str[i]);
        len++;
    }
    printf("\n");
    printf("Length of palindrome: %d\n", len);
}

/*get the minimum of 2 values*/
int min(int x, int y){

    int z;

    z = x;

    if(y < x)
    {
        z = y;
    }

    return z;
}