CC = gcc

SRC = format_string.c
TARGET = format_string

Cflags = -z execstack \
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