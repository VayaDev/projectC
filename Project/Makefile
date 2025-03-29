# Конфигурация
CC = gcc
RC = windres
CFLAGS = -Wall -Wextra -I utils
RFLAGS = -O coff
LDFLAGS = -mwindows -lgdi32
SRC_DIR = utils
RES_DIR = resource
RES = $(RES_DIR)/11.resource
TARGET = app.exe

# Описание исходных файлов
APP_SRC = main.c
WIN_SRC = $(SRC_DIR)/dialogproc.c $(SRC_DIR)/mainwinproc.c
WIN_HEADER = $(SRC_DIR)/headerMainWin.h $(SRC_DIR)/HeaderGreat.h $(SRC_DIR)/headerDialog.h
RC_SRC = $(RES_DIR)/11.rc

# Объектные файлы
OBJ = $(APP_SRC:.c=.o) $(WIN_SRC:.c=.o) $(RES)

# Правила
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c $(WIN_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(RES): $(RC_SRC)
	$(RC) -i $< -O coff -o $@

clean:
	del /Q /F $(TARGET) *.o
	del /Q /F $(SRC_DIR)\*.o
	del /Q /F $(RES_DIR)\*.res

# Исключения
.PHONY: all clean