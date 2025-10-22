# ╔══════════════════════════════════════════════════════════════════════════╗
# ║                              🚗  CAR PROJECT                              ║
# ║                              ✨ MAKEFILE ✨                                ║
# ╚══════════════════════════════════════════════════════════════════════════╝

# ────────────────────────────── CONFIGURATION ──────────────────────────────── #
NAME        = Car
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
SRC         = main.cpp
OBJ         = $(SRC:.cpp=.o)

# ──────────────────────────────── BUILD RULES ──────────────────────────────── #
all: header $(NAME)
	@echo "✅ Build complete!"
	@echo "🚀 Run './$(NAME)' to start the simulation!"
	@echo "───────────────────────────────────────────────"

header:
	@echo ""
	@echo "╔═══════════════════════════════════════════════╗"
	@echo "║       🏁 STARTING CAR SIMULATION BUILD 🏁      ║"
	@echo "╚═══════════════════════════════════════════════╝"

$(NAME): $(OBJ)
	@echo "🔧 Linking object files..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@echo "🧩 Compiling source file: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ──────────────────────────────── CLEANUP RULES ────────────────────────────── #
clean:
	@echo ""
	@echo "🧹 Cleaning object files..."
	rm -f $(OBJ)
	@echo "✨ Object cleanup complete!"

fclean: clean
	@echo "🗑️  Removing executable..."
	rm -f $(NAME)
	@echo "🧼 Full cleanup done!"

re: fclean all

# ──────────────────────────────── META RULES ───────────────────────────────── #
.PHONY: all clean fclean re header
