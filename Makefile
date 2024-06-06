# **************************************************************************** #
# VARIABLES                                                                    #
# **************************************************************************** #
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Verificar si los archivos existen y definir los objetos
SRC_FILES = grademe.c
OBJ_FILES = grademe.o

SRC_FILES += control/lib/ft_input_ok.c
OBJ_FILES += control/lib/ft_input_ok.o
SRC_FILES += control/lib/ft_itoa.c
OBJ_FILES += control/lib/ft_itoa.o
SRC_FILES += control/lib/ft_paco.c
OBJ_FILES += control/lib/ft_paco.o
SRC_FILES += control/lib/ft_msg.c
OBJ_FILES += control/lib/ft_msg.o
SRC_FILES += control/lib/ft_files.c
OBJ_FILES += control/lib/ft_files.o
SRC_FILES += control/lib/ft_ctr_txt.c
OBJ_FILES += control/lib/ft_ctr_txt.o

# Verificar si los archivos existen y agregar las definiciones y objetos necesarios
# ifeq ($(wildcard control/mymain/mft_putstr.c),control/mymain/mft_putstr.c)
#     CFLAGS += -D_FILE_MFT_PUTSTR_C
#     SRC_FILES += control/mymain/mft_putstr.c
#     OBJ_FILES += control/mymain/mft_putstr.o
# endif

# Regla por defecto, solo compila el programa
all: run

# Regla para compilar el ejecutable
grademe: $(OBJ_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
%.o: %.c mylib.h
	$(CC) $(CCFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	$(RM) *.o grademe

# Regla para limpiar solo los archivos objeto después de compilar
clean_objs:
	$(RM) *.o
	$(RM) control/lib/*.o

# Regla para limpiar y luego compilar el programa
rebuild: clean all

# Regla para ejecutar el programa después de compilarlo
run: grademe
	$(MAKE) clean_objs
	./grademe
