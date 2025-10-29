# ╔══════════════════════════════════════════════════════════════════════════╗
# ║                              🚀 BANK PROJECT                              ║
# ║                             AUTO-DEP BUILD                                ║
# ╚══════════════════════════════════════════════════════════════════════════╝

NAME        = Bank
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 -MMD -MP
SRC         = main.cpp
OBJ         = $(SRC:.cpp=.o)
DEP         = $(OBJ:.o=.d)

# ════════════════════════════════════════════════════════════════════════════ #
#                                   RULES
# ════════════════════════════════════════════════════════════════════════════ #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Build complete!"

-include $(DEP)

%.o: %.cpp
	@echo "🧩 Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Removing object and dependency files..."
	rm -f $(OBJ) $(DEP)

fclean: clean
	@echo "🗑️  Removing binary..."
	rm -f $(NAME)

re: fclean all

# ════════════════════════════════════════════════════════════════════════════ #
#                                 PHONY RULES
# ════════════════════════════════════════════════════════════════════════════ #
.PHONY: all clean fclean re
