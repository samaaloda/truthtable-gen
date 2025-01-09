main: main.c btree.c parsing.c header.h data.c eval.c table.c
	gcc `pkg-config --cflags gtk+-3.0` -o main main.c btree.c parsing.c data.c eval.c table.c `pkg-config --libs gtk+-3.0`

