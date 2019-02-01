#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
  int fd;
  int rgb[3];
  char line[30];

  fd = open("image.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  snprintf(line, sizeof(line), "P3 512 512 255 \n");
  write(fd,line,strlen(line));

  for(int i = 0; i < 512; i++){
    for(int j = 0; j < 512; j++){
      rgb[0] = j%256;
      rgb[1] = (i*i+j)%256;
      rgb[2] = i%256;

      sprintf(line, "%d %d %d ",rgb[0],rgb[1],rgb[2]);
      write(fd,line,strlen(line));
    }
  }

  close(fd);
}
