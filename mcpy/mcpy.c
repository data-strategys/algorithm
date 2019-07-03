
/******
1.不要破坏传进来的形参，定义新的临时变量来操作
2.考虑指针的类型，不同类型的指针不能直接++赋值
3.overlap情况下需要从高地址处向前copy


******/
#include <stdio.h>
#include <assert.h>

int strlen_d (char *src)
{
int i=0;
while (*src++!='\0')
    i++;
return i;
}

void *mcpy(void *dest, const void *src, size_t count)
{
 char *d;
 const char *s;
 
 if (dest > (src+count)|| (dest < src))
    {
    d = dest;
    s = src;
    while (count--)
        *d++ = *s++;        
    }
 else /* overlap */
    {
    d = (char *)(dest + count - 1); /* offset of pointer is from 0 */
    s = (char *)(src + count -1);
    while (count --)
        *d-- = *s--;
    }
  
 return dest;
}


char *strcpy_d(char *dst,const char *src)
{
	assert(dst != NULL);
	assert(src != NULL);
	char *ret = dst;
	mcpy(dst,src, strlen_d(src)+1); /* strlen确实不计算结尾的*/
	return ret;
}



int main(int argc,const char *argvs[])
{
	const char name="helloworld wenwp";
	char buf[50];
	
	printf("buf:=%s\n",strcpy_d(buf, name));

	return 0;
}





