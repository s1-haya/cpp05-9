NAME := RPN
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP

ifeq ($(DEBUG), 1)
  CXXFLAGS += -DDEBUG
endif

SRCS_DIR := srcs
SRCS := main.cpp\
		$(SRCS_DIR)/RPN.cpp\

TEST_DIR := test
SRCS += $(TEST_DIR)/test.cpp\
		$(TEST_DIR)/testTitle.cpp\
		$(TEST_DIR)/testRPN.cpp

OBJS_DIR := objs
OBJS := $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

DEPS := $(OBJS:%.o=%.d)

INCLUDES := -I./includes

.PHONY: all clean fclean re test leak

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	$(MAKE) re DEBUG=1
	./$(NAME)

leak: re
	valgrind --leak-check=full $(NAME)

-include $(DEPS)
