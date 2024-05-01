NAME := ./convert
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP
# CXXFLAGS += -pedantic-errors

SRCS_DIR := srcs
SRCS := main.cpp\
		$(SRCS_DIR)/ScalarConverter.cpp\
		# $(SRCS_DIR)/Cat.cpp\
		# $(SRCS_DIR)/Dog.cpp\
		# $(SRCS_DIR)/WrongAnimal.cpp\
		# $(SRCS_DIR)/WrongCat.cpp\

TEST_DIR := test
SRCS += $(TEST_DIR)/test.cpp\
		$(TEST_DIR)/testTitle.cpp\
		$(TEST_DIR)/testConvertChar.cpp\
		$(TEST_DIR)/testConvertDouble.cpp\
		# $(TEST_DIR)/testCorrectClass.cpp\
		# $(TEST_DIR)/testWrongClass.cpp\

OBJS_DIR := objs
OBJS := $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

DEPS := $(OBJS:%.o=%.d)

INCLUDES := -I./includes

.PHONY: all clean fclean re test leak

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $@

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	./$(NAME) | grep -v called

leak: re
	valgrind --leak-check=full $(NAME)

-include $(DEPS)
