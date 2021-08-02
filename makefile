# this is make file
# 冒号前是最终的目标文件，冒号后是依赖文件
# tab键，后面是要执行的命令
a.out: max.o min.o 03_multiple_files-v3.c
	gcc max.o min.o 03_multiple_files-v3.c -o a.out

# 然后是依赖文件怎么生成的
max.o: 03_max.c
	gcc -c 03_max.c -o max.o
min.o: 03_min.c
	gcc -c 03_min.c -o min.o

clean:
	rm -f *.out && rm -f *.o && rm -f *.log
