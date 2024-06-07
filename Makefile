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


# Verificar si el archivo ft_putstr.c existe y agregarlo a la compilación
ifeq ($(wildcard rendu/ft_putstr/ft_putstr.c),rendu/ft_putstr/ft_putstr.c)
    SRC_FILES += rendu/ft_putstr/ft_putstr.c
    OBJ_FILES += rendu/ft_putstr/ft_putstr.o
    CFLAGS += -D_FILE_FT_PUTSTR_C
endif

# Verificar si el archivo ft_strlen.c existe y agregarlo a la compilación
ifeq ($(wildcard rendu/ft_strlen/ft_strlen.c),rendu/ft_strlen/ft_strlen.c)
    SRC_FILES += rendu/ft_strlen/ft_strlen.c
    OBJ_FILES += rendu/ft_strlen/ft_strlen.o
    CFLAGS += -D_FILE_FT_STRLEN_C
endif

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
	$(RM) rendu/*.o

# Regla para limpiar y luego compilar el programa
rebuild: clean all

# Regla para ejecutar el programa después de compilarlo
run: grademe
	$(MAKE) clean_objs
	./grademe
