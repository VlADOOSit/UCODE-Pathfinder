LIB = libmx.a

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: create_obj LIBMX create_lib

create_obj:
	@mkdir obj

LIBMX:
	@clang $(FLAGS) -Iinc -c src/*.c
	@mv *.o obj/

create_lib:
	@ar -rc $(LIB) obj/*.o
	@ranlib $(LIB)

clean:
	@rm -rf obj

uninstall:
	@rm -rf obj
	@rm -rf $(LIB)

reinstall:
	@make uninstall
	@make