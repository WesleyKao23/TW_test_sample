//add to server

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUM(x, y) (x) + (y)
#define PRODUCT(x, y) x * y
#define ARR_MAX_SIZE 100

//static int f = 20;
void merge(int *arr, int left, int right)
{
  int mid = (left + right) / 2;
  int i = left;
  int j = mid + 1;
  int k = left;
  int temp[ARR_MAX_SIZE];

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]){
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    temp[k] = arr[i];
    k++;
    i++;
  }

  while (j <= right) {
    temp[k] = arr[j];
    k++;
    j++;
  }

  int l;
  for (l = left; l <= right; l++)
    arr[l] = temp[l];
}

void merge_sort(int *arr, int left, int right)
{
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, right);
  }
}

void q_sort(int *arr, int left, int right)
{
  if (left < right) {
    int i = left + 1;
    int j = right;
    int pivot = arr[left];
    int temp;

    while (1) {
      while (arr[i] < pivot && i <= right)
          i++;

      while (arr[j] > pivot && j > left)
          j--;

      if (i < j) {
          temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
      } else
          break;
    }

    temp = arr[j];
    arr[j] = arr[left];
    arr[left] = temp;

    q_sort(arr, left, j - 1);
    q_sort(arr, j + 1, right);
  }
}

int sum_r(int n)
{
  if(n == 0) return 0;
  if(n == 1) return 1;

  return n + sum_r(n-1);
}

void swap_by_pointer(int *c, int *d)
{
  int temp = *c;
  *c = *d;
  *d = temp;
}

void static_var_test()
{
	static int static_var = 0;
	printf("static_var[1]:%d\n", static_var);
	static_var++;
	printf("static_var[2]:%d\n", static_var);
}

int funC(int n)
{
	if(n <= 1)
		return 0;

	return n*(n-1) + funC(n-1);
}

int funC_NR(int n)
{
	if(n <= 1)
		return 0;

	int i;
	int res = 0;
	for(i = n;i >= 2;i--){
		res += i * (i-1);
	}

	return res;
}

int factorial(int n)
{
	if(n == 1)
		return 1;

	return n * factorial(n-1);
}

int fib_print_find(int n)
{
	int i, fn, fn1, fn2;
	fn2 = 0; //start by 0 or 1
	fn1 = 1;

	if(n == 1){
		printf("%d", fn2);
		return fn2;
	}
	if(n == 2){
		printf("%d %d", fn2, fn1);
		return fn1;
	}

	printf("%d %d ", fn2, fn1);

	for(i = 3;i <= n;i++){
		fn = fn2 + fn1;
		printf("%d ", fn);
		fn2 = fn1;
		fn1 = fn;
	}

	return fn;
}

int fib_r(int n)
{
	//start by 1
	/*if(n<=2)
		return 1;*/

	//start by 0
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;

	return fib_r(n-1)+fib_r(n-2);
}

size_t stringLength(const char *str)
{
  //not include '\0'
  size_t length = 0;
  while(*str++)
    length++;

  return length;
}

int reverse(int n) {
    int reversedNum = 0;
    int remainder = 0;

    while(n)
    {
        remainder = n%10;
        reversedNum = reversedNum*10 + remainder;
        n = n / 10;
    }
    return reversedNum;
}

int reverse_r(int n) {
    static int reversedNum = 0; //key point 'static', keep value
    int remainder = 0;

    if (n == 0) 
      return 0;

    remainder = n%10;
    reversedNum = reversedNum*10 + remainder;

    reverse_r(n/10);
    return reversedNum;
} 

int stringCompare(char *str1,char *str2){
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         return 1;
    else
         return 0;
}

int stringCompare2(char *str1,char *str2){
    int i=0;

    while(str1[i] == str2[i]){
         printf("count:%d", i);
         if(str1[i] == '\0'){
             return 1;
         }
         i++;
    }

    return 0;
}

void reverse_array(int *arr, int size)
{
  int start = 0;
  int end = size - 1;
  int temp, i;

  while(start < end){
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }

  //for(i = 0;i < size;i++){
  //  printf("%d ", arr[i]);
  //}
}

char* reverse_string(char *str_ori)
{
   int size = strlen(str_ori);
   int i = 0;
   int j = size - 1;
   char temp;
   char *buf;

   buf = (char *)malloc((size + 1) * sizeof(char));
   strncpy(buf, str_ori, size + 1);
   buf[size] = '\0';

   while (i < j) {
      temp = buf[i];
      buf[i] = buf[j];
      buf[j] = temp;
      i++;
      j--;
   }

   return buf;
}

void reverse_array_print_r(int *arr, int size)
{
  if(size == 0){
    return;
  }else{
    printf("%d ", arr[size-1]);
    reverse_array_print_r(arr, size - 1);
  }
}

void print_binary_num(int num)
{
  int arr[10];
  int i = 0;

  if(num == 0){
    printf("0");
    return;
  }


  while(num > 0){
    arr[i] = num % 2;
    i++;
    num = num / 2;
  }

  int j;
  for(j = i-1;j>=0;j--)
    printf("%d ", arr[j]);

}

void p_to_p(int **num){

  printf("%s: num=%p\n", __func__, num);
  printf("%s: &num=%p\n", __func__, &num);
  printf("%s: *num=%p\n", __func__, *num);
  printf("%s: **num=%d\n", __func__ ,**num);
  printf("-----\n");

  static int f = 20; //avoid wrong value when exit scope
  int *fp = &f;
  int **fpp = &fp;

  printf("%s: f=%d\n", __func__, f);
  printf("%s: &f=%p\n", __func__, &f);
  printf("%s: fp=%p\n", __func__, fp);
  printf("%s: &fp=%p\n", __func__, &fp);
  printf("%s: *fp=%d\n", __func__, *fp);
  printf("%s: fpp=%p\n", __func__ ,fpp);
  printf("%s: &fpp=%p\n", __func__ ,&fpp);
  printf("%s: **fpp=%d\n", __func__ ,**fpp);

  //num = fpp;
  *num = fp;

}

int get_channel2(char* input, char* output){

  if(strcmp(input, "7") == 0)
    sprintf(output, "%d", 100);
  else if(strcmp(input, "9") == 0)
    snprintf(output, 4, "%d", 200);
  else if(strcmp(input, "11") == 0)
    sprintf(output, "%d", 300);
  else
    sprintf(output, "%s", "UNKNOW");

  //key: snprintf' size parameter include '\0'

  return 1;
}

int get_bit7(int x)
{
  //128 64 32 16 | 8 4 2 1
  return x>>7 & 1;  
}

void set_bit5(int *x)
{
  //128 64 32 16 | 8 4 2 1
  *x |= (1<<5);  
}

void clear_bit_of_input(int *input, int bit)
{
  //128 64 32 16 | 8 4 2 1
  *input &= ~(1<<bit); 
}

void s_cpy(char* output, char* input)
{
    if(!input || !output){
      printf("NULL\n");
      return;
    }

    int i = 0;
    while(input[i]){
      output[i] = input[i];
      //printf("copy:%c\n", input[i]);
      i++;
    }
    output[i] = '\0';
}

int main(void)
{
  /*int m = 15;
  int count = 0;
  while (m) {
    count++;
    m = m & (m - 1);
    printf("m:%d\n", m);
  }
  printf("count:%d\n", count);*/
  int (*a)[10];
  //printf("ans:%lu\n", sizeof(a));
  //(0) bitwise+++
  //printf("get-bit7:%d\n", get_bit7(129));
  //int bit5test = 0;
  //set_bit5(&bit5test);
  //printf("after-set-bit5:%d\n", bit5test);
  //int bit_clear = 96;
  //clear_bit_of_input(&bit_clear, 5);
  //printf("after-clear-bit:%d\n", bit_clear);
  //(0) bitwise---

  //(1) sizeof test +++
  //printf("sizeof(byte):%lu\n", sizeof(byte));
  /*printf("sizeof(float):%lu\n", sizeof(float));
  printf("sizeof(int):%lu\n", sizeof(int));
  printf("sizeof(short):%lu\n", sizeof(short));
  printf("sizeof(long int):%lu\n", sizeof(long int));
  printf("sizeof(long double):%lu\n", sizeof(long double));
  printf("sizeof(unsigned int):%lu\n", sizeof(unsigned int));
  printf("sizeof(unsigned char):%lu\n", sizeof(unsigned char));
  printf("sizeof(unsigned short):%lu\n", sizeof(unsigned short));*/

  /*char str[] = "wesleykao";
  char *p = str;
  short sn = 5566;
  int n = 5566;
  double dn = 55.66;
  float ln = 55.66;
  char c1 = 'A';
  printf("sizeof(char str[] = \"wesleykao\"):%lu\n", sizeof(str));
  printf("sizeof(char *p = str):%lu\n", sizeof(p));
  printf("sizeof(int n = 5566):%lu\n", sizeof(n));
  printf("sizeof(short sn = 5566):%lu\n", sizeof(sn));
  printf("sizeof(double dn = 55.66):%lu\n", sizeof(dn));
  printf("sizeof(float ln = 55.66):%lu\n", sizeof(ln));
  printf("sizeof(char c1 = 'a'):%lu\n", sizeof(c1));
  int arr[] = {33,2,6,4,5,3,20};
  int *ptr = arr;
  int arr_size, i = 0;
  arr_size = sizeof(arr)/sizeof(int);
  printf("sizeof(arr):%lu\n", sizeof(arr));
  printf("arr_size:%d\n", arr_size);*/
  //(1) sizeof test ---

  //(2) array pointer test +++
  //int arr[] = {11,22,33,44,55,66,77,88};
  //printf("arr[] = {11,22,33,44,55,66,77,88}\n");
  //int *ptr = arr;
  //printf("ptr:%p | arr:%p\n", ptr, arr);
  //printf("*(ptr):%d | arr[0]:%d\n", *(ptr), arr[0]);
  //printf("&ptr:%p | &arr:%p\n", &ptr, &arr);
  //printf("sizeof(ptr):%ld | sizeof(arr):%ld\n", sizeof(ptr), sizeof(arr));
  //printf("sizeof(*ptr):%ld | sizeof(*arr):%ld\n", sizeof(*ptr), sizeof(*arr));
  //printf("sizeof(&ptr):%ld | sizeof(&arr):%ld\n", sizeof(&ptr), sizeof(&arr));
  //printf("sizeof(*(&ptr)):%ld | sizeof(*(&arr)):%ld\n", sizeof(*(&ptr)), sizeof(*(&arr)));
  //printf("*(ptr++):%d\n", *(ptr++));
  //printf("*(++ptr):%d\n", *(++ptr));
  //printf("*(++ptr):%d\n", *(++ptr));

  /*int arr2[] = {6,7,8,9,10};
  int *ptr2 = arr2;
  int i;
  printf("%d\n", *(ptr2+3));
  *(ptr2++);
  *(ptr2++)+= 123;
  *(++ptr2)+= 123;
  printf("=========\nprint arr all: ");
  for(i = 0;i<5;i++)
    printf("%d ", arr2[i]);*/
  //(2) array pointer test ---

  //(4) test base swap +++
  /*int a = 5, b = 6;
  int *ap = &a;
  int *bp = &b;
  swap_by_pointer(ap, bp);
  printf("%d %d\n", a, b);*/
  //(4) test base swap ---

  /*//(5) Array pointer +++
  int* arr1[8]; //array cpntain array and sizs is 8, so size is (pointer size*8)
  //ps1:arr1[] first => * second
  printf("sizeof(arr1):%lu\n", sizeof(arr1));

  int (*arr2)[8]; //just 1 pointer for int array, so size is 1 pointer size
  printf("sizeof(arr2):%lu\n", sizeof(arr2));

  int *(arr3[8]); //8 pointers
  //same as ps1
  printf("sizeof(arr3):%lu\n", sizeof(arr3));
  //(5) Array pointer ---*/

  //(6) union +++
  /*int i;
  union {
  	int num;
  	unsigned char n[9];
    double n2[2];
  }q;
  //memset(&q, 0, sizeof(q));
  printf("sizeof(int):%lu\n", sizeof(int));
  printf("sizeof(char):%lu\n", sizeof(char));
  printf("sizeof(q.n):%lu\n", sizeof(q.n));
  printf("sizeof(q.num):%lu\n", sizeof(q.num));
  printf("sizeof(q):%lu\n", sizeof(q));*/
  /*q.num = 256;
  for(i = 0;i < 4;i++){
  	printf("%x ", q.n[i]);
  }*/
  //(6) union ---

  //(7) n*n-1 sum +++
  //printf("(r  version) n*n-1 sum:%d\n", funC(2));
  //printf("(nr version) n*n-1 sum:%d\n", funC_NR(2));
  //(7) n*n-1 sum ---

  //(8) macro test +++
  /*int sum_ans = 0;
  int product_ans = 0;
  sum_ans = 10 * SUM(8, 2);
  product_ans = PRODUCT(2+3, 5);
  printf("sum_ans:%d | product_ans:%d\n", sum_ans, product_ans);*/
  //(8) macro test ---

  //(9) fibonacci +++
  //fib_print_find(8);
  //printf("find fib(8):%d", fib_r(8));
  //(9) fibonacci ---

  //(10) factorial +++
  //printf("find factorial(8):%d", factorial(8));
  //(10) factorial ---

  //(11) static test +++
  //static_var_test();
  //static_var_test();
  //static_var_test();
  //(11) static test ---

  //(12) stringLength +++
  //printf("length:%zu\n", stringLength("wesley"));
  //(12) stringLength ---

  //(13) number reverse +++
  //printf("%d\n", reverse(123045));
  //printf("%d\n", reverse_r(123045));
  //char *rev = "wesleykao";
  //char *ans = reverse_string(rev);
  //printf("%s", ans);
  //free(ans);
  //(13) number reverse ---

  //(14) string compare +++
  //printf("%d\n", stringCompare("1", "1"));
  //printf("\nANS:%d\n", stringCompare2("12", "1"));
  //(14) string compare ---

  //(15) reverse array +++
  //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //reverse_array(arr, sizeof(arr)/sizeof(arr[0]));
  //printf("\n");
  //int i;
  //for(i = 0;i < 10;i++){
  //  printf("%d ", arr[i]);
  //}
  //reverse_array_print_r(arr, sizeof(arr)/sizeof(arr[0]));
  //(15) reverse array ---

  //(16) print binary num +++
  //print_binary_num(0);
  //(16) print binary num ---

  //(17) pointer to pointer +++
  /*int v1 = 10;
  int *v1p = &v1;
  int **v1pp = &v1p;
  printf("%s: v1=%d\n", __func__, v1);
  printf("%s: &v1=%p\n", __func__, &v1);
  printf("-----\n");
  printf("%s: v1p=%p\n", __func__, v1p);
  printf("%s: &v1p=%p\n", __func__, &v1p);
  printf("%s: *v1p=%d\n", __func__, *v1p);
  printf("-----\n");
  printf("%s: v1pp=%p\n", __func__, v1pp);
  printf("%s: &v1pp=%p\n", __func__, &v1pp);
  printf("%s: *v1pp=%p\n", __func__, *v1pp);
  printf("%s: **v1pp=%d\n", __func__, **v1pp);
  printf("BEFORE=========================\n");
  p_to_p(v1pp);
  printf("AFTER===[*num = fp;]===========\n");
  printf("%s: v1=%d\n", __func__, v1);
  printf("%s: &v1=%p\n", __func__, &v1);
  printf("-----\n");
  printf("%s: v1p=%p\n", __func__, v1p);
  printf("%s: &v1p=%p\n", __func__, &v1p);
  printf("%s: *v1p=%d\n", __func__, *v1p);
  printf("-----\n");
  printf("%s: v1pp=%p\n", __func__, v1pp);
  printf("%s: &v1pp=%p\n", __func__, &v1pp);
  printf("%s: *v1pp=%p\n", __func__, *v1pp);
  printf("%s: **v1pp=%d\n", __func__, **v1pp);*/
  //(17) pointer to pointer ---

  //(18) channel Q+++
  /*char *freq = (char *)malloc(4*sizeof(char));
  memset(freq, 0, 4*sizeof(char));
  get_channel2("9" ,freq);
  printf("freq:%s\n", freq);*/
  //(18) channel Q---

  //(19) sum_r +++
  //printf("sum_r:%d",sum_r(5));
  //(19) sum_r ---

  //(20) str cpy+++
  /*char *buf = (char*)malloc(7*sizeof(char));
  char *input_s = "wesley";
  s_cpy(buf, input_s);
  printf("%s\n", buf);
  free(buf);*/
  //free(input_s); //wrong
  //(20) str cpy---

  //(21) quick sort+++
  //int arr[10] = {3, 6, 2, 7, 10, 9, 1, 8, 5, 4};
  //int arr_size = sizeof(arr)/sizeof(int);
  //q_sort(arr, 0, arr_size - 1);
  //int i;  
  //for (i = 0; i < arr_size; i++) {
  //  printf("arr[%d]:%d\n", i, arr[i]);
  //}
  //(21) quick sort---

  //(22) merge sort+++
  int arr[10] = {3, 6, 2, 7, 10, 9, 1, 8, 5, 4};
  int arr_size = sizeof(arr)/sizeof(int);
  merge_sort(arr, 0, arr_size - 1);
  int i;  
  for (i = 0; i < arr_size; i++) {
    printf("arr[%d]:%d\n", i, arr[i]);
  }
  //(22) merge sort---

#define SET_BIT(x, n) ( (x) |= (1<< (n)) )
#define CLR_BIT(x, n) ( (x) &= (~(1<< (n))))
#define CHK_BIT(x, n) ( ((x) & (1<< (n)))!=0 )
#define FLIP_BIT(x, n) ( (x) ^= (1<< (n)) )

  /*int bitTest = -0;
  //bitTest |= 0<<3;
  int value = 6;
  value  = (bitTest>>1) & 1;
  printf("value:%d",value);*/

  /*unsigned long v1 = 0x00001111;
  unsigned long v2 = 0x00001202;
  unsigned long v;
  v = v1&(~v2);
  v = v|v2;
  printf("%lx", v);*/

  printf("\n");
  return 0;
}
