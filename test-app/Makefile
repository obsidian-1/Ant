CC=g++-9
CFLAGS=-O3
LIB_PATH=~/Desktop/Coding/ant/ant-core/src

ant_graphics.o:
	$(CC) $(LIB_PATH)/Graphics/*.cpp -I$(LIB_PATH)/Graphics -I$(LIB_PATH) -c -o ant_graphics.o

ant_core.o:
	$(CC) -I$(LIB_PATH)/Graphics $(LIB_PATH)/*.cpp -c -o ant_core.o
