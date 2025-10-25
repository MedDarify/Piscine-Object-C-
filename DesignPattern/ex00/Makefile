# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = Preparation
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
SRC         = main.cpp Course.cpp Form.cpp Person.cpp Room.cpp
OBJ         = $(SRC:.cpp=.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Build complete!"

%.o: %.cpp
	@echo "🧩 Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Removing object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️  Removing binary..."
	rm -f $(NAME)
	rm -f app.log

re: fclean all

# **************************************************************************** #
#                                 PHONY RULES                                  #
# **************************************************************************** #

.PHONY: all clean fclean re
