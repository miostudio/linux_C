long mult2(long, long);

void multstore(long x, long y, long *dest){
	long t = mult2(x, y);
	*dest = t;
}

/*
查看汇编
$ gcc -Og -S -o mstore.s p3.c
$ less mstore.s

查看机器码
$ gcc -std=c11 -Og -c p3.c
$ ls -lt

$ gdb p3.o
(gdb) x/14xb multstore
0x0 <multstore>:	0xf3	0x0f	0x1e	0xfa	0x53	0x48	0x89	0xd3
0x8 <multstore+8>:	0xe8	0x00	0x00	0x00	0x00	0x48
(gdb) q
*/