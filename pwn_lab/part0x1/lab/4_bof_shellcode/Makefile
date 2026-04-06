CC = gcc

SRC = shellcode.c
TARGET = shellcode

Cflags = -fno-stack-protector \
		 -z execstack \
		 -no-pie \
		 -z norelro \
		 -g

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(Cflags) -o $(TARGET) $(SRC)
	@echo "[*] Compilation done."
	@echo "[*] Run checksec --file=$(TARGET) to check binary"

clean:
	rm -f $(TARGET)