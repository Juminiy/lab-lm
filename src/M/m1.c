#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int get_cur_pid() {
  return getpid();
}

int main(int argc, char *argv[]) {
  // for (int i = 0; i < argc; i++) {
  //   assert(argv[i]); // C 标准保证
  //   printf("argv[%d] = %s\n", i, argv[i]);
  // }
  // assert(!argv[argc]); // C 标准保证

  char * file_name = argv[1];  
  printf("arg = %s\n",file_name);
  FILE *fp = fopen(file_name, "r");
  
  // file_name == "/proc/meminfo"
  if ( fp ) {
    // 用fscanf, fgets等函数读取
    char * cat_name , * cat_data , *_line;
    while ( fgets( _line , 27 , fp ) ) { 
      puts( _line ) ; 
    } 
    fclose(fp);
  } else {
    // 错误处理
  }

  return 0;
}